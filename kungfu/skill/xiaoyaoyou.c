// xiaoyaoyou.c 逍遥游
// Last Modified by sir on 18.10.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"$n一个"RED"「蜻蜓点水」"NOR"，躲过了$N这一招。\n",
	"$n身形向后一纵，使出一招"HIW"「细胸巧翻云」"NOR"，避过了$N的攻击。\n",
	"$n使出"BLU"「虚怀若谷」"NOR"，恰好躲过了$N的攻势。\n"
	"但是$n一招"HIY"「蜻蜓点水」"NOR"身形飘忽，轻轻一纵，早已避开。\n",
	"$n身随意转，一招"MAG"「细胸巧翻云」"NOR"倏地往一旁挪开了三尺，避过了这一招。\n",
	"可是$n侧身一让，一招"HIY"「虚怀若谷」"NOR"$N这一招扑了个空。\n",
	"却见$n足不点地，一招"GRN"「蜻蜓点水」"NOR"往旁窜开数尺，躲了开去。\n",
	"$n身形微晃，一招"HIB"「虚怀若谷」"NOR"有惊无险地避开了$N这一招。\n"
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if ((int)me->query("can_learn/hong/xiaoyaoyou"))
 	return 1;
	if( (int)me->query_skill("huntian-qigong", 1) < 10 )
	return notify_fail("你的混天气功不够精熟，无法领会逍遥游。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("你的体力太差了，无法练习逍遥游。\n");
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
	write(HIC"\n逍遥游："NOR"\n");
	write(@HELP

    逍遥游是丐帮本门轻功身法。

	学习要求：

	   混天气功10级或有洪七公指点
HELP
	);
	return 1;
}

