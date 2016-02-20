// zhemei-shou.c 天山折梅手
// Last Modified by sir 10.23.2001

#include <ansi.h>
#include <xiaoyao.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一招"GRN"「吹梅笛怨」"NOR"，双手横挥，抓向$n",
	"lvl" : 0,
	"skill_name" : "吹梅笛怨"
]),
([	"action" : "$N一招"YEL"「黄昏独自愁」"NOR"，身子跃然而起，抓向$n的头部",
	"lvl" : 10,
	"skill_name" : "黄昏独自愁"
]),
([	"action" : "$N一招"CYN"「寒山一带伤心碧」"NOR"，双手纷飞，$n只觉眼花缭乱",
	"lvl" : 30,
	"skill_name" : "寒山一带伤心碧"
]),
([	"action" : "$N一招"MAG"「梅花雪落覆白苹」"NOR"，双手合击，$n只觉无处可避",
	"lvl" : 40,
	"skill_name" : "梅花雪落覆白苹"
]),
([	"action" : "$N一招"HIW"「砌下落梅如雪乱」"NOR"，双手飘然抓向$n",
	"lvl" : 50,
	"skill_name" : "砌下落梅如雪乱"
]),

([	"action" : "$N双手平举，一招"GRN"「云破月来花弄影」"NOR"击向$n",
	"lvl" : 60,
	"skill_name" : "云破月来花弄影"
]),
([	"action" : "$N一招"HIB"「花开堪折直须折」"NOR"，拿向$n，似乎$n的全身都被笼罩",
	"lvl" : 70,
	"skill_name" : "花开堪折直须折"
]),

([	"action" : "$N左手虚晃，右手一记"HIR"「红颜未老恩先绝」"NOR"击向$n的头部",
	"lvl" : 80,
	"skill_name" : "红颜未老恩先绝"
]),
([	"action" : "$N施出"HIM"「虚妄笑红」"NOR"，右手横扫$n的$l，左手攻向$n的胸口",
	"lvl" : 90,
	"skill_name" : "虚妄笑红"
]),
([	"action" : "$N施出"HIR"「玉石俱焚」"NOR"，不顾一切扑向$n",
	"lvl" : 100,
	"skill_name" : "玉石俱焚"
])
});

int valid_enable(string usage) { return usage=="parry" || usage=="hand"; }
int valid_combine(string combo) { return combo=="liuyang-zhang"; }

int valid_learn(object me)
{
	if(((int)me->query_skill("bahuang-gong", 1) < 15 ) &&
		((int)me->query_skill("beiming-shengong", 1) < 15 ))
		return notify_fail("你的本门内功还不够娴熟。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练天山折梅手必须空手。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练天山折梅手。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 60)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 60)
		return notify_fail("你的内力不够练天山折梅手。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -30);
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
	int d_e1 = -60;
	int d_e2 = -30;
	int p_e1 = 0;
	int p_e2 = 35;
	int f_e1 = 120;
	int f_e2 = 220;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("zhemei-shou", 1);
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
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (me->query("jiali") <= 10) return 0;
	if (fam_type(me)!="xiaoyao") return 0;
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/3) > victim->query_str() ) 
	{
		victim->receive_wound("qi", (damage_bonus - 80) / 3, me);
		return HIC "你听到一声脆响，仿佛是梅枝折断的声音！\n" NOR;	
	}
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"zhemei-shou/" + action;
}
int help(object me)
{
	write(HIC"\n天山折梅手："NOR"\n");
	write(@HELP

    天山折梅手是逍遥派手法。
    可与天山六阳掌互备。

	学习要求：
		北冥神功15级或八荒六合唯我独尊功15级
		内力50
HELP
	);
	return 1;
}

