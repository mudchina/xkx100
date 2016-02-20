// wuxing_poison.c 无形之毒

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int limit,limit1,limit2,limit3,limit4,damage;
  if (me->is_ghost()) return 1;
	damage = me->query("max_qi")/30;
	if(damage < 20) damage = 20;
	limit = me->query("con") + (int)me->query_skill("force",1) / 10;
	if(me->query_temp("nopoison")) return 0;
	if(limit >50) limit =49;
	limit1=50 - limit + 2;
	limit2=50 - limit*2/3;
	limit3=50 - limit/2;
	limit4=50 - limit/4;
	if( duration < limit1 && living(me) && !me->query_temp("noliving") )
	{
		tell_object(me,"你毒气攻心，心如刀绞，不由得大叫一声，一口鲜血狂喷而出。\n");
		message("vision", me->name() + "忽然大叫一声，口中鲜血狂喷不止，一头栽倒在地上。\n", environment(me), me);
		me->unconcious();
		me->die();
		return 0;
	}
	if( duration > limit4 )
	{
		tell_object(me,"你忽然觉得腹痛如绞，眼前一阵发黑，一定是吃了什么有毒的东西。\n");
		message("vision", me->name() + "忽然脸色苍白，豆大的汗珠从额头渗出。\n", environment(me), me);
	}
	if( duration > limit3 && duration < limit4)
	{
		tell_object(me,"你觉得肝肠寸断，全身痛苦得缩成一团，毒气似乎已经开始扩散了。\n");
		message("vision", me->name() + "嘴唇发青，牙关咬的咯咯直响，身子已经蜷缩成了一团。\n", environment(me), me);
	}
	if( duration > limit2 && duration < limit3)
	{
		tell_object(me,"你觉得四肢已经麻木，毒气已经升至小腹，快找解药吧，否则会死的。\n");
		message("vision", me->name() + "面上现出一股黑气，双目突出，眼中全是通红的血丝。\n", environment(me), me);
	}
	if( duration > limit1 && duration < limit2)
	{
		tell_object(me,"你觉得一阵天旋地转，毒气已升至胸口，快找解药吧，否则会死的。\n");
		message("vision", me->name() + "面上黑气越来越浓了，全身大汗淋漓，嘴角渗出了一缕黑血。\n", environment(me), me);
	}
	me->receive_wound("qi", damage,"无形之毒发作");
	me->receive_damage("jing", damage,"无形之毒发作");
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("wuxing_poison", duration - 1);
	if( !duration ) return 0;
	return 1;
}

string query_type(object me)
{
	return "poison";
}
