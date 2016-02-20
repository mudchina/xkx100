// tangshi-jian.c 唐诗剑法
// Last Modified by winder on Mar. 10 2000
// Edited by fandog, 02/13/2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N手中$w自左上方斜劈向下，跟着向后挺剑刺出，一招"HIC"「孤鸿海上来，池潢不敢顾」"NOR"，手中$w更不回头，一剑剑点向$n的$l。",
	"lvl" : 0,
	"skill_name" : "孤鸿海上来，池潢不敢顾"
]),
([	"action" : "$N退了两步，$w大开大阖，一声吆喝，横削三剑，一招"HIB"「哥翁喊上来，是横不敢过」"NOR"直刺$n的$l",
	"lvl" : 10,
	"skill_name"  : "哥翁喊上来，是横不敢过"
]),
([	"action" : "突然间嗤嗤嗤三声，$N向$n连刺三剑，一式"HIG"「俯听闻惊风，连山若波涛」"NOR"，剑刃在$n的$l边堪堪掠过，$n只觉$l凉飕飕地，大吃一惊，急忙倒退。",
	"lvl" : 20,
	"skill_name" : "俯听闻惊风，连山若波涛"
]),
([	"action" : "$N手中$w递出，一个虚招指向$n的左肩，反手却使出一式"HIY"「落日照大旗，马鸣风萧萧」"NOR"，由下而上$w疾刺$n的$l",
	"lvl" : 30,
	"skill_name" :"落日照大旗，马鸣风萧萧"
]),
([	"action" : "$N一招"HIW"「举头望明月，低头思故乡」"NOR"，身子前倾，忽地回剑斜削，手中$w平平地向$n的$l挥去",
	"lvl" : 40,
	"skill_name" : "举头望明月，低头思故乡"
]),
([	"action" : "$N上身往左侧一拧，一招"BLU"「长安一片月，万户捣衣声」"NOR"，右手$w反手向$n的$l挥去",
	"lvl" : 50,
	"skill_name" : "长安一片月，万户捣衣声"
]),
([	"action" : "$N左一招"MAG"「万国仰宗周」"NOR"，右一招"HIM"「衣冠拜冕旒」"NOR"，剑锋平指，一气呵成横扫$n的$l",
	"lvl" : 60,
	"skill_name" : "万国仰宗周 衣冠拜冕旒"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 10 )
		return notify_fail("你的内力或气不够练唐诗剑法。\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = 40;
	int d_e2 = 60;
	int p_e1 = 10;
	int p_e2 = 30;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 10;
	int m_e2 = 110;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("tangshi-jian", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n唐诗剑法："NOR"\n");
	write(@HELP

    铁骨墨萼梅念笙传给他三个徒弟五云手万震山，陆地神龙言达
平，铁锁横江戚长发的剑法。

	学习要求：
		内力100
HELP
	);
	return 1;
}
