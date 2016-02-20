// wuguan_job.c
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	me->apply_condition("wuguan_job", duration - 1);
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "job";
}
