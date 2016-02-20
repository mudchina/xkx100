// kungfu/skill/taixuan-gong/taixuan
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
   int skill;
   if ( userp(me) && !wizardp(me) && 
//  !me->query("perform/taixuan") &&
  !me->query("can_perform/taixuan-gong/taixuan") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

   if( target != me ) 
      return notify_fail("你只能对自己用["+HIW+"白首太玄"+NOR+"]\n"NOR,);
	 if ((int)me->query_skill("taixuan-gong", 1) < 100)
		  return notify_fail("你的太玄神功太差了。\n");
   if( (int)me->query("neili") < 100 ) 
  	  return notify_fail("你的内力不够。\n");
   if( (int)me->query_temp("powerup") ) return
       notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("taixuan-gong",1);

        me->add("neili", -100);
        me->receive_damage("qi",0);

        message_combatd(
HIW"$N突然一声长吟，极快的念出了一首诗来，旁人细听之下不由大惊!!!!!\n原来这居然竟是传说中的天下奇功【白首太玄经】！\n" NOR, me);
        me->add_temp("apply/attack", skill/3);
        tell_object(me,HIR"你的攻击力提高了!\n"NOR);
        me->add_temp("apply/dodge", skill/3);
        tell_object(me,HIR"你的防御力提高了!\n"NOR);
        me->set_temp("powerup", 1);
        me->add_temp("apply/strength",skill/40);
        tell_object(me,HIG"你的力量提高了!\n"NOR);
        me->add_temp("apply/dexerity",skill/40);
        tell_object(me,HIG"你的速度提高了!\n"NOR);
        me->add_temp("apply/constitution",skill/40);
        tell_object(me,HIG"你的根骨提高了!\n"NOR);
        me->add_temp("apply/intelligence",skill/40);
        tell_object(me,HIG"你的悟性提高了!\n"NOR);
        me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill:),skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int skill)
{
        me->add_temp("apply/attack", - skill/3);
        me->add_temp("apply/dodge", - skill/3);
        me->delete_temp("powerup");
        me->add_temp("apply/strength",- skill/40);
        me->add_temp("apply/intelligence",- skill/40);
        me->add_temp("apply/constitution",- skill/40);
        me->add_temp("apply/dexerity" , - skill/40);
        tell_object(me, "你的"+HIW+"【白首太玄】"+NOR+"运行完毕，将内力收回丹田。\n");
}
int help(object me)
{
		write(WHT"\n太玄功之【白首太玄经】"NOR"\n");
	write(@HELP

	使用功效：
		增加攻击力、防御力
		暂时提升后天臂力、悟性、根骨、身法

	出手要求：
		从侠客岛石壁参悟
		太玄功100级
		内力100
HELP
	);
	return 1;
}
