// pudu-zhang.c 普渡杖法
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$N使一招"HIB"「黄牛转角」"NOR"，手中$w自下而上，沉猛无比地向$n的小腹挑去。",
	"lvl" : 0,
	"skill_name" : "黄牛转角"
]),
([	"action":"$N快步跨出，一招"HIW"「野马追风」"NOR"，左手平托$w，右掌猛推杖端，顶向$n的胸口。",
	"lvl" : 9,
	"skill_name" : "野马追风"
]),
([	"action":"$N高举$w，一招"HIM"「猛虎跳涧」"NOR"，全身跃起，手中$w搂头盖顶地向$n击去。",
	"lvl" : 18,
	"skill_name" : "猛虎跳涧"
]),
([	"action":"$N一招"HIY"「狮子摇头」"NOR"，双手持杖如橹，对准$n猛地一搅，如同平地刮起一阵旋风。",
	"lvl" : 27,
	"skill_name" : "狮子摇头"
]),
([	"action":"$N横持$w，一招"HIR"「苍龙摆尾」"NOR"，杖端化出无数个圆圈，凝滞沉重，把$n缠在其中。",
	"lvl" : 36,
	"skill_name" : "苍龙摆尾"
]),
([	"action":"$N全身滚倒，$w盘地横飞，突出一招"HIG"「大蟒翻身」"NOR"，杖影把$n裹了起来",
	"lvl" : 45,
	"skill_name" : "大蟒翻身"
]),
([	"action":"$N双手和十，躬身一招"HIY"「胡僧托钵」"NOR"，$w自肘弯飞出，拦腰向$n撞去。",
	"lvl" : 53,
	"skill_name" : "胡僧托钵"
]),
([	"action":"$N一招"CYN"「慈航普渡」"NOR"，$w如飞龙般自掌中跃出，直向$n的胸口穿入。",
	"lvl" : 60,
	"skill_name" : "慈航普渡"
]),
});

int valid_enable(string usage) { return usage == "staff" || usage=="parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 10 )
		return notify_fail("你的内力或气不够练普渡杖法。\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = -35;
	int d_e2 = 0;
	int p_e1 = 30;
	int p_e2 = 55;
	int f_e1 = 200;
	int f_e2 = 250;
	int m_e1 = 150;
	int m_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("pudu-zhang", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n普渡杖法："NOR"\n");
	write(@HELP

    普渡杖法为少林七十二绝技之一。

	学习要求：
		混元一气功20级
		内力100
HELP
	);
	return 1;
}

