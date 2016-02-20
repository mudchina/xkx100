// xx_poison.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	if( duration < 1 ) return 0;
	if( !living(me) || me->query_temp("noliving") )
	{
		message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
	}
	else
	{
		tell_object(me, HIB"忽然一阵刺骨的奇寒袭来，你中的星宿掌毒发作了！\n"NOR );
		message("vision", me->name() + "的身子突然晃了两晃，牙关格格地响了起来。\n", environment(me), me);
	}
	me->receive_wound("qi",35 + random(10), "星宿掌毒发作");
	me->receive_wound("jing", 20, "星宿掌毒发作");
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("xx_poison", duration - 1);

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
