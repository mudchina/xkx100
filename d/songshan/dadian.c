// Room: /d/songshan/dadian.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "中岳大殿");
	set("long", @LONG
大殿面阔九间，进深五间，重檐庑殿式屋顶，座落在七尺高的台基
上，气势雄伟。大殿中供奉岳神天中王。
LONG );
	set("exits", ([
		"northup" : __DIR__"shandao1",
		"south"   : __DIR__"chongsheng",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/lu": 1,
	]));
	set("coor/x", 0);
	set("coor/y", 730);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
