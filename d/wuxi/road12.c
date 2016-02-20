// Room: /d/wuxi/road12.c
// Winder 2000/02/22 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "湖边小径");
	set("long", @LONG
这是太湖边上的一条小径，道旁花草杂生，耳中莺歌燕啼。东面
是一望无际的太湖，碧波万顷，烟波浩渺，眺之身心舒畅。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"road11",
		"northeast" : __DIR__"road13",
	]));
	set("coor/x", 380);
	set("coor/y", -880);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}