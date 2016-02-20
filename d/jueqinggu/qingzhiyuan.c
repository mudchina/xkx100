// Room: /d/jueqinggu/qingzhiyuan.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "青芝院");
	set("long", @LONG
这是一间不大的小屋，桌上，柜中满列药罐，壁上一丛丛的挂著无
数乾草药，西首并列三座丹炉，铜迹斑斑，年代久远。
LONG
	);

	set("exits", ([
		"north" : __DIR__"songtang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -530);
	set("coor/y", -370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM); 
}

