// drunk.c
#include <combat.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

  if (me->is_ghost()) return 1;
	if( !living(me) ) {
		message("vision", me->name() + "身上的伤口尚未痊愈, 但是觉得似乎油尽灯枯了!!\n",
			environment(me), me);
	} else if( duration > 20 ) {
		tell_object(me, "你的伤口似乎很严重, 血流不止.\n");
		message("vision", me->name() + "身上的伤口血流如注, 显然受伤十分严重. \n",
			environment(me), me);
		me->receive_wound("qi", 20,"伤势过重");
	} else if( duration > 10 ) {
		tell_object(me, "你觉得身上的伤口开始密合了, 血流量也变少了. \n");
		message("vision", me->name() + "似乎受伤不轻, 身上血迹班班. \n",
			environment(me), me);
		me->receive_wound("qi", 10,"伤势过重");
	} else if( duration > 5 ) {
                tell_object(me, "你身上的伤口开始结疤了, 也感觉不到痛苦了. \n");
                message("vision", me->name() + "的身上有一道新疤, 好像受到不轻的伤害. \n",
                        environment(me), me);
                me->receive_wound("qi", 5,"伤势过重");
	}
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("bleeding", duration - 1);
//	COMBAT_D->report_status(me, 1);
	if( !duration )
	 	return 0;
	return 1;
}
