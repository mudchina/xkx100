// huashan-shenfa.c 华山身法
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
"$n一式"HIY"「巨鹏亮翅」"NOR"，两臂鹏举如翼，在剌剌风声中，从$N头顶横跃而过。\n",
"$n一式"HIC"「风送紫霞」"NOR"，如一阵清风，舒缓地闪过了$N的凌厉攻势。\n",
"$n一式"HIB"「燕回朝阳」"NOR"，轻盈地一跃，一转眼间便绕到了$N的身后。\n",
"$n一式"HIY"「却别苍松」"NOR"，一转身间，向后飘出近一丈远\n",
"$n一式"HIM"「旭日初升」"NOR"，全身笔直，拔地而起，在半空中一转，已落到几丈远的地方。\n",
"$n一式"HIY"「金雁横空」"NOR"，身体如一只金雁般行云流水地滑出丈余。\n",
"$n一式"HIW"「晚月朗星」"NOR"，双脚点地，全身化为一道白影，急速绕着$N打了几转。\n",
"$n一式"GRN"「幻眼云湮」"NOR"，身形陡地变得飘忽不定，令$N无法看清。\n",
"$n一式"HIM"「苍龙盘岭」"NOR"，宛若一条矫矢苍龙，围着$N急速地盘旋了几圈。\n",
});

int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }
int valid_learn(object me)
{      	
	if( (int)me->query_skill("zixia-shengong", 1) < 10 )
	return notify_fail("你的紫霞神功不够精熟，无法领会华山身法。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 20|| (int)me->query("neili") < 4 )
		return notify_fail("你的体力太差了，不能练华山身法。\n");
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
	write(HIC"\n华山身法："NOR"\n");
	write(@HELP

    华山身法为华山剑宗轻功身法。

	学习要求：
	  紫霞神功10级
HELP
	);
	return 1;
}

