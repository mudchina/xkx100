// baiyun-xinfa.c 白云心法
// Last Modify by sir 5/17/2001

#include <ansi.h>
#include "force.h";
inherit FORCE;

string type() { return "martial"; }
string martialtype() { return "force"; }
int valid_enable(string usage) { return usage == "force"; }
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point() { return 1; }

int valid_learn(object me)
{
	int i,nb,ny,ns;
	
	nb = (int)me->query_skill("buddhism", 1);
	ny = (int)me->query_skill("baiyun-xinfa", 1);
	ns = (int)me->query("guilty");

	if ( me->query("couple/have_couple") )
		return notify_fail("你尘缘未了，无法再学习白云心法！\n");	
	if ( me->query("gender") != "女性" )
		return notify_fail("白云心法只适合女性修练。\n");
	if ( me->query("sex/number") )
		return notify_fail("你非处女之身，无法修习白云心法！\n");	
	if (((string)me->query("class") != "bonze") && i > 29)
		return notify_fail("你不是尼姑，学不了高深的白云心法。\n");
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");

	if ( nb < 100 && nb <= ny )
		return notify_fail("你的禅宗心法修为不够，无法领会更高深的白云心法。\n");
	if ( ns > 0 ) 
		return notify_fail("你屡犯僧家数戒，无法领会更高深的白云心法。\n");
	return valid_public(me);
	
}

int practice_skill(object me)
{
	return notify_fail("白云心法只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
	return __DIR__"baiyun-xinfa/" + func;
}

int help(object me)
{
	write(HIC"\n白云心法："NOR"\n");
	write(@HELP

  恒山派内功

	学习要求：
		基本内功10级
		处女纯阴之体		
HELP
	);
        return 1;
}

