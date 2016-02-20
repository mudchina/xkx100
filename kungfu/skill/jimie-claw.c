// Last Modified by Winder on May. 29 2001
// jimie-claw.c 寂灭爪 和波罗密手互备 截至佛经中人生八苦。

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N全身拔地而起，一式"HIG"「生」"NOR"字诀，双爪相扣，迅猛地抓向$n，却又不带任何霸气",
	"lvl"    : 0,
	"skills_name" : "生",
]),
([	"action" : "$N一式"HIY"「老」"NOR"字诀，双爪中宫直进，却不变招，待其用老之际，$n已避无可避",
	"lvl"    : 10,
	"skills_name" : "老",
]),
([	"action" : "$N脚步蹒跚，有如"MAG"「病」"NOR"态，左手曲抓随意一挥，竟然能带起数到劲风直袭$n$l",
	"lvl"    : 20,
	"skills_name" : "病",
]),
([	"action" : "$N双爪交错，一式"HIB"「死」"NOR"字诀，身随抓动，追着$n如影附骨，誓要击杀$p去爪下",
	"lvl"    : 30,
	"skills_name" : "死",
]),
([	"action" : "$N一式"GRN"「求不得」"NOR"，右爪突出，左爪跟进，接着右抓又出，双爪相叠，抓向$n的胸口",
	"lvl"    : 40,
	"skills_name" : "求不得",
]),
([	"action" : "$N原地不动，一式"RED"「爱别离」"NOR"，只待$n袭来，双手猛然变爪而出，直插$n的两处大穴",
	"lvl"    : 60,
	"skills_name" : "爱别离",
]),
([	"action" : "$N翻身一挥，双爪无数道劲气破空而出，一式"HIM"「怨憎会」"NOR"，迅疾无比地飞刺向$n",
	"lvl"    : 80,
	"skills_name" : "怨憎会",
]),
([	"action" : "$N腾空高飞数丈，打出一式"HIR"「五阴炽盛」"NOR"，一时间空中出现无数$N的身影，层层抓影罩向$n",
	"lvl"    : 100,
	"skills_name" : "五阴炽盛",
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_combine(string combo){ return combo=="boluomi-hand"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练寂灭爪必须空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 40)
		return notify_fail("你的站桩功火候不够，无法学寂灭爪。\n");
	if ((int)me->query("max_neili") < 400)
		return notify_fail("你的内力太弱，无法练习寂灭爪。\n");
	if (me->query_skill("sanhua-strike", 1) < 40)
		return notify_fail("你的散花掌火候不够，无法学寂灭爪。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练寂灭爪。\n");
	me->receive_damage("qi", 40);
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
	int d_e1 = 60;
	int d_e2 = 30;
	int p_e1 = -5;
	int p_e2 = -20;
	int f_e1 = 100;
	int f_e2 = 250;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("jimie-claw", 1);
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
		"damage_type" : random(2) ? "内伤" : "抓伤",
	]);
}
int learn_bonus() { return 30; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	 return __DIR__"jimie-claw/" + action;
}

int help(object me)
{
	write(HIC"\n寂灭爪："NOR"\n");
	write(@HELP

    寂灭爪是南少林入门爪法，和波罗密手互备。出自佛经中人生八苦。

	学习要求：
		站桩功40级
		散花掌40级
		内力修为400。
HELP
	);
	return 1;
}

