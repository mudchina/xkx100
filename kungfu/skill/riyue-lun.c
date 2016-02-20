// riyue-lun.c 日月轮法
// Last Modified by sir 10.23.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N使一招"GRN"「破竹势」"NOR"，抡起手中的$w向$n的$l砸去",
	"skill_name" : "破竹势",
	"lvl" : 0
]),
([	"action" : "$N使一招"BLU"「隐山谷势」"NOR"，双肩一沉，舞动手中$w向$n的$l横扫",
	"skill_name" : "隐山谷势",
	"lvl" : 8
]),
([	"action" : "$N使一招"MAG"「隐微势」"NOR"，就地一滚，手中自下而上撩向$n的$l",
	"skill_name" : "隐微势",
	"lvl" : 16
]),
([	"action" : "$N使一招"RED"「擒纵势」"NOR"，身形起伏之际$w扫向$n的$l",
	"skill_name" : "擒纵势",
	"lvl" : 24
]),
([	"action" : "$N使一招"YEL"「圆满势」"NOR"，$w如离弦之箭般直捣$n的$l",
	"skill_name" : "圆满势",
	"lvl" : 32
]),
([	"action" : "$N跃入半空，使一招"HIC"「月重辉势」"NOR"，高举$w敲向$n的$l",
	"skill_name" : "月重辉势",
	"lvl" : 40
]),
([	"action" : "$N使一招"HIW"「捉月势」"NOR"，斜举手中$w击向$n的$l",
	"skill_name" : "捉月势",
	"lvl" : 48
]),
([	"action" : "$N提一口真气，使出"HIR"「显吉祥」"NOR"，$w扫向$n的头部",
	"skill_name" : "显吉祥",
	"lvl" : 56
]),
});

int valid_enable(string usage) { return usage == "hammer" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("longxiang", 1) < 20)
		return notify_fail("你的龙象般若功火候太浅。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "hammer")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 50 )
		return notify_fail("你的内力或气不够,练不了日月轮法。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -40);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	object my_w, victim_w;
	object piece;
	victim_w = victim->query_temp("weapon");
	my_w = victim->query_temp("weapon");

//	if( me->query("dex") < 20 || me->query("str") < 20 )

	if (victim->query_temp("weapon") || victim->query_temp("secondary_weapon"))
	{
		if( (int)(me->query_skill("riyue-lun", 1)) < 20 )
			return HIW"一阵兵刃相撞的声音过后，对方兵器居然完好无损。\n"NOR;
		if( random(victim->query_temp("apply/damage")) < random(me->query_skill("riyue-lun", 1)/3 ) )
		{
			if (objectp(my_w = me->query_temp("weapon")) &&
				((string)my_w->query("id") == "fa lun" 
                                  ||(string)my_w->query("id")=="yin lun"
                                   ||(string)my_w->query("id")=="jin lun" ) 
                                   && my_w->query("ownmake") != 1)
			{
				seteuid(getuid());
				piece = new("/clone/misc/piece");
				piece->set_name(victim_w->query("name") + "的碎片",({victim_w->query("id"),"piece"}));
        piece->move(environment(victim));
				piece->set("long", "一堆破碎物事，好象是兵器碎片。\n");
				destruct(victim_w);
				return HIB "你听到「叮当」一声兵刃破碎的声音，兵器碎片溅了一地！\n" NOR;
			}
			else return HIR"可惜你没用法轮，没法砸碎对方兵器！\n"NOR;
		}
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
	int d_e1 = 20;
	int d_e2 = 40;
	int p_e1 = -40;
	int p_e2 = -20;
	int f_e1 = 300;
	int f_e2 = 400;
	int m_e1 = 100;
	int m_e2 = 250;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("riyue-lun", 1);
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
int success() { return 15; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n日月轮法："NOR"\n");
	write(@HELP

    日月轮法为金轮法王的武功，是雪山寺极为霸道的功夫。

	学习要求：
		龙相般若功20级
		内力100
HELP
	);
	return 1;
}

