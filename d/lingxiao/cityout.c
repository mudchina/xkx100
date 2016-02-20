// Room: /d/lingxiao/cityout.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "城外");
	set("long", @LONG
这里是凌霄城的城外，出现在你面前的是高耸的城墙，看来如果不
从城门走，想要越墙而入，是不太可能的。凌霄城外野狼很多，绝对不
是什么安全的地方，还是赶快进城吧。
LONG
	);
	set("exits", ([
		"west" : __DIR__"shanya",
	]));
	set("objects", ([
		__DIR__"npc/wolf" : 2,
	]));
	set("outdoors", "lingxiao");
	set("coor/x", -30990);
	set("coor/y", -8940);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

