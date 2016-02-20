// Room: /city/bingyin.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "兵营");
	set("long", @LONG
这里是兵营，密密麻麻到处都是官兵，有的在武将的指挥下列队操
练，有的独自在练功，有的坐着、躺着正在休息。南墙下坐着主帅，不
动声色地寻视着四周。看到你进来，他们全都向你包围了过来，形势看
来不太妙。南边有一个门(door)。
LONG );
	set("item_desc", ([
		"door" : "这是一扇极厚的铁门。\n",
	]));
	set("exits", ([
		"south" : __DIR__"bingqiku",
		"north" : __DIR__"bingyindamen",
	]));
	set("objects", ([
		__DIR__"npc/shi" : 1,
		__DIR__"npc/wujiang" : 2,
		__DIR__"npc/bing" : 2,
	]));
//	set("no_clean_up", 0);
	create_door("south", "铁门", "north", DOOR_CLOSED);
	set("coor/x", 20);
	set("coor/y", -61);
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