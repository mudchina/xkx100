// Room: /beijing/nandajie1.c

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
这里是南大街。北边是天安门广场，南边是南大街广场。西边是一
家店铺，墙上写着一个大大的“当”字，仔细倾听，可以听到压低的讨
价还价的声音。东边是一家小客店。
LONG );
        set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"dangpu",
		"south" : __DIR__"nandaj2",
		"east" : __DIR__"kedian",
		"north" : __DIR__"tian_anm",
	]));
        set("objects", ([
		"/d/shaolin/npc/tiao-fu" : 1,
		__DIR__"npc/xiaofan" : 1,
        ]));
	set("coor/x", -200);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
