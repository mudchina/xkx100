// qiangpo.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string dest, cmd;
	object ob;

	if( me != this_player() ) return 0;

	me = this_player();

	if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
		return notify_fail("指令格式: qiangpo <某人> to <指令>\n");
//	if (!ob = get_object( dest ) )	
	if( !objectp(ob = present(dest, environment(me))))
		return notify_fail("找不到" + dest + "。\n");
	if( !living(ob) )
		return notify_fail("这个物件不能执行命令。\n");
	if( wiz_level(me) < wiz_level(ob) )
		return notify_fail("你没有强制" + ob->name() + "执行指令的权力。\n");
	if( userp(ob) )
		log_file("force_player", sprintf("[%s] %s forces %s to %s\n",  
			ctime(time()), geteuid(me), geteuid(ob), cmd));
	return ob->force_me(cmd);
}

int help(object me)
{
	write(@Help
 指令格式: qiangpo <某人> to <指令>

 强迫某人做某事, 但你的巫师等级必须比对方高。
Help
	);
	return 1;
}
