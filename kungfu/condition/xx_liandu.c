// Last Modified by Winder on Apr. 25 2001

#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1) return 0;
	me->apply_condition("xx_liandu", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "busy_time";
}
