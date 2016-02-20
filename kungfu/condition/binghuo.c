// binghuo.c

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !living(me) || me->query_temp("noliving") )
		message("vision", me->name() + "打了个嗝，口里吐出一股蓝红之气。\n", environment(me), me);
	else
		message("vision", me->name() + "摇头晃脑地站都站不稳，手心尽是蓝红的斑点。\n", environment(me), me);

	me->apply_condition("binghuo", duration - 1);
	if( !duration ) return 0;
	return 1;
}

string query_type(object me)
{
	return "drunk";
}

