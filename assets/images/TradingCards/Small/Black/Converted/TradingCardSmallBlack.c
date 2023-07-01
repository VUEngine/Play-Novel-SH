//---------------------------------------------------------------------------------------------------------
//
//  TradingCardSmallBlack
//  • 32×48 pixels
//  • 1 tiles, reduced by non-unique and flipped tiles, not compressed
//  • 4×6 map, not compressed
//  Size: 20 + 48 = 68
//
//---------------------------------------------------------------------------------------------------------

const uint32 TradingCardSmallBlackTiles[5] __attribute__((aligned(4))) =
{
    0x00000000,
    0x55555555,0x55555555,0x55555555,0x55555555,
};

const uint16 TradingCardSmallBlackMap[24] __attribute__((aligned(4))) =
{
    0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
    0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
    0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
};
