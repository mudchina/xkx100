// shuishangpiao.c 铁掌水上飘
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
"$n足跟一支，全身后仰，一招"BLU"「鲤鱼倒穿波」"NOR"，反窜出丈余，躲过了$N的攻击。\n",
"$n身体忽然柔若无骨，左右摇摆，使出一招"BLU"「雨打漂萍」"NOR"，避过了$N的攻击。\n",
"$n使出"HIB"「物换星移」"NOR"，滴溜溜一个转身，从$N身旁擦身而过，反而到了$N身后。\n",
"$n一招"HIY"「落叶随风」"NOR"，身体如一片落叶一般飘了出去，身行之潇洒，迅速到了极处。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("guiyuan-tunafa", 1) < 10 )
	return notify_fail("你的归元吐纳法不够精熟，无法领会铁掌水上飘。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("你的体力太差了，无法练习铁掌水上飘。\n");
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
int river_point() {return 1.5;} // 过河比普通容易 越高越好
string river_go_msg() {	return HIW"$N飞身跃在水面，身形稳凝，河水只及小腿，一步步走了过去。\n"NOR;}
string river_come_msg() {	return HIW"只见水面上人影闪动，$N如飘在上面一般，直走过来。\n"NOR;}

int help(object me)
{
	write(HIC"\n铁掌水上飘："NOR"\n");
	write(@HELP

    铁掌帮的独门轻功身法。

	学习要求：
	  归元吐纳法10级
HELP
	);
	return 1;
}

