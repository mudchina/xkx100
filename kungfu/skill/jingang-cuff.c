// Last Modified by winder on May. 29 2001
// jingang-cuff.c 大金刚拳 不能互备 截自佛经中之“八正道”。

#include <ansi.h>
inherit "/inherit/skill/cuff.c";
string type() { return "martial"; }
string martialtype() { return "skill"; }
 
mapping *action = ({
([	"action" : "$N双臂一挥，第一式"HIY"「正见」"NOR"打出，以通臂之势，拳消力不消，劲风直逼$n而去",
	"lvl"   : 0,
	"skill_name" : "正见"
]),
([	"action" : "$N躬腰曲背，左臂一抡，架起一道气墙，接着右手握拳，对着$n，一招"HIY"「正思」"NOR"穿墙而出",
	"lvl" : 10,
	"skill_name" : "正思"
]),
([	"action" : "$N一个马步式"HIY"「正业」"NOR"，双拳凝力，跟着两臂相并，对准$n$l一式挥出，劲力异常",
	"lvl" : 20,
	"skill_name" : "正业"
]),
([	"action" : "$N使出一招"HIY"「正语」"NOR"，双臂连连挥动，拳风伴着口中的狮子吼，如猛兽下山般袭向$n",
	"lvl" : 40,
	"skill_name" : "正语"
]),
([	"action" : "$N单臂抡起一式"HIY"「正命」"NOR"打出，接着又是一拳相随，后浪推前浪，两波劲力合击$n",
	"lvl" : 60,
	"skill_name" : "正命"
]),
([	"action" : "$N挥出数拳，正当$n质疑这花拳之势时，一股劲风爆出，正对$p胸口，是招虚实的"HIY"「正勤」"NOR"",
	"lvl" : 70,
	"skill_name" : "正勤"
]),
([	"action" : "$N口颂佛经，打出一招"HIY"「正念」"NOR"，直轰$n前胸，拳风至刚至阳，正大光明，不带丝毫阴气",
 	"lvl" : 80,
	"skill_name" : "正念"
]),
([	"action" : "只见$N合十而立，以这"HIY"「正定」"NOR"一招为本，以身为拳，劲力布满全身，重重压向$n",
	"lvl" : 100,
	"skill_name" : "正定"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		 return notify_fail("练大金刚拳必须空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 140)
		 return notify_fail("你的站桩功火候不够，无法学大金刚拳。\n");
	if ((int)me->query("max_neili") < 2000)
		return notify_fail("你的内力太弱，无法练大金刚拳。\n");
	if ((me->query_skill("shaolin-cuff", 1) < 50) ||
		(me->query_skill("one-finger", 1) < 50))
		return notify_fail("你的少林南拳和一指禅火候不够，无法学大金刚拳。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练大金刚拳。\n");
	me->receive_damage("qi", 45);
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
	int d_e1 = 20;
	int d_e2 = 40;
	int p_e1 = -40;
	int p_e2 = -20;
	int f_e1 = 210;
	int f_e2 = 410;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jingang-cuff", 1);
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
		"damage_type" : "瘀伤",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"jingang-cuff/" + action;
}

int help(object me)
{
	write(HIC"\n大金刚拳："NOR"\n");
	write(@HELP

    大金刚拳是南少林高级拳法，出自佛经中之“八正道”。

	学习要求：
		站桩功140级
		少林南拳50级
		一指禅50级
		内力修为2000

HELP
	);
	return 1;
}

