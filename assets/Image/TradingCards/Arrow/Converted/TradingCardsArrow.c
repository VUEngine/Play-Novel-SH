
//——————————————————————————————————————————————————————————————————————————————————————————————————————————

//
//	TradingCardsArrow
//	* 6 tiles, reduced by non-unique and flipped tiles, not compressed
//	* 3x2 map, not compressed
//	Size: 100 + 12 = 112 byte
//

//——————————————————————————————————————————————————————————————————————————————————————————————————————————


const uint32 TradingCardsArrowTiles[] __attribute__((aligned(4))) =
{
	0x00000000,
	0x00000000,0x00000000,0x50000000,0xAAA05500,0x40000000,0x95505400,0x96955955,0x9AA6699A,
	0x04000000,0x15411540,0x09411941,0x15411941,0xBE40ABE4,0x4000E400,0x00000000,0x00000000,
	0x999AA669,0xAABE66AB,0xF900AFA4,0x00009000,0x16411941,0x15411941,0x1B811681,0x00001900,
};

const uint16 TradingCardsArrowMap[] __attribute__((aligned(4))) =
{
	0x0000,0x0001,0x0002,0x0003,0x0004,0x0005,
};
