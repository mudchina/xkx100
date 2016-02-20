// Room: /d/nanshaolin/celang-3.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "东侧廊");
	set("long", @LONG
这里是天王殿旁的侧廊。彩梁画栋，连顶棚也用彩漆绘满了各种飞
天的图形，每幅画似乎都在诉说一个娓娓动人的佛经故事。由此向东通
向钟楼。南面是一片广场。
LONG );
	set("outdoors", "nanshaolin");
	set("exits", ([
		"east"  : __DIR__"zhonglou",
		"south" : __DIR__"gchang-3",
                "north" : __DIR__"celang-4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1830);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

