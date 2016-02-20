// Room: /d/gaochang/road.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;
#include <ansi.h>

void create ()
{
	set ("short", "沙丘小路");
	set ("long",
"注意：由此处向北！将进入高昌迷宫地域，不知走法和没有作好准
备的玩家请考虑清楚是否还要向北行。
              
                    "HIR"高   昌   迷   宫\n\n\n"NOR

);

	set("outdoors", "gaochang");
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"shulin1",
//		"west" : "/d/xingxiu/shanjiao",
		"south" : "/d/hasake/shulin1",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/liwenxiu" : 1,
	]));

	set("coor/x", -38000);
	set("coor/y", 10000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}