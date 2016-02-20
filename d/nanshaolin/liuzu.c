// Room: /d/nanshaolin/liuzu.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "六祖殿");
	set("long", @LONG
这里是供奉少林六祖的地方。正面是观音，文殊，菩贤，地藏，大
势至等菩萨的玉雕像。两山安放着初祖达摩，二祖惠可，三祖僧璨，四
祖道信，五祖弘忍，六祖慧能的塑像。 
LONG );
	set("exits", ([
		"east" : __DIR__"pingtai",
	]));
	set("objects",([
		WEAPON_DIR+"stick/mugun" : 1,
	]));
	set("coor/x", 1810);
	set("coor/y", -6210);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}



