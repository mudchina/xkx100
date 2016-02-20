// Room: /d/nanshaolin/celang-4.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "东侧廊");
	set("long", @LONG
这里是天王殿旁的侧廊。彩梁画栋，连顶棚也用彩漆绘满了各种飞
天的图形，每幅画似乎都在诉说一个娓娓动人的佛经故事。东面飘来阵
阵米饭的清香，乃是僧人们用膳的斋堂。
LONG );
	set("outdoors", "nanshaolin");
	set("exits", ([
		"east"      : __DIR__"zhaitang",
		"south"     : __DIR__"celang-3",
                "northwest" : __DIR__"sblu-1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1830);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

