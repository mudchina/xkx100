// putizi_drug.c

#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) return 0;
	me->apply_condition("putizi_drug", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "drug";
}

