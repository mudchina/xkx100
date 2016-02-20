// jiasi.c
inherit F_CLEAN_UP;

#include <ansi.h>

int main(object me, string arg)
{
//	if(me->query("class") != "bandit")
//		return notify_fail("名门正派的人不可以装死！\n");
//	if(me->query("shen") > 10000 )
//		return notify_fail("名门正派的人怎么可以装死！\n");
	seteuid(getuid());
	if( !me->is_fighting() )
		return notify_fail("你不在战斗中，不需要假装死。\n");
	if(me->query("qi")/me->query("max_qi")*100>20 &&
		me->query("jing")/me->query("max_jing")*100>20)
		return notify_fail("没受什么伤就想装假死，傻子也看得出来。\n");
	if(me->query_temp("jiasi"))
			return 1;
//		return notify_fail("你正在为假死做准备。\n");
//	if(me->query_temp("sleepd")) 
//		return notify_fail("你现在没办法假死。\n");
	me->set_temp("jiasi",1);
	me->add_temp("no_sleep",1);
	me->start_call_out((: call_other, __FILE__, "begin_jiasi",me :),3);
	return 1;
}
void begin_jiasi(object me)
{
	int wimpy;
	if (!me->is_fighting() || sizeof(me->query_temp("noliving")) > 0
	   || (int)me->query("jing")<0 || (int)me->query("qi")<0 ) 
	{
		me->delete_temp("jiasi");
		me->add_temp("no_sleep",-1);
		return;
	}
	wimpy = (int)me->query("env/wimpy");
	message_vision("$N惨叫一声，一头栽倒在地下。$N死了。\n",me);
	me->set_temp("disable_inputs",1);
	me->set_temp("block_msg/all",1);
	if(userp(me)) me->set_temp("noliving/fakedie", 1);
	else me->disable_player(HIG "<装死中>" NOR);
	me->set("no_put",1);
	me->set("no_get",1);
	me->set("no_get_from",1);
	me->remove_all_killer();
	me->remove_all_enemy();
	me->delete("env/wimpy");
	me->start_call_out( (: call_other, __FILE__, "remove_jiasi", me, wimpy :), random(120 - (int) me->query_con()));
}

void remove_jiasi(object me, int wimpy)
{
	int t=0;
	me->delete_temp("disable_inputs");
	me->set("env/wimpy",wimpy);
	me->delete("no_get_from");
	me->delete("no_put");
	me->delete("no_get");
	me->delete_temp("jiasi");
	me->delete_temp("no_sleep");
	if(userp(me)) me->delete_temp("noliving");
	else me->enable_player();
	me->delete_temp("block_msg/all");
	message_vision("$N在地上悄悄地翻了个身，小心翼翼地睁开了眼。\n",me);
	while(environment(me) && environment(environment(me)) && t<10 )
	{
			me->move(environment(environment(me)),1);
			t++;
	}
}

int help(object me)
{
	write(@HELP
指令格式 : jiasi

    让你在战斗中装死，创造逃生的机会。

HELP
	);
	return 1;
}
 
