// /kaifeng/eroad1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
东大街是开封府内东街区的主要通道。道路的两端店铺府第不断。
行人如缕，观光的，作生意的，攀交情的，以至走亲访友的，喧闹无比。
北边不远就是山陕甘会馆。
LONG);
	set("objects", ([
		__DIR__"npc/hanzi" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"eroad0",
		"north" : __DIR__"eroad2",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
