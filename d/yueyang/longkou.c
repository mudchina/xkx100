// Room: /d/yueyang/longkou.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "龙口");
	set("long", @LONG
龙口位于君山南端，两边钳形山嘴，岩壁拱护，为龙的上、下腭，
张口向南，含住一弯洞庭湖水，形如长龙吞水，故名龙口。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"longxianjing",
		"eastup"    : __DIR__"shijie1",
		"southeast" : __DIR__"xiaolu1",
		"southwest" : __DIR__"xiaolu2",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/xu" : 1,
		CLASS_D("gaibang")+"/bangzhong" : 4,
	]));
	set("coor/x", -1720);
	set("coor/y", 2290);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
