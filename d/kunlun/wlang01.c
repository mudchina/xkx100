// Room: /d/kunlun/wlang01.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "西长廊");
	set("long",@long
这是一条长廊，连接前厅和客房，不断看见各种打扮的江湖人士走
过，看过廊外，是一片青色的树林，幽静雅致，只听见不断传来的鸟鸣
声。
long );
	set("exits",([
		"east" : __DIR__"qianting",
		"west" : __DIR__"wlang02",
	]));
	set("outdoors", "kunlun");
	set("coor/x", -120000);
	set("coor/y", 40060);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}