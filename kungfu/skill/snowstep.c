// Last Modified by sir on 10.18.2001
// snowstep.c 梅雪飘香步

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *dodge_msg = ({
	"但是$n轻笑一声，回身高拨而起，一式"+(order[random(13)])+"「红梅飘雪」"NOR"，轻轻闪过了这招。\n",
	"$n随意转身，一招"+(order[random(13)]) +"「檀板金樽」"NOR"，如舞乐般飘身而上，避过了这招。\n",
	"只见$n身形一旋，拨身而起，使出"+(order[random(13)]) +"「梅月黄昏」"NOR"，整个人都失去了踪影，令$N扑了个空。\n",
	"却见$n伸手往地上遥遥一拍，一式"+(order[random(13)]) +"「梅飘九宵」"NOR"，如柳絮般轻轻飘起，躲过了这招。\n",
	"$n长笑一声，一式"+(order[random(13)]) +"「寒梅傲雪」"NOR"，长身而起，一时四面八方都是$n的影子，虚虚实实，不知哪个才是真的。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me)
{      	
	if( (int)me->query_skill("bingxue-xinfa", 1) < 10 )
		return notify_fail("你的冰雪心法不够精熟，无法领会梅雪飘香步。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 20|| (int)me->query("neili") < 4 )
		return notify_fail("你的体力太差了，不能练梅雪飘香步。\n");
	me->receive_damage("qi", 20);
	me->add("neili", -4);	
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 20; }
int power_point(object me) { return 1.2; }

int help(object me)
{
	write(HIC"\n梅雪飘香步："NOR"\n");
	write(@HELP

    梅雪飘香步是凌霄派本门轻功身法。

	学习要求：
          冰雪心法10级
HELP
	);
	return 1;
}
