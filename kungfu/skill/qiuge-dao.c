// Last Modified by winder on Sep. 12 2001
// qiuge-dao.c 秋歌七刀

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N使一招"GRN"「一叶浮萍归大海」"NOR"，手中$w一摆，身形急进如飞，刀人合一，射向$n的$l！",
	"lvl"    : 0,
	"skill_name" : "一叶浮萍归大海",
]),
([	"action" : "$N$w划出道道弧光，一招"HIB"「人生何处不相逢」"NOR"，刀刀不离$n的$l！",
	"lvl"    : 15,
	"skill_name" : "人生何处不相逢",
]),
([	"action" : "$N手中$w刀光宛如流水，一招"HIY"「衰草斜阳流曲浦」"NOR"，斜斜削向$n的$l",
	"lvl"    : 30,
	"skill_name" : "衰草斜阳流曲浦",
]),
([	"action" : "$N手中$w刀光激荡，一招"YEL"「黄云影日暗长堤」"NOR"，斩向$n！",
	"lvl"    : 45,
	"skill_name" : "黄云影日暗长堤",
]),
([	"action" : "$N手中$w狂舞，刀光团团簇簇，一招"HIR"「红萝花繁知景色」"NOR"，飘飘荡荡向$n落去",
	"lvl"    : 60,
	"skill_name" : "红萝花繁知景色",
]),
([	"action" : "$N手中$w刀气森然，一招"CYN"「白萍香远任依依」"NOR"直劈$n的$l",
	"lvl"    : 75,
	"skill_name" : "白萍香远任依依",
]),
([	"action" : "$N使一招"RED"「缤纷天雨落花红」"NOR"，手中$w摆动，刀光霍霍斩向$n的$l",
	"lvl"    : 90,
	"skill_name" : "缤纷天雨落花红",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_learn(object me)
{ 
	if ((int)me->query("max_neili") < 150)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("honghua-shengong", 1) < 20)
		return notify_fail("你的红花神功火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练秋歌刀法。\n");
	me->receive_damage("qi", 25);
	return 1;
}
string *parry_msg = ({
	"$n使出一招「风摇山竹寒声动」，手中的$W散出丝丝寒气格开了$P的$w。\n",
	"$n手中$W虚晃数刀，一招「淡烟疏雨间斜阳」，刀影中突然爆出一缕光芒从侧面划向$P之必救。\n",
	"$n身形微顿，手中的$W化作一道弧光，一招「雁点青天字一行」，反削$P的$w。\n",
});
string *unarmed_parry_msg = ({
	"$n使出一招「霜凋红叶正晚秋」，手中的$W内力激荡，$N的攻势随波而散。\n",
	"$n身形急退，手中$W上下飞舞，一招「雨过天连青壁润」，封住$N的招式。\n",
	"$n手中的$W挽出朵朵刀花，一招「金花玉萼影浮沉」，游刃有余。\n",
});
string query_parry_msg(object weapon)
{
	if( weapon ) return parry_msg[random(sizeof(parry_msg))];
	else return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
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
	int d_e1 = 45;
	int d_e2 = 25;
	int p_e1 = -5;
	int p_e2 = -25;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 90;
	int m_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("qiuge-dao", 1);
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
		"damage_type" : random(2) ? "擦伤" : "割伤",
	]);
}
int learn_bonus() { return 15; }
int practice_bonus() { return 10; }
int success() { return 15; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"qiuge-dao/" + action;
}
int help(object me)
{
	write(HIM"\n秋歌七刀："NOR"\n");
	write(@HELP

    红花会本门刀法。

	学习要求：
		红花神功20级
		内力修为100
HELP
	);
	return 1;
}
