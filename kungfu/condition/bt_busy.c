// bt_stop.c

//#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		return 0;
	}
	me->apply_condition("bt_busy", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "job";
}
