#pragma once

enum class EAlphaTest
{
	kAlways = 0x800,
	kGE128 = 0x3000,
	kGT0 = 0x1000,
	kLT128 = 0x2000
};

enum class EBlendOp
{
	kDisable = 0x0,
	kAdd = 0x100,
	kSubtract = 0x200,
	kRevSubtract = 0x300,
	kMin = 0x400,
	kMax = 0x500
};

enum class ESrcBlend
{
	kZero = 0x1,
	kOne = 0x2,
	kSrcColor = 0x3,
	kInvSrcColor = 0x4,
	kSrcAlpha = 0x5,
	kInvSrcAlpha = 0x6,
	kDestAlpha = 0x7,
	kInvDestAlpha = 0x8,
	kDestColor = 0x9,
	kInvDestColor = 0xa,
	kBlendFactor = 0xc,
	kInvBlendFactor = 0xd
};

enum class EDestBlend
{
	kZero = 0x10,
	kOne = 0x20,
	kSrcColor = 0x30,
	kInvSrcColor = 0x40,
	kSrcAlpha = 0x50,
	kInvSrcAlpha = 0x60,
	kDestAlpha = 0x70,
	kInvDestAlpha = 0x80,
	kDestColor = 0x90,
	kInvDestColor = 0xa0,
	kBlendFactor = 0xc0,
	kInvBlendFactor = 0xd0
};

enum class EBlendOpAlpha
{
	kDisable = 0x0,
	kAdd = 0x1000000,
	kSubtract = 0x2000000,
	kRevSubtract = 0x3000000,
	kMin = 0x4000000,
	kMax = 0x5000000
};

enum class ESrcBlendAlpha
{
	kZero = 0x10000,
	kOne = 0x20000,
	kSrcColor = 0x30000,
	kInvSrcColor = 0x40000,
	kSrcAlpha = 0x50000,
	kInvSrcAlpha = 0x60000,
	kDestAlpha = 0x70000,
	kInvDestAlpha = 0x80000,
	kDestColor = 0x90000,
	kInvDestColor = 0xa0000,
	kBlendFactor = 0xc0000,
	kInvBlendFactor = 0xd0000
};

enum class EDestBlendAlpha
{
	kZero = 0x100000,
	kOne = 0x200000,
	kSrcColor = 0x300000,
	kInvSrcColor = 0x400000,
	kSrcAlpha = 0x500000,
	kInvSrcAlpha = 0x600000,
	kDestAlpha = 0x700000,
	kInvDestAlpha = 0x800000,
	kDestColor = 0x900000,
	kInvDestColor = 0xa00000,
	kBlendFactor = 0xc00000,
	kInvBlendFactor = 0xd00000
};

enum class ECullFace
{
	kNone = 0x4000,
	kBack = 0x8000,
	kFront = 0xc000
};

enum class EColorWriteRgb
{
	kEnable = 0x8000000,
	kDisable = 0x0
};

enum class EColorWriteAlpha
{
	kEnable = 0x10000000,
	kDisable = 0x0
};

enum class EFog
{
	kEnable = 0x20000000,
	kDisable = 0x0
};

enum class EDepthTest
{
	kDisable = 0x2,
	kLessEqual = 0x4,
	kEqual = 0x8,
	kAlways = 0xc
};

enum class EDepthWrite
{
	kEnable = 0x1,
	kDisable = 0x0
};

enum class EPolygonOffset
{
	k0 = 0x0,
	k1 = 0x10,
	k2 = 0x20
};

enum class EStencil
{
	kDisable = 0x0,
	kOneSided = 0x40,
	kTwoSided = 0xc0
};

enum class EStencilFuncFront
{
	kNever = 0x0,
	kLess = 0x20000,
	kEqual = 0x40000,
	kLessEqual = 0x60000,
	kGreater = 0x80000,
	kNotEqual = 0xa0000,
	kGreaterEqual = 0xc0000,
	kAlways = 0xe0000
};

enum class EStencilOpFrontPass
{
	kKeep = 0x0,
	kZero = 0x100,
	kReplace = 0x200,
	kIncrSat = 0x300,
	kDecrSat = 0x400,
	kInvert = 0x500,
	kIncr = 0x600,
	kDecr = 0x700
};

enum class EStencilOpFrontFail
{
	kKeep = 0x0,
	kZero = 0x800,
	kReplace = 0x1000,
	kIncrSat = 0x1800,
	kDecrSat = 0x2000,
	kInvert = 0x2800,
	kIncr = 0x3000,
	kDecr = 0x3800
};

