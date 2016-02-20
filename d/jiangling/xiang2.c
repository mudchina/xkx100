//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "小巷");
	set ("long", @LONG
这是荆州城内的小巷，两旁是高高的围墙，僻静无人，听不到街市
的喧哗。西边是一条大街，但见许多行人来来往往。
LONG);

	set("outdoors", "jiangling");
	set("exits", ([
		"east"  : __DIR__"xiang1",
		"west"  : __DIR__"xijie2",
	]));

	set("no_clean_up", 0);
	set("coor/x", -1490);
	set("coor/y", -2020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}