// Last Modified by Winder on May. 15 2001
// eat.c
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	object obj;

	if(!living(me) || me->query_temp("noliving") ) return 1;
	if(me->query("jing")<0 || me->query("qi")<0 )
		return notify_fail("你太累了，实在没力气吃什么了。\n");
	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if(!arg) return notify_fail("你要吃什么东西？\n");
	if(!objectp(obj = present(arg, me)) )
	{
		if(objectp(obj = present(arg, environment(me))) &&
			!obj->is_character())
			tell_room(environment(me), me->name() + "盯着地上的"+obj->name() + "，咽了一口唾沫。\n",({ me }));
		return notify_fail("你身上没有这样东西。\n");
	}
	if(!obj->query("food_supply") )
		return notify_fail("看清楚点，这东西能吃吗？\n");
	if(!obj->query("food_remaining") )
		return notify_fail( obj->name() + "已经没什么好吃的了。\n");
	if( me->query("food") >= me->max_food_capacity() )
		return notify_fail("你已经吃太饱了，再也塞不下任何东西了。\n");
		
	me->add("food", obj->query("food_supply"));
	if( obj->query("eat_func") ) return 1;
	if( !obj ) return 1;
	
	obj->set("value", 0);
	obj->add("food_remaining", -1);
	if((int)obj->query("food_busy"))
		me->start_busy(obj->query("food_busy"));
		
	if( !obj->query("food_remaining") )
	{
		obj->delete_temp("apply/long");
		if((string)obj->query("finish_msg"))
			message_vision(obj->query("finish_msg"), me, obj);
		else message_vision("$N将剩下的$n吃得干干净净。\n", me, obj);
		if( !obj->finish_eat() ) destruct(obj);
	} 
	else
	{
		if((string)obj->query("eat_msg"))
			message_vision(obj->query("eat_msg"), me, obj);
		else message_vision("$N拿起$n咬了几口。\n", me, obj);
	}
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : eat | chi <物品名称>
 
    这个指令就是吃，补充消耗的食物。但要注意有些食物可能是带毒的。
 
HELP
	);
	return 1;
}
 
