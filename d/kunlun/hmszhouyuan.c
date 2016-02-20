// Room: /d/kunlun/houyuan.c
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"后院"NOR);
	set("long", @LONG
这里是山庄的后院。此庄号称“红梅”，当有应有其根源。院子里
就长着许多梅树。每逢春天梅花盛开之时，到处一片火红，分外美丽，
梅花飘香更是令人心旷神怡。北边是“灵獒宫”。
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"linggong",
		"west"  : __DIR__"hmszdating",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/guanjia" : 1,
	]));
	set("outdoors", "hongmei");
	set("coor/x", -90020);
	set("coor/y", 10020);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
