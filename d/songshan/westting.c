// Room: /d/songshan/westting.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "西庭");
	set("long", @LONG
这里是一个小小庭院，院子里常有嵩山弟子结伴往来。庭院四周矮
墙下长着的小灌木里，偶尔冒出几星白色小花。鹅卵细石铺就的小路在
灌木丛和长草间穿过。
LONG );
	set("outdoors", "songshan");
	set("exits", ([
		"east"  : __DIR__"westpath1",
		"west"  : __DIR__"chufang",
		"north" : __DIR__"westpath2",
		"south" : __DIR__"cangku",
	]));
	set("objects", ([
		__DIR__"npc/dizi": random(2),
	]));
	set("coor/x", -40);
	set("coor/y", 900);
	set("coor/z", 90);
	setup();
	create_door("south" , "木门", "north" , DOOR_CLOSED);
	replace_program(ROOM);
}
