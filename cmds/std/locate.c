// /cmds/std/locate.c

// Created by Constant Jan 4 2001

inherit F_CLEAN_UP;

int main(object me, string str)
{
	string output = "";
	
	if (!str) return notify_fail("指令格式: locate <物品>\n");
	if(me->query("jing") < 10)
		return notify_fail("抱歉，你没有精气探知此物方位。\n");
	me->receive_damage("jing", 10+random(10));
	output = TASK_D->locate_obj(me, str);
	if (output=="") return notify_fail("抱歉，无法探知此物方位。\n");
	write(output);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: locate <物品>

    用来得知任务物品的大致位置。

HELP
	);
	return 1;
}
