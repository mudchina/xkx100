// /d/shenlong/shanpo2 山坡2
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山坡");
	set("long", @LONG
这是一个山坡，通向北方的一座山峰，你已经爬的气喘嘘嘘了，真
想停下来休息休息，突然间，你看见树上、草上、路上，东一条，西一
条全是毒蛇，可怕极了！... 是非之地，不可久留，还是赶快离开吧。
北面是一个狭窄的山道，往南是一个山坡。
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"northup"   : __DIR__"shandao",
		"southdown" : __DIR__"shanpo1",
	]));
	set("snaketype", ({"jinhuan", "yinhuan"}));
	setup();
}

#include "snakeroom.h"
