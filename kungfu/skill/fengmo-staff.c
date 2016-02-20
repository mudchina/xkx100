// fengmo-staff.c 疯魔杖法

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N斜举$w, 一招"HIB"「秦王鞭石」"NOR"，斜肩铲背砸向$n的$l",
	"lvl"    : 0,
	"skill_name" : "秦王鞭石"
]),
([	"action" : "$N一声大喝，使出一招"GRN"「鲁达拔柳」"NOR", 手中$w自下而上扫向$n的$l",
	"lvl"    : 39,
	"skill_name" : "鲁达拔柳"
]),
([	"action" : "$N使出一招"BLU"「霸王扛鼎」"NOR"，将$w从肩头甩出砸向往$n的$l",
	"lvl"    : 69,
	"skill_name" : "霸王扛鼎"
]),
([	"action" : "$N身子一晃，一招"RED"「八仙醉打」"NOR"，手中$w如狂风暴雨般向$n打出",
	"lvl"    : 79,
	"skill_name" : "八仙醉打"
]),
([	"action" : "$N一声咆哮，一招"HIW"「长虹经天」"NOR", $w从手中掷出，飞向$n的$l",
	"lvl"    : 89,
	"skill_name" : "长虹经天"
]),
([      "action" : RED "$N脸上突现煞气，举起$w，猛向$n後脑击落。这一杖出手又快又狠，竟是「疯魔杖法」中的毒招"NOR,
        "lvl"    : 99,
	"skill_name" : "疯魔杖法"
]),	
});

int valid_enable(string usage) { return (usage=="staff") || (usage=="parry");}

int valid_learn(object me)
{
	if ((int)me->query_skill("huntian-qigong", 1) < 20)
		return notify_fail("你的混天气功火候不到。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你还是先集中精力修练内力吧。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;
	int lvl = me->query_skill("fengmo-staff", 1);
	int i = sizeof(action);
	while (i--) if (lvl == action[i]["lvl"]) return 0;
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你手上的武器不能用来练疯魔杖法。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 30 )
		return notify_fail("你先歇口气再练吧。\n");
	me->receive_damage("qi", 45);
	me->add("neili", -25);
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
	int d_e1 = -45;
	int d_e2 = -15;
	int p_e1 = 10;
	int p_e2 = 45;
	int f_e1 = 250;
	int f_e2 = 300;
	int m_e1 = 200;
	int m_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("fengmo-staff", 1);
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
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n疯魔杖法："NOR"\n");
	write(@HELP

    疯魔杖法为丐帮的武技。

	学习要求：
		混天气功20级
		内力200
HELP
	);
	return 1;
}

