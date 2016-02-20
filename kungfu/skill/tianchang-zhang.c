//tianchang-zhang 天长掌
// Last Modified by sir on 5/19/ 2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N使一招"GRN"「青山隐隐」"NOR"，双手划了个半圈，按向$n的$l",
	"skill_name" : "青山隐隐",
	"lvl" : 5
]),
([	"action" : "$N使一招"MAG"「云霞出海」"NOR"，左手轻轻一挥，劈向$n的$l",
	"skill_name" : "云霞出海",
	"lvl" : 15
]),
([	"action" : "$N右手掌心向外，由右向左，使一招"CYN"「星河鹭起」"NOR"，向$n的$l打去",
	"skill_name" : "星河鹭起",
	"lvl" : 10
]),
([	"action" : "$N使一招"HIM"「彩舟云淡」"NOR"，分击$n的胸口和$l",
	"skill_name" : "彩舟云淡",
	"lvl" : 20
]),
([	"action" : "$N使一招"HIB"「月照幽林」"NOR"，左右掌同时击出，在空中突然左右掌方向互变",
	"skill_name" : "月照幽林",
	"lvl" : 30
]),
([	"action" : "$N左手不住晃动，右掌一招"HIW"「白日参辰」"NOR"，向$n的$l打去",
	"skill_name" : "白日参辰",
	"lvl" : 50
]),
([	"action" : "$N左手变掌为啄，右掌立掌如刀，一招"HIY"「鹤舞白沙」"NOR"，劈向$n的$l",
	"skill_name" : "鹤舞白沙",
	"lvl" : 70
]),
([	"action" : "$N左脚退后半步，右掌使一招"HIC"「水天一色」"NOR"，横挥向$n",
	"skill_name" : "水天一色",
	"lvl" : 80
]),
([	"action" : "$N一招"CYN"「月华流照」"NOR"，左掌先发而后至，右掌后发而先至",
	"skill_name" : "月华流照",
	"lvl" : 90
]),
([	"action" : "$N双掌缩入袖中，双袖飞起扫向$n的$l，却是一招"HIR"「嫦娥奔月」"NOR"，仪态潇洒",
	"skill_name" : "嫦娥奔月",
	"lvl" : 100
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }
int valid_combine(string combo) { return combo=="chuanyun-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练天长掌必须空手。\n");
	if ((int)me->query_skill("baiyun-xinfa", 1) < 20)
		return notify_fail("你的白云心法火候不够，无法学天长掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练天长掌。\n");
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
	int d_e1 = -35;
	int d_e2 = -5;
	int p_e1 = 5;
	int p_e2 = 35;
	int f_e1 = 170;
	int f_e2 = 280;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("tianchang-zhang", 1);
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
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"tianchang-zhang/" + action;
}
int help(object me)
{
	write(HIC"\n天长掌："NOR"\n");
	write(@HELP

    天长掌为恒山派武功。
    可与穿云手互备。

	学习要求：
		白云心法20级
HELP
	);
	return 1;
}

