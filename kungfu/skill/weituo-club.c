// Last Modified by winder on May. 29 2001
// weituo-club.c 韦陀棍

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$N一招"HIY"「黄石纳履」"NOR"，手中$w如蜻蜓点水般，招招向$n的下盘要害点去
",
	"lvl"   : 0,
	"skill_name" : "黄石纳履"
]),
([	"action":"$N把$w平提胸口，一拧身，一招"HIG"「勒马停锋」"NOR"，$w猛地撩向$n的颈部",
	"lvl" : 8,
	"skill_name" : "勒马停锋"
]),
([	"action":"$N一招"HIY"「平地龙飞」"NOR"，全身滴溜溜地在地上打个大转，举棍向$n的胸腹
间戳去",
	"lvl" : 16,
	"skill_name" : "平地龙飞"
]),
([	"action":"$N伏地一个滚翻，一招"HIM"「伏虎听风」"NOR"，$w挟呼呼风声迅猛扫向$n的足胫
",
	"lvl"   : 25,
	"skill_name" : "伏虎听风"
]),
([	"action":"$N一招"HIC"「流星赶月」"NOR"，身棍合一，棍端逼成一条直线，流星般向顶向$n
的$l",
	"lvl"   : 35,
	"skill_name" : "流星赶月"
]),
([	"action":"$N双手持棍划了个天地大圈，一招"HIR"「红霞贯日」"NOR"，一棍从圆心正中击出
，撞向$n的胸口",
	"lvl"   : 44,
	"skill_name" : "红霞贯日"
]),
([	"action":"$N一招"HIB"「投鞭断流」"NOR"，$w高举，以雷霆万钧之势对准$n的天灵当头劈下
",
	"lvl"   : 52,
	"skill_name" : "投鞭断流"
]),
([	"action":"$N潜运真力，一招"HIY"「苍龙归海」"NOR"，$w顿时长了数丈，矫龙般直射$n的胸
口",
	"lvl"   : 60,
	"skill_name" : "苍龙归海"
]),
});

int valid_enable(string usage) { return usage == "club" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 20)
		return notify_fail("你的站桩功火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "club")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 50 )
		return notify_fail("你的内力或气不够练韦陀棍。\n");
	me->receive_damage("qi", 20);
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
	int d_e1 = -40;
	int d_e2 = -30;
	int p_e1 = 15;
	int p_e2 = 30;
	int f_e1 = 200;
	int f_e2 = 250;
	int m_e1 = 50;
	int m_e2 = 150;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("weituo-club", 1);
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
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : "挫伤",
	]);
}
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n韦陀棍："NOR"\n");
	write(@HELP

    韦陀棍是南少林入门棍法。

	学习要求：
		站桩功20级
		内力修为100
HELP
	);
	return 1;
}

