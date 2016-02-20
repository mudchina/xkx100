//hanxing-bada.c 寒星八打
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$N使一招「陨星乍现」，手中$w疾射$n的$l",
	"force": 20,
	"dodge": 20,
	"damage":90,
	"lvl" : 0,
	"skill_name" : "陨星乍现",
	"damage_type": "刺伤",
	"post_action": (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action":"$N使出「玉隼击空」，双手下沉$w陡的向上飞出直袭$n的$l",
	"force": 25,
	"dodge": 20,
	"damage": 70,
	"lvl" : 10,
	"skill_name": "玉隼击空",
	"damage_type": "刺伤",
	"post_action": (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action":"$N一招「暮霭沉沉」，长袖一挥，手中$w从腋下激射$n的$l",
	"force":35,
	"dodge": 30,
	"damage":40,
	"lvl" : 120,
	"skill_name": "暮霭沉沉",
	"damage_type": "刺伤",
	"post_action": (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action":"$N手中$w一式「长电裂空」，$w幻作一道白光直奔$n的$l",
	"force":80,
	"dodge": 40,
	"damage":90,
	"lvl" : 30,
	"skill_name": "长电裂空",
	"damage_type": "刺伤",
	"post_action": (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action":"$N纵身一跃，手中$w一招「苍龙入海」射向$n的$l",
	"force":120,
	"dodge": 45,
	"damage":170,
	"lvl" : 40,
	"skill_name":"苍龙入海",
	"damage_type": "刺伤",
	"post_action": (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action":"$N手扣$w,凭空一指，一招「巴山夜雨」洒向$n的$l",
	"force":160,
	"dodge": 20,
	"damage":50,
	"lvl" : 50,
	"skill_name": "巴山夜雨",
	"damage_type": "刺伤",
	"post_action": (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action":"$N身形一晃，使一招「彗星横空」$w脱手而出，袭向$n的$l",
	"force":220,
	"dodge": 50,
	"damage":60,
	"lvl" : 60,
	"skill_name": "彗星横空",
	"damage_type": "刺伤",
	"post_action": (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action":"$N身形一转手中$w使一招「后弈射日」画出一道光弧袭向$n的$l",
	"force":135,
	"dodge": 55,
	"damage":140,
	"lvl" : 100,
	"skill_name": "后羿射日",
	"damage_type": "刺伤",
	"post_action": (: call_other, WEAPON_D, "throw_weapon" :),
]),
});

int valid_enable(string usage) { return usage=="throwing" || usage=="parry"; }
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_neili") < 100 )
		return notify_fail("你的内力不够，没有办法练寒星八打。\n");
	if ((int)me->query_skill("honghua-shengong", 1) < 50)
                return notify_fail("你的红花神功火候不够，没法学寒星八打!\n");         
        if( !(ob = me->query_temp("weapon"))
		|| (string)ob->query("skill_type") != "throwing" )
		return notify_fail("你必须先找一些飞镖之类的东西才能练暗器。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 30 ||(int)me->query("neili") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习寒星八打。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -3);
//	write("你按着所学练了一遍寒星八打。\n");
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
	int i, level;
	level = (int) me->query_skill("hanxing-bada",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 5; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"hanxing-bada/" + action;
}

int help(object me)
{
	write(HIC"\n寒星八打："NOR"\n");
	write(@HELP

    红花会赵半山的绝技。

	学习要求：
		红花心法50级
		内力修为100
HELP
	);
	return 1;
}

