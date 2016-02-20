// Room: /d/kunlun/elang02.c
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "东外廊");
	set("long",@long
这是一条长廊，连接前厅和客房，不断看见各种打扮的江湖人士走
过，看过廊外，是一片青色的树林，幽静雅致，只听见不断传来的鸟鸣
声。
long);
	set("exits",([
		"west" : __DIR__"elang01",
		"east" : __DIR__"keting1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -119970);
	set("coor/y", 40060);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}