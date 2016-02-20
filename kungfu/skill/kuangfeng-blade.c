//kuangfeng-blade 狂风刀法
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N手中$w轻挥，一招"+HIW"「风平浪静」"NOR+"，看似平缓实则迅速地向$n的$l撩去",
	"lvl" : 0,
	"skill_name" : "风平浪静",
]),
([	"action" : "$N一招"+HIW"「风起云涌」"NOR+"，右脚一点，$w寒光闪闪，快速涌$n的$l",
	"lvl" : 10,
	"skill_name" : "风起云涌",
]),
([	"action" : "$N一招"+HIY"「风卷残云」"NOR+"，手臂一抡，刀锋一卷，自上而下斩向$n",
	"lvl" : 20,
	"skill_name" : "风卷残云",
]),
([	"action" : "$N一招"+HIC"「风流云散」"NOR+"，侧身而退，$w却在胸前划出一道圆弧，横劈$n的$l",
	"lvl" : 32,
	"skill_name" : "风流云散",
]),
([	"action" : "$N侧身滑步而上，一招"+HIW"「风声鹤唳」"NOR+"，欺至$n身前，$w猛砍$n的$l",
	"lvl" : 45,
	"skill_name" : "风声鹤唳",
]),
([	"action" : "$N快速挥舞$w，使出一招"+RED"「风中残烛」"NOR+"，幻起一片刀花罩向$n的$l",
	"lvl" : 58,
	"skill_name" : "风中残烛",
]),
([	"action" : "$N一招"+HIC"「风刀霜剑」"NOR+"，只见漫天刀光闪烁，重重刀影向$n的全身涌去",
	"lvl" : 71,
	"skill_name" : "风刀霜剑",
]),
([	"action" : "$N使一招"+HIW"「风驰电掣」"NOR+"，$w舞出阵阵光影向$n的$l涌去",
	"lvl" : 86,
	"skill_name" : "风驰电掣",
]),
([	"action" : "$N一招"+HIB"「风雨飘摇」"NOR+"，$w刀光闪烁不定，似幻似真地逼$n的$l",
	"lvl" : 101,
	"skill_name" : "风雨飘摇",
]),
([	"action" : "$N挪步小退，一招"+HIC"「风花雪月」"NOR+"，手中$w轻描淡写地挥出一刀，随即又“唰唰”连劈出两刀，后发先至，洒向$n的$l",
	"lvl" : 120,
	"skill_name" : "风花雪月",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; } 
int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");
	if ((int)me->query("max_neili") < 300)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("force", 1) < 60)
		return notify_fail("你的内功心法火候太浅。\n");
	if ((int)me->query_skill("dodge", 1) < 60)
		return notify_fail("你的轻功火候太浅。\n");
	if ((int)me->query_dex() < 25)
		return notify_fail("你的身法还不够灵活。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力不够练狂风刀法。\n");
	me->receive_damage("qi", 25);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
	if(level >= action[i]["lvl"])
		return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 60;
	int d_e2 = 35;
	int p_e1 = 5;
	int p_e2 = -10;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 30;
	int m_e2 = 140;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("kuangfeng-blade", 1);
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
		"damage_type" : "割伤",
	]);
}
int learn_bonus() { return 30; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"kuangfeng-blade/" + action;
}
int help(object me)
{
	write(HIC"\n狂风刀法："NOR"\n");
	write(@HELP

    田伯光的快刀。

	学习要求：
		基本内功60级
		基本轻功60级
		后天身法25以上
		内力300
HELP
	);
	return 1;
}

