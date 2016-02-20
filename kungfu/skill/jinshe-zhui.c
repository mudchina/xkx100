// jinshe-zhui.c 金蛇锥法
//last Modified by Sega by 3/18/2000
//算是暗器中的特殊吧,威力很大但易被还击,而且难练.

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"name":		"千变万化",
	"action":"$N双手一晃，一招「千变万化」，手中的$w幻出万道金光，
如一条金龙般飞向$n的$l",
	"dodge":	-20,
	"force":	200,
	"damage":	300,
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":  "刺伤"
]),
([	"name":		"奇诡莫测",
	"action":"$N右手一抖，一道金光冒出，只一刹那间，左手$w迅雷般越
过右手的$w，正是一招「奇诡莫测」，抢先飞向$n的$l",
	"dodge":	-30,
	"force":	300,
	"damage":	400,
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":  "刺伤"
]),
});

int valid_enable(string usage) { return usage=="throwing" ; }
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("你的内力不够，没有办法练金蛇锥法。\n");

	if( !(ob = me->query_temp("weapon")) ||
		(string)ob->query("skill_type") != "throwing" )
		return notify_fail("你必须先找一些暗器才能练金蛇锥法。\n");

	return notify_fail("金蛇锥法没法教授。\n");
}
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 30
	|| (int)me->query("neili") < 500 )
		return notify_fail("你的内力或气不够，没有办法练习金蛇锥法。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -30);
//	write("你按著所学练了一遍金蛇锥法。\n");
	return 1;
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 20; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"jinshe-zhui/" + action;
}
 
int help(object me)
{
	write(HIC"\n金蛇锥法："NOR"\n");
	write(@HELP

    金蛇锥法载于「金蛇密笈」，乃金蛇郎君夏雪宜的独门武功。
夏雪宜幼时全家不幸被温家五老劫掠灭门，立志报仇。后于苗疆得
识五毒教教主之妹何红药，并得其助获得五毒教的「三宝」──金
蛇剑、金蛇锥及藏宝图，因而练成绝世武功。
    夏雪宜性情古怪，为人阴狠，武功便正如其人般诡异难测。江
湖上人人闻其名而为之色变，乃是出名的难缠人物。夏雪宜留下的
「金蛇密笈」载有他一身武功，即金蛇剑法、金蛇锥法和金蛇游身
掌。 

	学习要求：
		内力500
HELP
	);
	return 1;
}

