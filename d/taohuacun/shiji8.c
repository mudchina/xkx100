// /d/taohuacun/shiji8.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set( "short", "市集" );
	set( "long", @LONG
你身处市集中，身边人头攒动，吆喝叫卖之声不绝于耳。这个小贩
有什么可卖的？
LONG
	);
	set( "exits", ([
		"east"	: __DIR__"shiji3",
		"south"	: __DIR__"shiji6",
	]));
	set("objects", ([
		__DIR__"npc/xiaofan" : 1,
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -110);
	set("coor/y", 60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}