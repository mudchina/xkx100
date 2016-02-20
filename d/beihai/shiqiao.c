// /d/beihai/shiqiao.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "石桥");
	set("long", @LONG
只是一座小石桥，连接了漪澜堂和智珠殿。桥虽然不大，却非常精
美。桥栏上雕刻了许多花草动物，栩栩如生。
LONG
	);
	set("exits", ([
		"southup"   : __DIR__"zhizhu",
		"northwest" : __DIR__"yilan",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -180);
	set("coor/y", 4100);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
