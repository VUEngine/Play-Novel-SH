//---------------------------------------------------------------------------------------------------------
//
//	LowPowerIndicatorBlack
//	* 8 tiles, unreduced, not compressed
//	* 2x4 map, not compressed
//	* 4 animation frames, spritesheet
//	Size: 132 + 16 = 148 byte
//
//---------------------------------------------------------------------------------------------------------

const uint32 LowPowerIndicatorBlackTiles[] __attribute__((aligned(4))) =
{
	0x00000000,
	0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,
	0xFFFC3C00,0xC00CF00C,0x000C000C,0x0000FFFC,0xF3FFF000,0x03FF03FF,0x03FC03FF,0xF0F0F3FF,
	0xFFFD7D55,0xD55DF55D,0x555D555D,0x5555FFFD,0xF7FFF555,0x57FF57FF,0x57FD57FF,0xF5F5F7FF,
	0xFFFEBEAA,0xEAAEFAAE,0xAAAEAAAE,0xAAAAFFFE,0xFBFFFAAA,0xABFFABFF,0xABFEABFF,0xFAFAFBFF,
};

const uint16 LowPowerIndicatorBlackMap[] __attribute__((aligned(4))) =
{
	0x0000,0x0001,
};
