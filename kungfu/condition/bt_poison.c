// Last Modified by winder on May. 15 2001
// bt_poison.c 白驼怪蛇毒
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	if( !living(me) || me->query_temp("noliving") ) return CND_CONTINUE;
	tell_object(me, HIB "你忽然感到身体僵直，已经不听使唤了。\n" NOR);
	me->receive_wound("qi", 50,"体内怪蛇之毒发作");
	if(userp(me)) me->receive_wound("jing", 60,"体内怪蛇之毒发作");
	else me->receive_wound("jing", 80,"体内怪蛇之毒发作");
	if( me->query("jing") > 301)
		tell_room(environment(me),YEL+me->name()+"突然只膝弯曲，身子慢慢垂下，口中发出似人似兽的荷荷之声。\n" NOR, ({ me }));
	else
		if( me->query("jing") < 450 && me->query("jing") > 301)
			tell_room(environment(me),BLU+me->name()+"忽然满面堆欢裂嘴嘻笑，更显得诡异无伦。\n" NOR, ({ me }));
		else
			if( me->query("jing") < 300 && me->query("jing") > 201)
				tell_room(environment(me),HIB+me->name()+"此时神智更加胡涂，指东打西，乱□乱咬。\n" NOR,({ me }));
			else tell_room(environment(me), HIR+me->name()+"突然缩成一团，滚在地上不停地发颤。\n" NOR,({ me }));
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	if( duration < 1 ) return 0;
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("bt_poison", duration - 1);
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
