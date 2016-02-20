// Filename : /cmds/std/stop.c
// Last Modified by Winder on Jul. 15 2001
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	object ob;
	int cost, i = 0;

	seteuid(getuid());

	if ( !arg )
		return notify_fail("你要让什么野兽停止咬人？\n");
	if( !objectp(ob = present(arg, environment(me)) ))
		return notify_fail("这里没有这个野兽吧？\n");
	if( ob->query_temp("owner") != me->query("id") )
		return notify_fail("你不是它的主人，它根本不理你！\n");
	if( ob->is_busy() )
		return notify_fail(ob->name() + "正在忙乎，没空理你！\n");
	message_vision("只见$N冲着$n口中一声呼哨，$n向后一窜，不咬了！\n\n",me,ob);
	ob->remove_all_enemy();
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : stop <动物>

    此指令可用于让帮你咬人的动物停止攻击。

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

