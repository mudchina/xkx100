// Room: /d/gumu/woshi1.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"小卧室"NOR);
	set("long", @LONG
这里是杨过当年的卧室，房中空空洞洞。一块长条青石作床，床上
铺了张草席，一幅白布当作薄被，此外除了一根人高的绳索横过室中，
别无他物。
LONG	);
	set("exits", ([
		"west" : __DIR__"mudao20",
	]));
	set("objects", ([
		__DIR__"obj/bed" : 1,
	]));
	set("sleep_room", 1);
	set("no_fight", 1);

	set("coor/x", -3160);
	set("coor/y", -10);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_zuo", "zuo");
	add_action("do_zuo", "sleep");
	add_action("do_liao", "liao");
}

int do_zuo(string arg)
{
	object me = this_player();
	int exp, lvl;

	exp = me->query("combat_exp");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if (arg == "bed" || arg == "chuang")
	{
		if( me->query_skill("yunv-xinfa", 1) < 1)
		{
			message_vision("$N现在的内功承受不住寒玉床的寒冰之气。\n", me);
			me->start_busy(1);
			return 1;
		}
		if(me->query("neili") < 300 )
		{
			message_vision("$N现在的功力承受不住寒玉床的寒冰之气。\n", me);
			me->start_busy(1);
			return 1;
		}
		lvl = (int)me->query_skill("force", 1);
		if(lvl > 100 && lvl < 200)
		{
			message_vision("$N躺上了寒玉床，开始潜运内功，使内息遍行大小周天。\n", me);
			if (random(10) > 6)
			{
				message_vision("$N调息完毕，只觉得精神健旺，内息充沛欲奔腾而出。\n", me);
				if ((lvl*lvl*lvl/10) < exp)
				{
					me->improve_skill("force", random(lvl));
				}
				me->receive_damage("qi", random(lvl/3));
			}
			else
				message_vision("$N调息完毕，站起身来，提了提内力，好象没什么长进。\n", me);
		}
		else
			message_vision("$N躺上寒玉床，只觉得冰冷刺骨，‘啊’的一声狼狈不堪地跳了起来。\n", me);
		me->start_busy(1);
		return 1;
	}
	else return notify_fail("你要坐在哪里？\n");
}

int do_liao(string arg)
{
	object me = this_player();

	if (me->is_fighting() || me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if (me->query("eff_qi") >= me->query("max_qi"))
		return notify_fail("你现在身上没有受到任何伤害！\n");
	if ( (int)me->query_condition("bed_poison") > 0 )
	{
		me->receive_wound("qi", 10);
		message_vision(HIR "$N突然只觉一阵奇寒侵入身体，想是两次疗伤时隔太短，身子尚未复原之故。\n"NOR, me);
		me->unconcious();
		return 1;
	}
	if (arg == "bed" || arg == "chuang")
	{
		message_vision(HIY"$N爬上寒玉床，要借千年寒玉疗伤。\n"NOR, me);
		if (me->query_skill("yunv-xinfa", 1) < 40)
			return notify_fail("寒玉床疗伤需以纯熟的玉女心经内功相辅，否则无法外疗。\n");
		me->set("eff_qi", me->query("max_qi"));
		me->apply_condition("bed_poison", 25);
		return 1;
	}
	return notify_fail("你要在哪里疗伤？\n");
}
