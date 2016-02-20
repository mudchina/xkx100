// Room: /d/jueqinggu/xiangqinxie.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "响琴榭");
	set("long", @LONG
响琴榭分为三间，东南北三面为敞选，中为明间，顶部平直，结构
灵巧。榭下是引泉入池的渠道，上有响琴桥，流水击石，声若琴瑟。气
爽风清，是读书做画之地。
LONG
	);

	set("exits", ([
		"westdown"  : __DIR__"feiyunyan",
		"southdown" : __DIR__"guanlanting",
	]));
	set("no_clean_up", 0);
	set("outdoors","jueqinggu");
	set("coor/x", -480);
	set("coor/y", -370);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

