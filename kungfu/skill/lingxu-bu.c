// lingxu-bu 凌虚步
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"$n一式"HIW"「雪地莲花」"NOR"，身子掣忽一转，$N只觉的眼前一花，失去了目标。\n",
	"$n一式"HIY"「一狐冲天」"NOR"，双脚点地，身子突然拔高了丈许，缓缓飘落在$N身后。\n",
	"$n一式"CYN"「移行幻影」"NOR"，身行一晃，顿时无数条身影一下子出现在$N的面前。\n",
	"$n一式"MAG"「狡兔三窟」"NOR"，飘然向后一退，躲开$N的凌厉攻势。\n",
	"$n一式"BLU"「烟雨飘渺」"NOR"，身体急转，化为一道白光，虚幻不定的出现在$N的周围。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me)
{      	
	if( (int)me->query_skill("baiyun-xinfa", 1) < 10 )
	return notify_fail("你的白云心法不够精熟，无法领会凌虚步。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("你的体力太差了，无法能练习凌虚步。\n");
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
	write(HIC"\n凌虚步："NOR"\n");
	write(@HELP

    凌虚步为恒山派轻功。

	学习要求：
          白云心法10级
HELP
	);
	return 1;
}

