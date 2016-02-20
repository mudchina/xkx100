// Room: /d/kunlun/fufengshan.c
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_climb();

void create()
{
	set("short", "扶峰山");
	set("long", @LONG
扶峰山极高且十分陡峭，山腰以上尽没入茫茫云海中，峰顶终年积
雪，山腰以下却是郁郁苍苍，林木茂密，花团锦簇，春意烂漫。
LONG );
	set("outdoors", "kunlun");
	set("exits", ([
		"northeast" : __DIR__"bainiuling",
                "enter" : __DIR__"houyuan", 
	]));
/*	set("objects",([
		"/kungfu/class/kunlun/gaozecheng.c" :   1,
		"/kungfu/class/kunlun/jiangtao.c" :   1,
	]));
*/
	set("no_clean_up",0);
	create_door("enter", "小门", "out", DOOR_CLOSED);
	set("coor/x", -119980);
	set("coor/y", 40170);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
}
int do_climb()
{
	object me= this_player();

	if( random((int)me->query_skill("dodge",1))<=30)
	{
		me->receive_damage("qi", 50);
		me->receive_wound("qi", 50);
		message_vision(HIR"$N一不小心脚下踏了个空... 啊...！\n"NOR, me);
		me->move(__DIR__"fufengshan.c");
		tell_object(me,
		HIR"你从山上滚了下来，只觉得浑身无处不疼，还受了几处伤。\n"NOR);
		message("vision",HIR"只见" + me->query("name") +
		"从山上骨碌碌地滚了下来，躺在地上半天爬不起来！\n"NOR, environment(me), ({me}));
		return 1;
	}
	message("vision",
	me->name() + "提一口真气，足尖连点数下，发足向山上奔去。\n",
		environment(me), ({me}) );
	me->move(__DIR__"sanshengao");
	return 1;
}