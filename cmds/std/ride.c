// Filename : /cmds/std/ride.c
// Last Modified by winder on Aug. 5 2001
inherit F_CLEAN_UP;

#include <ansi.h>


int do_ride(object me, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, env;

	if( !arg ) return notify_fail("你要骑什么东西？\n");
	if( me->query_temp("is_riding") )
		return notify_fail("你已经有座骑了！\n");
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");
	if( me->is_fighting() )	return notify_fail("你还在战斗中！没空骑上去。\n");

	// Check if a container is specified.
	env = environment(me);

	if( !objectp(obj = present(arg, env)) || !living(obj) )
		return notify_fail("这里没有这样东西可骑。\n");
	if( !obj->query("ridable") &&
		obj->query_temp("owner") != me->query("id") )
		return notify_fail("这个东西你也要骑？当心你的屁股！\n");
	if( !living(obj) || obj->query_temp("noliving"))
		return notify_fail("这个东西自己都晕倒了，你怎么骑？\n");
	return do_ride(me, obj);
	write("骑上去了。\n");
}
	
int do_ride(object me, object obj)
{
	object old_env, *guard;

	if( !obj ) return 0;

	if( guard = obj->query_temp("guarded") )
	{
		guard = filter_array(guard, (: objectp($1) && present($1, environment($2)) && living($1) && ($1!=$2) :), me);
		if( sizeof(guard) )
			return notify_fail( guard[0]->name() + "正守在" + obj->name() + "一旁，防止任何人骑走。\n");
	}

	if( obj->move(me) )
	{
		message_vision("$N走近$n，飞身骑了上去，身手很是矫捷。\n", me, obj );
		obj->set_temp("is_rided_by", me);
		me->set_temp("is_riding", obj);
//骑动物增加膂力和身法。
/*
		if(obj->query("dex"))
			me->set_temp("apply/dexerity", obj->query("dex")/3);
		if(obj->query("str"))
			me->set_temp("apply/strength", obj->query("str")/3);
*/
	}
	else
	{
		message_vision("$N身上带的东西太重了，无法骑到$n身上去。\n", me, obj );
	}
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : ride <生物名>
 
    这个指令可以让你骑上代步的已驯养的动物。

    对于已经驯服的动物，可以进行下述指令：

基本指令：
        come <动物名>:                  让动物跟随主人行动。
        stay:                           停止动物的跟随状态。
        attack <某物>:                  让动物攻击敌人。
        stop <动物名>:                  让动物停止对人的攻击。
        release:                        结束主奴状态，将动物放离。

特殊指令：（只对某些动物适用）
        ride <动物名>:                  骑，如骑马，虎，雕，鲨等。
        unride <动物名>:                下，离开坐骑。
        feed <饲料> to <动物名>:        替动物喂食。
        imbibe <动物名>:                给动物饮水。

HELP
	);
	return 1;
}

