// beimin-shengong.c 北冥神功
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int valid_enable(string usage) { return usage=="force"; }
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	int i, lvl = (int)me->query_skill("beiming-shengong", 1);

	if(me->query("family/family_name")!="逍遥派")
		return notify_fail("只有逍遥弟子才能学北冥神功。\n");
	if ( me->query_skill("force",1) < 10)
		return notify_fail("你的基本内功火候还不够，难以领会北冥神功。\n");
	if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的北冥神功。\n");
	return valid_public(me,"bahuang-gong");
}

int practice_skill(object me)
{
	return notify_fail("北冥神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}
/* 被击中对方的副作用，目前主要用在内功上 factor= 加力 damage_bonus=臂力 */
mixed be_hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap, dp;
	int jiali;
	string msg;
	
	
	  if ((int) me->query_skill("beiming-shengong", 1) < 70 ||
            ! living(me) 
     	  || victim->query_skill_mapped("force") == "taixuan-gong"
				)
       return;
       if (!me->query("perform/shield") 
       && !SCBORN_D->valid_learn(me,"beiming-shengong"))
       return ;
   jiali=factor;
   if ( jiali <1 || victim->query("id")=="songyang" /*给布袋打木人开个后门*/ )
      return;

	ap=me->query_skill("force");
	dp=victim->query_skill("force");
	switch (random(4))
                {
                case 0:
                        msg=HIM "$N" HIM "只觉得内力源源而泻，不由得大吃一惊。\n" NOR;
                        break;
                case 1:
                        msg=HIM "$N" HIM "只觉得发出的内力犹如石沉大海，不知所踪。\n" NOR;
                        break;
                case 2:
                        msg=HIM "$N" HIM "只觉得发出的内力犹无影无踪，浑然不知着落。\n" NOR;
                        break;
                default:
                        msg=HIM "$N" HIM "不住催动内力，但是只觉得$n竟似毫不费力。\n" NOR;
                        break;
                }

	if (dp/2+random(dp)<ap )
	{

//		message("vision",msg,environment(me));
    if (victim->query("neili")>0)
		   {
		   	victim->add("neili",-(jiali+ap/6));
    		if (me->query("neili") < me->query("max_neili") * 2)
          	me->add("neili", ap/6+jiali);
      	return msg;
        }
	}
	return 0;
}

string exert_function_file(string func)
{
	return __DIR__"beiming-shengong/" + func;
}
int help(object me)
{
	write(HIC"\n北冥神功："NOR"\n");
	write(@HELP

    北冥神功为逍遥派无上内功。
    庄子‘逍遥游’有云：‘穷发之北有冥海者，天池也。有鱼焉，
其广数千里，未有知其修也。’又云：‘且夫水之积也不厚，则其
负大舟也无力。覆杯水于坳堂之上，则芥为之舟；置杯焉则胶，水
浅而舟大也。’是故逍遥派武功，以积蓄内力为第一要义。内力既
厚，天下武功无不为我所用，犹之北冥，大舟小舟无不载，大鱼小
鱼无不容。是故内力为本，招数为末。北冥神功系引世人之内力而
为我有。北冥大水，非由自生。语云：百川汇海，大海之水以容百
川而得。汪洋巨浸，端在积聚。
    世人练功，皆自云门而至少商，我逍遥派则反其道而行之，自
少商而至云门，拇指与人相接，彼之内力即入我身，贮于云门等诸
穴。然敌之内力若胜于我，则海水倒灌而入江河，凶险莫甚。逍遥
派旁支，未窥要道，惟能消敌内力，不能引而为我用，犹日取千金
而复弃之于地，暴殄珍物，殊可哂也。

	学习要求：
		基本内功10级
		太监无法学到50级以上的北冥神功
HELP
	);
	return 1;
}

