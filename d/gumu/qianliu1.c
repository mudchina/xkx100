// Room: /d/gumu/qianliu1.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"潜流"NOR);
	set("long", @LONG
你没在水中，只觉水势甚急，冲得你无法立足。你气闷异常，只得屏气摸
索潜行，当真是进退维谷。
LONG	);

	set("exits", ([
		"east"   : __DIR__"qianliu2",
		"westup" : __DIR__"anhe1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -2990);
	set("coor/y", -50);
	set("coor/z", -30);
	setup();
}

void init()
{
	object me = this_player();

	me->receive_damage("qi", 50 );
	me->receive_damage("jing", 50 ); 
	message_vision(HIB"$N的真气正在流失，呼吸十分困难。\n"NOR, me);
	if ((int)me->query("qi") < 10 || (int)me->query("jing") < 10)
	{
		me->set_temp("last_damage_from","在潜流中被淹");
		me->unconcious();
		me->die();   
		return;
	}
}

