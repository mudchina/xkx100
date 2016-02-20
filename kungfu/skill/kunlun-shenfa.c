// kunlun-shenfa.c (kunlun) 昆仑身法

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
"$n一式"HIC"「雁落平沙」"NOR"，变招奇速，右足向前踢出，身子已然腾起，轻轻巧巧地落在一旁。\n",
"$n一式"HIY"「玉龙飞起」"NOR"，纵身高跃，半空中一折一转，已飘身在数丈之外。\n",
"$n一式"HIY"「夏日消融」"NOR"，两足足跟不动，足尖左磨，身子随之右转，卸开了$N这一招。\n",
"$n一式"YEL"「枯松倒挂」"NOR"，只见$n身子后仰，双掌往地下一撑，身子借势倒射而出，$N便已打$n不着。\n",
"$n一式"HIW"「晴雪飞滩」"NOR"，纵高伏低，东奔西闪，身形飘忽不定，$N手无足措，只得回招自守。\n",
"$n一式"HIW"「冰丝带雨」"NOR"，突然反手一招，竟然是两败俱伤的打法，趁$N手忙脚乱安全脱身。\n",
"$n一式"HIW"「寒江钓雪」"NOR"，不招不架，只微微一侧身，$N犹如暴风骤雨般的进攻便即落空。\n",
"$n一式"HIY"「鱼龙潜跃」"NOR"，陡然间身形拔起，直冲云霄，直如鹰隼，几个盘旋，飘飘荡荡落在数丈之外。\n",
});

int valid_enable(string usage) { return usage=="dodge" || usage=="move"; }
int valid_learn(object me)
{
	int ng, nl, nk;
	ng = (int)me->query_skill("goplaying", 1);
	nl = (int)me->query_skill("luteplaying", 1);
	nk = (int)me->query_skill("kunlun-shenfa", 1);

	if (me->query("family/master_name") != "何足道" )
	{
		if ( nl < nk || ng < nk  )
		return notify_fail("琴棋技艺当与武功并重，不然你无法领会更高深的昆仑身法。\n");
	}

	if( (int)me->query_skill("xuantian-wuji", 1) < 10 )
	return notify_fail("你的玄天无极功不够精熟，无法领会昆仑身法。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 6  )
		return notify_fail("你的体力太差了，不能练昆仑身法。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -6);
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.4; }

int help(object me)
{
	write(HIC"\n昆仑身法："NOR"\n");
	write(@HELP

    昆仑身法为昆仑高级轻功。

	学习要求：
		相当的琴棋技艺的造诣
		何足道的嫡传弟子
HELP
	);
	return 1;
}

