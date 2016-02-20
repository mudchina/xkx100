// jinshe-zhang.c 金蛇游身掌
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" : "千蛇出洞",
	"action" : "$N双掌一错，一招"HIY"「千蛇出洞」"NOR"幻出漫天掌影拢向$n的$l",
	"lvl"    : 0
]),
([	"skill_name" :  "魔吼天地",
	"action" : "$N暴喝一声，双掌连环推出，一招"HIY"「大沼龙蛇」"NOR"强劲的掌风直扑$n的$l",
	"lvl"    : 10
]),
([	"skill_name" : "双蛇抢珠",
	"action" : "$N双掌纷飞，一招"HIY"「双蛇抢珠」"NOR"直取$n的$l",
	"lvl"    : 20
]),
([	"skill_name" : "游走式",
	"action" : "$N提气缠身游走，一招"HIY"「游走式」"NOR"，森森掌风无孔不入般地击向$n的$l",
	"lvl"    : 30
]),
([	"skill_name" : "盘身式",
	"action" : "$N盘身错步，双掌平推，凝神聚气，一招"HIY"「盘身式」"NOR"拍向$n的$l",
	"lvl"    : 40
]),
([	"skill_name" : "金蛇吐衅",
	"action" : "$N左掌立于胸前，右掌推出，一招"HIY"「金蛇吐衅」"NOR"击向$n$l",
	"lvl"    : 50
]),
([	"skill_name" : "金蛇翻身咬",
	"action" : "$N使出"HIY"「金蛇翻身咬」"NOR"，身形凌空飞起，从空中当头向$n的$l出掌攻击",
	"lvl"    : 60
]),
([	"skill_name" : "杯弓蛇影",
	"action" : "$N使出一招"HIY"「杯弓蛇影」"NOR"，左掌化虚为实击向$n的$l",
	"lvl"    : 70
]),
([	"skill_name" : "金蛇缠丝手",
	"action" : "$N左掌画了个圈圈，右掌推出，一招"HIY"「金蛇缠丝手」"NOR"击向$n$l",
	"lvl"    : 80
]),
([	"skill_name" : "灵蛇游八方",
	"action" : "$N使出"HIY"「灵蛇游八方」"NOR"，身形散作八处同时向$n的$l出掌攻击",
	"lvl"    : 90
]),
([	"skill_name" : "金蛇探头",
	"action" : "$N使出金蛇游身掌法"HIY"「金蛇探头」"NOR"，如鬼魅般欺至$n身前，一掌拍向$n的$l",
	"lvl"    : 100
]),
([	"skill_name" : "金龙升天",
	"action" : "$N内气上提，全身拔起，一招"HIY"「金龙升天」"NOR"，双掌凌空拍下，$n的全身都被笼罩在掌力之下",
	"lvl"    : 110
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练金蛇游身掌必须空手。\n");
	if( (int)me->query("max_neili", 1) < 500)
		return notify_fail("你的内力不足，无法练金蛇游身掌。\n");
	return notify_fail("金蛇游身掌没法教授。\n");
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if( (int)me->query("qi") < 30 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("neili") < 15 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
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
	int d_e1 = -10;
	int d_e2 = 10;
	int p_e1 = 30;
	int p_e2 = 60;
	int f_e1 = 100;
	int f_e2 = 210;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jinshe-zhang", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"jinshe-zhang/" + action;
}

int help(object me)
{
	write(HIC"\n金蛇游身掌："NOR"\n");
	write(@HELP

    金蛇游身掌载于「金蛇密笈」，乃金蛇郎君夏雪宜的独门武功。
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

