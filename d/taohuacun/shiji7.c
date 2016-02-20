// /d/taohuacun/shiji7.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set( "short", "市集" );
	set( "long", @LONG
你身处市集中，身边人头攒动，吆喝叫卖之声不绝于耳。集市里有
个卖花姑娘，你不禁想买点什么。
LONG
	);
	set( "exits", ([
		"west"	: __DIR__"shiji2",
		"south"	: __DIR__"shiji5",
		"north"	: __DIR__"shiji9",
	]));
	set("objects", ([
		__DIR__"npc/flowerg" : 1,
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -90);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}