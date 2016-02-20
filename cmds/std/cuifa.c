// cuifa.c

inherit F_SSERVER;
#include <ansi.h>
void sanshi(object me, object target);

int main(object me, string arg)
{
	object target;
	if( me->is_fighting() ) return notify_fail("战斗中催发？找死吗？\n");
	if(me->query("family/master_id") != "ren woxing")
		return notify_fail("你不是任教主的弟子，无法催发丹药！\n");
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
	if ( !arg ) return notify_fail("你要催发谁身上的丹药？\n");
	if ( present(arg, environment(me)) )
		return notify_fail("你要催发的人就在你身边，不怕被砍？\n");
	target = find_player(arg);
	if (!target) target = find_living(arg);
	if (!target || !me->visible(target)) return notify_fail("你要催发的人现在没在吧？\n");

	write( HIW "你盘膝坐下来开始催发三尸脑神丹。\n" NOR);
	message("vision", HIW + me->name() + "运起吸星大法，盘膝坐下，开始催发三尸脑神丹。\n" NOR, environment(me), me);
	me->add("neili", -300);
	me->start_busy(5);
	me->start_call_out( (: call_other,__FILE__,"sanshi",me,target :),5);
	return 1;
}
void sanshi(object me, object target)
{
	message_vision("$N盘膝而坐，嘴里不知道念叨着什么。\n",me);
	if (!target->query("sanshi") )
	{
		tell_object(me, "你忽然觉得不对头，"+target->query("name")+"体内没有被种尸虫！\n");
		return;
	}
	if (target->query("sanshi") != me->query("id"))
	{
		tell_object(me, "你忽然觉得不对头，"+target->query("name")+"体内种的不是你的尸虫！\n");
		return;
	}
	tell_object(target, "你忽然觉得头不知什么原因疼了起来，渐渐痛不可抑。猛然想起是尸虫发作，只觉得头脑一轰，就什么也不知道了！\n");
//	target->die();
	target->delete("sanshi");
	target->receive_wound("qi", 10000,"三尸脑神丹突发而亡。真是可惜。");
	target->receive_damage("qi", 10000,"三尸脑神丹突发而亡。真是可惜。");
	target->receive_wound("jing", 10000,"三尸脑神丹突发而亡。真是可惜。");
	target->receive_damage("jing", 10000,"三尸脑神丹突发而亡。真是可惜。");
//message("channel:rumor", MAG"【谣言】某人："+target->query("name")+"三尸脑神丹突发而亡。真是可惜！\n"NOR, users());
	return;
}

int help(object me)
{
	write(@HELP
指令格式 : cuifa <人物>
 
    这个指令让你催发一个人物身上的三尸脑神丹。当然，只有吃了
你的三尸脑神丹的人才会被你催发。

HELP
	);
	return 1;
}
 
