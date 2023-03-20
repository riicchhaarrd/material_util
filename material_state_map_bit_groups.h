#pragma once

MtlStateMapBitName mtlAlphaTest[] = {
	{"Always", 0x800},
	{"GE128", 0x3000},
	{"GT0", 0x1000},
	{"LT128", 0x2000},
	{NULL, 0x0}
};

MtlStateMapBitName mtlBlendOp[] = {
	{"Disable", 0x0},
	{"Add", 0x100},
	{"Subtract", 0x200},
	{"RevSubtract", 0x300},
	{"Min", 0x400},
	{"Max", 0x500},
	{NULL, 0x0}
};

MtlStateMapBitName mtlSrcBlend[] = {
	{"Zero", 0x1},
	{"One", 0x2},
	{"SrcColor", 0x3},
	{"InvSrcColor", 0x4},
	{"SrcAlpha", 0x5},
	{"InvSrcAlpha", 0x6},
	{"DestAlpha", 0x7},
	{"InvDestAlpha", 0x8},
	{"DestColor", 0x9},
	{"InvDestColor", 0xa},
	{"BlendFactor", 0xc},
	{"InvBlendFactor", 0xd},
	{NULL, 0x0}
};

MtlStateMapBitName mtlDestBlend[] = {
	{"Zero", 0x10},
	{"One", 0x20},
	{"SrcColor", 0x30},
	{"InvSrcColor", 0x40},
	{"SrcAlpha", 0x50},
	{"InvSrcAlpha", 0x60},
	{"DestAlpha", 0x70},
	{"InvDestAlpha", 0x80},
	{"DestColor", 0x90},
	{"InvDestColor", 0xa0},
	{"BlendFactor", 0xc0},
	{"InvBlendFactor", 0xd0},
	{NULL, 0x0}
};

MtlStateMapBitName mtlBlendOpAlpha[] = {
	{"Disable", 0x0},
	{"Add", 0x1000000},
	{"Subtract", 0x2000000},
	{"RevSubtract", 0x3000000},
	{"Min", 0x4000000},
	{"Max", 0x5000000},
	{NULL, 0x0}
};

MtlStateMapBitName mtlSrcBlendAlpha[] = {
	{"Zero", 0x10000},
	{"One", 0x20000},
	{"SrcColor", 0x30000},
	{"InvSrcColor", 0x40000},
	{"SrcAlpha", 0x50000},
	{"InvSrcAlpha", 0x60000},
	{"DestAlpha", 0x70000},
	{"InvDestAlpha", 0x80000},
	{"DestColor", 0x90000},
	{"InvDestColor", 0xa0000},
	{"BlendFactor", 0xc0000},
	{"InvBlendFactor", 0xd0000},
	{NULL, 0x0}
};

MtlStateMapBitName mtlDestBlendAlpha[] = {
	{"Zero", 0x100000},
	{"One", 0x200000},
	{"SrcColor", 0x300000},
	{"InvSrcColor", 0x400000},
	{"SrcAlpha", 0x500000},
	{"InvSrcAlpha", 0x600000},
	{"DestAlpha", 0x700000},
	{"InvDestAlpha", 0x800000},
	{"DestColor", 0x900000},
	{"InvDestColor", 0xa00000},
	{"BlendFactor", 0xc00000},
	{"InvBlendFactor", 0xd00000},
	{NULL, 0x0}
};

MtlStateMapBitName mtlCullFace[] = {
	{"None", 0x4000},
	{"Back", 0x8000},
	{"Front", 0xc000},
	{NULL, 0x0}
};

MtlStateMapBitName mtlColorWriteRgb[] = {
	{"Enable", 0x8000000},
	{"Disable", 0x0},
	{NULL, 0x0}
};

MtlStateMapBitName mtlColorWriteAlpha[] = {
	{"Enable", 0x10000000},
	{"Disable", 0x0},
	{NULL, 0x0}
};

MtlStateMapBitName mtlFog[] = {
	{"Enable", 0x20000000},
	{"Disable", 0x0},
	{NULL, 0x0}
};

MtlStateMapBitName mtlDepthTest[] = {
	{"Disable", 0x2},
	{"LessEqual", 0x4},
	{"Equal", 0x8},
	{"Always", 0xc},
	{NULL, 0x0}
};

MtlStateMapBitName mtlDepthWrite[] = {
	{"Enable", 0x1},
	{"Disable", 0x0},
	{NULL, 0x0}
};

MtlStateMapBitName mtlPolygonOffset[] = {
	{"0", 0x0},
	{"1", 0x10},
	{"2", 0x20},
	{NULL, 0x0}
};

MtlStateMapBitName mtlStencil[] = {
	{"Disable", 0x0},
	{"OneSided", 0x40},
	{"TwoSided", 0xc0},
	{NULL, 0x0}
};

MtlStateMapBitName mtlStencilFuncFront[] = {
	{"Never", 0x0},
	{"Less", 0x20000},
	{"Equal", 0x40000},
	{"LessEqual", 0x60000},
	{"Greater", 0x80000},
	{"NotEqual", 0xa0000},
	{"GreaterEqual", 0xc0000},
	{"Always", 0xe0000},
	{NULL, 0x0}
};

