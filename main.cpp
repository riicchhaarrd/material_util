#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include "buffer_reader.h"
#include "state.h"
#include "material.h"
#include "material_state_map_bit_groups.h"

class MaterialReader
{
	std::string name, reference_image_name;
	//not sure whether there is possibility of a key existing multiple times
	//probably not, i ran a check against all of the stock material files and none of them had a key multiple times
	std::unordered_map<std::string, std::string> maps;
	Material m;
	MaterialState state;
	std::unordered_map<std::string, uint32_t> state_map;
  public:
	MaterialReader()
	{
		memset(&m, 0, sizeof(m));
		assert(sizeof(MaterialInfo) == 0x2c);
		assert(sizeof(Material) == 0x44);
	}
	bool read_from_buffer(void* buffer, size_t buffer_size)
	{
		if (buffer_size < sizeof(Material))
			return false;
		memcpy(&m, buffer, sizeof(m));
		BufferReader br(buffer, buffer_size);
		br.set_cursor(m.info.name);
		name = br.read_string();
		br.set_cursor(m.info.reference_image_name);
		reference_image_name = br.read_string();

		if (m.texture_count)
		{
			br.set_cursor(m.textures);
			std::vector<MaterialTextureDef> material_texture_defs;
			material_texture_defs.resize(m.texture_count);
			if (!br.read(material_texture_defs.data(), sizeof(MaterialTextureDef), m.texture_count))
				return false;
			for (int i = 0; i < m.texture_count; ++i)
			{
				auto& def = material_texture_defs[i];
				br.set_cursor(def.name);
				std::string def_name = br.read_string();
				//printf("\t\tdef name = %s\n", def_name.c_str());
				if (def.semantic == SEMANTIC_WATER)
					continue; //ignoring/skipping water
				br.set_cursor(def.u.image);
				std::string image_name = br.read_string();
				printf("\t\tdef %s->image: %s\n", def_name.c_str(), image_name.c_str());
				printf("\t\tsemantic %d\n", def.semantic);
				printf("\t\tsampler_state %d\n", def.sampler_state);
				printf("\t\tunused_0 %d\n", def.unused_0);
				printf("\t\tunused_1 %d\n", def.unused_1);
				#if 0 //unneeded
				if (maps.find(def_name) != maps.end())
				{
					printf("error reading, '%s' already exists.\n", def_name.c_str());
					getchar();
					exit(-1);
				}
				#endif
				maps[def_name] = image_name;
			}
		}
		br.set_cursor(m.technique_set);
		auto techset = br.read_string();
		printf("technique set = %s\n", techset.c_str());
		if (m.constant_count > 0)
		{
			br.set_cursor(m.constants);
			MaterialConstantDefObj c;
			if (!br.read(&c, sizeof(c), m.constant_count))
				return false;
			for (int i = 0; i < m.constant_count; ++i)
			{
				br.set_cursor(c.name);
				std::string constant_name = br.read_string();
				printf("\tconstant '%s' = %f,%f,%f,%f\n", constant_name.c_str(), c.literal_[0], c.literal_[1],
					   c.literal_[2], c.literal_[3]);
			}

		}
		check_bits(m.state_bits[0], &MtlStateMapBitGroup::stateBitsMask1);
		check_bits(m.state_bits[1], &MtlStateMapBitGroup::stateBitsMask2);
		state.alpha_test = (EAlphaTest)state_map["mtlAlphaTest"];
		state.blend_op = (EBlendOp)state_map["mtlBlendOp"];
		state.src_blend = (ESrcBlend)state_map["mtlSrcBlend"];
		state.dest_blend = (EDestBlend)state_map["mtlDestBlend"];
		state.blend_op_alpha = (EBlendOpAlpha)state_map["mtlBlendOpAlpha"];
		state.src_blend_alpha = (ESrcBlendAlpha)state_map["mtlSrcBlendAlpha"];
		state.dest_blend_alpha = (EDestBlendAlpha)state_map["mtlDestBlendAlpha"];
		state.cull_face = (ECullFace)state_map["mtlCullFace"];
		state.color_write_rgb = (EColorWriteRgb)state_map["mtlColorWriteRgb"];
		state.color_write_alpha = (EColorWriteAlpha)state_map["mtlColorWriteAlpha"];
		state.fog = (EFog)state_map["mtlFog"];
		state.depth_test = (EDepthTest)state_map["mtlDepthTest"];
		state.depth_write = (EDepthWrite)state_map["mtlDepthWrite"];
		state.polygon_offset = (EPolygonOffset)state_map["mtlPolygonOffset"];
		state.stencil = (EStencil)state_map["mtlStencil"];
		state.stencil_func_front = (EStencilFuncFront)state_map["mtlStencilFuncFront"];
		state.stencil_op_front_pass = (EStencilOpFrontPass)state_map["mtlStencilOpFrontPass"];
		state.stencil_op_front_fail = (EStencilOpFrontFail)state_map["mtlStencilOpFrontFail"];
		state.stencil_op_front_z_fail = (EStencilOpFrontZFail)state_map["mtlStencilOpFrontZFail"];
		state.stencil_func_back = (EStencilFuncBack)state_map["mtlStencilFuncBack"];
		state.stencil_op_back_pass = (EStencilOpBackPass)state_map["mtlStencilOpBackPass"];
		state.stencil_op_back_fail = (EStencilOpBackFail)state_map["mtlStencilOpBackFail"];
		state.stencil_op_back_z_fail = (EStencilOpBackZFail)state_map["mtlStencilOpBackZFail"];
		return true;
	}

