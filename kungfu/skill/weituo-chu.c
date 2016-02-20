// Last Modified by winder on May. 29 2001
// weituo-chu.c 韦陀杵

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
 
mapping *action = ({
([
	"action" : "$N跃在半空，一招"HIG"「仙鹤展翅入灵山」"NOR"，手中$w已化成无数棍影，令$n眼花缭乱，不知所措，连连倒退",
	"lvl"    : 0,
	"skill_name" : "仙鹤展翅入灵山"
]),
([
	"action" : "$N挺$w将$n的$W架住，顺势一招"HIC"「玉马衔环拜仙宫」"NOR"，$w上下左右飞快搅动，身随棍走，向$n压了下来",
	"lvl"    : 40,
	"skill_name" : "玉马衔环拜仙宫"
]),
([
	"action" : "$N一招"HIY"「鸣鹿踏蹄觅仙草」"NOR"，屈膝俯身，手中$w连点$n下盘，却未等招数用老，猛的一提，向$n的胸腹间戳去",
	"lvl"    : 60,
	"skill_name" : "鸣鹿踏蹄觅仙草"
]),
([
	"action" : "$N突然滚到在地，$n错愕间，一招"HIR"「金鲤跃水潜天池」"NOR"，竟从$n的裆下窜过，更不回头，$w反手扫向$n的$l",
	"lvl"    : 80,
	"skill_name" : "金鲤跃水潜天池"
]),
([
	"action" : "$N一招"HIM"「灵猿献果赴蓬莱」"NOR"，身形如电，绕着$n飞快奔跑，手中$w一招快似一招，刹那间向$n连打出十六棍",
	"lvl"    : 100,
	"skill_name" : "灵猿献果赴蓬莱"
]),
([
	"action" : "$N大踏步上前，劲贯双臂，手中$w大开大阖，呼呼风声中一招"HIC"「飞鹰盘旋扫乾坤」"NOR"扫向$n的腰间",
	"lvl"    : 120,
	"skill_name" : "飞鹰盘旋扫乾坤"
]),
([
	"action" : "$N大喝一声，一招"HIY"「天龙出水腾宇宙」"NOR"，$w脱手飞出，夹着劲风射向$n的前心，随即抢到$n的身后，伸手又把$w抄在手中",
	"lvl"    : 130,
	"skill_name" : "天龙出水腾宇宙"
]),
([
	"action" : "$N双目圆睁，口中默诵真言，一招"HIW"「白象卷云憾天柱」"NOR"，$w似有千斤，缓缓举起，又缓缓向$n的当头砸落",
	"lvl"    : 150,
	"skill_name" : "白象卷云憾天柱"
]),
});

int valid_enable(string usage) { return (usage=="club") || (usage=="parry"); }
int valid_learn(object me)
{
	if ((int)me->query_skill("ranmu-blade",1) > 1 ||
		(int)me->query_skill("riyue-whip",1) > 1 )
		return notify_fail("你如果有达摩老祖的修为，方可同时学习少林三绝技。\n"); 
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 150)
		return notify_fail("你的站桩功火候太浅。\n");
	if ((int)me->query_skill("yijinjing", 1) < 150)
		return notify_fail("你的易筋经内功火候太浅。\n");
	if((int)me->query_skill("zui-club",1) < 150)
		return notify_fail("你的醉棍火候不足，难以领悟韦陀杵。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "club")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 70)
		return notify_fail("你的体力不够练韦陀棍。\n");
	if ((int)me->query("neili") < 70)
		return notify_fail("你的内力不够练韦陀棍。\n");
	me->receive_damage("qi", 60);
	if((int)me->query_skill("weituo-chu",1)> 200)
	{
		me->add("neili",-20);
	}
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
	int d_e2 = -40;
	int p_e1 = -5;
	int p_e2 = 10;
	int f_e1 = 300;
	int f_e2 = 400;
	int m_e1 = 150;
	int m_e2 = 450;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("weituo-chu", 1);
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
	return __DIR__"weituo-chu/" + action;
}
int help(object me)
{
	write(HIC"\n韦陀杵："NOR"\n");
	write(@HELP

    韦陀杵是南少林顶级棍法。
    韦陀杵、日月鞭法和燃木刀法并列为南少林三绝技。
    三绝技不能同时修习。

	学习要求：
		易筋经150级
		站桩功150级
		少林醉棍150级
		内力修为1500
HELP
	);
	return 1;
}

