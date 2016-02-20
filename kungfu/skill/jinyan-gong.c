// jinyan-gong.c 金雁功
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"却不料$n身形一转，一个"HIY"「藏形匿迹」"NOR"突然转到了$N的身后。\n",
	"$n足尖在地面一点，身形拔地而起，"HIC"「飞灵八方」"NOR"躲开了这一招。\n",
	"$n随着$N攻来的招式一个"HIW"「乘虚御空」"NOR"飘了起来，就如一片微风中的柳絮一般。\n",
	"$n使出"HIY"「解行遁变」"NOR"，身形左一晃、右一闪，不知怎么的，从攻击的间隙中钻了出来。\n",
	"$n使出"HIM"「回神转玄」"NOR"，足不点地地围绕$N连绕三个大圈，把$N这一招避了开去。\n",
	"$n连旋数个大圈，跟着又是一个大圈，运起金雁功的"HIC"「弃厄飞霄」"NOR"，身形高高地拔了起来。\n",
	"$n身形流转，衣袖飘拂，绕场团走，正是金雁功的"HIB"「隐景舞天」"NOR"，形态缦妙已极。\n",
	"$n身形飘浮，长袖翻卷，一势"HIW"「出有入无」"NOR"，轻松自如地避开了$N的攻势。\n",
});

int valid_enable(string usage) { return usage=="dodge" || usage=="move"; }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("xiantian-qigong", 1) < 10 )
	return notify_fail("你的先天功不够精熟，无法领会金雁功。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 20|| (int)me->query("neili") < 4 )
		return notify_fail("你的体力太差了，不能练金雁功。\n");
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
	write(HIC"\n金雁功："NOR"\n");
	write(@HELP

    金雁功为全真派本门轻功。

	学习要求：
	  先天功10级
HELP
	);
	return 1;
}

