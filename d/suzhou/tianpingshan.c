// Room: /d/suzhou/tianpingshan.c
// Last Modified by winder on Mar. 8 2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "天平山");
	set("long",@long
过了灵岩山，距离几里地就到了天平山。它为苏州西南诸山之最高
峰。此山因地势平坦如砥而得名。又因山势高峻，白雾缭绕，也称“白
云山”。具载：宋仁宗赵祯将天平山赐与范文正公，故也称“范文山”。
long);
	set("outdoors", "suzhou");
	set("exits",([
		"northeast" : __DIR__"qsgdao",
		"north" : __DIR__"shihu",
		"southeast" : __DIR__"lingyanshan",
		"eastup" : __DIR__"baiyunquan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 840);
	set("coor/y", -1090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
