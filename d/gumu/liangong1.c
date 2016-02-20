// Room: /d/gumu/lianggong1.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"石室"NOR);
	set("long", @LONG
这是一间密闭的石室，室中点着灯火，石室奇小，仅容一人周转，
墙上刻着一些图谱，供古墓弟子修炼入门轻功时参看。
LONG	);

	set("exits", ([
		"north" : __DIR__"mudao08",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", -10);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_cankan", "cankan");
	add_action("do_cankan", "watch");
}

int do_cankan(string arg)
{
	object me=this_player();
	int c_exp, c_skill;

	c_skill=(int)me->query_skill("dodge", 1);
	c_exp=me->query("combat_exp");
	if( !arg ) return notify_fail("你东张西望地乱看什么？\n");
	if( arg != "picture" || arg != "tu" )
		return notify_fail("这里没有你想看的东西。\n");
	if( me->query("jing") < 30 )
		return notify_fail("你觉得太累了，不如歇会吧？\n");
	me->receive_damage("jing", random(10));
	if( random((int)c_skill/10) + 1 < 2)
	{
		message_vision("$N认真地看墙上的图谱，可是光线实在太暗，眼睛生痛，好象也没看到什么特别的东西。\n", me);
		return 1;
	}
	message_vision("$N正在仔细察看墙上的图谱。\n", me);
	if ((random(10)>3) && c_skill*c_skill*c_skill/10<c_exp && c_skill<101)
	{
		me->improve_skill("dodge", random(me->query("int")));
		tell_object(me,"你的基本轻功进步了！\n");
	}
	return 1;
}
