//---------------------------------------------------------------------------------------------------------
//
//  LowPowerIndicatorBlack
//  • 16×32 pixels
//  • 8 tiles, unreduced, not compressed
//  • 2×4 map, not compressed
//  • 4 animation frames, 2×1, spritesheet
//  Size: 132 + 16 = 148
//
//---------------------------------------------------------------------------------------------------------

const uint32 LowPowerIndicatorBlackTiles[33] __attribute__((aligned(4))) =
{
    0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
    0x00014155,0x15510551,0x55515551,0x55550001,0x04000555,0x54005400,0x54015400,0x05050400,
    0x000282AA,0x2AA20AA2,0xAAA2AAA2,0xAAAA0002,0x08000AAA,0xA800A800,0xA802A800,0x0A0A0800,
    0x0003C3FF,0x3FF30FF3,0xFFF3FFF3,0xFFFF0003,0x0C000FFF,0xFC00FC00,0xFC03FC00,0x0F0F0C00,
};

const uint16 LowPowerIndicatorBlackMap[8] __attribute__((aligned(4))) =
{
    0x0000,0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,
};

const uint32 LowPowerIndicatorBlackTilesFrameOffsets[4] __attribute__((aligned(4))) =
{
    0x00000001,0x00000009,0x00000011,0x00000019,
};