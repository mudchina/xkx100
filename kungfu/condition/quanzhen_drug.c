// quanzhen_drug.c
// 用以控制全真炼丹和吃药。

#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) return 0;
	me->apply_condition("quanzhen_drug", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "drug";
}

