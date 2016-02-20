// pomopima-jian.c泼墨披麻剑法

inherit SKILL;

mapping *action = ({
([	"action":       "$N使一招「白虹贯日」，手中$w轻飘飘地向$n的$l斩去！",
	"damage":	100,
	"damage_type":	"割伤"
]),
([	"action":       "$N金刃劈风，$w随著一招「腾蛟起风」由下而上撩往$n的$l",
	"damage":	120,
	"damage_type":	"割伤"
]),
([	"action":       "$N身形一转，一招「春风杨柳」$w剑光不定，斩向$n的$l",
	"damage":	140,
	"damage_type":	"割伤"
]),
([	"action":       "$N舞动$w，一招「心驰神遥」迅捷无伦地劈向$n的$l",
	"damage":	160,
	"damage_type":	"划伤",
]),
([	"action":       "$N手中$w一晃，一招「青山依旧」往$n的$l斜斜砍出一剑",
	"damage":	180,
	"damage_type":	"割伤",
]),
([	"action":       "$N提剑过肩，蓄劲发力，一招「玉龙倒悬」直劈$n$l",
	"damage":	200,
	"damage_type":	"劈伤",
]),
([	"action":       "$N移步侧身，使一招「漫山遍野」剑光霍霍斩向$n的$l",
	"damage":	250,
	"damage_type":	"划伤",
]),
});

int valid_learn(object me)
{
	if(me->query_skill("xuantian-zhi",1)<20)
		return notify_fail("你的「玄天指法」不够娴熟。\n");
	if ((int)me->query_skill("kuihua-xinfa", 1) < 80)
		return notify_fail("你的葵花心法火候不够。\n");
	if(me->query("max_neili")<50)
		return notify_fail("你的内力修为不够。\n");
	return 1;
}

int valid_enable(string usage)
{
	return (usage=="sword") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑，才能练剑法。\n");

	if( (int)me->query("qi") < 40 )
		return notify_fail("你的体力不够练这门剑法，还是先休息休息吧。\n");
	me->receive_damage("qi", 40);
	return 1;
}

