//HSQTAN6.C

inherit ROOM;

void create()
{
	set("short", "深潭");
	set("long", @LONG
这里的水只有齐腰深，但站在水中，仍感觉寒意从脚下漫起，经久
不散。
LONG );
	set("exits", ([
		"up"   : __DIR__"hsqmen",
		"west" : __DIR__"hsqtan5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52020);
	set("coor/y", 940);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}