#pragma once

#define BIT(x) (1 << (x))

enum EToolFlag
{
	kDrawToggle = BIT(1),
	kRadialNormals = BIT(3)
};
enum EGameFlag
{
	kSky = BIT(3)
};

enum class EUsage
{
	kNotInEditor,
	kCase,
	kTools,
	kDoor,
	kFloor,
	kCeiling,
	kRoof,
	kInteriorWall,
	kInteriorTrim,
	kExteriorWall,
	kExteriorTrim,
	kWindow,
	kPoster,
	kSign,
	kCore,
	kDamage,
	kTrench,
	kFence,
	kBackgroundFoliage,
	kGround,
	kLiquid,
	kRoad,
	kRock,
	kSky,
	kBarrel,
	kCrate
};

enum class ELocaleFlag
{
	kFlagNone = 0,
	kFlagCase = BIT(0),
	kFlagTest = BIT(1),
	kFlagTools = BIT(2),
	kFlagDecal = BIT(3),
	kFlagStalingrad = BIT(4),
	kFlagStalingradWinter = BIT(5),
	kFlagKiev = BIT(6),
	kFlagIwoJima = BIT(7),
	kFlagTinian = BIT(8),
	kFlagTarawa = BIT(9),
	kFlagHill400 = BIT(10),
	kFlagNormandy = BIT(11),
	kFlagDuhoc = BIT(12),
	kFlagVillers = BIT(13),
	kFlagEgypt = BIT(14),
	kFlagLibya = BIT(15),
	kFlagTunisia = BIT(16),
	kFlagIndustrial = BIT(17),
	kFlagPoland = BIT(18)
};

enum class ESamplerStateFilter
{
	kAuto = 0,
	kNearest = 1,
	kLinear = 2,
	kBilinear = 6,
	kAnisotropic = 7,
	kTrilinear = 10,
	kMax = 16,
	kMask = (kMax - 1)
};

enum class ESamplerStateTileFlag
{
	kBoth = 0,
	kVertical = 16,
	kHorizontal = 32,
	kNone = kVertical | kHorizontal,
};