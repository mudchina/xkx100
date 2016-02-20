// Room: /d/lingxiao/sroad6.c
// Last Modified by Winder on Jul. 15 2001

#include <room.h>
inherit ROOM;
void create()
{
	set("short","山路");
	set("long",@LONG 
走到这里，反觉暖和一些了，风仍在刮，但耳边只听到叮当的流水
声。一道白波从岩缝中垂下，簌簌清流令人心神一爽，左边热气腾腾，
烟雾弥漫，显然是个温泉，右边零零落落有几间木屋，是凌霄弟子巡山
看守时住宿之地。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"west"    : __DIR__"water", 
		"east"    : __DIR__"muwu",
		"south"   : __DIR__"sroad5",
		"northup" : __DIR__"fentianya", 
	]));
	create_door("east", "木门", "west", DOOR_CLOSED);
	set("no_clean_up", 0);
	set("coor/x", -31000);
	set("coor/y", -8950);
	set("coor/z", 110);
	setup();
	replace_program(ROOM); 
}

