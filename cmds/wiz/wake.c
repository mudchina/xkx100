// wake.c
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	object target;

	if(!arg || !objectp(target = present(arg, environment(me))))
		return notify_fail("你想唤醒谁？\n");
	if(target == me)
		return notify_fail("你不能自己唤醒自己！\n");
	message_vision(HIY "$N拍了拍$n的头，喊道：“别装蒜了，起来！”\n$n睁开眼睛一脸不好意思地站了起来。\n" NOR, me, target );
	target->receive_curing("qi", 10 );
	target->remove_call_out("revive");
	target->revive();
	target->reincarnate();
 
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : wake <生物>
 
唤醒活物
 
HELP
    );
    return 1;
}
