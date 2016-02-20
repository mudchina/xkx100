// /cmds/usr/finger.c

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	int i;
	if( !arg ) {
		if( (int)me->query("jing") < 50 )
			return notify_fail("你的精神无法集中。\n");
		if( !wizardp(me) )
			me->receive_damage("jing", 50);
		me->start_more( FINGER_D->finger_all() );
	} else {
		for (i = 0; i < sizeof(arg); i++)
        		if (arg[i]<'a' || arg[i]>'z')
                           return notify_fail("没有这个人存在。\n"); 
		if( (int)me->query("jing") < 15 )
			return notify_fail("你的精神无法集中。\n");
		if( !wizardp(me) )
			me->receive_damage("jing", 15);
		write( FINGER_D->finger_user(arg) );
	}
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : finger [使用者姓名]
 
    这个指令，如果没有指定使用者姓明，会显示出所有正在线上玩家
的连线资料。反之，则可显示有关某个玩家的连线，权限等资料。
 
see also : who
HELP
	);
	return 1;
}
 
