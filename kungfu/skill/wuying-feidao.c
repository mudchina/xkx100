// Last Modified by winder on Sep. 12 2001
// wuying-feidao.c 无影飞刀

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([      "action": "$N双手一晃，手中的$w如一条银蛇般飞向$n的$l",
        "force" : 20,
        "dodge" : -20,
        "damage": 90,
        "damage_type": "刺伤",
        "post_action": (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action": "$N右手一抖，$w发出刺耳的破空声直射$n的$l",
        "force" : 120,
        "dodge" : -30,
        "damage": 190,
        "damage_type": "刺伤",
        "post_action": (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action": "$N手指微动，$w斜斜的飞向$n的$l",
        "force" : 220,
        "dodge" : -20,
        "damage": 290,
        "damage_type": "刺伤",
        "post_action": (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action": "$N力发肩肘，右手一甩，手中的$w化作一道弧光射向$n的$l",
        "force" : 320,
        "dodge" : -40,
        "damage": 390,
        "damage_type": "刺伤",
        "post_action": (: call_other, WEAPON_D, "throw_weapon" :),
]),
});

int valid_enable(string usage) { return usage=="throwing" ; }
int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不够，没有办法练无影飞刀。\n");
        if( !(ob = me->query_temp("weapon")) || 
		(string)ob->query("skill_type") != "throwing" )
                return notify_fail("你必须先找一些暗器才能练无影飞刀。\n");
	if ((int)me->query_skill("honghua-shengong", 1) < 50)
		return notify_fail("你的红花神功火候不够，无法学无影飞刀。\n");

        return 1;
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 || (int)me->query("neili") < 50 )
                return notify_fail("你的内力或气不够，没办法练习无影飞刀。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -30);
  //      write("你按著所学练了一遍无影飞刀。\n");
        return 1;
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
        return  __DIR__"wuying-feidao/" + action;
}
 
int help(object me)
{
	write(HIM"\n无影飞刀："NOR"\n");
	write(@HELP

    无影飞刀为神刀骆元通的家传功夫。骆元通之女骆冰便是
红花会的文四奶奶。

	学习要求：
		红花神功50级
		内力修为500
HELP
	);
	return 1;
}
