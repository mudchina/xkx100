// wudu-yanluobu 五毒烟萝步
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
HIB"$n不慌不忙，一式「江水横流」，身行倏的向一旁平移数尺，堪堪躲过了$N的功势。\n"NOR,
HIB"$n身行如鬼魅般一晃，刹那间已远去数丈之外，$N顿时扑了个空。\n"NOR,
BLU"$n身行忽的加快，如一缕青烟般绕着$N飞快旋转，看得$N一阵头晕眼花，急忙收招跳开。\n"NOR,
BLU"$n怪异的一笑，身行忽的变得朦胧不清，$N的凌厉招式竟然透体而过，原来竟是一具幻影。\n"NOR,
BLU"$n的身行顿时变得如蛇一般柔软，随着$N的招式左右摆动，竟使得$N招招落空。\n"NOR,
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me)
{      	
	if( (int)me->query_skill("wudu-shengong", 1) < 10 )
	return notify_fail("你的五毒神功不够精熟，无法领会五毒烟萝步。\n");
	return 1;
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 10|| (int)me->query("neili") < 2 )
		return notify_fail("你的体力太差了，不能练五毒烟萝步。\n");
	me->receive_damage("qi", 10);
	me->add("neili", -2);	
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.1; }

int help(object me)
{
	write(HIC"\n五毒烟萝步："NOR"\n");
	write(@HELP

    五毒教祖师模仿毒虫动作而创立的一门轻功，是五毒教本门内
功。

	学习要求：
	   五毒神功10
HELP
	);
	return 1;
}

