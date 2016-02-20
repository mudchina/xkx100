// Room: /d/wuxi/road17.c
// Winder 2000/02/22 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "山道");
	set("long", @LONG
山路翻上了山坡，反面觉得平坦些。从这里向西北去，还要走不
少这里的山路，真有些留恋江南的繁华。山道旁树木葱葱，景致还算
怡人，只是略显荒凉而已。
LONG );
	set("outdoors", "yixing");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"road16",
		"northwest" : "/d/yixing/shanlu2",
	]));
	set("coor/x", 250);
	set("coor/y", -180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
