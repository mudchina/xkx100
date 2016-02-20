// hannbing-mianzhang.c 寒冰绵掌
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"HIB"「大江东去」"NOR"，双掌大开大合，直向$n的$l击去",
	"lvl" : 0,
	"skill_name" : "大江东去"
]),
([	"action" : "$N身形一变，一式"YEL"「黄河九曲」"NOR"，双掌似曲似直，拍向$n的$l",
	"lvl" : 10,
	"skill_name" : "黄河九曲"
]),
([	"action" : "$N使一式"GRN"「湖光山色」"NOR"，左掌如微风拂面，右掌似细雨缠身，直取$n的$l",
	"lvl" : 20,
	"skill_name" : "湖光山色"
]),
([	"action" : "$N两掌一分，一式"MAG"「曾经沧海」"NOR"，隐隐发出潮声，向$n横击过去",
	"lvl" : 30,
	"skill_name" : "曾经沧海"
]),
([	"action" : "$N身形一转，使出一式"HIM"「水光潋滟」"NOR"，只见漫天掌影罩住了$n的全身",
	"lvl" : 40,
	"skill_name" : "水光潋滟"
]),
([	"action" : "$N突然身形一缓，使出一式"HIG"「小雨初晴」"NOR"，左掌凝重，右掌轻盈，击往$n的$l",
	"lvl" : 50,
	"skill_name" : "小雨初晴"
]),
([	"action" : "$N使一式"HIW"「风雪江山」"NOR"，双掌挟狂风暴雪之势，猛地劈向$n的$l",
	"lvl" : 60,
	"skill_name" : "风雪江山"
]),
([	"action" : "$N一招"HIW"「霜华满地」"NOR"，双掌带着萧瑟的秋气，拍向$n的$l",
	"lvl" : 70,
	"skill_name" : "霜华满地"
]),
([	"action" : "$N身法陡然一变，使出一式"HIW"「仙乡冰舸」"NOR"，掌影千变万幻，令$n无法躲闪",
	"lvl" : 80,
	"skill_name" : "仙乡冰舸"
]),
([	"action" : "$N清啸一声，一式"HIW"「冰霜雪雨」"NOR"，双掌挥舞，如同雪花随风而转，击向$n的$l",
	"lvl" : 90,
	"skill_name" : "冰霜雪雨"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练寒冰绵掌必须空手。\n");
	if (me->query_skill("jiuyang-shengong", 1) < 40)
		return notify_fail("你的九阳神功不到火候，无法学寒冰绵掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练寒冰绵掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练寒冰绵掌。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("hanbing-mianzhang",1)) > 10 )
		victim->apply_condition("ice_poison", random(me->query_skill("hanbing-mianzhang",1)/10) + 1 + victim->query_condition("ice_poison"));
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
	int d_e1 = -15;
	int d_e2 = 5;
	int p_e1 = 25;
	int p_e2 = 55;
	int f_e1 = 110;
	int f_e2 = 220;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("hanbing-mianzhang", 1);
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
	return __DIR__"hanbing-mianzhang/" + action;
}
int help(object me)
{
	write(HIC"\n寒冰绵掌："NOR"\n");
	write(@HELP

    寒冰绵掌是明教青翼蝠王韦一笑的独门武功。中掌后就会寒毒
发作，历时发作，其害无比。

	学习要求：
		九阳神功40级
		内力100
HELP
	);
	return 1;
}