enum class EStencilOpFrontZFail
{
	kKeep = 0x0,
	kZero = 0x4000,
	kReplace = 0x8000,
	kIncrSat = 0xc000,
	kDecrSat = 0x10000,
	kInvert = 0x14000,
	kIncr = 0x18000,
	kDecr = 0x1c000
};

enum class EStencilFuncBack : unsigned int
{
	kNever = 0x0,
	kLess = 0x20000000,
	kEqual = 0x40000000,
	kLessEqual = 0x60000000,
	kGreater = 0x80000000,
	kNotEqual = 0xa0000000,
	kGreaterEqual = 0xc0000000,
	kAlways = 0xe0000000
};

enum class EStencilOpBackPass
{
	kKeep = 0x0,
	kZero = 0x100000,
	kReplace = 0x200000,
	kIncrSat = 0x300000,
	kDecrSat = 0x400000,
	kInvert = 0x500000,
	kIncr = 0x600000,
	kDecr = 0x700000
};

enum class EStencilOpBackFail
{
	kKeep = 0x0,
	kZero = 0x800000,
	kReplace = 0x1000000,
	kIncrSat = 0x1800000,
	kDecrSat = 0x2000000,
	kInvert = 0x2800000,
	kIncr = 0x3000000,
	kDecr = 0x3800000
};

enum class EStencilOpBackZFail
{
	kKeep = 0x0,
	kZero = 0x4000000,
	kReplace = 0x8000000,
	kIncrSat = 0xc000000,
	kDecrSat = 0x10000000,
	kInvert = 0x14000000,
	kIncr = 0x18000000,
	kDecr = 0x1c000000
};

struct MaterialState
{
	EAlphaTest alpha_test;
	EBlendOp blend_op;
	ESrcBlend src_blend;
	EDestBlend dest_blend;
	EBlendOpAlpha blend_op_alpha;
	ESrcBlendAlpha src_blend_alpha;
	EDestBlendAlpha dest_blend_alpha;
	ECullFace cull_face;
	EColorWriteRgb color_write_rgb;
	EColorWriteAlpha color_write_alpha;
	EFog fog;
	EDepthTest depth_test;
	EDepthWrite depth_write;
	EPolygonOffset polygon_offset;
	EStencil stencil;
	EStencilFuncFront stencil_func_front;
	EStencilOpFrontPass stencil_op_front_pass;
	EStencilOpFrontFail stencil_op_front_fail;
	EStencilOpFrontZFail stencil_op_front_z_fail;
	EStencilFuncBack stencil_func_back;
	EStencilOpBackPass stencil_op_back_pass;
	EStencilOpBackFail stencil_op_back_fail;
	EStencilOpBackZFail stencil_op_back_z_fail;

	MaterialState()
	{
		set_sane_defaults();
	}

	void set_sane_defaults()
	{
		alpha_test = EAlphaTest::kAlways;
		blend_op = EBlendOp::kDisable;
		src_blend = ESrcBlend::kOne;
		dest_blend = EDestBlend::kZero;
		blend_op_alpha = EBlendOpAlpha::kDisable;
		src_blend_alpha = ESrcBlendAlpha::kOne;
		dest_blend_alpha = EDestBlendAlpha::kZero;
		cull_face = ECullFace::kBack;
		color_write_rgb = EColorWriteRgb::kEnable;
		color_write_alpha = EColorWriteAlpha::kDisable;
		fog = EFog::kEnable;
		depth_test = EDepthTest::kLessEqual;
		depth_write = EDepthWrite::kEnable;
		polygon_offset = EPolygonOffset::k0;
		stencil = EStencil::kDisable;
		stencil_func_front = EStencilFuncFront::kNever;
		stencil_op_front_pass = EStencilOpFrontPass::kKeep;
		stencil_op_front_fail = EStencilOpFrontFail::kKeep;
		stencil_op_front_z_fail = EStencilOpFrontZFail::kKeep;
		stencil_func_back = EStencilFuncBack::kNever;
		stencil_op_back_pass = EStencilOpBackPass::kKeep;
		stencil_op_back_fail = EStencilOpBackFail::kKeep;
		stencil_op_back_z_fail = EStencilOpBackZFail::kKeep;
	}

	bool is_blending_enabled()
	{
		return blend_op == EBlendOp::kDisable && blend_op_alpha == EBlendOpAlpha::kDisable;
	}
};