#include <room.h>
inherit ROOM;

void create()
{
	set("short", "东厂兵器库");
	set("long", @LONG
这里是兵器库，到处银光闪闪，让人眼花缭乱。宝刀、宝剑、金箍棒，
大刀、长剑、哨棒，短刀、短剑、短棍，各色各样的兵器应有尽有，你一
时不知道挑什么好。
LONG );

	set("exits", ([
		"north" : __DIR__"bingyin1",
		"southwest" :  __DIR__"aobai12",
	]));
	set("objects", ([
		WEAPON_DIR"changbian" : 1,
		WEAPON_DIR"changjian" : 1,
		WEAPON_DIR"gangdao" : 1,
		"/d/xingxiu/obj/tiegun" : 1,
		"/d/city/obj/duanjian" : 1,
	]));

	create_door("north", "铁门", "south", DOOR_CLOSED);
	set("coor/x", -190);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
