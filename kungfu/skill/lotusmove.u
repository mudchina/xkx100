// lotusmove.c
// By Dream Dec. 18, 1996

inherit SKILL;

string *dodge_msg = ({
	"$n轻轻一纵，使个「出淤泥而不染」，毫不费力地躲开了$N这一招。\n",
	"$n几个错步，使出「映日荷花」，$N只觉得眼一花，顿失$n的踪影。\n",
	"$n一招「重重叠叠」，$N眼前出现了无数个$n，$N显然有点有力无处使。\n",
	"$n双足一顿，一招「亭亭玉立」身体向上笔直地拔起，避了开去。\n",
	"但是$n使一招「雨露滚莲」，身子向后飘开丈余，轻轻着地。\n",
	"只见$n一式「无尽碧莲」拔地而起，在半空中转了数转，$N的攻势尽告落空。\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 0 )
		return notify_fail("你的内力不够，不能够学习莲花步。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的气或内力不够，不能练莲花步。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
