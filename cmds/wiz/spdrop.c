// drop.c

inherit F_CLEAN_UP;


int do_drop(object me, object obj);
int all;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, *inv, obj2;
	int i, amount;
	string item;
 	all=0;
 	if(!arg) return notify_fail("你要丢下什么东西？\n");

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

	if(sscanf(arg, "%d %s", amount, item)==2)
	{
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");
		if( stringp(obj->query("no_drop")) )
			return notify_fail( (string)obj->query("no_drop") );
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分开丢弃。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() )
			return notify_fail("你没有那么多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_drop(me, obj);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_drop(me, obj2);
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		if (sizeof(inv)>=20) all=1;
		for(i=0; i<sizeof(inv); i++) {
			do_drop(me, inv[i]);
		}
		if (all!=1)
		  write("Ok.\n");
    else
      message_vision("$N把身上的东西都丢了下来。\n",me); 
	return 1;
	}

	if(!objectp(obj = present(arg, me)))
		return notify_fail("你身上没有这样东西。\n");
	return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
	mixed no_drop;

	if( obj->query_temp("is_rided_by") == me)
		return notify_fail( obj->name() + "不是正被你骑着。\n");
//	if( no_drop = obj->query("no_drop") )
//		return notify_fail( stringp(no_drop) ? no_drop : "这样东西不能随意丢弃。\n");
//	if( no_drop = environment(me)->query("no_drop") )
//		return notify_fail( stringp(no_drop) ? no_drop : "这里东西丢弃下去也看不见。\n");
//  if ( !me->visible(obj))
//    return 0;
	if (obj->move(environment(me))) {
		if (all!=1)
		{
		if( obj->is_character() )
			message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
		else {
			message_vision( sprintf("$N丢下一%s$n。\n",	obj->query("unit")), me, obj );
		if (obj->query("no_value")) obj->set("value",0);
		if( !obj->query("value") && !obj->value() )
				write( "因为这样东西并不值钱，所以人们并不会注意到它的存在。\n");
      }
    }		
	if( !obj->query("value") && !obj->value() && !obj->is_character() )
      		destruct(obj);    
		return 1;
	}
	return 0;
}

int help(object me)
{
	write(@HELP
指令格式 : drop <物品名称>
           drop all

    这个指令可以让你丢下你所携带的物品。ａｌｌ参数将会把能丢掉
的东西全丢掉。
 
HELP
    );
    return 1;
}
 
