// bt_stop.c

//#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		tell_object(me, "你可以再去为知府大人效力了！\n");
		return 0;
	}
	me->apply_condition("bt_stop", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "job";
}
