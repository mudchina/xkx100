// 泼墨披麻刀法

inherit SKILL;

mapping *action = ({
	([  "action":       "$N使一招「白虹贯日」，手中$w轻飘飘地向$n的$l斩去！",
		"damage":	100,
		"damage_type":	"割伤"
	]),
	([  "action":       "$N金刃劈风，$w随著一招「腾蛟起风」由下而上撩往$n的$l",
		"damage":	120,
		"damage_type":	"割伤"
	]),
	([  "action":       "$N身形一转，一招「春风杨柳」$w刀光不定，斩向$n的$l",
		"damage":	140,
		"damage_type":	"割伤"
	]),
	([  "action":       "$N舞动$w，一招「心驰神遥」迅捷无伦地劈向$n的$l",
		"damage":	160,
		"damage_type":	"划伤",
	]),
	([  "action":       "$N手中$w一晃，一招「青山依旧」往$n的$l斜斜砍出一刀",
		"damage":	180,
		"damage_type":	"割伤",
	]),
	([  "action":       "$N提刀过肩，蓄劲发力，一招「玉龙倒悬」直劈$n$l",
		"damage":	200,
		"damage_type":	"劈伤",
	]),
	([  "action":       "$N移步侧身，使一招「漫山遍野」刀光霍霍斩向$n的$l",
		"damage":	250,
		"damage_type":	"划伤",
	]),
});

int valid_learn(object me)
{
	if(me->query_skill("xuantian-quan",1)<20)
		return notify_fail("你的「玄天拳法」不够娴熟。\n");
	if(me->query_skill("xuantian-neigong",1)<20)
	return notify_fail("你的「玄天内功」功力不够。\n");
	if(me->query("max_force")<50)
	return notify_fail("你的内力修为不够。\n");
	return 1;
}

int valid_enable(string usage)
{
	return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "blade" )
		return notify_fail("你必须先找一把刀，才能练刀法。\n");

	if( (int)me->query("kee") < 40 )
		return notify_fail("你的体力不够练这门刀法，还是先休息休息吧。\n");
	me->receive_damage("kee", 40);
	return 1;
}

string perform_action_file(string action)
{
return "/daemon/class/meizhuang/pomopima-dao/"+action;
}
int power_point()	{	return 1.25;	}
