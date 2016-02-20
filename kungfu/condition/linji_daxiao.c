// linji_daxiao.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration == 0 )
	{
		tell_object(me, 
HIB "忽然你全身感到一阵乏力，一肚皮不自在，原来你的大小庄收功了！\n" NOR );
		me->add("max_jing", me->query("linji/jing"));
		me->add("eff_jing", me->query("linji/jing"));
		me->add("jing", me->query("linji/jing"));
		me->add("max_qi", 0 - 2 * me->query("linji/jing"));
		if (me->query("eff_qi") > me->query("max_qi"))
			me->set("eff_qi", me->query("max_qi"));
		if (me->query("qi") > me->query("eff_qi"))
			me->set("qi", me->query("eff_qi"));
		if (me->query("eff_jing") > me->query("max_jing"))
			me->set("eff_jing", me->query("max_jing"));
		if (me->query("jing") > me->query("eff_jing"))
			me->set("jing", me->query("eff_jing"));
		me->delete("linji/jing");
		me->save();
		return 0;
	}
	me->apply_condition("linji_daxiao", duration - 1);

	return CND_CONTINUE;
}

string query_type(object me)
{
	return "force";
}

