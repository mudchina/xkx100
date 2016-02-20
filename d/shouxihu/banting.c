// Room: /yangzhou/banting.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "寒竹风松");
	set("long", @LONG
小南海西面的二角半亭，板瓦顶，置美人靠。亭上悬挂孙龙父所书
“寒竹风松”匾，外柱悬挂田原所书楹联(lian)。
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : HIG"
        江        日
        秋        瘦
        逼        抱
        山        松
        翠        寒
\n"NOR
	]));
	set("exits", ([
		"east"   : __DIR__"guanyindian",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}