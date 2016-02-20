// Filename : /cmds/std/stay.c
// Last Modified by winder on Aug. 5 2001
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me)
{
	object ob;

	seteuid(getuid());

	if( !me->query_temp("comedby"))
		return notify_fail("已经没有野兽跟着你了！\n");
	if( me->is_fighting() )
		return notify_fail("一边打架一边驯兽？你真是活腻了！\n");
	if( !objectp(ob = present(me->query_temp("comedby"), environment(me)) ))
		return notify_fail("这里没有这只野兽吧？\n");
	if( ob->query("race") == "人类" )
		return notify_fail(ob->name()+"是野兽么？瞪大眼睛看看！\n");
	if( !ob->query_temp("owner") )
		return notify_fail(ob->name() + "是只无主野兽，你得先驯服(train)它啊！\n");
	if( ob->query_temp("owner") &&
		( ob->query_temp("owner") != me->query("id") ))
	{
		ob->kill_ob(me);
		return notify_fail(ob->name() + "是被人家驯服了，你不是找死啊！\n");
	}
	if (!living(ob))
		return notify_fail("它都已经晕倒了，你怎能让它听你的呢？\n");
	if (ob->is_fighting()) 
		return notify_fail("它正在大打出手，没空理你呢？\n");

	message_vision("只见$N冲着"+ob->name()+"手中摆了个手式，它冲着你点了点头。\n\n",me);

	me->delete_temp("comedby");
	ob->set_leader(0);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : stay <动物>

    此指令可用于让某动物停止跟随你。

    对于已经驯服的动物，可以进行下述指令：

基本指令：
        come <动物名>:                  让动物跟随主人行动。
        stay:                           停止动物的跟随状态。
        attack <某物>:                  让动物攻击敌人。
        stop <动物名>:                  让动物停止对人的攻击。
        release:                        结束主奴状态，将动物放离。

特殊指令：（只对某些动物适用）
        ride <动物名>:                  骑，如骑马，虎，雕，鲨等。
        unride <动物名>:                下，离开坐骑。
        feed <饲料> to <动物名>:        替动物喂食。
        imbibe <动物名>:                给动物饮水。

HELP
	);
	return 1;
}

