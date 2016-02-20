// goplaying.c 纹枰手谈
// Last Modified by winder on Jun. 10 2000

#include <ansi.h>
inherit SKILL;

void init();
int do_play(string arg);

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	int lvl;

	lvl = (int)me->query_skill("goplaying", 1);

	if ( me->query("int") < 24 && me->query_int() < 32)
	return notify_fail("琴棋书画乃是极其风雅之事，" +RANK_D->query_respect(me)+"似乎太过于俗气了些。\n");

	if( (int)me->query("shen") < -10000 )
	return notify_fail("你杀人如麻，倘若不能先平息了心头魔念，哪里又会有心思弹琴下棋？\n");

	if (lvl > 29 && me->query("kar") != 29 &&
		me->query("family/master_name") != "何足道" )
		return notify_fail("限于天资，你只能修习这个程度了。\n");
	else return 1;
}

int practice_skill(object me)
{
	return notify_fail("纹枰手谈只能靠学习来提高。\n");
}
void init()
{
	add_action("do_play", "play");
}

int do_play(string arg)
{
	object me = this_player();

	if ( present("wei qi", this_player()) && ((arg == "wei qi") ||
		(arg == "qi") || (arg == "go")) )
	{
		if ( (me->query_skill("art", 1) < 40) )
		{
			message_vision("$N摆出一张棋盘，想研究围棋，却总觉得心烦意乱，定不下神来。\n", me);
			me->receive_damage("jing", random(20) );
			me->receive_damage("qi", random(20) );
			return 1;
		}
		if ( me->query_skill("art", 1) >100 )
		{
			message_vision("$N摆出一张棋盘，只觉棋面布局尽在筹幄只之中，无密可研。\n", me);
			return 1;
		}

		me->receive_damage("jing", 10);
		me->receive_damage("qi", 10);
		me->improve_skill("art", (int)me->query_int()/4 + (int)me->query_skill("art", 1)/10);
		tell_object(me, "你摆出一张棋盘，研究起围棋来，只觉得心平气和，很快就仿佛入定了。\n");

		message_vision("只见" + me->query("name") +
		"雅兴大发，竟打起棋谱来，对外界仿佛不闻不问，一副莫测高深的模样。\n",
		environment(me), ({me}) );

	}
	return 1;
}

int help(object me)
{
	write(HIC"\n纹枰手谈："NOR"\n");
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

