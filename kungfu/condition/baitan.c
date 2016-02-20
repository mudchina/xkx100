// ss_poison.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	if( duration < 1 ) return 0;
	if (file_name(environment(me))!=me->query_temp("baitan_place"))
	{
		"/cmds/std/baitan.c"->halt_baitan(me,1);
		return 0;
	}
	"/cmds/std/baitan.c"->baitan(me);
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "job";
}
