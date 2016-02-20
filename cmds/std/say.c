// say.c
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)
{
	if (!arg) {
		write("你自言自语不知道在说些什么。\n");
		message("sound", me->name() + "自言自语不知道在说些什么。\n",
			environment(me), me);
		return 1;
	}
	if( (int)me->query("qi") < (int)me->query("max_qi") / 5 ) {
		arg = replace_string(arg, " ", " ... ") + " ...";
	}

	tell_object(me, CYN "你说道：" + arg + "\n" NOR);
	message("sound", CYN + me->name() + "说道：" + arg + "\n" NOR, environment(me), me);
	if( userp(me))
		message("channel:snp", HIB"【监听】" + me->name() + "说道：" + arg + "\n"NOR, users());

	// The mudlib interface of say
	all_inventory(environment(me))->relay_say(me, arg);

	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: say <讯息>
 
    说话，所有跟你在同一个房间的人都会听到你说的话。
 
注: 本指令可用 ' 取代.
 
HELP
	);
	return 1;
}
