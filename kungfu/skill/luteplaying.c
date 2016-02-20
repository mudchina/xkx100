// luteplaying.c 绕梁琴艺
// Last Modified by winder on Jun. 10 2000

#include <ansi.h>
inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

void init();
int do_play(string arg);

int valid_learn(object me)
{
	int lvl;
	if ( me->query("int") < 24 && me->query_int() < 32)
		return notify_fail("琴棋书画乃是极其风雅之事，" +RANK_D->query_respect(me)+"似乎太过于俗气了些。\n");

	if( (int)me->query("shen") < -10000 )
		return notify_fail("你杀人如麻，倘若不能先平息了心头魔念，哪里又会有心思弹琴下棋？\n");

	lvl = (int)me->query_skill("luteplaying", 1);

	if (lvl > 29 && me->query("kar") != 29 &&
		me->query("family/master_name") != "何足道" )
		return notify_fail("限于天资，你只能修习这个程度了。\n");

	return 1;
}

void init()
{
	add_action("do_play", "play");
}

int do_play(string arg)
{
	object me = this_player();

	if( !arg && (arg != "music") && (arg != "zheng") && (arg != "gu zheng"))
		return notify_fail("你要做什么？\n");

	if ( present("gu zheng", this_player()) &&
		((arg == "music") || (arg == "zheng") || (arg == "gu zheng")) )
	{
		if ( me->query_skill("luteplaying", 1) < 30 )
		{
			message_vision("$N摆出一张古筝，铮铮琮琮弹了几声，只听得曲调杂乱无章，宛如鬼哭狼号。\n", me);
			me->receive_damage("jing", random(20) );
			me->receive_damage("qi", random(20) );
			return 1;
		}
		if ( me->query_skill("luteplaying", 1) >100 )
		{
			message_vision("$N摆出一张古筝，铮铮琮琮弹了几声，只听得曲调平和，洋洋洒洒，颇有佳意。\n", me);
			return 1;
		}
		me->receive_damage("jing", 10);
		me->receive_damage("qi", 10);
		me->improve_skill("art", (int)me->query_int()/4 + (int)me->query_skill("art", 1)/10);
		tell_object(me, "你摆出一张古筝，调了调弦，弹了起来，你只觉得连日来烦燥的心情好了许多。\n");

		message_vision("只见" + me->query("name") +
		"雅兴大发，竟弹起曲子来，你只觉得时而金戈铁马、大漠平沙。。。。。。\n"
		"时而小桥流水、几户人家。。。。。。万般气象，你心情顿时宁静了许多。\n",
		environment(me), ({me}) );

		return 1;
	}
	return 1;
}


int practice_skill(object me)
{
	return notify_fail("绕梁琴艺只能靠学习来提高。\n");
}
int help(object me)
{
	write(HIC"\n绕梁琴艺："NOR"\n");
	write(@HELP

    逍遥派祖师逍遥子学究天人，胸中所学包罗万象。他共传下七
门绝艺：绕梁琴艺 (luteplaying)、纹枰手谈 (goplaying)、泼墨
丹青(painting)、济世之术(medicine)、土木机关(construction)、
园艺莳花(horticulture)、梨园旧艺(dramaturgy)。

	学习要求：
		无。但天赋才气限制了对更高深境界的努力
HELP
	);
	return 1;
}

