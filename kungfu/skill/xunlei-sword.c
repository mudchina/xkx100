// xunlei-sword.c
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N剑尖向右，绕身一周，一式"HIC"「仙人指路」"NOR"，$w突然向$n的$l刺去，",
	"lvl" : 0,
	"skill_name"  : "仙人指路"
]),
([	"action" : "$N使出一式"BLU"「鹞子翻身」"NOR"，身体凌空侧翻，一剑从身下刺出",
	"lvl" : 5,
	"skill_name"  : "鹞子翻身"
]),
([	"action" : "$N左手剑指血指，右手$w使出一招"MAG"「海底寻针」"NOR"，由上至下猛向$n的$l劈刺",
	"lvl" : 10,
	"skill_name"  : "海底寻针"
]),
([	"action" : "$N撤步缩身，$w按藏于臂下，一招"GRN"「灵猿探洞」"NOR"，快如闪电般刺向$n的$l",
	"lvl" : 15,
	"skill_name"  :"灵猿探洞"
]),
([	"action" : "$N踏步向前，一式"HIG"「拨草寻蛇」"NOR"，手中长剑摆动，剑尖刺向$n的$l",
	"lvl" : 20,
	"skill_name"  : "拨草寻蛇"
]),
([	"action" : "$N一招"HIY"「斜插神枝」"NOR"，身体背转，手中$w由右肩上方反手向下刺出",
	"lvl" : 25,
	"skill_name"  : "斜插神枝"
]),
([	"action" : "$N一式"HIC"「电闪雷动」"NOR"，剑走中锋，气势威严，将$n笼罩于重重剑气之中",
	"lvl" : 30,
	"skill_name"  : "电闪雷动"
]),
([	"action" : "$N向前弯身，一招"RED"「夫子揖手」"NOR"，$w忽然从身下刺出，快如流星闪电",
	"lvl" : 35,
	"skill_name"  : "夫子揖手"
]),
([	"action" : "$N横握$w，左右晃动，一招"HIW"「玉带缠腰」"NOR"，剑气直逼$n的腰部要害",
	"lvl" : 45,
	"skill_name"  : "玉带缠腰"
]),
([	"action" : "$N双手持剑，将$w当做刀使，一招"HIR"「举火烧天」"NOR"，由身后向$n的前上方劈去",
	"lvl" : 55,
	"skill_name"  : "举火烧天"
]),
([	"action" : "$N侧身向$n，使出一招"HIB"「败马斩蹄」"NOR"，挥动手中$w，直劈$n的下三路",
	"lvl" : 65,
	"skill_name"  : "败马斩蹄"
]),
([	"action" : "$N手中$w由右自左，一招"HIC"「玉女穿针」"NOR"，$w突然反手刺向$n的$l",
	"lvl" : 75,
	"skill_name"  : "玉女穿针"
]),
([	"action" : "$N跳步向前，剑尖上指，一招"HIG"「灵猿登枝」"NOR"，$w挑向$n的头部要害",
	"lvl" : 85,
	"skill_name"  : "灵猿登枝"
]),
([	"action" : "$N一招"BLU"「苏武挥鞭」"NOR"，$w随身走，犹如一条白龙，将$n全身上下笼罩",
	"lvl" : 95,
	"skill_name"  : "苏武挥鞭"
]),
([	"action" : "$N剑尖向下，一招"RED"「挑灯看剑」"NOR"，$w忽然急转直上，剑气将$n的上身要害团团围住",
	"lvl" : 100,
	"skill_name"  : "挑灯看剑"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 10)
		return notify_fail("你的玄天无极功火候太浅。\n");
	if ((int)me->query_skill("sword", 1) < 10)
		return notify_fail("你的基本剑法火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 35 )
		return notify_fail("你的内力或气不够练迅雷十六剑。\n");
	me->receive_damage("qi", 45);
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
	int d_e1 = -10;
	int d_e2 = 10;
	int p_e1 = -40;
	int p_e2 = -20;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 160;
	int m_e2 = 250;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("xunlei-sword", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"xunlei-sword/" + action;
}

int help(object me)
{
	write(HIC"\n迅雷十六剑："NOR"\n");
	write(@HELP

    迅雷十六剑是昆仑派的剑法。

	学习要求：
		玄天无极功10级
		基本剑法10级
		内力100
HELP
	);
	return 1;
}

