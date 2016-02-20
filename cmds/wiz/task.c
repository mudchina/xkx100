
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string str)
{
	string output;
	
	output = HIC"≡" + HIG"────────────" + HIG" 飞雪连天任务榜 " + HIG"────────────" + HIC"≡\n"NOR;
    	output += TASK_D->dyn_quest_list();
	output += HIC"≡" + HIG"──────────────────────────────" + HIC"≡\n"NOR;
	output += "前面带√的表示该任务已完成。";
	me->start_more(output);
	
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: task

这个指令是用来得知目前的所有使命.

HELP
	);
	return 1;
}
