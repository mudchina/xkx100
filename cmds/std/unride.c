// Filename : /cmds/std/unride.c
// Last Modified by winder on Aug. 5 2001
inherit F_CLEAN_UP;

#include <ansi.h>


void create() { seteuid(getuid()); }

int main(object me)
{
	object obj, *inv;
	int i = 0;

	inv = all_inventory(me);
	while( i < sizeof(inv) && i >= 0 )
	{
		if( inv[i]->query_temp("is_rided_by") == me )
		{
			obj = inv[i];
			i = -10;
		}
		i++;
	}
	if( i >= 0 ) return notify_fail("下什么下！你根本就没坐骑！\n");
	message_vision("$N从$n上飞身跳下。\n", me, obj);
//跳下动物减少膂力和身法。
	if( !living(obj) || obj->query_temp("noliving"))
		return notify_fail("这个东西自己都晕倒了，你也没法下了。\n");
/*
	if(obj->query("dex"))
		me->delete_temp("apply/dexerity");
	if(obj->query("str"))
		me->delete_temp("apply/strength");
*/
	obj->move( environment(me) );
	obj->delele("is_rided_by");
	me->delete_temp("is_riding");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : unride
 
    这个指令可以让你从骑着的已驯养的动物上跳下来。
 
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

