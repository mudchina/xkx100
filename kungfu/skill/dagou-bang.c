// dagou-bang.c 打狗棒法
// Last Modified by sir 10.22.2001
// write by Xiang

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$N使出一招"HIG"「棒打双犬」"NOR"，手中$w化作两道青光砸向$n的$l",
	"lvl"        : 10,
	"skill_name" : "棒打双犬"
]),
([	"action": "$N手中$w左右晃动，一招"HIG"「拨草寻蛇」"NOR"向$n的$l攻去",
	"lvl"        : 20,
	"skill_name" : "拨草寻蛇"
]),
([	"action": "$N举起$w，居高临下使一招"HIG"「打草惊蛇」"NOR"敲向$n的$l",
	"lvl"        : 30,
	"skill_name" : "打草惊蛇"
]),
([	"action": "$N施出"HIG"「拨狗朝天」"NOR"，$w由下往上向$n撩去",
	"lvl"        : 40,
	"skill_name" : "拨狗朝天"
]),
([	"action":"$N眼中射出一道青芒，手中绿玉棒使出"HIR"「天下无狗」"NOR"，劈天盖地劈落",
	"lvl"        : 50,
	"skill_name" : "天下无狗"
]),
});

int valid_enable(string usage) { return (usage=="stick") || (usage=="parry"); }

int valid_learn(object me)
{
	if ((int)me->query_skill("huntian-qigong", 1) < 50)
		return notify_fail("你的混天气功的火候还不够。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力不够。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "stick")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 50 )
		return notify_fail("你的内力或气不够练打狗棒法。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -40);
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
	int p_e1 = -10;
	int p_e2 = 10;
	int f_e1 = 300;
	int f_e2 = 400;
	int m_e1 = 100;
	int m_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("dagou-bang", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 5; }
int power_point() { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"dagou-bang/" + action;
}

int help(object me)
{
	write(HIC"\n打狗棒法："NOR"\n");
	write(@HELP

    三十六路打狗棒法是丐帮开帮祖师爷所创，历来是前任帮主传
后任帮主，决不传给第二个人。丐帮第三任帮主的武功尤胜开帮祖
师，他在这路棒法中更加入无数奥妙变化。数百年来，丐帮逢到危
难关头，帮主亲自出马，往往便仗这打狗棒法除奸杀敌，镇慑群邪。
    打狗棒法名字虽然陋俗，但变化精微，招术奇妙，实是古往今
来武学中第一等特异的功夫，卓然自成一家，与各门派的功夫均无
牵涉。单学招数，若是不明『绊、劈、缠、戳、挑、引、封、转』
八字口诀，那是一点无用。每句口诀，须与每个招数相配，威力无
俦。为丐帮帮主历代相传的镇帮之宝。

	学习要求：
		混天气功50级
		内力200
HELP
	);
	return 1;
}

