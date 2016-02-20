// jiangjun-zhang.c 裴将军诗杖法
// Last Modified by sir 11.1.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([      "action":               
"$N手中$w向$n的$l连点三点，正是"HIC"「裴」"NOR"字起首三笔！",
	"lvl" : 0,
	"skill_name" : "裴"
]),
([      "action":               
"$N挥起$w，对准$n的$l虚点，自右上角至右下角弯曲而下，正是"HIC"「如」"NOR"字草书！",
	"lvl" : 10,
	"skill_name" : "如"
]),
([      "action":               
"$N横过$w，写了个"HIC"「猛」"NOR"字，对着$n斜扫过去！",
	"lvl" : 20,
	"skill_name" : "猛"
]),
([      "action":               
"$N大喝一声，笔法一变写出个"HIC"「将」"NOR"字，$w一挺撞向$n$l！",
	"lvl" : 30,
	"skill_name" : "将"
]),
([	"action":
"$N身形微转，$w向着$n的$l横扫过去，顺势带出个"HIC"「龙」"NOR"字！",
	"lvl" : 40,
	"skill_name" : "龙"
]),
([	"action":
"$N高高跃起，手中$w划出个"HIC"「壮」"NOR"字，向着$n的$l撞了过来！",
	"lvl" : 50,
	"skill_name" : "壮"
]),
([	"action":
"$N怒喝一声，手中$w急舞正是个"HIC"「腾」"NOR"字，将$n$l罩于杖下！",
	"lvl" : 60,
	"skill_name" : "腾"
]),
});
int valid_enable(string usage) { return usage == "staff" || usage == "parry";}
int valid_learn(object me)
{
	if ((int)me->query_skill("kuihua-xinfa", 1) < 20)
		return notify_fail("你的葵花心法火候不够。\n");
	if(me->query("max_neili")<200)
		return notify_fail("你的内力修为不够。\n");
        return 1;
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "staff" )
                return notify_fail("你必须先找一根木杖或者是类似的武器，才能练杖法。\n");

	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 50 )
                return notify_fail("你的内力或气不够练这门杖法，还是先休息休息吧。\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = -40;
	int d_e2 = -5;
	int p_e1 = 15;
	int p_e2 = 50;
	int f_e1 = 250;
	int f_e2 = 300;
	int m_e1 = 185;
	int m_e2 = 280;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jiangjun-zhang", 1);
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
		"damage_type" : "挫伤" ,
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n裴将军诗杖法："NOR"\n");
	write(@HELP

    日月神教黑木崖武功，梅庄三庄主秃笔翁看家本领。

	学习要求：
		葵花心法20级
		最大内力200
HELP
	);
	return 1;
}