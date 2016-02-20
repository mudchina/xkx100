// Room: /yangzhou/pingtai3.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "乱石平台");
	set("long", @LONG
水云胜概前乱石平台，围以石栏。面南两端，设石级通湖岸。平台
低于大厅三级，高于湖岸一十六级，平台不仅用以衬托“水云胜概”大
厅，也可作为戏班的露台。
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"northup" : __DIR__"shuiyun",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 100);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}