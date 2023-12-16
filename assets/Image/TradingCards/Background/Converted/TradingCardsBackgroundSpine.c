//---------------------------------------------------------------------------------------------------------
//
//  TradingCardsBackgroundSpine
//  * 3 tiles, reduced by non-unique and flipped tiles, not compressed
//  * 2x15 map, not compressed
//  Size: 52 + 60 = 112
//
//---------------------------------------------------------------------------------------------------------

const uint32 TradingCardsBackgroundSpineTiles[13] __attribute__((aligned(4))) =
{
    0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0xAAA0A900,0x00168598,0x0003000D,
    0x00000000,0x02AA001A,0x25000995,0x30001C00,
};

const uint16 TradingCardsBackgroundSpineMap[30] __attribute__((aligned(4))) =
{
    0x0001,0x0002,0x0000,0x0000,0x0001,0x0002,0x0000,0x0000,
    0x0001,0x0002,0x0000,0x0000,0x0001,0x0002,0x0000,0x0000,
    0x0001,0x0002,0x0000,0x0000,0x0001,0x0002,0x0000,0x0000,
    0x0001,0x0002,0x0000,0x0000,0x0001,0x0002,
};
