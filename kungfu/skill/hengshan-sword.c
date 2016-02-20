// hengshan-sword.c 衡山剑法
// Last Modified by sir 10.22.2001
// Modified by Java Sep.1998
//重进攻轻防守

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([      "skill_name" :"衡山云雾",
	"action":  "$N右手$w慢慢指出，突然间在空中一颤，发出嗡嗡之声，跟着便是嗡嗡两剑，一招"HIW"「衡山云雾」"NOR"手中$w剑光暴长，向$n的$l刺去",
        "lvl" : 0
]),
([      "skill_name" :"百变千幻",
	"action":  "$N一招"HIC"「百变千幻」"NOR"手中$w如鬼如魅，竟然已绕到了$n背后，$n急忙转身，耳边只听得嗡嗡两声",
	"lvl" : 10
]),
([      "skill_name":    "泉鸣芙蓉",
	"action":  "$N不理会对方攻势来路，手中$w刷的一剑"MAG"「泉鸣芙蓉」"NOR"，向$n小腹刺去",
	"lvl" : 20
]),
([      "skill_name":    "鹤翔紫盖",
	"action":  "$N不理会对方攻势来路，手中$w刷的一剑"HIM"「鹤翔紫盖」"NOR"，向$n额头刺去",
	"lvl" : 30
]),
([      "skill_name":    "石廪书声",
	"action":  "$N手中$w倏地刺出，剑势穿插迂回，如梦如幻，正是一招" HIG"「石廪书声」"NOR"，向$n$l刺去",
	"lvl" : 40
]),
([      "skill_name":    "天柱云气",
	"action":  "$N手中$w倏地刺出，极尽诡奇之能事，动向无定，不可捉摸。正是一招"RED"「天柱云气」"NOR"，指向$n$l",
	"lvl" : 50
]),
([      "skill_name":    "雁回祝融",
	"action" : "$N飞身跃起，"HIR"『雁回祝融』"NOR"！，$w发出一声龙吟从半空中洒向$n的$l",
	"lvl" : 60
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力不够，没有办法练衡山剑法。\n");
	if( (string)me->query_skill_mapped("force")!= "huiyan-xinfa")
		return notify_fail("衡山剑法必须配合回雁心法才能练。\n");
	if( !(ob = me->query_temp("weapon"))
		|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("你的内力或气不够，没有办法练习衡山剑法。\n");
	me->receive_damage("qi", 35);
	me->add("neili", -20);
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
	int d_e1 = 5;
	int d_e2 = 30;
	int p_e1 = -20;
	int p_e2 = -5;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 110;
	int m_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("hengshan-sword", 1);
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
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
	return __DIR__"hengshan-sword/" + action;
}
int help(object me)
{
	write(HIC"\n衡山剑法："NOR"\n");
	write(@HELP

    衡山剑法为衡山武功。

	学习要求：
		回雁心法
		内力50
HELP
	);
	return 1;
}

