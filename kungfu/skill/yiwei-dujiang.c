// yiwei-dujiang.c 南少林身法一苇渡江

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
"$n一式"HIW"「一苇渡江」"NOR"，前后脚脚尖脚跟相靠，身体如行云流水般滑出丈余。\n",
"$n一式"BLU"「雨燕掠波」"NOR"，双臂前伸，全身贴地平飞，顿时闪过了$N的凌厉攻势。\n",
"$n一式"HIG"「移步换形」"NOR"，足不动，手不抬，一转眼间便绕到了$N的身后。\n",
"$n一式"HIC"「分身化影」"NOR"，一转身间，四面八方飘动着无数个$n的身影，令$N手无足措。\n",
"$n一式"HIY"「孤骛落日」"NOR"，全身笔直，拔地而起，在半空中一转，已落到几丈远的地方。\n",
"$n一式"GRN"「鸿雁双飞」"NOR"，两臂鹏举如翼，在剌剌风声中，从$N头顶横跃而过。\n",
"$n一式"HIY"「苍龙出水」"NOR"，双脚点地，全身化为一道白影，急速绕着$N打了几转。\n",
"$n一式"HIG"「稚凤归巢」"NOR"，身体如陀螺般急转，气流形成一个个漩涡，令$N陷身其间，动弹不得。\n",
});


int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("zhanzhuang-gong", 1) < 10 )
	return notify_fail("你的四平大马站桩功不够精熟，无法领会一苇渡江。\n");
	return 1;
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("你的体力太差了，无法练习一苇渡江。\n");
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
int river_point() {return 2;} // 过河比普通容易 越高越好
string river_go_msg() {	return HIW"$N捡起一段芦苇抛入水中，紧跟着飞身跃上芦苇，长袖飘飘，渡过了水面。\n"NOR;}
string river_come_msg() {	return HIW"只见$N踩着一段芦苇从对岸过来，姿态潇洒地落在岸边。\n"NOR;}

int help(object me)
{
	write(HIC"\n一苇渡江："NOR"\n");
	write(@HELP

    南少林身法一苇渡江

	学习要求：
	   四平大马站桩功10级
HELP
	);
	return 1;
}



