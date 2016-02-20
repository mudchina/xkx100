// Room: /d/chengdu/wangjianglou1.c
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "望江楼");
	set("long",@LONG
这里就是有名的望江楼了，楼外是成都的府南河。河面不宽，对岸
就是一片竹林，林里有口井称做薛涛井。是一带才女葬身之地。楼上视
野辽阔可以远眺锦官城。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"up"    : __DIR__"wangjianglou2",
		"east"  : __DIR__"wanliqiao",
		"north" : __DIR__"funanhe3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8030);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}


