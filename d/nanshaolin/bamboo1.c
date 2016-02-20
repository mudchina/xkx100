// Room: /d/nanshaolin/bamboo1.c
// Last Modified by winder on May. 29 2001
// 这里也是去达摩洞的地方。南少林也不要。

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "竹林");
	set("long", @LONG
这是一片密密的竹林。这里人迹罕至，惟闻足底叩击路面，有僧敲木鱼
声；微风吹拂竹叶，又如簌簌禅唱。令人尘心为之一涤，真是绝佳的禅修所
在。
LONG );

	set("exits", ([
		"east"  : __FILE__,
		"west"  : __FILE__,
		"north" : __FILE__,
		"south" : __FILE__,
/*
		"northeast" : __DIR__"bamboo"+(random(13)+1),
		"southwest" : __DIR__"bamboo2",
		"northwest" : __DIR__"bamboo"+(random(13)+1),
		"southeast" : __DIR__"bamboo"+(random(13)+1),
		"south" : __DIR__"shanroad6",
*/
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6020);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}

