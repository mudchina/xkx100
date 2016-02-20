// shanlu3.c 山路
// Winder Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这里是山路的尽头，南面好象有一片小树林，折而向东，就是终
南山的山脚了。
LONG
	);
	set("outdoors", "zhongnan");
	set("objects", ([
		CLASS_D("quanzhen")+"/lu" : 1,
	]));
	set("exits", ([
		"northwest" : __DIR__"shanlu1",
		"eastup"    : __DIR__"shanjiao",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3140);
	set("coor/y", -10);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
