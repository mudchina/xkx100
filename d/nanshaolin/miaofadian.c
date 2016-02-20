// Room: /d/nanshaolin/miaofadian.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIR"妙法殿"NOR);
	set("long", @LONG
这里是少林寺的妙法殿。殿内香烟燎绕，幔角叮咚。香火十分的旺
盛。殿里陈设极为简朴。大抵认为妙法从空，所以不宜排设物件。
LONG );
	set("exits", ([
		"south" : __DIR__"stoneroad2",
		"north" : __DIR__"dxshijie",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

