// follow.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) return notify_fail("指令格式：follow <某人>|none。\n");

	if( arg=="none")
		if( me->query_leader() )
		{
			me->set_leader(0);
			write("你决定不再跟随任何人了。\n");
			return 1;
		} else {
			write("你现在并没有跟随任何人。\n");
			return 1;
		}
	if( me->is_ghost())
	{
                write("你是鬼魂，不能跟随行走。\n");
		return 1;
	}
	if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail("这里没有 " + arg + "。\n");
	if( !ob->is_character() )
		return notify_fail("什么？跟随...." + ob->name() + "。\n");
	if( ob->query_leader() == me )
	{
		write("人家已经在跟随你了耶！\n");
		return 1;
	}
/* 不允许旋环follow，避免宕机*/
	if( ob==me )
	{
		write("跟随自己？亏你想得出来！\n");
		return 1;
	}
	if( ob->query_leader() && !(wizardp(me) && me->query("env/invisibility")))
	{
		write("人家已经在跟随别人跑呢，你恐怕跟不上耶！\n");
		return 1;
	}

	me->set_leader(ob);
  if (!me->query("env/invisibility"))
	message_vision("$N决定开始跟随$n一起行动。\n", me, ob);

	return 1;
}

int help (object me)
{
	write(@HELP
指令格式 : follow [<生物>|none]
 
    这个指令让你能跟随某人或生物。不能跟随已经在跟随别人的生物。
    如果输入 follow none 则停止跟随。
    （你可能会问：如果玩家的ｉｄ也是ｎｏｎｅ，该怎么做才能跟随他
（她）？仔细想想啦，很容易做的。：)

 
HELP );
	return 1;
}
