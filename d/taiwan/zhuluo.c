// Room: /d/taiwan/zhuluo.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "诸罗");
	set("long", @LONG
诸罗，位于阿里山山麓原为平埔族土陇社聚居之地，于清代初年始
逐渐发展成都会区。是阿里山林业的木材集散地与制材加工中心。 
LONG );
	set("exits", ([
		"northwest" : __DIR__"pingye",
		"southwest" : __DIR__"zhenbeifang",
	]));
	set("objects", ([
		__DIR__"npc/qiaofu": 1,
		__DIR__"npc/shangren": 1,
		__DIR__"npc/pingpuren": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2520);
	set("coor/y", -7030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

