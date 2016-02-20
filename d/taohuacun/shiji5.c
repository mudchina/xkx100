// /d/taohuacun/shiji5.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set( "short", "市集" );
	set( "long", @LONG
你身处市集中，身边人头攒动，吆喝叫卖之声不绝于耳。于是你就
想，如果手头有点什么货水，不就可以和这个老大娘换(change)点东西
回去嘛？！
LONG
	);
	set( "exits", ([
		"west"	: __DIR__"shiji1",
		"north"	: __DIR__"shiji7",
	]));
	set("objects", ([
		__DIR__"npc/oldwoman" : 1,
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -90);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}