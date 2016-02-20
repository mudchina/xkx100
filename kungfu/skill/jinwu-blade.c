// Last Modified by winder on Jul. 9 2001
// jinwu-blade.c 金乌刀法

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *mjj = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action" : "$N手中$w直劈，一招"+(mjj[random(13)])+"「开门揖盗」"NOR"，挟着劲风万丈之式，向$n当头而下",
	"lvl"    : 0,
	"skill_name" : "开门揖盗"
]),
([	"action" : "$N一招"+(mjj[random(13)])+"「梅雪逢夏」"NOR"，卷起一片光幕，只见刀光漫天，向$n疾卷而去",
	"lvl"    : 10,
	"skill_name" : "梅雪逢夏"
]),
([	"action" : "$N横刀直挥，一招"+(mjj[random(13)])+"「汉将当关」"NOR"，刀身疾下，拢起一阵劲飙，向$n$l劈去",
	"lvl"    : 20,
	"skill_name" : "汉将当关"
]),
([	"action" : "$N一招"+(mjj[random(13)])+"「赤日金鼓」"NOR"，$w左右连劈六刀，一阵金芒自刀上疾射而出，映的$n\n双眼紧闭，$N乘机趋步上前，挥刀力斩$n$l",
	"lvl"    : 30,
	"skill_name" : "赤日金鼓"
]),
([	"action" : "$N手中$w一沉，一招"+(mjj[random(13)])+"「千钧压驼」"NOR"，$w看似沉滞不堪，实则似缓实快，自下挽了一个刀花，\n直劈$n$l",
	"lvl"    : 40,
	"skill_name" : "千钧压驼"
]),
([	"action" : "$N将$w往后一带，使出一招"+(mjj[random(13)])+"「大海沉沙」"NOR"，$w顿时消失得无影无踪，$n正惊疑间，\n只见刀光一闪，$w已迅如闪电般斩往$l",
	"lvl"    : 50,
	"skill_name" : "大海沉沙"
]),
([	"action" : "$N一招"+(mjj[random(13)])+"「鲍鱼之肆」"NOR"，挥舞$w狂劈十八刀，看似混乱不堪，实则刀刀劈向$n要害",
	"lvl"    : 60,
	"skill_name" : "鲍鱼之肆"
]),
([	"action" : "$N踏步上前，使出"+(mjj[random(13)])+"「赤日炎炎」"NOR"，手中$w倒提横挥，化成一簇簇烈焰，向$n劈头盖脸的斩去",
	"lvl"    : 70,
	"skill_name" : "赤日炎炎"
]),
([	"action" : "$N一招"+(mjj[random(13)])+"「旁敲侧击」"NOR"，手中$w划出一个大平十字，向$n纵横劈去",
	"lvl"    : 80,
	"skill_name" : "旁敲侧击"
]),
([	"action" : "$N反转刀尖对准自己，一招"+(mjj[random(13)])+"「长者折枝」"NOR"，全身一个翻滚，$w向$n拦腰斩去",
	"lvl"    : 90,
	"skill_name" : "长者折枝"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_neili") < 500 )
		return notify_fail("你的内力不够，没有办法练金乌刀法。\n"); 
	if( (int)me->query_skill("xueshan-sword",1) < 80)
		return notify_fail("金乌刀法必须有雪山剑法为根底才能练习。\n");
	if( (int)me->query_skill("bingxue-xinfa",1) < 50)
		return notify_fail("金乌刀法必须有冰雪心法为根底才能练习。\n");
	if( !(ob = me->query_temp("weapon")) ||
		(string)ob->query("skill_type") != "blade" )
	return notify_fail("你必须先找一把刀才能练刀法。\n");

	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 20 || (int)me->query("neili") < 10 )
		return notify_fail("你的内力或气不够，没办法练习金乌刀法。\n");
	me->receive_damage("qi", 10);
	me->add("neili", -5);
//	write("你按着所学练了一遍金乌刀法。\n");
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
	int d_e2 = 15;
	int p_e1 = -15;
	int p_e2 = -30;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 150;
	int m_e2 = 260;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("jinwu-blade", 1);
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
		"damage_type" : random(2) ? "割伤" : "擦伤",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"jinwu-blade/" + action;
}

int help(object me)
{
        write(HIC"\n金乌刀法："NOR"\n");
        write(@HELP

    金乌刀法为雪山派掌门夫人史小翠所创。史小翠与其夫白自在
斗气，创此刀法专为克制雪山剑法，并传授给石破天，试图籍石破
天打败白万剑之势，以压过乃夫的气焰，出一口自己数十年被欺压
的闷气。此刀法专为克制雪山剑法而创，与雪山剑法联手，却能尽
补其漏失，威力无俦。

        学习要求：
                冰雪心法50级
                雪山剑法80级
                内力100
HELP
        );
        return 1;
}

