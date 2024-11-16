//---------------------------------------------------------------------------------------------------------
//
//	TradingCardsCursor
//	* 4 tiles, reduced by non-unique and flipped tiles, not compressed
//	* 2x2 map, not compressed
//	Size: 68 + 8 = 76 byte
//
//---------------------------------------------------------------------------------------------------------

const uint32 TradingCardsCursorTiles[] __attribute__((aligned(4))) =
{
	0x00000000,
	0x00000000,0xBFF0FFF0,0xBFF02FF0,0xF8B0FEF0,0x00000000,0x00000002,0x00000000,0x000B0002,
	0x8000E020,0x00000000,0x00000000,0x00000000,0x00BF002F,0x0BF802FE,0xBF802FE0,0x08002E00,
};

const uint16 TradingCardsCursorMap[] __attribute__((aligned(4))) =
{
	0x0000,0x0001,0x0002,0x0003,
};
