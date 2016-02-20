// ruyi-dao.c 如意刀
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
#include <xiaoyao.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N手中$w斜指，一招"BLU"「停车问路」"NOR"，反身一顿，一刀向$n的$l撩去",
	"lvl"    : 0,
	"skill_name" : "停车问路",
]),
([	"action" : "$N一招"HIW"「童子挂画」"NOR"，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
	"lvl"    : 8,
	"skill_name" : "童子挂画",
]),
([	"action" : "$N展身虚步，提腰跃落，一招"MAG"「推窗望月」"NOR"，刀锋一卷，拦腰斩向$n",
	"lvl"    : 16,
	"skill_name" : "推窗望月",
]),
([	"action" : "$N一招"HIG"「开门见山」"NOR"，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
	"lvl"    : 24,
	"skill_name" : "开门见山",
]),
([	"action" : "$N手中$w一沉，一招"CYN"「临溪观鱼」"NOR"，双手持刃拦腰反切，砍向$n的胸口",
	"lvl"    : 33,
	"skill_name" : "临溪观鱼",
]),
([	"action" : "$N挥舞$w，使出一招"BLU"「张弓望的」"NOR"，上劈下撩，左挡右开，齐齐罩向$n",
	"lvl"    : 42,
	"skill_name" : "张弓望的",
]),
([	"action" : "$N一招"YEL"「风送轻舟」"NOR"，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
	"lvl"    : 51,
	"skill_name" : "风送轻舟",
]),
([	"action" : "$N盘身驻地，一招"HIC"「川流不息」"NOR"，挥出一片流光般的刀影，向$n的全身涌去",
	"lvl"    : 60,
	"skill_name" : "川流不息",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
	if(//((int)me->query_skill("bahuang-gong", 1) < 10 ) &&
		((int)me->query_skill("beiming-shengong", 1) < 10 ))
		return notify_fail("你的本门内功还不够娴熟。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
	return notify_fail("你的体力不够练如意刀。\n");
	me->receive_damage("qi", 30);
	me->add("neili",-10);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
string perform_action_file(string action)
{
	return __DIR__"ruyi-dao/" + action;
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 45;
	int d_e2 = 25;
	int p_e1 = -5;
	int p_e2 = -25;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 150;//110;
	int m_e2 = 350;//220;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("ruyi-dao", 1);
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
		"damage_type" : random(2) ? "割伤" : "擦伤",
	]);
}
int learn_bonus() { return 15; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { 
	if (fam_type(me)=="xiaoyao")
	return 1.3;
 return 1.0;
}

int help(object me)
{
	write(HIC"\n如意刀："NOR"\n");
	write(@HELP

    如意刀是逍遥派的刀法。

	学习要求：
		北冥神功10级
		内力50
HELP
	);
	return 1;
}

