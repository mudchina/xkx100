// hubo.c 左右互博
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int valid_learn(object me) 
{
	if( (int)me->query("int") > 24 )
		return notify_fail("你的天性不适合学习左右互博之术！\n" ) ;
	if( (int)me->query("cps") < 20 )
		return notify_fail("你的天性不适合学习左右互博之术！\n" ) ;
	if( !me->query("double_attack") )
		return notify_fail("左右互博之术要向周伯通讨教！\n" ) ;
	if( me->query_skill("qimen-wuxing"))
    return notify_fail("你的杂学太多，一时无法领会左右互博！\n");
	return 1;
}
int help(object me)
{
	write(HIC"\n左右互博："NOR"\n");
	write(@HELP

    左右互搏是周伯通在桃花岛被困十五年，苦于没人拆招，只有
左手和右手打架中无意悟得。其要旨是「心分二用，左手画方，右
手画圆」。左右互搏可称得天下最奇特的武功，能双手分使不同武
功，同时攻击敌人。然唯有淳厚质朴之人，能一神守内，一神游外，
或练过玉女心经，能摒除七情六欲，方能习之。

	学习要求：
		先天悟性不大于24级
		其它天赋条件
HELP
	);
	return 1;
}

