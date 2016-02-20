// Room: /d/nanshaolin/huilang5.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
这里是法堂东侧的回廊。彩梁画栋，连顶棚也用彩漆绘满了各种飞
天的图形，每幅画似乎都在诉说一个娓娓动人的佛经故事。廊外两侧是
翠绿的青竹，在微风中沙沙做响。四周静悄悄的，只有你自己的脚步声
在耳边回荡。
LONG );
	set("exits", ([
		"west"  : __DIR__"fatang",
                "east"  : __FILE__,
		"south" : __FILE__,
                "north" : __DIR__"huilang6",
	]));
	set("no_clean_up", 0);
	set("outdoors","nanshaolin");
	set("coor/x", 1830);
	set("coor/y", -6110);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

