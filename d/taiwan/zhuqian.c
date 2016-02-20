// Room: /d/taiwan/zhuqian.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "竹堑");
	set("long", @LONG
竹堑，在台湾岛西北部，是介于北部与中部的过渡地带，全境多山
岭与台地，沿海和河流沿岸始有狭小平原。东、南、北为丘陵环拱，西
临台湾海峡，因多季风，有“风城”之称。最早来此开垦的汉人是客家
人，由于土地贫瘠且多丘陵山地，居民们大半以种茶、植树、栽果为生，
此地的茧丝、茗茶、西瓜都是闻名全台的特产。
LONG );
	set("exits", ([
		"northeast" : __DIR__"danshui",
		"southwest" : __DIR__"maolishe",
	]));
	set("objects", ([
		__DIR__"npc/kejiaren": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2530);
	set("coor/y", -6980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

