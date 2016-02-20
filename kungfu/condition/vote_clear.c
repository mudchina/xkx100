// vote_clear.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1)
	{
		if (duration > -5)
			tell_object(me, HIM"因为响应的人不多，对你的投票取消了。\n" NOR);
		me->delete("vote/reason");
		me->delete("vote/juror");
		me->delete("vote/count");
		return 0;
	}
	me->apply_condition("vote_clear", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "vote";
}
