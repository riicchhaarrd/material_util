#pragma once

#define BIT(x) (1 << (x))

// I didn't bother with the techniquesets

#pragma pack(push, 1)
struct MaterialInfo
{
	int32_t name;				  // actually char*
	int32_t reference_image_name; // actually char*
	int16_t hash_index;
	int16_t sorted_index;
	int8_t game_flags;
	int8_t sort_key;
	int8_t texture_atlas_row_count;
	int8_t texture_atlas_column_count;
	int32_t max_deform_move;
	int8_t deform_flags;
	int8_t usage;
	int16_t tool_flags;
	int32_t locale;
	int16_t auto_tex_scale_width;
	int16_t auto_tex_scale_height;
	int32_t tess_size;
	int32_t surface_flags;
	int32_t contents;
};

struct MtlStateMapBitName
{
	const char* name;
	uint32_t value;
};

struct MtlStateMapBitGroup
{
	const char* name;
	MtlStateMapBitName* bitNames;
	uint32_t stateBitsMask1;
	uint32_t stateBitsMask2;
};

struct Material
{
	MaterialInfo info;
	uint32_t state_bits[2];
	int16_t texture_count;
	int16_t constant_count;
	int32_t technique_set;
	int32_t textures;
	int32_t constants;
};

// From what I understand semantics are basically the slot index/number/name that the texture is attached to e.g sampler
// https://stackoverflow.com/questions/22064165/why-does-hlsl-have-semantics

#define SEMANTIC_COLOR (2)
#define SEMANTIC_NORMAL (3)
#define SEMANTIC_SPECULAR (4)
#define SEMANTIC_WATER (5)

union MaterialTextureDefInfo
{
	int32_t image;
	int32_t water;
};

struct MaterialWaterDef
{
	// not sure whether they're floats or ints
	int32_t texture_width;
	int32_t horizontal_world_length;
	int32_t vertical_world_length;
	float amplitude;
	float wind_speed;
	float wind_direction[2];
	int32_t map;
};

struct MaterialTextureDef
{
	int32_t name;
	int8_t sampler_state;
	int8_t semantic;
	int8_t unused_0;
	int8_t unused_1;
	MaterialTextureDefInfo u;
};

//it's used e.g detailMap, first the offset of the detailMap followed by 4x float, altough the detailMap xy offset is multiplied by 8 for some reason
struct MaterialConstantDefObj
{
	int32_t name;
	float literal_[4];
};
#pragma pack(pop)