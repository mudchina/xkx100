// Room: /d/taiwan/dagougang.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "打狗港");
	set("long", @LONG
打狗港也称“西港”，港域口小腹大，外有岛链环抱，内具曲折峡
湾，诚全台第一良港。明朝都督俞大猷曾屯兵于此抗击倭寇。大清收台
后，打狗港的渔业日趋发达，贸易日益昌盛，与大陆间的往来频繁，逐
渐成为台湾西部海岸的最佳停泊港。
LONG );
	set("exits", ([
		"east"  : __DIR__"yahoushe",
		"north" : __DIR__"ningnanfang",
	]));
	set("objects", ([
		__DIR__"npc/yufu": 1,
		__DIR__"npc/shangren": 1,
//		__DIR__"npc/pingpuren": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2510);
	set("coor/y", -7070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

