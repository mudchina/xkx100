// huagong-dafa.c 化功大法
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("huagong-dafa", 1);
	int t = 1, j;
	for (j = 1; j < i / 10; j++) t*= 2;

	if(me->query("family/family_name")!="星宿派")
		return notify_fail("只有星宿弟子才能学化功大法。\n");
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学化功大法。\n");
	if (i > 10 && (int)me->query("shen") > t * 100)
		return notify_fail("学化功大法，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
	if ( me->query_skill("buddhism",1) )
		return notify_fail("你练了秃驴们的心法，还学化功大法做什麽！\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("化功大法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"huagong-dafa/" + func;
}
/* 被击中对方的副作用，目前主要用在内功上 factor= 加力 damage_bonus=臂力 */
mixed be_hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap, dp;
	int jiali;
	string msg;
  if ((int) me->query_skill("huagong-dafa", 1) < 70 ||
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
                        msg=HIB "$N" HIB "只觉得内力源源而泻，不由得大吃一惊。\n" NOR;
                        break;
                case 1:
                        msg=HIB "$N" HIB "只觉得发出的内力犹如石沉大海，不知所踪。\n" NOR;
                        break;
                case 2:
                        msg=HIB "$N" HIB "只觉得发出的内力犹无影无踪，浑然不知着落。\n" NOR;
                        break;
                default:
                        msg=HIB "$N" HIB "不住催动内力，但是只觉得$n竟似毫不费力。\n" NOR;
                        break;
                }

//if (dp/2+random(dp)<ap)  // 北冥同等级1/2几率
	if (dp*2/3+random(dp)<ap)	//同等级1/3几率
//化功大法源自北冥 重用毒，内功上面比北冥弱
	{

//		message("vision",msg,environment(me));
    if (victim->query("neili")>0)
		   {
		   	victim->add("neili",-(ap/6+jiali));
    		if (me->query("neili") < me->query("max_neili") * 2)
        	{
         //   	me->add("neili", ap/6+jiali);//化功不算吸内力？
        	}
        	return msg;
        }
	}
	return 0;
}
int help(object me)
{
	write(HIC"\n化功大法："NOR"\n");
	write(@HELP

    星宿祖师丁春秋原为逍遥派无崖子之徒，无崖子精通北冥神功，
但未授与丁春秋。后丁春秋叛师出门，凭着过人的智慧，吸收北冥
神功的精髓，自创出一套化功大法，与北冥神功各擅胜场，难分轩
轾。

	学习要求：
		基本内功10级
		不能学禅宗心法
		相应的戾气
HELP
	);
	return 1;
}

