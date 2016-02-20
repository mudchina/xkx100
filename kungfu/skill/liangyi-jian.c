//liangyi-jian.c 两仪剑法
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" : "法分玄素",
	"action"     : "$N剑尖剑芒暴长，一招"HIC"「法分玄素」"NOR"，手中$w自左下大开大阖，一剑斜上刺向$n的$l",
	"lvl"        : 0
]),
([	"skill_name" : "道尽阴阳",
	"action"     : "$N剑势圈转，手中$w如粘带连，平平展展挥出，一招" HIR"「道尽阴阳」"NOR"轻轻划过$n的$l",
	"lvl"        : 10
]),
([	"skill_name" : "渊临深浅",
	"action"     : "$N长剑轻灵跳动，剑随身长，右手$w使出一式" HIB"「渊临深浅」"NOR"刺向$n的$l",
	"lvl"        : 20
]),
([	"skill_name" : "水泛青黄",
	"action"     : "$N长剑下指，剑意流转，一招"HIG"「水泛青黄」"NOR"直取$n的$l",
	"lvl"        : 30
]),
([	"skill_name" : "云含吞吐",
	"action"     : "$N剑芒吞吐，幻若灵蛇，右手$w使出一式"HIW"「云含吞吐」"NOR"，剑势极尽曼妙，刺向$n的$l",
	"lvl"        : 40
]),
([	"skill_name" : "梦醒蝶庄",
	"action"     : "$N屈腕云剑，剑光如彩碟纷飞，幻出点点星光，右手$w使出一式"HIG"「梦醒蝶庄」"NOR"跃跃洒洒飘向$n的$l",
	"lvl"        : 50
]),
([	"skill_name" : "人在遐迩",
	"action"     : "$N挥剑分击，剑势自胸前跃出，右手$w一式"HIM"「人在遐迩」"NOR"，毫无留恋之势，刺向$n的$l",
	"lvl"        : 60
]),
([	"skill_name" : "情系短长",
	"action"     : "$N退步，左手剑指划转，腰部一扭，右手$w一记" GRN"「情系短长」"NOR"自下而上刺向$n的$l",
	"lvl"        : 80
]),
});

int valid_enable(string usage){return (usage== "sword") || (usage== "parry");}
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 50)
		return notify_fail("你的太极神功火候太浅。\n");
	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("liangyi-jian", 1) )
		return notify_fail("你的基本剑法火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 60)
		return notify_fail("你的体力不够练两仪剑法。\n");
	if ((int)me->query("neili") < 45)
		return notify_fail("你的内力不足以练两仪剑法。\n");
	me->receive_damage("qi", 55);
	me->add("neili", -40);
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
	int d_e1 = -25;
	int d_e2 = 0;
	int p_e1 = -50;
	int p_e2 = -35;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 200;
	int m_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("liangyi-jian", 1);
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
		"damage_type" : random(2) ? "割伤" : "刺伤",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"liangyi-jian/" + action;
}

int help(object me)
{
	write(HIC"\n两仪剑法："NOR"\n");
	write(@HELP

    太极生两仪。
    武当派两位道长，穷数十年心血，创此两仪剑法，剑法中有阴
有阳，亦刚亦柔，阴阳合一，威力无俦。

	学习要求：
		太极神功50级
		内力200
		基本剑法不低于两仪剑法
HELP
	);
	return 1;
}

