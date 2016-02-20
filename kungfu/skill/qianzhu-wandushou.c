// qianzhu-wandushou.c 千蛛万毒手
// Last Modified by winder on May. 17 2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N身形一晃而至，一招"HIB"「小鬼勾魂」"NOR"，双掌带着一缕腥风拍向$n的前心",
	"lvl"    : 0,
	"skill_name" : "小鬼勾魂"
]),
([	"action" : "$N身形化做一缕轻烟绕着$n急转，一招"MAG"「天网恢恢」"NOR"，双掌幻出无数掌影罩向$n",
	"lvl"    : 20,
	"skill_name" : "天网恢恢"
]),
([	"action" : "$N大喝一声，一招"BLU"「恶鬼推门」"NOR"，单掌如巨斧开山带着一股腥风猛劈向$n的面门",
	"lvl"    : 30,
	"skill_name" : "恶鬼推门"
]),
([	"action" : "$N一声冷笑，一招"HIR"「灵蛇九转」"NOR"，身形一闪而至，一掌轻轻拍出，手臂宛若无骨，掌到中途竟连变九变，如鬼魅般印向$n的$l",
	"lvl"    : 40,
	"skill_name" : "灵蛇九转"
]),
([	"action" : "$N侧身向前，一招"BLU"「地府阴风」"NOR"，双掌连环拍出，一缕缕彻骨的寒气从掌心透出，将$n周围的空气都凝结了",
	"lvl"    : 50,
	"skill_name" : "地府阴风"
]),
([	"action" : "$N厉叫一声，身形忽的蜷缩如球，飞身撞向$n，一招"YEL "「黄蜂吐刺」"NOR"单掌如剑，直刺$n的心窝",
	"lvl"    : 60,
	"skill_name" : "黄蜂吐刺"
]),
([	"action" : "$N一个急旋，飞身纵起，半空中一式"HIB"「毒龙摆尾」"NOR"，反手击向$n的$l",
	"lvl"    : 70,
	"skill_name" : "毒龙摆尾"
]),
([	"action" : "$N大喝一声，运起五毒神功，一招"RED"「毒火焚身」"NOR"，刹那间全身毛发尽绿，一对碧绿的双爪闪电般的朝$n的$l抓去",
	"lvl"    : 80,
	"skill_name" : "毒火焚身"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="wudu-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练千蛛万毒手必须空手。\n");
	if ((int)me->query_skill("wudu-shengong", 1) < 10)
		return notify_fail("你五毒神功火候不够，无法练千蛛万毒手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练千蛛万毒手");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必须空手才能练习。\n");
	if ((int)me->query("qi") < 60)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 60)
		return notify_fail("你的内力不够练千蛛万毒手。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -30);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("qianzhu-wandushou",1)) > 30 )
		victim->receive_wound("qi", damage_bonus/3);
	if ( victim->query("family/family_name")!= "五毒教" && me->query_skill("wudu-shengong",1)>40)
	{
		switch( random(5) )
		{
			case 0:
				victim->apply_condition("snake_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("snake_poison"));
				break;
			case 1:
				victim->apply_condition("zhizhu_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("zhizhu_poison"));
				break;
			case 2:
				victim->apply_condition("wugong_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("wugong_poison"));
				break;
			case 3:
				victim->apply_condition("xiezi_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("xiezi_poison"));
				break;
			case 4:
				victim->apply_condition("chanchu_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("chanchu_poison"));
				break;
		}
		return HIR "$n只觉得伤处一阵发麻，似乎中毒了。\n" NOR;
	}
}
void skill_improved(object me)
{
	if(random(15) < 1 && me->query("per") > 5)
	{
		tell_object(me, HIR"你忽然觉得体内毒气狂窜，面上顿时罩着一层黑气！\n" NOR );
		me->add("per", -1);
	}
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
	int d_e1 = -55;
	int d_e2 = -20;
	int p_e1 = 10;
	int p_e2 = 35;
	int f_e1 = 190;
	int f_e2 = 290;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("qianzhu-wandushou", 1);
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
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"qianzhu-wandushou/" + action;
}
int help(object me)
{
	write(HIC"\n千蛛万毒手："NOR"\n");
	write(@HELP

    千蛛万毒手是五毒教的独门功夫，有独门修炼方法。靠吸取毒
虫身上的毒气来练成毒功，虽然厉害，但毒气会损坏自己的容貌，
使自己变的丑陋无比。

	学习要求：
		五毒神功20级
		内力100
HELP
	);
	return 1;
}

