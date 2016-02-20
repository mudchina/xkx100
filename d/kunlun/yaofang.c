// Room: /d/kunlun/yaofang.c
// Last Modified by winder on Nov. 15 2000

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "药房");
	set("long", @LONG
这里是昆仑派的药房，房间里弥漫着浓浓的药香，房间内排满了装
满各类药材的大药柜，每个药柜都有上百个装药的抽屉贴满了各类药名。
西边是一个巨大红杉木柜，柜上贴着方丈印的封条。一位年轻女子正来
回忙碌着指点众执役称量药品，熬药煎汤。
LONG );
	set("exits", ([
		"southeast" : __DIR__"jiuqulang6", 
	]));
	set("objects", ([
		__DIR__"npc/kl-dizi1" : 1, 
	]));
	set("no_clean_up", 0);
	set("coor/x", -120010);
	set("coor/y", 40120);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}