//huifeng-jian.c 回风拂柳剑
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name":   "清风袭月",
	"action" : "$N剑尖剑芒暴长，一招"HIC"「清风袭月」"NOR"，手中$w自左下大开大阖，一剑向右上向$n的$l",
	"lvl" : 0
]),
([	"skill_name":   "飘雪穿云",
	"action" : "$N长剑圈转，一招"HIW"「飘雪穿云」"NOR"，手中$w平展下刺，一剑轻轻划过$n的$l",
	"lvl" : 10
]),
([	"skill_name":   "千峰竞秀",
	"action" : "$N长剑轻灵跳动，剑随身长，右手$w使出一式"GRN"「千峰竞秀」"NOR"刺向$n的$l",
	"lvl" : 20
]),
([	"skill_name":   "万流归宗",
	"action" : "$N长剑下指，剑意流转，一招"HIB"「万流归宗」"NOR"直取$n的$l",
	"lvl" : 30
]),
([	"skill_name":   "乌龙搅柱",
	"action" : "$N剑芒吞吐，幻若灵蛇，右手$w使出一式"BLU"「乌龙搅柱」"NOR"，剑势曼妙，刺向$n的$l",
	"lvl" : 40
]),
([	"skill_name":   "大雁啼沙",
	"action" : "$N屈腕云剑，剑光如彩碟纷飞，幻出点点星光，右手$w使出一式
"HIY"「大雁啼沙」"NOR"跃跃洒洒飘向$n的$l",
	"lvl" : 50
]),
([	"skill_name":   "进退龙游",
	"action" : "$N挥剑分击，剑势自胸前跃出，右手$w一式"HIM"「进退龙游」"NOR"，毫无留恋之势，刺向$n的$l",
	"lvl" : 60
]),
([	"skill_name":   "天地鹤翔",
	"action" : "$N退步，左手剑指划转，腰部一扭，右手$w一记"MAG"「天地鹤翔」"NOR"自下而上刺向$n的$l",
	"lvl" : 70
]),
});

int valid_enable(string usage) { return (usage=="sword") || (usage=="parry") ; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("你的临济十二庄火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 35 )
		return notify_fail("你的内力或气不够练回风拂柳剑。\n");
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
	int m_e2 = 260;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("huifeng-jian", 1);
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
	return __DIR__"huifeng-jian/" + action;
}

int help(object me)
{
	write(HIC"\n回风拂柳剑："NOR"\n");
	write(@HELP

    回风拂柳剑为峨嵋派武功。

	学习要求：
		临济十二庄20级
		内力50
HELP
	);
	return 1;
}

