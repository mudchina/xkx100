//Edited by fandog, 01/31/2000

inherit ROOM;
void create ()
{
	set ("short", "甬道");
	set ("long", @LONG
一条阴暗潮湿的甬道，东边尽头是一间牢房，是知府衙门用来关押
朝廷重犯的地方。
LONG);
	set("exits", ([ 
		"east" : __DIR__"laofang",
		"west" : __DIR__"lingtang",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1460);
	set("coor/y", -2029);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
