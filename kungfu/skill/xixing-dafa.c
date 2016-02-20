// xixing-dafa.c 吸星大法
// Last Modified by winder on Apr. 10 2000

#include <ansi.h>
inherit FORCE;
#include "force.h"
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point() { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("xixing-dafa", 1);
	int t = 1, j;
	for (j = 1; j < i / 10; j++) t*= 2;
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学吸星大法。\n");
	if (i > 10 && (int)me->query("shen") > t * 100)
		return notify_fail("学吸星大法，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
	if (!me->query("family") || me->query("family/master_id")!="ren woxing")
		return notify_fail("吸星大法只能向任教主学习。\n");
	if (((int)me->query_skill("xixing-dafa", 1) < 20) &&
		((int)me->query_skill("xixing-dafa", 1) > 1) &&
		((int)me->query("max_neili") > 0))
		return notify_fail("你未放弃掉的内力，无法继续学吸星大法！\n");

	if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
		return notify_fail("你练了秃驴牛鼻子们的心法，还学吸星大法做什麽！\n");

	if ( !me->query_skill("kuihua-xinfa",1))
		return notify_fail("你不先学葵花心法，怎能学吸星大法？！\n");

  return valid_public(me,"kuihua-xinfa");
}
int practice_skill(object me)
{
	return notify_fail("吸星大法只能用学(learn)的来增加熟练度。\n");
}

mixed be_hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap, dp;
	int jiali;
	string msg;
  if ((int) me->query_skill("xixing-dafa", 1) < 70 ||
            ! living(me) 
            || victim->query_skill_mapped("force") == "taixuan-gong"
				)
                return;
    jiali=factor;
   if (jiali < 1 )
     return;

	ap=me->query_skill("force");
	dp=victim->query_skill("force");
	switch (random(4))
                {
                case 0:
                        msg=BLU "$N" BLU "只觉得内力源源而泻，不由得大吃一惊。\n" NOR;
                        break;
                case 1:
                        msg=BLU "$N" BLU "只觉得发出的内力犹如石沉大海，不知所踪。\n" NOR;
                        break;
                case 2:
                        msg=BLU "$N" BLU "只觉得发出的内力犹无影无踪，浑然不知着落。\n" NOR;
                        break;
                default:
                        msg=BLU "$N" BLU "不住催动内力，但是只觉得$n竟似毫不费力。\n" NOR;
                        break;
                }

//if (dp/2+random(dp)<ap)  // 北冥同等级1/2几率
                           // 化功 1/3
	if (dp*3/4+random(dp)<ap)	//同等级1/4几率
	{

    if (victim->query("neili")>0)
		   {
		   	victim->add("neili",-(ap/6+jiali));
    		if (me->query("neili") < me->query("max_neili") * 2)
        	{
           	me->add("neili", ap/6+jiali);
        	}
        	return msg;
        }
	}
	return 0;
}

string exert_function_file(string func)
{
	return __DIR__"xixing-dafa/" + func;
}

int help(object me)
{
	write(HIC"\n吸星大法："NOR"\n");
	write(@HELP

    日月神教黑木崖的一种内功。

    吸星大法创自北宋年间的逍遥派，分为北冥神功和化功大法两
路，后来从大理段氏和星宿派分别传落，合而为一，称为吸星大法。
主要是继承了化功大法一路，修习者当令丹田常如空箱，恒似深谷，
空箱可贮物，深谷可容水。若有内息，散之于任脉诸穴。
    吸星大法只能拜任我行为师学习，非有相当机缘不能学到。

	学习要求：
		葵花心法
		基本内功10级
		尽量少的正气
		不能学习佛门心法
		散功
HELP
	);
	return 1;
}

