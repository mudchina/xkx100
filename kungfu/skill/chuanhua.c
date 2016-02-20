// chuanhua.c 穿花绕树
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"$n一式"GRN"「斜燕归林去」"NOR"，身体如雨燕投林般直滑出丈余。\n",
	"$n一式"MAG"「花蝶戏蕊心」"NOR"，忽然一弯腰，全身凌空而行，顿时闪过了$N的凌厉攻势。\n",
	"$n一式"HIY"「黄雀啄叶露」"NOR"，足不动，手不抬，一转眼间便绕到了$N的身后。\n",
	"$n一式"GRN"「青蜂弄花粉」"NOR"，一转身间，四面八方飘动着无数个$n的身影，令$N手足无措。\n",
	"$n一式"HIW"「蜓尾点水舞」"NOR"，长袖一拂，全身化为一道白影，幽幽地从$N头顶飘落。\n",
	"$n一式"MAG"「知了藏影踪」"NOR"，身行倏的从$N的眼前飘过，长发一甩，潇洒之极。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
       if( (int)me->query_skill("qingming-xuangong", 1) < 10 )
       return notify_fail("你的青冥玄功不够精熟，无法领会穿花绕树。\n");
       return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("你的体力太差了，不能练穿花绕树。\n");
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
int power_point() { return 1.3; }

int help(object me)
{
	write(HIC"\n穿花绕树："NOR"\n");
	write(@HELP

    青城派本门轻功。

	学习要求：
            青冥玄功 10 级		
HELP
	);
	return 1;
}

