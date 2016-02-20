// Room: /d/wuxi/huishan.c
// Winder 2000/02/22 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "惠山山顶");
	set("long", @LONG
登上惠山山顶，但见满山青松绰约，绿树苍翠，寺院石塔，巍然
耸立。从此可远眺无锡全城和浩渺太湖。此山原名锡山，山产锡矿，
到汉代采尽。又有人挖到一石碑，上书：有锡兵，天下争。无锡宁，
天下清。遂命名此城无锡。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown"  : __DIR__"road15",
	]));
	set("coor/x", 260);
	set("coor/y", -160);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}