// Room: /d/5lt/yanboting.c

inherit ROOM;

void create()
{
	set("short", "演播厅");
	set("long", @LONG
这里是电视台的多功能演播厅。导播、摄像、灯光、主持、嘉宾，
一个个忙得不可开交。
LONG	);
	set("outdoors", "5lt");
	set("exits", ([
		"down"      : __DIR__"mishuchu",
		"east"      : __DIR__"sheyingpeng",
		"northeast" : __DIR__"houtai",
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("coor/x", -185);
	set("coor/y", 30);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