MtlStateMapBitName mtlStencilOpFrontPass[] = {
	{"Keep", 0x0},
	{"Zero", 0x100},
	{"Replace", 0x200},
	{"IncrSat", 0x300},
	{"DecrSat", 0x400},
	{"Invert", 0x500},
	{"Incr", 0x600},
	{"Decr", 0x700},
	{NULL, 0x0}
};

MtlStateMapBitName mtlStencilOpFrontFail[] = {
	{"Keep", 0x0},
	{"Zero", 0x800},
	{"Replace", 0x1000},
	{"IncrSat", 0x1800},
	{"DecrSat", 0x2000},
	{"Invert", 0x2800},
	{"Incr", 0x3000},
	{"Decr", 0x3800},
	{NULL, 0x0}
};

MtlStateMapBitName mtlStencilOpFrontZFail[] = {
	{"Keep", 0x0},
	{"Zero", 0x4000},
	{"Replace", 0x8000},
	{"IncrSat", 0xc000},
	{"DecrSat", 0x10000},
	{"Invert", 0x14000},
	{"Incr", 0x18000},
	{"Decr", 0x1c000},
	{NULL, 0x0}
};

MtlStateMapBitName mtlStencilFuncBack[] = {
	{"Never", 0x0},
	{"Less", 0x20000000},
	{"Equal", 0x40000000},
	{"LessEqual", 0x60000000},
	{"Greater", 0x80000000},
	{"NotEqual", 0xa0000000},
	{"GreaterEqual", 0xc0000000},
	{"Always", 0xe0000000},
	{NULL, 0x0}
};

MtlStateMapBitName mtlStencilOpBackPass[] = {
	{"Keep", 0x0},
	{"Zero", 0x100000},
	{"Replace", 0x200000},
	{"IncrSat", 0x300000},
	{"DecrSat", 0x400000},
	{"Invert", 0x500000},
	{"Incr", 0x600000},
	{"Decr", 0x700000},
	{NULL, 0x0}
};

MtlStateMapBitName mtlStencilOpBackFail[] = {
	{"Keep", 0x0},
	{"Zero", 0x800000},
	{"Replace", 0x1000000},
	{"IncrSat", 0x1800000},
	{"DecrSat", 0x2000000},
	{"Invert", 0x2800000},
	{"Incr", 0x3000000},
	{"Decr", 0x3800000},
	{NULL, 0x0}
};

MtlStateMapBitName mtlStencilOpBackZFail[] = {
	{"Keep", 0x0},
	{"Zero", 0x4000000},
	{"Replace", 0x8000000},
	{"IncrSat", 0xc000000},
	{"DecrSat", 0x10000000},
	{"Invert", 0x14000000},
	{"Incr", 0x18000000},
	{"Decr", 0x1c000000},
	{NULL, 0x0}
};

MtlStateMapBitGroup state_map_bit_groups[] = {
	{"mtlAlphaTest", mtlAlphaTest, 0x3800, 0x0},
	{"mtlBlendOp", mtlBlendOp, 0x700, 0x0},
	{"mtlSrcBlend", mtlSrcBlend, 0xf, 0x0},
	{"mtlDestBlend", mtlDestBlend, 0xf0, 0x0},
	{"mtlBlendOpAlpha", mtlBlendOpAlpha, 0x7000000, 0x0},
	{"mtlSrcBlendAlpha", mtlSrcBlendAlpha, 0xf0000, 0x0},
	{"mtlDestBlendAlpha", mtlDestBlendAlpha, 0xf00000, 0x0},
	{"mtlCullFace", mtlCullFace, 0xc000, 0x0},
	{"mtlColorWriteRgb", mtlColorWriteRgb, 0x8000000, 0x0},
	{"mtlColorWriteAlpha", mtlColorWriteAlpha, 0x10000000, 0x0},
	{"mtlFog", mtlFog, 0x20000000, 0x0},
	{"mtlDepthTest", mtlDepthTest, 0x0, 0xe},
	{"mtlDepthWrite", mtlDepthWrite, 0x0, 0x1},
	{"mtlPolygonOffset", mtlPolygonOffset, 0x0, 0x30},
	{"mtlStencil", mtlStencil, 0x0, 0xc0},
	{"mtlStencilFuncFront", mtlStencilFuncFront, 0x0, 0xe0000},
	{"mtlStencilOpFrontPass", mtlStencilOpFrontPass, 0x0, 0x700},
	{"mtlStencilOpFrontFail", mtlStencilOpFrontFail, 0x0, 0x3800},
	{"mtlStencilOpFrontZFail", mtlStencilOpFrontZFail, 0x0, 0x1c000},
	{"mtlStencilFuncBack", mtlStencilFuncBack, 0x0, 0xe0000000},
	{"mtlStencilOpBackPass", mtlStencilOpBackPass, 0x0, 0x700000},
	{"mtlStencilOpBackFail", mtlStencilOpBackFail, 0x0, 0x3800000},
	{"mtlStencilOpBackZFail", mtlStencilOpBackZFail, 0x0, 0x1c000000},
	{NULL, NULL, 0x0, 0x0}
};