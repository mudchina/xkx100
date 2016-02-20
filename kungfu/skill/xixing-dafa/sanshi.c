// sanshi.c

#include <ansi.h>
void mess(object me);

int exert(object me, object target)
{		
/*  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/sanshi") &&
  !me->query("can_perform/xixing-dafa/sanshi") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");*/
	if( me->is_fighting() ) return notify_fail("战斗中炼丹？找死吗？\n");

	if(me->query("family/master_id") != "ren woxing")
		return notify_fail("你不是任教主的弟子，无法炼制丹药！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if((int)me->query_skill("xixing-dafa", 1) < 100)
		return notify_fail("你的吸星大法修为还不够。\n");
	if((int)me->query_skill("kuihua-xinfa", 1) < 100)
		return notify_fail("你的葵花心法修为太低。\n");
	if((int)me->query("qi") < 300) 
		return notify_fail("你的气不够。\n");
	if((int)me->query("neili") < 400) 
		return notify_fail("你的真气不够。\n");
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2)
		return notify_fail("你受伤过重，只怕一运真气便有生命危险！\n");

	write( HIW "你坐下来开始运功炼制丹药。\n" NOR);
	message("vision",
		HIW + me->name() + "运起吸星大法开始炼制丹药。\n" NOR,
		environment(me), me);
	me->add("neili", -300);
	me->add("max_neili", -10);
	me->set("jiali", 0);
	me->start_busy(5);
	me->start_call_out( (: call_other,__FILE__,"mess",me :),5);
	return 1;
}
void mess(object me)
{
	object ob;
	int now_qi = me->query("eff_qi");
	message_vision("$N盘膝而坐，伸起三指打了个诀，渐渐的头上渗出一粒粒豆大的冷汗。真累！\n",me);
	me->receive_wound("qi", now_qi - 30);
	me->set("qi", me->query("eff_qi"));
	if (random(10) > 6)
	{
		seteuid(getuid());
		ob=new("/clone/medicine/nostrum/sanshi");
		message_vision("$N炼成三尸脑神丹了。\n",me);
		ob->set("owner", me->query("id"));
		ob->move(me);
	}
	else
		message_vision("$N白折腾了。没炼成三尸脑神丹了。\n",me);
	return;
}

int help(object me)
{
	write(WHT"\n吸星大法之三尸"NOR"\n");
	write(@HELP

	使用功效：
		炼制三尸脑神丹
		吸星大法炼制的三尸脑神丹，为天下第一毒药，中毒者
		的生死，就完全操在炼丹者是否催发的一念间。
		请help cuifa

	出手要求：
		葵花心法100级
		吸星大法100级
		内力400
		气血300
		身为任我行的嫡传弟子
HELP
	);
	return 1;
}

