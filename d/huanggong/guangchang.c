//guangchang.c

inherit ROOM;

void create()
{
	set("short", "大广场");
	set("long", @LONG
这个大广场的地面铺的石砖横七竖八, 共一十五层. 是皇帝为防有
人挖地道入宫特地设计的. 可想皇城的戒备森严之至.
LONG
	);
	set("outdoors", "huanggong");
        set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"wenhua",
		"west"  : __DIR__"wuying",
		"south" : __DIR__"taihemen",
		"north" : __DIR__"taiji",
	]));
	set("objects", ([
		__DIR__"npc/eshuo" :1,
	]));
	set("coor/x", -200);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}