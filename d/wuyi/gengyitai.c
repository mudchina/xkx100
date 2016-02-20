// Room: /d/wuyi/gengyitai.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "更衣台");
	set("long", @LONG
五曲溪南的更衣台，突兀竟秀、石峰耸立。乘坐竹筏，远远便能看
到它的尊容。相传魏子骞在次换衣，登上天柱峰升天的。至今半腰石壁
上仍有“更衣台”和“玉皇大天尊”的石刻。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"jiutanfeng",
		"northeast" : __DIR__"5qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1360);
	set("coor/y", -5030);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

