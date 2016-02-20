// shengjing.c

#include <ansi.h>
void mess(object me);

int exert(object me, object target)
{		
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/shengjing") &&
  !me->query("can_perform/xiantian-qigong/shengjing") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");
	if( me->is_fighting() ) return notify_fail("战斗中炼丹？找死吗？\n");

	if(me->query("class") != "quanzhen")
		return notify_fail("你不是玄门清修之士，无法炼制丹药！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if(me->query_condition("quanzhen_drug")>0)
		return notify_fail("你刚接触丹药不久，不宜再炼。\n");
	if((int)me->query_skill("xiantian-qigong", 1) < 80)
		return notify_fail("你的先天气功修为还不够。\n");
	if((int)me->query("neili") < 300) 
		return notify_fail("你的真气不够。\n");
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2)
		return notify_fail("你受伤过重，只怕一运真气便有生命危险！\n");

	write( HIW "你坐下来开始运功炼制丹药。\n" NOR);
	message("vision",
		HIW + me->name() + "运起先天气功开始炼制丹药。\n" NOR,
		environment(me), me);
	me->add("neili", -200);
	me->set("jiali", 0);
	me->start_busy(5);
	me->start_call_out( (: call_other,__FILE__,"mess",me :),5);
	me->apply_condition("quanzhen_drug", 15);
	return 1;
}
void mess(object me)
{
	object ob;
	if (random(10) > 7)
	{
		seteuid(getuid());
		ob=new("/clone/medicine/nostrum/shengjingdan");
message_vision("$N盘膝而坐，两掌合十，渐渐的掌缝中露出一线碧绿的光芒，有一粒
"+HIG"凌霄生精丹"NOR+"啪的一声，掉在膝上。\n",me);
		ob->move(me);
	}
	else
	{
message_vision("$N盘膝而坐，两掌合十，渐渐的头上渗出一粒粒豆大的冷汗，慢慢地
委顿在地。好累啊！\n",me);
	}
	return;
}

int help(object me)
{
	write(WHT"\n先天气功之生精"NOR"\n");
	write(@HELP

	使用功效：
		炼制凌霄生精丹

	出手要求：
		先天气功80级
		内力300
		身为全真门下道士
HELP
	);
	return 1;
}

