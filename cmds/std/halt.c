// halt.c
// By Xiang@XKX (12/17/95)

int main(object me, string arg)
{
	if (me->is_fighting()) {
		me->remove_all_enemy();
                message_vision("$N身行向后一跃，跳出战圈不打了。\n", me); 
	}
	else if (!me->is_busy()) 
		return notify_fail("你现在不忙。\n");
	else if ((int)me->query_temp("pending/exercise") != 0) {
	        message_vision("$N把正在运行的真气强行压回丹田，站了起来。\n", me);
		me->interrupt_me();
	}
	else if ((int)me->query_temp("pending/respirate") != 0)
		me->interrupt_me();
	me->interrupt_me();
//	me->start_busy(1);

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : halt
 
    这个指令可以让你用于停止手头正在做的事情，例如：攻击敌
人（当对方要杀你时无效，只是单方面取消你对别人的杀指令），
打坐或吐纳等。
 
HELP
    );
    return 1;
}
 