	void check_bits(uint32_t bits, uint32_t MtlStateMapBitGroup::*ptr)
	{
		for (int i = 0; state_map_bit_groups[i].name; ++i)
		{
			auto& bg = state_map_bit_groups[i];

			// check whether the mask is 0, then it's not in this mask and skip it
			if (bg.*ptr == 0)
				continue;
			uint32_t masked = bits & bg.*ptr;

			std::map<int, std::string> map;
			for (int j = 0; bg.bitNames[j].name; ++j)
				map[bg.bitNames[j].value] = bg.bitNames[j].name;

			bool found = false;
			for (auto it = map.rbegin(); it != map.rend(); ++it)
			{
				if (it->first == masked)
				{
					found = true;
					state_map[bg.name] = it->first;
					printf("%s: %s\n", bg.name, it->second.c_str());
					break;
				}
			}
		}
	}

	void dump()
	{
		printf("material: '%s'\n", name.c_str());
		printf("reference_image_name: '%s'\n", reference_image_name.c_str());
		printf("\tname = %d\n", m.info.name);
		printf("\treference_image_name = %d\n", m.info.reference_image_name);
		printf("\thash_index = %d\n", m.info.hash_index);
		printf("\tgame_flags = %d\n", m.info.game_flags);
		printf("\tsort_key = %d\n", m.info.sort_key);
		printf("\ttexture_atlas_row_count = %d\n", m.info.texture_atlas_row_count);
		printf("\ttexture_atlas_column_count = %d\n", m.info.texture_atlas_column_count);
		printf("\tmax_deform_move = %d\n", m.info.max_deform_move);
		printf("\tdeform_flags = %d\n", m.info.deform_flags);
		printf("\tusage = %d\n", m.info.usage);
		printf("\ttool_flags = %d\n", m.info.tool_flags);
		printf("\tlocale = %d\n", m.info.locale);
		printf("\tauto_tex_scale_width = %d\n", m.info.auto_tex_scale_width);
		printf("\tauto_tex_scale_height = %d\n", m.info.auto_tex_scale_height);
		printf("\ttess_size = %d\n", m.info.tess_size);
		printf("\tsurface_flags = %d\n", m.info.surface_flags);
		printf("\tcontents = %d\n", m.info.contents);
		for (int i = 0; i < 2; ++i)
			printf("state_bits[%d] = %d\n", i, m.state_bits[i]);
//		check_bits(m.state_bits[0], &MtlStateMapBitGroup::stateBitsMask1);
//		check_bits(m.state_bits[1], &MtlStateMapBitGroup::stateBitsMask2);
		printf("texture_count = %d\n", m.texture_count);
		printf("constant_count = %d\n", m.constant_count);
		printf("technique_set = %d\n", m.technique_set);
		printf("textures = %d\n", m.textures);
		printf("constants = %d\n", m.constants);

		for (auto& it : maps)
		{
			printf("%s: %s\n", it.first.c_str(), it.second.c_str());
		}
	}
};

size_t add_string(size_t& pos, std::unordered_map<std::string, size_t>& ind, const std::string str)
{
	auto fnd = ind.find(str);
	if (fnd != ind.end())
		return fnd->second;
	size_t _ = pos;
	ind[str] = _;
	pos += str.size() + 1;
	return _;
}

void get_bits_for_material_state(MaterialState& state, uint32_t& a, uint32_t& b)
{
	a = uint32_t(state.alpha_test) | uint32_t(state.blend_op) | uint32_t(state.src_blend) | uint32_t(state.dest_blend) |
		uint32_t(state.blend_op_alpha) | uint32_t(state.src_blend_alpha) | uint32_t(state.dest_blend_alpha) |
		uint32_t(state.cull_face) | uint32_t(state.color_write_rgb) | uint32_t(state.color_write_alpha) | uint32_t(state.fog);
	b = uint32_t(state.depth_test) | uint32_t(state.depth_write) | uint32_t(state.polygon_offset) | uint32_t(state.stencil) |
		uint32_t(state.stencil_func_front) | uint32_t(state.stencil_op_front_pass) | uint32_t(state.stencil_op_front_fail) |
		uint32_t(state.stencil_op_front_z_fail) | uint32_t(state.stencil_func_back) | uint32_t(state.stencil_op_back_pass) |
		uint32_t(state.stencil_op_back_fail) | uint32_t(state.stencil_op_back_z_fail);
}

