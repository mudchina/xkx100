// taishan-sword.c 泰山剑法
// Last Modified by suncity may 31st,2002
// Modified by Java Sep.1998

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" :"朗月无云",
	"action":  "$N手中$w一晃，向右滑出三步，一招"HIB"「朗月无云」"NOR"，转过身来，身子微矮，$w向$n斜斜刺去",
        "lvl" : 0
]),
([	"skill_name" :"峻岭横空",
	"action":  "$N手中$w圈转，一招"HIC"「峻岭横空」"NOR"去势奇疾，无数剑光刺向$n的$l",
	"lvl" : 10
]),
([	"skill_name" :"来鹤清泉",
	"action": "$N突然腰一弯，挺$w向$n刺去，这一剑力劲剑疾，正是一招"HIC"「来鹤清泉」"NOR"",
	"lvl" : 20
]),
([	"name":    "石关回马",
	"action":  "$N手中$w刷的一声，反手砍向$n，剑势圆润如意："HIY"「石关回马」"NOR"！",
	"lvl" : 30
]),
([	"skill_name" : "泰山十八盘",
	"action":  "$N展开剑势，身随剑走，左边一拐，右边一弯，越转越急。猛地$w剑光暴长，一招"HIM"「泰山十八盘」"NOR"往$n$l刺去",
	"lvl" : 40
]),
([	"skill_name" :"快活三里",
	"action": "$N手臂暴长，手中$w豁豁展开，刷刷两剑，指向$n，正是"GRN"「快活三里」"NOR"",
	"lvl" : 50
]),
([	"skill_name" :  "七星落长空",
	"action":  "$N一招"HIR"「七星落长空」"NOR"挺$w向$n当胸刺去，剑光闪烁，$w发出嗡嗡之声，罩住了$n胸口“膻中”、“神藏”、“灵墟”、“神封”、“步廊”、“幽门”、“通谷”七处大穴",
	"lvl" : 60
]),
([	"skill_name" :"五大夫剑",
	"action":  "$N手中$w倏地刺出，一连五剑，每一剑的剑招皆苍然有古意。招数古朴，内藏奇变，正是"HIW"「五大夫剑」"NOR"",
	"lvl" : 70
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_neili") < 20 )
		return notify_fail("你的内力修为不够，没有办法练泰山剑法。\n");
	if( (string)me->query_skill_mapped("force")!= "panshi-shengong")
		return notify_fail("泰山剑法必须配合磐石神功才能练。\n");
	if( me->query_skill("panshi-shengong", 1) < 20)
		return notify_fail("你的磐石神功修为不够。\n");
//	if( me->query("family/generation") > 12 &&
//		me->query_skill("taishan-sword",1) > 150)
//		return notify_fail("你要修习更高的泰山剑法，必须拜十二代长老为师。\n");
	if( !(ob = me->query_temp("weapon"))
		|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 40 ||(int)me->query("neili") < 30 )
		return notify_fail("你的内力或气不够，没法练习泰山剑法。\n");
	me->receive_damage("qi", 35);
	me->add("neili", -20);
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
	int d_e1 = 5;
	int d_e2 = 30;
	int p_e1 = -25;
	int p_e2 = -5;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 110;
	int m_e2 = 210;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("taishan-sword", 1);
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
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
	return __DIR__"taishan-sword/" + action;
}
int help(object me)
{
	write(HIC"\n泰山剑法："NOR"\n");
	write(@HELP

    泰山剑法为泰山本门剑法。

	学习要求：
		磐石神功20级
		内力修为20
HELP
	);
	return 1;
}

