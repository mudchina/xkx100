// Last Modified by Winder on May. 15 2001
// drink.c
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	object obj;
	
	if( !living(me) || me->query_temp("noliving") ) return 1;
	if( me->query("jing")<0 || me->query("qi")<0 )
		return notify_fail("你太累了，实在没力气喝东西了。\n");
	if( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if( (int)me->query("water") >= me->max_water_capacity() )
		return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");
	if(!arg)
	{
		obj = environment(me);
		if(!obj->query("resource/water"))
			return notify_fail("这地方可没水。\n");
	
		if((string)obj->query("drink_msg"))
			message_vision(obj->query("drink_msg"), me);
		else message_vision("$N捧起一些清水，慢慢喝了下去。\n", me);
		me->add("water", 20);
		if( obj->query("liquid/drink_func") ) return 1;
		return 1;
	}
	
	else if(!objectp(obj = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");
	if(!obj->query("liquid") )
		return notify_fail("看清楚点，这东西装有喝的吗？\n");
	if(!obj->query("liquid/remaining") )
		return notify_fail( obj->name() + (obj->query("liquid/name") ? "已经被喝得一滴也不剩了。\n":"是空的。\n"));
	me->add("water", 10+((int)obj->query("liquid/drunk_apply")?obj->query("liquid/drunk_apply"):20));
	obj->add("liquid/remaining", -1);

	if((int)obj->query("liquid/busy"))
		me->start_busy(obj->query("liquid/busy"));

	if((string)obj->query("drink_msg"))
		message_vision(obj->query("drink_msg"), me, obj);
	else message_vision("$N拿起$n咕噜噜地喝了几口" + obj->query("liquid/name")+ "。\n", me, obj);
	if( obj->query("liquid/poisontime") > 1 )
	{
		me->apply_condition(obj->query("liquid/poison"), obj->query("liquid/poisontime") );
		write("你突然觉得喝的东西有点不对劲。可已经来不及了。\n");
	}
	if( !obj->query("liquid/remaining") )
	{
		if((string)obj->query("finish_msg"))
			write(obj->query("finish_msg"));
		else write("你已经将" + obj->name() + "里的" + obj->query("liquid/name")+ "喝得一滴也不剩了。\n");
	}

	if( obj->query("liquid/drink_func") ) return 1;
	if (!obj) return 1;

	switch(obj->query("liquid/type"))
	{
		case "alcohol":
			me->apply_condition("drunk",(int)me->query_condition("drunk")+ (int)obj->query("liquid/drunk_apply"));
			break;
	}
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : drink | he [物品名称]
 
    这个指令就是喝，补充消耗的水分。但要注意有些饮料可能是带毒的。
    如果你身上带着器皿且里面还有水，可以drink <器皿>
    如果你所在的地方有水源的话，可以直接用drink来喝水。
	
HELP
	);
	return 1;
}
 