void write_material(const std::string path, const std::string material_name, std::unordered_map<std::string, std::string>& texture_map,
					std::string_view techset = "2d")
{
	Material m = {0};
	// write default material
	std::string _ = path + "/" + material_name;
	FILE* fp = fopen(_.c_str(), "wb");
	if (!fp)
		return;
	m.texture_count = texture_map.size();
	m.constant_count = 0;
	m.info.auto_tex_scale_width = 1;
	m.info.auto_tex_scale_height = 1;
	m.info.texture_atlas_column_count = 1;
	m.info.texture_atlas_row_count = 1;
	m.info.contents = 1;
	m.info.sort_key = 3;
	MaterialState state;
	state.alpha_test = EAlphaTest::kAlways;
	state.blend_op = EBlendOp::kDisable;
	state.src_blend = ESrcBlend::kOne;
	state.dest_blend = EDestBlend::kZero;
	state.blend_op_alpha = EBlendOpAlpha::kDisable;
	state.src_blend_alpha = ESrcBlendAlpha::kOne;
	state.dest_blend_alpha = EDestBlendAlpha::kZero;
	state.cull_face = ECullFace::kBack;
	state.color_write_rgb = EColorWriteRgb::kEnable;
	state.color_write_alpha = EColorWriteAlpha::kDisable;
	state.fog = EFog::kEnable;
	state.depth_test = EDepthTest::kLessEqual;
	state.depth_write = EDepthWrite::kEnable;
	state.polygon_offset = EPolygonOffset::k0;
	state.stencil = EStencil::kDisable;
	state.stencil_func_front = EStencilFuncFront::kNever;
	state.stencil_op_front_pass = EStencilOpFrontPass::kKeep;
	state.stencil_op_front_fail = EStencilOpFrontFail::kKeep;
	state.stencil_op_front_z_fail = EStencilOpFrontZFail::kKeep;
	state.stencil_func_back = EStencilFuncBack::kNever;
	state.stencil_op_back_pass = EStencilOpBackPass::kKeep;
	state.stencil_op_back_fail = EStencilOpBackFail::kKeep;
	state.stencil_op_back_z_fail = EStencilOpBackZFail::kKeep;
	get_bits_for_material_state(state, m.state_bits[0], m.state_bits[1]);
	//m.state_bits[0] = 672303122;
	//m.state_bits[1] = 5;
	char reference_image_name[256] = {0};
	snprintf(reference_image_name, sizeof(reference_image_name), "%s", texture_map["colorMap"].c_str());

	size_t filepos = sizeof(m);
	m.textures = filepos;
	filepos += m.texture_count * sizeof(MaterialTextureDef);
	m.technique_set = filepos;
	m.constants = m.technique_set;
	filepos += techset.size() + 1;
	m.info.name = filepos; // name offset is after material header
	filepos += material_name.size() + 1;
	//m.info.reference_image_name = filepos; // offset after name
	//filepos += strlen(reference_image_name) + 1;

	std::unordered_map<std::string, size_t> indexed_strings;
	for (auto& it : texture_map)
	{
		add_string(filepos, indexed_strings, it.second);
		add_string(filepos, indexed_strings, it.first);
	}
	m.info.reference_image_name = indexed_strings[texture_map["colorMap"]];

	fwrite(&m, sizeof(m), 1, fp);

	if (m.texture_count)
	{
		for (auto& it : texture_map)
		{
			MaterialTextureDef def = {0};
			def.semantic = 2;
			def.sampler_state = 0;
			def.name = indexed_strings[it.first];
			def.u.image = indexed_strings[it.second];
			fwrite(&def, sizeof(def), 1, fp);
		}
	}

	fwrite(techset.data(), 1, techset.size() + 1, fp);
	fwrite(material_name.data(), 1, material_name.size() + 1, fp);
	//fwrite(reference_image_name, 1, strlen(reference_image_name) + 1, fp);

	for (auto it = indexed_strings.begin(); it != indexed_strings.end(); ++it)
	{
		fwrite(it->first.c_str(), 1, it->first.size() + 1, fp);
	}

	fclose(fp);
}

int main(int argc, char **argv)
{
#if 1
	if (argc < 2)
		return 0;
	std::ifstream in(argv[1], std::ios::ate | std::ios::binary);
	if (!in.is_open())
	{
		printf("Failed to open '%s'\n", argv[1]);
		return 0;
	}
	size_t file_size = in.tellg();
	in.seekg(std::ios::beg);
	std::vector<char> v;
	v.resize(file_size);
	in.read(v.data(),file_size);

	MaterialReader m;
	m.read_from_buffer(v.data(), v.size());
	m.dump();
	getchar();
#else
	//should create a 1:1 copy of the caulk material but with the name caulx instead of caulk
	//altough i might have changed the states or things to match a other material
	std::unordered_map<std::string, std::string> tex;
	tex["colorMap"] = "caulk";
	write_material(".", "caulx", tex, "tools");
	#endif
	return 0;
}