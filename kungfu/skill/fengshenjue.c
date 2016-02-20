// fengshenjue.c  风神诀
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"只见$n使出" HIC"「洛神凌波」"NOR"，衣诀飘飘，脚下如凌波踏水，快速几步，已避开攻击。\n",
	"但是$n使出" HIW"「凌空虚度」"NOR"，提气纵起，在空中连跨七步，已在$N寻丈之外。\n",
	"$n一招"HIY"「布法行云」"NOR"，脚踏子午，掌分阴阳，不经意间避过$N这一招。\n",
	"可是$n一个" HIC"「风起云涌」"NOR"，身形如被大风所吹，飘飘优悠落到$N身后。\n",
	"却见$n使出" GRN"「春风拂柳」"NOR"，一足脚尖点地，身如弱柳，俯仰不定，$N这招可落了空。\n",
	"$n使出"YEL "「秋风萧瑟」"NOR"，一手捂胸，挺身前行，大有壮士一去不复返之势，$N被其气势所慑，只得退开。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("panshi-shengong", 1) < 10 )
	return notify_fail("你的磐石神功不够精熟，无法领会风神诀。\n");
	return 1;
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("你的体力太差了，无法练习风神诀。\n");
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
	write(HIC"\n风神诀："NOR"\n");
	write(@HELP

    泰山派的轻功身法。

	学习要求：
	   磐石神功10级
HELP
	);
	return 1;
}

