// yunu-sword.c 玉女金针十三剑
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" : "穿针引线",
	"action":  "$N使一招"HIM"「穿针引线」"NOR"，脚踏中宫，手中$w直指$n$l",
	"lvl" : 0
]),
([	"skill_name" : "天衣无缝",
	"action":  "$N剑随身转，一招"HIB"「天衣无缝」"NOR"，撒出一片剑影，罩向$n的$l",
	"lvl" : 10
]),
([	"skill_name" : "夜绣鸳鸯",
	"action":  "$N舞动$w，使出一招"HIG"「夜绣鸳鸯」"NOR"剑光忽左忽右，闪烁不定，直刺$n的$l",
	"lvl" : 20
]),
([	"skill_name" : "织女穿梭",
	"action":  "$N一声娇喝，祭出"HIW"「织女穿梭」"NOR"，手中$w化为一道弧光，射向$n的$l",
	"lvl" : 30
]),
([	"skill_name" :  "小鸟依人",
	"action":  "$N忽然蹂身直上，一招"HIR"「小鸟依人」"NOR"，手中$w自下往上刺向$n的$l",
	"lvl" : 40
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
int valid_learn(object me)
{
	object ob;
	if( (string)me->query("gender") != "女性" )
		return notify_fail("玉女金针十三剑是只有女子才能练的武功。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力不够，没有办法练玉女金针十三剑。\n") ;
	if( (string)me->query_skill_mapped("force")!= "zixia-shengong")
		return notify_fail("玉女金针十三剑必须配合紫霞神功才能练。\n");
	if( !(ob = me->query_temp("weapon"))
		|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 35 || (int)me->query("neili") < 15 )
		return notify_fail("你的内力或气不够，没有办法练习玉女金针十三剑。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -15);
//	write("你按著所学练了一遍玉女金针十三剑。\n");
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
	int d_e1 = 15;
	int d_e2 = 40;
	int p_e1 = -10;
	int p_e2 = 5;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 80;
	int m_e2 = 170;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("yunu-sword", 1);
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
		"damage_type" : random(2) ? "劈伤" : "刺伤",
	]);
}
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
	return __DIR__"yunu-sword/" + action;
}
int help(object me)
{
	write(HIC"\n玉女金针十三剑："NOR"\n");
	write(@HELP

    玉女金针十三剑是岳夫人宁中则传给女弟子的华山派剑法。

	学习要求：
		女性
		紫霞神功
		内力50
HELP
	);
	return 1;
}

