// Filename : /cmds/std/release.c
// Last Modified by winder on Aug. 5 2001
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me)
{
	object *inv;
	int j = 0, i = 0;

	inv = all_inventory(environment(me));
	while( i < sizeof(inv) && i >= 0 )
	{
		if( inv[i]->query_temp("owner") == me->query("id") && //驯养
			inv[i]->query("owner") != me->query("id"))    //宠物
		{
			message_vision("$N很慈悲地把$n放离，任其回归自然了。\n", me, inv[i]);
			inv[i]->delete_temp("owner");
			inv[i]->delete_temp("ownername");
			j=1;
		}
		i++;
	}
	if (j == 0) message_vision("$N想放生，可是没啥可放的。\n", me);
	
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : release

    此指令可用于让某动物结束主奴状态，将动物放离。宠物不能放生。

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

