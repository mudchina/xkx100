// qiankun-danuoyi.c 乾坤大挪移
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *parry_msg = ({
	HIY"$N一招击在$n身上，却被$n暗运乾坤大挪移，将内力尽数移入地下。\n"NOR,
	HIW"$n轻轻一带，$N发现自己招数回击过来，吓得往后倒退几步。\n"NOR,
	HIC"$n手臂回转，在$N手肘下轻轻一推，$N招数落空。\n"NOR,
	HIG"$n右手伸出，在$N手腕上轻轻一拉，$N收势不住，直往前扑去。\n"NOR,
	MAG"$n身形不动，$N一招击下，有如石沉大海，不觉呆住了。\n"NOR,
	HIM"$n左牵右引，$N如身处漩流，连续转了好几个圈。\n"NOR,
	GRN"$n双手回圈，$N只觉得前面好象有一堵墙，再也攻不进去。\n"NOR,
	HIY"$n轻轻一转，$N一招击在地上，只打得尘土飞扬。\n"NOR,
});

string *dodge_msg = ({
	"$N一招击在$n身上，却被$n暗运乾坤大挪移，将内力尽数移入地下。\n",
	"$n轻轻一带，$N发现自己招数回击过来，吓得往后倒退几步。\n",
	"$n手臂回转，在$N手肘下轻轻一推，$N招数落空。\n",
	"$n右手伸出，在$N手腕上轻轻一拉，$N收势不住，直往前扑去。\n",
	"$n身形不动，$N一招击下，有如石沉大海，不觉呆住了。\n",
	"$n左牵右引，$N如身处漩流，连续转了好几个圈。\n",
	"$n双手回圈，$N只觉得前面好象有一堵墙，再也攻不进去。\n",
	"$n轻轻一转，$N一招击在地上，只打得尘土飞扬。\n",
});

int valid_enable(string usage) 
{ 
	return (usage == "parry") || (usage == "dodge") || (usage=="move"); }

string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int valid_learn(object me)
{
	int lvl = (int)me->query_skill("qiankun-danuoyi", 1);

	if ( me->query("gender") == "无性" && lvl > 99)
		return notify_fail("你先天不足，再学下去难免走火入魔。\n");
	if ((int)me->query_skill("force", 1) < 100)
		return notify_fail("就这么点基本内功还想学乾坤大挪移？\n");
	if (lvl > 50)
		return notify_fail("乾坤大挪移只能通过读<<乾坤大挪移心法>>提高。\n");
	if ((int)me->query("max_neili", 1) < 1500)
		return notify_fail("就这么点内力还想学乾坤大挪移？\n");
	if ((int)me->query_skill("force", 1) < lvl)
		return notify_fail("你的基本内功火候还不够，小心走火入魔！\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < lvl)
		return notify_fail("你的九阳神功火候还不够，小心走火入魔！\n");
	if ((int)(me->query("max_neili")/15) < lvl)
		return notify_fail("你的内力火候还不够，小心走火入魔！\n");
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("乾坤大挪移只能通过读<<乾坤大挪移心法>>提高。\n");
}
string perform_action_file(string action)
{
	return __DIR__"qiankun-danuoyi/" + action;
}

int learn_bonus() { return 0; }
int practice_bonus() { return 0; } 
int success() { return 5; }
int power_point(object me) { return 1.5; }

int help(object me)
{
	write(HIC"\n乾坤大挪移："NOR"\n");
	write(@HELP

    “乾坤大挪移”是明教历代相传一门最厉害的武功，是明教的
护教神功。为波斯大盗山中老人所创，专门讲述运气使力的法门。
中原会用的人甚少，自明教三十三代教主阳顶天死后，几乎失传，
但后来张无忌一番奇遇，以其深厚的内功一朝而成。乾坤大挪移只
作招架和轻功用，不具攻击。其威力之所在是可以把别人的招数尽
数还于对方。
    乾坤大挪移神功的主旨，乃在颠倒一刚一柔、一阴一阳的乾坤
二气，脸上现出青红之色，便是体内血液沉降、真气变换之象。练
至第六层时，全身都能忽红忽青，但到第七层时，阴阳二气转换于
不知不觉之间，外形上便半点也瞧不出表征了。其根本道理也并不
如何奥妙，只不过先求激发自身潜力，然后牵引挪移敌劲，但其中
变化神奇，却是匪夷所思。

	学习要求：
		基本内功100级并不得低于乾坤大挪移的级别
		九阳神功不得低于乾坤大挪移的级别
		内力1500并不得低于乾坤大挪移的级别的15倍
		太监无法领悟100级以上的乾坤大挪移
HELP
	);
	return 1;
}

