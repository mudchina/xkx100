// save.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object link_ob;

	seteuid(getuid());

	if( !wizardp(me) && time()-me->query("last/lastsave") < 30)
		return notify_fail("你刚存过盘，不会丢数据，不必连续存盘。\n");

	if( !objectp(link_ob = me->query_temp("link_ob")) )
		return notify_fail("你不是经由正常连线进入，不能储存。\n");

	if( environment(me)->query("valid_startroom") || wizardp(me) )
	{
		me->set("startroom", base_name(environment(me)));
		write("当你下次连线进来时，会从这里开始。\n");
	}
	me->set("last/lastsave", time());
	if( (int)link_ob->save() && (int)me->save() )
	{
		write("档案储存完毕。\n");
		return 1;
	} else {
		write("储存失败。\n");
		return 0;
	}
}

int help(object me)
{
	write(@HELP
指令格式：save

    把你辛苦奋斗的结果存起来。
HELP
	);
	return 1;
}
