// canhe-finger.c 参合指
// Modified by sir 10.23.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"MAG"「目不识丁」"NOR"，真气自指间喷薄而出，连出三指，快如电闪，点向$n的$l",
	"lvl" : 0,
	"skill_name" : "目不识丁"
]),
([	"action" : "$N身形一转，一式"HIR"「画龙点睛」"NOR"，右手自下而起，食指伸处，一股真气冲关而出，直向$n的眼睛点去",
	"lvl" : 20,
	"skill_name" : "画龙点睛"
]),
([	"action" : "$N左手食指一抬，向$n点去，右手食指紧接着点向$n的$l，一式"GRN"「扑朔迷离」"NOR"，双手亦虚亦实，$n顿觉不知道如何对付",
	"lvl" : 40,
	"skill_name" : "扑朔迷离"
]),
([	"action" : "$N忽然面现惊惧之色，返身欲走，只一瞬间，身形不退反进，一式
"BLU"「受宠若惊」"NOR"，右手食指自下而上，趁势点向$n的$l",
	"lvl" : 60,
	"skill_name" : "受宠若惊"
]),
([	"action" : "$N运起慕容世家自然心法，左右手一收一放，一式"YEL"「滔滔不绝」"NOR"，双手食指连指，向$n的$l点去",
	"lvl" : 70,
	"skill_name" : "滔滔不绝"
]),
([	"action" : "$N左右双脚碎步后移，眼角瞥见$n跟进，突然间左手变掌为指，嗤的一声响，一式"CYN"「退避三舍」"NOR"，回点$n的$l",
	"lvl" : 90,
	"skill_name" : "退避三舍"
]),
([	"action" : "$N一闪身到了$n背后，左膝一屈，侧身右手一指，一式"RED"「卧薪尝胆」"NOR"，指向$n的后腰",
	"lvl" : 100,
	"skill_name" : "卧薪尝胆"
]),
([	"action" : "$N左脚向左踏出一步，又快如闪电般抽回，右步上前一大步，顿时欺近$n，"GRN"「相煎何急」"NOR"！食指疾点$n的$l",
	"lvl" : 130,
	"skill_name" : "相煎何急"
]),
});
int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="xingyi-strike"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练参合指必须空手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练参合指。\n");
	if ((int)me->query_skill("shenyuan-gong", 1) < 15)
		return notify_fail("你的神元火候不够，无法学参合指。\n");
	return 1;
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 25)
		return notify_fail("你的内力不够练。\n");
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
	int d_e1 = 30;
	int d_e2 = 50;
	int p_e1 = -30;
	int p_e2 = -10;
	int f_e1 = 280;
	int f_e2 = 380;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("canhe-finger", 1);
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
		"damage_type" : random(2) ? "刺伤" : "瘀伤",
	]);
}
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point() { return 1.0; }
string perform_action_file(string action)
{
	return __DIR__"canhe-finger/" + action;
}

int help(object me)
{
	write(HIC"\n参合指："NOR"\n");
	write(@HELP

    参合指为姑苏慕容家指法绝技。慕容氏家学渊源，参合指威力
亦不逊于少林派大力金刚指。
    可与星移掌互备。

	学习要求：
		神元功15级
		内力100
HELP
	);
	return 1;
}

