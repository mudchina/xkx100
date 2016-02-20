// Room: /d/gumu/anhe1.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"暗河"NOR);
	set("long", @LONG
原来这正是一条地下暗河，此处水声已是轰轰，声势极为骇人。你
脚下一处踏空，便有水流直冲咽喉。此潜流不知来自何处，更不知通往
何方。
LONG	);

	set("exits", ([
		"northup"  : __DIR__"shishi6",
		"eastdown" : __DIR__"qianliu1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3000);
	set("coor/y", -50);
	set("coor/z", 30);
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

