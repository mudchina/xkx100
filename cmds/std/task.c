// /cmds/std/task.c

// Created by Constant Jan 4 2001
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string str)
{
	string output;

	output = HIC"\n≡" + 
		 HIY"━━━━━━━━━━━━"+ 
		 HIC"飞雪连天任务榜" + 
		 HIY"━━━━━━━━━━━━"+ 
		 HIC"≡\n"NOR;

	output += HIG"       「任务物品」" + 
		"                " + 
		"          「物品主人」\n"NOR;

	output += HIY"  ───────────────────────────────"NOR + "\n";

	if (!str || str != "-u") output += TASK_D->dyn_quest_list(0);
	else output += TASK_D->dyn_quest_list(1);

	output += HIC"≡"HIY"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"HIC"≡\n"NOR;
	output += HIW"      前面带"HIR"√"HIW"的表示该任务已完成。"NOR;
	me->start_more(output);
	
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: task [-u]

    这个指令是用来得知目前的所有使命，带-u参数则显示所有未
完成之使命。

HELP
	);
	return 1;
}

