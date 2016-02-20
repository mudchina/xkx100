// pine_road.c 松林大道
// Last Modified by winder on Aug. 18 2002

inherit ROOM;

void create()
{
	set("short", "松林大道");
	set("long", @LONG
你走在山脚松林中的一条道路上，不时有道士打扮的人扛着红松树
木从身旁经过。西面是上山的路，两边是茂密的松树林，林中伐木铿锵，
间或有大树倒塌声，「喀哧」作响。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"eastdown" : __DIR__"jiejianyan",
		"west"     : __DIR__"xuanyuegate",
		"north"    : __DIR__"pine_road1",
		"south"    : __DIR__"pine_road2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

