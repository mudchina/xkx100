// emote.c (Mon 09-04-95)
inherit F_CLEAN_UP;

#include <ansi.h>

 
int main(object me, string str)
{
	if (!str)
	{
		write(CYN"你看起来表情丰富。\n"NOR);
		tell_room(environment(me),CYN+(string)me->name()+"看起来表情丰富。\n" +NOR, me);
		return 1;
	}
	write(CYN"你"+str+"\n"NOR);
	tell_room(environment(me), CYN+(wizardp(me)? "":"->")+(string)me->name()+str+"\n"+NOR, me);
	message("channel:snp", HIB"【监听】"+me->query("name")+"表情："+str+"\n"NOR, users());
	return 1;
}
 
int help(object me)
{
	write(@HELP
指令格式: emote <动作词>

    这个指令可以让你表达一个系统没有预设的动作词，系统会将你
所输入的文字加上你的姓名後显示给所有在同一个地方的生物看。为
了避免造成困扰，玩家所输入的词句前面会加上 -> 以供区别（巫师
则不在此限）。
    预设的指令可以直接键入。

    范例：emote 坐了下来。

你会看见：你坐了下来。
其他人会看到：->包子坐了下来。

    其中，包子就是你的名字.

相关指令: semote
HELP
	);
	return 1;
}
