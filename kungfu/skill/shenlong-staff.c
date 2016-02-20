// shenlong-staff 神龙杖法
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一立一个翻身，一式「乌龙盘树」，杖尾霍地横卷过来，扫击$n的$l",
        "lvl"    : 0,
        "skill_name" : "乌龙盘树"
]),
([	"action" : "$N大喝一声，手中$w化成一片银光，一招「夜战八方」，向$n的$l猛扫过去",
        "lvl"    : 10,
        "skill_name" : "夜战八方"
]),
([	"action" : "$N蓦然一声长啸，一招「流星赶月」，手中$w幻成三道白光，分袭$n胸腹要穴",
        "lvl"    : 15,
        "skill_name" : "流星赶月"
]),
([	"action" : "$N身形陡然飞起三丈多，一式「千斤压顶」，手中$w带着呼啸破空声从天而降",
        "lvl"    : 20,
        "skill_name" : "千斤压顶"
]),
([      "action" : "$N趁着$n脚步未稳，撵杖向前进招，骤然一指，杖尾起处，「毒蛇寻穴」，直取白$n丹田下“血海穴”",
        "lvl"    : 25,
        "skill_name" : "毒蛇寻穴"
]),
([      "action" : "$N杖头一转，迅即一招「横扫千军」，刚猛迅捷，如雷霆疾发向$n下三路猛扫过去",
        "lvl"    : 30,
        "skill_name" : "横扫千军"
]),
([	"action" : "陡然间，$N手中杖光华大盛，$w宛似「蛟龙出海」，登时把$n圈在当中",
        "lvl"    : 35,
        "skill_name" : "蛟龙出海"
]),
([	"action" : "$N手中$w盘旋，左右飞舞宛如银龙入海，十荡十决，一式「横云断峰」向$n的$l横扫过去",
        "lvl"    : 40,
        "skill_name" : "横云断峰",
]),
([      "action" : "$N高高跃起，挥舞着手中的$w一招「一柱擎天」犹如一条黑蟒般向$n当头直落而下",
        "lvl"    : 50,
        "skill_name" : "一柱擎天",
]),
([	"action" : "$N一声暴喝「蛟龙横空」！将$w由下往上一撩，双手握住$w尾，转身猛得横扫打向$n的$l",
        "lvl"    : 60,
        "skill_name" : "蛟龙横空",
]),
([      "action" : "$N忽然招数一变，使出「灵蛇出洞」，杖法显得灵巧之极，手中$w化作条条蛇影缠向$n",
        "lvl"    : 70,
        "skill_name" : "灵蛇出洞"
]),
([      "action" : "$N以杖代剑，$w中宫直进，夹着一阵狂风刺出，逼向$n的$l，正是招「长蛟化龙」",
        "lvl"    : 80,
        "skill_name" : "长蛟化龙"
]),
([	"action" : "$N一式「一杖定海」，当头一$w击将下来，杖头未至，一股风已将$n逼得难以喘气",
        "lvl"    : 90,
        "skill_name" : "一杖定海"
]),
([	"action" : "$N变招「群蛇狂舞」，$w扫出一道道灰影从四面八方围向$n，要将$n淹没吞食",
        "lvl"    : 100,
        "skill_name" : "群蛇狂舞"
]),
});

int valid_enable(string usage) { return usage=="staff" || usage=="parry"; }
int valid_learn(object me)
{
	object weapon;

	if (objectp(weapon = me->query_temp("weapon")))
	if ((string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query_skill("dulong-dafa", 1) < 30)
		return notify_fail("你的毒龙大法火候不够，无法学神龙杖法。\n");
	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("你的基本内功火候不够，无法学神龙杖法。\n");
	if ((int)me->query_skill("shenlong-bashi", 1) < 30)
		return notify_fail("你的神龙八式火候不够，无法学神龙杖法。\n");
	if ((int)me->query_skill("dulong-dafa",1) <(int)me->query_skill("shenlong-staff",1))
		return notify_fail("你的毒龙大法火候不够，无法继续学神龙杖法。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 60)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练神龙杖法。\n");
	me->receive_damage("qi", 55);
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
	int d_e1 = -60;
	int d_e2 = -30;
	int p_e1 = 0;
	int p_e2 = 30;
	int f_e1 = 300;
	int f_e2 = 400;
	int m_e1 = 220;
	int m_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("shenlong-staff", 1);
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
		"damage_type" : "挫伤",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"shenlong-staff/" + action;
}
int help(object me)
{
	write(HIC"\n神龙杖法："NOR"\n");
	write(@HELP

    神龙杖法是神龙岛杖法，相当狠辣。

	学习要求：
		基本内功30级
		毒龙大法30级且不低于神龙杖法的级别
		神龙八式30级
		内力100
HELP
	);
	return 1;
}

