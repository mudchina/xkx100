#include <room.h>
inherit ROOM;

void create()
{
	set("short", "兵营");
	set("long", @LONG
这里是兵营，密密麻麻到处都是官兵，有的在武将的指挥下列队操练，
有的独自在练功，有的坐着、躺着正在休息。还有些太监在四处走动。南
边有一扇铁门(door)。
LONG );
	set("exits", ([
		"south" : __DIR__"bingqiku",
		"north" : __DIR__"dongchangdamen",
	]));
	set("item_desc", ([
		"door" : "这是一扇极厚的铁门。\n",
	]));
	set("objects", ([
		"/d/huanggong/npc/taijian" : 1,
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	create_door("south", "铁门", "north", DOOR_CLOSED);
	set("coor/x", -190);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail("官兵拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}
