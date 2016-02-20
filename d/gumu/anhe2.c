// Room: /d/gumu/anhe2.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"暗河"NOR);
	set("long", @LONG
原来这正是一条地下暗河，此处水声已是轰轰，声势极为骇人。你
脚下一处踏空，便有水流直冲咽喉。此潜流不知来自何处，更不知通往
何方。慢慢你已感觉水势渐缓，地势渐高。
LONG	);

	set("exits", ([
		"northup"  : "/d/quanzhen/shandong1",
		"westdown" : __DIR__"qianliu2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -2970);
	set("coor/y", -50);
	set("coor/z", -20);
	setup();
}

void init()
{
	object me = this_player();

	me->receive_damage("qi", 50 );
	me->receive_damage("jing", 50 ); 
	message_vision(HIB"$N的真气正在流失，呼吸十分困难。\n"NOR, me);
	if ( me->query("qi") < 10 || (int)me->query("jing") < 10)
	{
		me->set_temp("last_damage_from","在暗河中被淹");
		me->unconcious();
		me->die();
		return;
	}
}

int valid_leave(object me, string dir)
{
	if (dir == "northup")
	{
		write(HIW"\n你出得洞来，强光闪耀，一时之间竟然睁不开眼。\n"NOR);
	}
	return ::valid_leave(me, dir);
}
