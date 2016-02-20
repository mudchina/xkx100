// Room: /d/yueyang/langyinting.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "朗吟亭");
	set("long", @LONG
相传为吕洞宾吟过诗的地方，座落在君山龙口的东侧山头上。与对
楼的岳阳楼和三醉亭遥遥相望。吕洞宾数次游过岳阳，曾作诗：“朝游
北越暮苍梧，袖里青蛇胆气粗。三醉岳阳人不识，朗吟飞过洞庭湖。”
飞到君山以后，以泉洗脚，在山高卧，于千夜玩月，为纪念他，就在他
倾酒高吟，醉卧酣眠之处建立了一座两层的“朗吟亭”。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown"  : __DIR__"shijie2",
		"westdown"  : __DIR__"shijie1",
		"southdown" : __DIR__"xijiaochi",
	]));
	set("coor/x", -1690);
	set("coor/y", 2290);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
