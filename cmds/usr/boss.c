// /cmds/usr/boss.c
inherit F_CLEAN_UP;

#include <ansi.h>

int main(object me, string arg)
{
	string msg;
	write(CLR);
	if(arg)
	{
		msg = read_file("/open/shit.txt");
		write(msg);
	}
	me->set_temp("block_msg/all",1);
	me->set_temp("boss_screen", 1);
//	message("channel:chat",RED"【警铃】"+me->name(1)+"匆匆关上屏幕，回头就跑。看来是老板来了。\n"NOR,users());
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: boss <arg>

    这个指令让你在老板出现前一秒钟时将屏幕上所有的中文消
除，如果 <arg>不是零的话，侠客行会在你的屏幕上显示出一些
文章。与此同时，你将受不到任何来自风云的讯息，直到你输入
bossgone指令。

有关指令：bossgone
HELP
	);
	return 1;
}
