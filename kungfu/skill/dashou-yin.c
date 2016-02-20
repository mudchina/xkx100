// dashou-yin.c 密宗大手印
// Last Modified by sir 10.23.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N使出一招"HIC"「莲花合掌印」"NOR"，双掌合十，直直撞向$n的前胸",
	"skill_name" : "莲花合掌印",
	"lvl" : 0
]),
([	"action" : "$N使出一招"HIW"「合掌观音印」"NOR"，飞身跃起，双手如勾，抓向$n的$l",
	"skill_name" : "合掌观音印",
	"lvl" : 8
]),
([	"action" : "$N使出一招"HIY"「准提佛母印」"NOR"，运力于指，直取$n的$l",
	"skill_name" : "准提佛母印",
	"lvl" : 16
]),
([	"action" : "$N使出一招"HIR"「红阎婆罗印」"NOR"，怒吼一声，一掌当头拍向$n的$l",
	"skill_name" : "红阎婆罗印",
	"lvl" : 24
]),
([	"action" : "$N使出一招"HIG"「药师佛根本印」"NOR"，猛冲向前，掌如游龙般攻向$n",
	"skill_name" : "药师佛根本印",
	"lvl" : 32
]),
([	"action" : "$N使出一招"HIM"「威德金刚印」"NOR"，伏身疾进，双掌自下扫向$n的$l",
	"skill_name" : "威德金刚印",
	"lvl" : 40
]),
([	"action" : "$N使出一招"HIB"「上乐金刚印」"NOR"，飞身横跃，双掌前后击出，抓向$n的咽
喉",
	"skill_name" : "上乐金刚印",
	"lvl" : 48
]),
([	"action" : "$N使出一招"HIW"「六臂智慧印」"NOR"，顿时劲气弥漫，天空中出现无数掌影打
向$n的$l",
	"skill_name" : "六臂智慧印",
	"lvl" : 56
]),
});

int valid_enable(string usage) { return usage == "hand" || usage == "parry"; }
int valid_combine(string combo) { return combo=="yujiamu-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练密宗大手印必须空手。\n");
	else if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("longxiang", 1) >= 20 ||
		(int)me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else if ((int)me->query_skill("longxiang", 1) < 20)
		return notify_fail("你的龙象般若功火候太浅。\n");
	else if ((int)me->query_skill("xiaowuxiang", 1) < 20)
		return notify_fail("你的小无相功火候太浅。\n");
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练「密宗大手印」必须空手。\n");
	if(!me->query_skill("longxiang",1) && !me->query_skill("xiaowuxiang",1))
		return notify_fail("练「密宗大手印」必须要有雪山派的内功作为根基。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练「密宗大手印」。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -15);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = -40;
	int d_e2 = -5;
	int p_e1 = 25;
	int p_e2 = 50;
	int f_e1 = 100;
	int f_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("dashou-yin", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 获得招数序号上限 */
			break;
		}
	seq = random(seq);       /* 选择出手招数序号 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage_type" : random(2) ? "内伤" : "瘀伤",
	]);
}
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point() { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"dashou-yin/" + action;
}

int help(object me)
{
	write(HIC"\n密宗大手印："NOR"\n");
	write(@HELP

    密宗大手印为雪山派手法。
    可与金刚瑜迦母拳互备。

	学习要求：
		龙象功或小无相功20级
		内力50
HELP
	);
	return 1;
}

