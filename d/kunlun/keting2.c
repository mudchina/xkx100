// Room: /d/kunlun/keting2.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "客卧厅");
	set("long",@long
这里是待客休息厅，里面简单，只有几张床，供疲惫的客人歇息，
屋子里烤着火，暖烘烘的。
long);
	set("exits",([
		"east" : __DIR__"wlang02",
	]));
	set("no_fight",1);
	set("sleep_room",1);
	set("no_clean_up", 0);
	set("coor/x", -120020);
	set("coor/y", 40060);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}