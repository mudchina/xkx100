// /d/beihai/yongansi.c
// Last Modified by winder on May. 22 2002
inherit ROOM;

void create()
{
	set("short", "永安寺");
	set("long", @LONG
这里是永安寺，历史已经很悠久了。由永安寺北上就可到达白塔。
永安寺南是一座石桥，名永安石桥，是连接白塔山和团城的通道。
LONG
	);
	set("exits", ([
		"west"      : __DIR__"yuexin",
		"south"     : __DIR__"yonganqiao",
		"northup"   : __DIR__"baita",
		"northeast" : __DIR__"zhizhu",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
