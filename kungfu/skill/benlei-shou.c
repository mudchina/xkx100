// Last Modified by winder on Sep. 12 2001
// benlei-shou.c 奔雷手

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"CYN"「行云流水」"NOR"，双掌一翻，一股劲力缓缓推向$n的$l",
	"lvl"   : 0,
	"skill_name" : "行云流水"
]),
([	"action" : "$N一式"BLU"「披云戴月」"NOR"，两掌一并，疾向$n的$l戳去",
	"lvl"   : 10,
	"skill_name" : "披云戴月"
]),
([	"action" : "$N使一式"MAG"「翻云赴雨」"NOR"，左掌微拂，右掌乍伸乍合，猛地插往$n的$l",
	"lvl"   : 20,
	"skill_name" : "翻云覆雨"
]),
([	"action" : "$N掌心隐隐发红，一式"YEL"「排山倒海」"NOR"，掌力如海水般向$n击去",
	"lvl"   : 30,
	"skill_name" : "排山倒海"
]),
([	"action" : "$N身形往上一纵，使出一式"HIB"「乌云敝日」"NOR"，双掌一摊，笔直地向$n的$l拍去",
	"lvl"   : 40,
	"skill_name" : "乌云敝日"
]),
([	"action" : "$N身形一变，使一式"HIB"「重云深锁」"NOR"，双掌带着萧刹的劲气，猛地击往$n的$l",
	"lvl"   : 50,
	"skill_name" : "重云深锁"
]),
([	"action" : "$N使一式"HIW"「撕天排云」"NOR"，左掌凝重，右掌轻盈，同时向$n的$l击去",
	"lvl"   : 60,
	"skill_name" : "撕天排云"
]),
([	"action" : "$N突地一招"HIM"「云海波涛」"NOR"，双掌挟着一阵风雷之势，猛地劈往$n的$l",
	"lvl"   : 70,
	"skill_name" : "云海波涛"
]),
([	"action" : "$N一式"HIY"「变云无定」"NOR"，双掌缦妙地一阵挥舞，不觉已击到$n的$l上",
	"lvl"   : 80,
	"skill_name" : "变云无定"
]),
([	"action" : "$N一式"HIR"「殃云天降」"NOR"，身形向上窜起丈余，双掌一高一低，看似简单，却令$n无法躲闪",
	"lvl"   : 90,
	"skill_name" : "殃云天降"
]),
([	"action" : "$N一式"HIW"「云莱仙境」"NOR"，身形凝立不动，两掌间绽出万道霞光，将$n紧紧罩住",
	"lvl"   : 100,
	"skill_name" : "云莱仙境"
])
});
int valid_enable(string usage) { return usage=="hand" || usage=="parry" ; }
int valid_combine(string combo) { return combo=="baihua-cuoquan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练奔雷手必须空手。\n");
	if ((int)me->query_skill("honghua-shengong", 1) < 20)
		return notify_fail("你的红花神功火候不够，无法学奔雷手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练奔雷手。\n");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练奔雷手。\n");
	me->receive_damage("qi", 35);
	me->add("neili", -25);
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
	int d_e2 = -20;
	int p_e1 = 10;
	int p_e2 = 40;
	int f_e1 = 180;
	int f_e2 = 280;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("benlei-shou", 1);
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
int success() { return 10; }
int power_point(object me) { return 1.0; }
string perform_action_file(string action)
{
	return __DIR__"benlei-shou/" + action;
}

int help(object me)
{
	write(HIM"\n奔雷手："NOR"\n");
	write(@HELP

    红花会四当家文泰来的看门武功。

	学习要求：
		红花神功20级
		内力修为100
HELP
	);
	return 1;
}
