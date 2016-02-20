// tiyunzong.c 梯云纵
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"只见$n一招"HIW"「白鹤冲天」"NOR"，身体向上笔直地纵起丈余，躲过了$N这一招。\n",
	"$n一个"BLU"「鹞子翻身」"NOR"，向后纵出数丈之远，避开了$N的凌厉攻势。\n",
	"$n使出"HIY"「大鹏展翅」"NOR"，向一旁飘然纵出，轻轻着地。\n",
	"但是$n一招"HIC"「白鹤冲天」"NOR"身形飘忽，轻轻一纵，早已避开。\n",
	"$n身随意转，一招"HIB"「鹞子翻身」"NOR"倏地往一旁挪开了三尺，避过了这一招。\n",
	"可是$n一招"YEL"「大鹏展翅」"NOR"侧身一让，$N这一招扑了个空。\n",
	"却见$n足不点地一招"HIC"「白鹤冲天」"NOR"，往旁窜开数尺，躲了开去。\n",
	"$n身形微晃，一招"MAG"「鹞子翻身」"NOR"有惊无险地避开了$N这一招。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("taiji-shengong", 1) < 10 )
	return notify_fail("你的太极神功不够精熟，无法领会梯云纵。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 10 )
		return notify_fail("你的体力太差了，无法练习梯云纵。\n");
	me->receive_damage("qi", 50);
	me->add("neili", -10);
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point(object me) { return 1.1; }

int help(object me)
{
	write(HIC"\n梯云纵："NOR"\n");
	write(@HELP

    梯云纵为武当最高轻功心法。

	学习要求：
	  太极神功10级
HELP
	);
	return 1;
}

