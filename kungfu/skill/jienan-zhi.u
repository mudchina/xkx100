//【劫难指】 jienan-zhi.c
// dream...12/18/96
//menpai skill

inherit SKILL;

mapping *action = ({
	([	"action":		"$N右手食指和中指并拢，一前一后戳向$n的$l",
		"dodge":		-5,
		"parry":		-5,
		"force":		70,
		"damage_type":	"刺伤",
                        "weapon":		"$N的右手食中指",
	]),
	([	"action":		"$N左掌虚托，右指穿腋疾出，指向$n的$l",
		"dodge":		-5,
		"parry":		-5,
		"force":		80,
		"damage_type":	"刺伤",		
                        "weapon":		"$N的右手食指",
	]),
	([	"action":		"只见$N侧身抬臂，右指划了个半圈，击向$n的$l",
		"dodge":		-5,
		"parry":		-5,
		"force":		60,
		"damage_type":	"刺伤",
                        "weapon":		"$N的右手食指",
	]),
	([	"action":		"$N身形微侧，右手便拿$n手腕，跟着左手后发先至，攻向$n的$l",
		"dodge":		-5,
		"parry":		-5,
		"force":		120,
		"damage_type":	"刺伤",
                        "weapon":		"$N的左手食指", 
	]),
            ([	"action":		"只见$N身形不动，只是稍稍抬起右手食指，等着$n的$l自行撞上来",
		"dodge":		-5,
		"parry":		-5,
		"force":		60,
		"damage_type":	"刺伤",
                        "weapon":		"$N的右手食指",
	]),
            ([	"action":		"忽见$N一纵身欺近$n身旁，伸出左手拇指和食指朝$n的$l扣来",
		"dodge":		-5,
		"parry":		-5,
		"force":		50,
		"damage_type":	"刺伤",
                        "weapon":		"$N的左手拇指和食指",
	]),
});

int valid_learn(object me)
{
	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练劫难指必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("sen", 20);
	me->receive_damage("kee", 20);
	me->add("force", -10);

	return 1;
}

string perform_action_file(string func)
{
return CLASS_D("bonze") + "/jienan-zhi/" + func;
}

