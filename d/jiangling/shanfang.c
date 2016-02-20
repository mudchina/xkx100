//Edited by fandog, 02/15/2000

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这是知府衙门的膳房。一位厨娘正站在灶台后面笑眯眯地看着你，
她手上拿着一柄铁勺，用力地把锅里煮着的一大堆食物搅匀。正中一张
八仙桌，桌上叠了许多盘碗。
LONG
	);
	set("exits", ([
		"west" : __DIR__"keting",
	]));
	set("objects", ([ 
		__DIR__"npc/chuniang" : 1,
	]));
	set("no_clean_up", 0);

	set("coor/x", -1387);
	set("coor/y", -2031);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}