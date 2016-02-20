// Last Modified by Winder on May. 29 2001
// mohe-finger.c 摩诃指 和散花掌互备 截至佛经中“以慈度心，摩诃无量”一句。

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N左掌一摆，护在胸前，接着右手食指画出一个"HIB"「以」"NOR"字，轻轻点向$n$l",
	"lvl"   : 0,
	"skill_name" : "以"
]),
([	"action" : "$N左手食指缓缓画了个"HIM"「慈」"NOR"字，跟着手指微曲，以字为中心，对着$n一弹",
	"lvl"   : 20,
	"skill_name" : "慈"
]),
([	"action" : "$N双掌合十，身体微欠，双指画一"HIG"「度」"NOR"字，那撇捺两画有如两条柳枝般，抚向$n$l",
	"lvl"   : 30,
	"skill_name" : "度"
]),
([	"action" : "$N双手小指向$n挥动，连点三点，接着双指并拢，一招斜划，拼成了一个"HIR"「心」"NOR"字",
	"lvl"   : 50,
	"skill_name" : "心"
]),
([	"action" : "$N连连出招，幻出漫天指影，仿佛间竟然形成了一个"HIC"「摩」"NOR"字，照着$n激射而去，越来越快",
	"lvl"   : 60,
	"skill_name" : "摩"
]),
([	"action" : "$N右手食指伸出，在空中写出个"HIW"「诃」"NOR"字来，形如狂草，向着$n最后一提时竟飞射出一道青气",
	"lvl"   : 70,
	"skill_name" : "诃"
]),
([	"action" : "只见$N手指横竖连划，将指力在空中凝结不散，形成一个"CYN"「无」"NOR"字，对着$n当胸压下",
	"lvl"   : 80,
	"skill_name" : "无"
]),
([	"action" : "$N双拳并拢，夹出一个"HIY"「量」"NOR"字来，合力击向$n，突然下半招一变，右手一指破空击出",
	"lvl"   : 100,
	"skill_name" : "量"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo){ return combo=="sanhua-strike"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练摩诃指必须空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 30)
		return notify_fail("你的站桩功火候不够，无法学摩诃指。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力太弱，无法练摩诃指。\n");
	if (me->query_skill("weituo-strike", 1) < 30)
		return notify_fail("你的韦陀掌火候不够，无法学摩诃指。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练摩诃指。\n");
	me->receive_damage("qi", 20);
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
	int p_e1 = -20;
	int p_e2 = 0;
	int f_e1 = 100;
	int f_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("mohe-finger", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	 return __DIR__"mohe-finger/" + action;
}

int help(object me)
{
	write(HIC"\n摩诃指："NOR"\n");
	write(@HELP

    摩诃指是南少林入门指法，和散花掌互备。出自佛经中“以慈度心，摩诃无量”。

	学习要求：
		站桩功30级
		韦陀掌30级
		内力修为200
HELP
	);
	return 1;
}

