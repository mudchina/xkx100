// yubee.c

#include <condition.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	object bee;
	string *msg=({
HIR"\n$N手舞足蹈地想捉住一只"HIW"玉蜂"HIR"，可玉蜂一下子又飞开了。\n",
HIW"\n玉蜂"HIY"一会儿聚在一起，一会儿又散开，在$N头上跳起舞来。\n",
HIW"\n玉蜂"HIC"忽然一下子都不见了，$N着急地想把他们找出来，却怎么也找不着。\n",
HIW"\n玉蜂"HIM"在飞舞！穿梭在飘香的花雨中，恍若来自天国的舞者，吸引着你的目光。\n",
	});
	if( !duration || !me->query_temp("marks/bee1"))
	{
		me->apply_condition("yubee", 0);
		return 0;
	}
	if(duration == 1)
	{
		me->reincarnate();
		message_vision(HIY"玉蜂嗡地一声飞回蜂巢里面。$N喜道：该去取蜜了。\n"NOR,me);
		me->set_temp("marks/bee1",0);
//		bee=present("yu bee", environment(me));
//		destruct(bee);
		me->set_temp("marks/getmi",1);
		me->set_temp("marks/mihave",1);
		me->add_temp("marks/mi",1);
		return 0;
	}
//	if(me->query_temp("marks/bee1") && present("yu bee", environment(me)))
	{
		message_vision(msg[random(4)]+NOR,me);
	}
//	if(!present("yu bee", environment(me))) me->apply_condition("yubee", 0);
	me->apply_condition("yubee", duration - 1);
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "job";
}

