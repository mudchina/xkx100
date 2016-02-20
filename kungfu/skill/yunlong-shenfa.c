// yunlong-shenfa 云龙身法
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"$n一式"HIY"「龙腾虎跃」"NOR"，身行一转，猛的跳向一旁,躲过了$N的功势。\n",
	"$n一式"HIY"「沙场点兵」"NOR"，双臂置于身后，不急不缓，昂首从$N眼前跨过。\n",
	"$n一式"HIG"「风雨同舟」"NOR"，不退反进，一下子绕到了$N的身后。\n",
	"$n一式"HIG"「养精蓄锐」"NOR"，缓缓的向后一退，轻松让过了$N的凌厉攻势。\n",
	"$n一式"GRN"「无心插柳」"NOR"，左手一扬，身行一晃，便向右飘出丈远。\n",
	"$n一式"MAG"「苍鹰搏兔」"NOR"，身体如一只苍鹰，呼的一声从$N的眼前飞过。\n",
	"$n一式"HIY"「九龙在天」"NOR"，忽的拔地而起，在半空中一转，已落到几丈远的地方。\n",
	"$n一式"HIC"「瀑落九天」"NOR"，全身化为一道白影，忽的一个空翻，从左边飘到右边。\n",
	"$n一式"HIC"「幻眼云烟」"NOR"，身形陡地变得飘忽不定，令$N无法看清。\n",
	"$n一式"HIW"「九天揽月」"NOR"，宛若一条矫矢苍龙，倏的拔地而起，令$N不敢仰视。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("yunlong-shengong", 1) < 10 )
	return notify_fail("你的云龙神功不够精熟，无法领会云龙身法。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 40|| (int)me->query("neili") < 8 )
		return notify_fail("你的体力太差了，不能练云龙身法。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -8);	
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point() { return 1.4; }

int help(object me)
{
	write(HIC"\n云龙身法："NOR"\n");
	write(@HELP

    云龙身法为天地会云龙门本门轻功身法。

	学习要求：
	   云龙神功10级
HELP
	);
	return 1;
}

