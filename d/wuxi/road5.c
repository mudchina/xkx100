// Room: /d/wuxi/road5.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
这是官府为驻军来往与江阴要塞和锡城而专修的一条官道，因为
除要塞外不通向什么地方，官道上的行人稀少。向南去是北门大桥，
可以远远地看见莲蓉门的城楼。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"lianrongqiao",
		"north"  : __DIR__"road6",
	]));
	set("coor/x", 370);
	set("coor/y", -740);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}