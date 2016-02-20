// Last Modified by Winder on May. 29 2001
// boruo-strike.c 般若掌 和龙爪功互备 取自佛门《十愿》。

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N后腿脚尖点地而出，一式"HIY"「礼敬诸佛」"NOR"，二掌合十，罡气直出，攻向$n全身",
	"lvl"   : 0,
	"skill_name" : "礼敬诸佛"
]),
([	"action" : "$N左掌划一半圆护胸，一式"YEL"「称赞如来」"NOR"，右掌化刀斜穿而出，疾插$n$l",
	"lvl"   : 10,
	"skill_name" : "称赞如来"
]),
([	"action" : "$N使一式"HIB"「广修供养」"NOR"，右掌上引，左掌由后而上一个甩拍，穿过$n护墙击出",
	"lvl"   : 30,
	"skill_name" : "广修供养"
]),
([	"action" : "$N左掌护胸，右拳凝劲，一式"MAG"「忏悔业障」"NOR"，四周罡气弥漫，出掌缓缓拍向$n$l",
	"lvl"   : 50,
	"skill_name" : "忏悔业障"
]),
([	"action" : "$N使一式"BLU"「请转法轮」"NOR"，全身飞速旋转，罡气飞卷，双掌一前一后，猛地按向$n的胸口",
	"lvl"   : 60,
	"skill_name" : "请转法轮"
]),
([	"action" : "$N合掌抱球，猛吸一口气，一式"HIM"「随喜功德」"NOR"，全身护满至阳罡气，跟着双掌疾推$n",
	"lvl"   : 80,
	"skill_name" : "随喜功德"
]),
([	"action" : "$N向上高高跃起，一式"RED"「请佛往世」"NOR"，罡气居高临下，四散而出，将掌力笼罩了$n的全身",
	"lvl"   : 100,
	"skill_name" : "请佛往世"
]),
([	"action" : "$N使一式"HIR"「恒顺众生」"NOR"，瞬间劲气弥漫，$P双掌连劈如轮，一环环向$n的$l斩去",
	"lvl"   : 120,
	"skill_name" : "恒顺众生"
]),
([	"action" : "$N两掌上下护胸，一式"HIC"「普皆回向」"NOR"拍出，掌影重重叠叠，带起无边罡气攻向$n",
	"lvl"   : 150,
	"skill_name" : "普皆回向"
]),
});
int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo){ return combo=="dragon-claw"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练般若掌必须空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 80)
		return notify_fail("你的站桩功火候不够，无法学般若掌。\n");
	if ((int)me->query("max_neili") < 800)
		return notify_fail("你的内力太弱，无法练般若掌。\n");
	if ((me->query_skill("nianhua-finger", 1) < 50) ||
		(me->query_skill("jingang-strike", 1) < 50))
		return notify_fail("你的大金刚神掌和拈花指火候不够，无法学般若掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 55)
		return notify_fail("你的力气太低了。\n");
	if ((int)me->query("neili") < 35)
		return notify_fail("你的内力不够练般若掌。\n");
	me->receive_damage("qi", 50);
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
	int d_e1 = -50;
	int d_e2 = -30;
	int p_e1 = -10;
	int p_e2 = 20;
	int f_e1 = 260;
	int f_e2 = 360;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("banruo-strike", 1);
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
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 5; }
int power_point(object me) { return 1.0; }
string perform_action_file(string action)
{
	return __DIR__"boruo-strike/" + action;
}

int help(object me)
{
	write(HIC"\n般若掌："NOR"\n");
	write(@HELP

    般若掌是南少林掌法，和龙爪功互备。
    出自佛门《十愿》。

	学习要求：
		站桩功80级
		拈花指50级
		大金刚神掌50级
		内力修为800
HELP
	);
	return 1;
}

