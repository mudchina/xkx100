// Room: /d/taishan/longmen.c
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "龙门");
	set("long", @LONG
此处山势陡峭，登山的人一个不小心很容易便会跌堕到崖谷之中。
西岩有清道光年间魏祥摹刻狂草“龙门”大字。坊址东为大龙峪，雨季
众水归峡，飞泉若泻。
LONG );
	set("exits", ([
		"northup"   : __DIR__"jinman18",
		"southdown" : __DIR__"man18",
	]));
	set("objects", ([
		__DIR__"npc/chi" : 1,
	]));
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 730);
	set("coor/z", 160);
	setup();
}

void init()
{
	object me = this_player();
	
	if( userp(me) && random((int)me->query_skill("dodge")) <= 10) 
	{
		me->receive_damage("qi", 50);
		me->receive_wound("qi",  50);
		message_vision(HIR"$N一不小心脚下踏了个空... 啊...！\n"NOR, me);
		me->move(__DIR__"daizong");
		tell_object(me, HIR"你从山上滚了下来，只觉得浑身无处不疼，还受了几处伤。\n"NOR);
		message("vision",HIR"只见" + me->query("name") + "从山上骨碌碌地滚了下来，躺在地上半天爬不起来！\n"NOR, environment(me), me);
	}
}
