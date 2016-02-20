// wuhu-duanmendao.c 五虎断门刀
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N手中$w斜指，一招"HIC"「直来直去」"NOR"，反身一顿，一刀向$n的$l撩去",
	"lvl"    : 0,
	"skill_name" : "直来直去",
]),
([	"action" : "$N一招"HIM"「童子挂画」"NOR"，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
	"lvl"    : 10,
	"skill_name" : "童子挂画",
]),
([	"action" : "$N展身虚步，提腰跃落，一招"HIW"「推窗望月」"NOR"，刀锋一卷，拦腰斩向$n",
	"lvl"    : 20,
	"skill_name" : "推窗望月",
]),
([	"action" : "$N一招"HIB"「力劈华山」"NOR"，$w大开大阖，自上而下划出一个闪电，直劈向$n",
	"lvl"    : 30,
	"skill_name" : "力劈华山",
]),
([	"action" : "$N手中$w一沉，一招"MAG"「临溪观鱼」"NOR"，双手持刃拦腰反切，砍向$n的胸口",
	"lvl"    : 40,
	"skill_name" : "临溪观鱼",
]),
([	"action" : "$N挥舞$w，使出一招"HIR"「张弓望的」"NOR"，上劈下撩，左挡右开，齐齐罩向$n",
	"lvl"    : 50,
	"skill_name" : "张弓望的",
]),
([	"action" : "$N一招"HIW"「风送轻舟」"NOR"，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
	"lvl"    : 60,
	"skill_name" : "风送轻舟",
]),
([	"action" : "$N盘身驻地，一招"CYN"「川流不息」"NOR"，挥出一片流光般的刀影，向$n的全身涌去",
	"lvl"    : 70,
	"skill_name" : "川流不息",
]),
([	"action" : "$N右手后撤，手腕一翻，一招"YEL"「壮士断腕」"NOR"，顿时一道白光直斩向$n的手臂",
	"lvl"    : 80,
	"skill_name" : "壮士断腕",
]),
([	"action" : "$N高高跃起，一招"HIR"「人头落地」"NOR"，手中$w直劈向$n的颈部",
	"lvl"    : 90,
	"skill_name" : "人头落地",
]),
([	"action" : "$N贴地滑行，一招"BLU"「断子绝孙」"NOR"，手中$w直撩去$n的裆部",
	"lvl"    : 100,
	"skill_name" : "断子绝孙",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("blade", 1) < 20)
		return notify_fail("你的基本刀法火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练五虎断门刀法。\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = 55;
	int d_e2 = 35;
	int p_e1 = 5;
	int p_e2 = -15;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 30;
	int m_e2 = 140;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("wuhu-duanmendao", 1);
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
		"damage_type" : "割伤",
	]);
}
int learn_bonus() { return 30; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point(object me) { return 1; }
/*
mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action)-1;
	level = (int) me->query_skill("wuhu-duanmendao",1);

	if (level < 60 ) zhaoshu--;
	if (level < 50 ) zhaoshu--;
	if (level < 40 ) zhaoshu--;
	if (level < 30 ) zhaoshu--;
	if (level < 20 ) zhaoshu--;
	if (level < 10 ) zhaoshu--;
	return action[random(zhaoshu)];
}
*/
string perform_action_file(string action)
{
	return __DIR__"wuhu-duanmendao/" + action;
}
int help(object me)
{
	write(HIC"\n五虎断门刀："NOR"\n");
	write(@HELP

    五虎断门刀是茅十八纵横江湖，苟且偷生的功夫。

	学习要求：
		基本刀法20级
		内力100
HELP
	);
	return 1;
}

