// Room: /d/wuxi/road13.c
// Winder 2000/02/22 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "湖边小径");
	set("long", @LONG
这是太湖边上的一条小径，蜿蜒北去。一路前行，花草渐深。东
面是一望无际的太湖，碧波万顷，烟波浩渺，眺之身心舒畅。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest"   : __DIR__"road12",
	]));
	set("coor/x", 390);
	set("coor/y", -870);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}