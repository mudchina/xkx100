// nbonze_jail.c 南少林监狱

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		me->move("/d/nanshaolin/shanmen");
		message("vision", HIY"只听乒地一声，你吓了一跳，定睛一看，\n原来是一个昏昏沉沉的家伙从大门里被扔了出来！\n" NOR, environment(me), me);
		tell_object(me, HIY"只觉一阵腾云驾雾般，你昏昏沉沉地被扔出了南少林寺！\n" NOR);
		me->set("startroom", START_ROOM);
		return 0;
	}
//	tell_object(me, "debug: " + duration + " beats more to go...\n");
	me->apply_condition("nbonze_jail", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "jail";
}

