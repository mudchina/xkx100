// /d/taohuacun/shiji6.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set( "short", "市集" );
	set( "long", @LONG
你身处市集中，身边人头攒动，吆喝叫卖之声不绝于耳。于是你就
想，如果手头有点什么货水，不就可以和这个老农换(change)点东西回
去嘛？！
LONG
	);
	set( "exits", ([
		"east"	: __DIR__"shiji2",
		"south"	: __DIR__"shiji4",
		"north" : __DIR__"shiji8",
	]));
	set("objects", ([
		__DIR__"npc/oldman" : 1,
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -110);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}