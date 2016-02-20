// Room: /d/nanshaolin/duanya.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",CYN"断崖坪"NOR);
	set("long", @LONG
出得屋来，对面便是危崖一片。左面是一座孤峰刺天，右面是绝壑
无地。只中央一片平地。对崖看去险峻已极，难以攀援。且壁间遍生青
苔，其滑如油，竟似无路可上。
LONG );
	set("exits", ([
		"south"  : __DIR__"xctang",
	]));
	set("no_clean_up", 0);
	set("outdoors","nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6080);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
