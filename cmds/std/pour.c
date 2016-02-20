// pour.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item, poison;
	object obj, dest, *inv, obj2;
	int i, amount, poisontime;

	if(!arg) return notify_fail("你要下什么毒？\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("你要往哪里下毒？\n");

	dest = present(target, me);
	if( !dest) return notify_fail("这里没有这样东西。\n");

	if( !objectp(obj = present(item, me)) )
		return notify_fail("你身上没有这样东西。\n");
	if( !obj->query("pour_type"))
		return notify_fail("这东西不能这样下毒的。\n");

	if( dest->query("liquid/remaining") < 1 )
	{
		tell_object(me, "里面一点喝的都没有是不能下毒的。\n");
		return 1;
	}
	message_vision( sprintf("$N将一%s%s偷偷洒进%s。\n",
		obj->query("unit"), obj->name(), dest->name()), me );
	poisontime = (int)(me->query_skill("poison",1)/5) + (int)(me->query_skill("five-poison",1)/5);
	poison = obj->query("pour_type");
	dest->set("liquid/poison", poison);
	dest->set("liquid/poisontime", poisontime);
	destruct(obj);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : pour <毒品名称> in <某容器>
 
    这个指令可以让你将某样毒品放进一个容器，当然，首先你要拥有
这样物品。容器里有喝的东西。
HELP
	);
	return 1;
}
