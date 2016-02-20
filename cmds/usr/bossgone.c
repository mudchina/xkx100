// TIE@FY3
inherit F_CLEAN_UP;

#include <ansi.h>

int main(object me, string arg)
{
	string msg;
	me->delete_temp("block_msg/all");
	write(CLR);
	me->delete_temp("boss_screen");
	write("侠客行告诉你：运气如何？被抓住了吗？哈哈！\n");
//	message("channel:chat",GRN"【警铃】"+me->name(1)+"得意洋洋地打开屏幕，看着老板在门外消失：拜拜了您哪。\n"NOR,users());
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: bossgone

    这个指令让你(玩家)在老板走后恢复正常侠客行游戏。

有关指令：boss
HELP
	);
	return 1;
}
