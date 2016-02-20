// Room: /d/taiwan/homgmaocheng.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "红毛城");
	set("long", @LONG
红毛城，位于“五虎冈”第二冈岭上，紧临淡水河北岸，东、西、
南三面都是陡坡，形势险要，是明末清初，西方海权强国西、荷所建的
城堡。
LONG );
	set("exits", ([
		"south" : __DIR__"danshui",
	]));
	set("objects", ([
		__DIR__"npc/hongmao": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2540);
	set("coor/y", -6960);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

