// Room: /d/nanshaolin/celang-2.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "西侧廊");
	set("long", @LONG
这里是天王殿旁的侧廊。彩梁画栋，连顶棚也用彩漆绘满了各种飞
天的图形，每幅画似乎都在诉说一个娓娓动人的佛经故事。左面传来阵
阵木鱼的敲击声和轻轻的梵唱。
LONG
	);
	set("outdoors", "nanshaolin");
	set("exits", ([
		"northeast" : __DIR__"sblu-1",
		"south"     : __DIR__"celang-1",
                "west"      : __DIR__"zdyuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

