// qiuyan-nanhui.c 秋雁南回
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"$n一式"CYN"「雁渡寒潭」"NOR"，身不倾，脚不移，身体如行云流水般直滑出丈余。\n",
	"$n一式"CYN"「平沙落雁」"NOR"，忽然一弯腰，全身贴地而行，顿时闪过了$N的凌厉攻势。\n",
	"$n一式"CYN"「雁舞风堂」"NOR"，一转身间，四面八方飘动着无数个$n的身影，令$N手足无措。\n",
	"$n一式"CYN"「云雁惊厥」"NOR"，长袖一拂，全身化为一道白影，幽幽地从$N头顶飘落。\n",
	"$n一式"CYN"「雁影行洲」"NOR"，身体如陀螺般急转，登时一股气流涌出，令$N难以动弹。\n",
});


int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("huiyan-xinfa", 1) < 10 )
	return notify_fail("你的回雁心法不够精熟，无法领会秋雁南回。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("你的体力太差了，无法练习秋雁南回。\n");
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
int power_point(object me) { return 1.3; }

int help(object me)
{
	write(HIC"\n秋雁南回："NOR"\n");
	write(@HELP

    衡山派的轻功身法。

	学习要求：
	   回雁心法10级
HELP
	);
	return 1;
}

