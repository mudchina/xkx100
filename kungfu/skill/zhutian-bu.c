// zhutian-bu.c 诸天化身步
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
"只见$n一招"MAG"「天地钩」"NOR"，身体腾空，双足向上，笔直地纵起丈余，躲过了$N这一招。\n",
"$n身随意转，一式"HIM"「凤点头」"NOR"头部前挺，侧身收腹，倏地往一旁挪开了三尺，避过了这一招。\n",
"$n双足抓地，身形微晃，一招"BLU"「鹰爪松」"NOR"有惊无险地避开了$N这一招。\n",
"但是$n身形飘忽，一式"GRN"「风摆柳」"NOR"，轻轻一纵，早已避开。\n",
"$n一个"HIB"「阴阳箭」"NOR"，向后纵出数丈之远，避开了$N的凌厉攻势，立即又欺近$N身旁。\n",
"$n使出"HIW"「日月扣」"NOR"，双手如钩向一旁飘然纵出，轻轻着地。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("linji-zhuang", 1) < 10 )
	return notify_fail("你的临济十二庄不够精熟，无法领会诸天化身步。\n");
	return 1;
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 20|| (int)me->query("neili") < 4 )
		return notify_fail("你的体力太差了，不能练诸天化身步。\n");
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
	write(HIC"\n诸天化身步："NOR"\n");
	write(@HELP

    诸天化身步是峨嵋派本门轻功身法。

	学习要求：
          临济十二庄10级
HELP
	);
	return 1;
}

