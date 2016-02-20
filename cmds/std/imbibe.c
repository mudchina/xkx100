// Filename : /cmds/std/imbibe.c
// Last Modified by winder on Aug. 5 2001
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	object *obj, pet;
	string owner;
	int i, j, lvl;

	seteuid(getuid());

	if(!arg || arg == " ")
		return notify_fail("你要给谁喂水？\n");
	if(!objectp(pet = present(arg, environment(me))) || !living(pet))
		return notify_fail("这里没有这动物。\n");
	if(pet->query("race") == "人类" )
		return notify_fail(pet->name()+"是宠物么？瞪大眼睛看看！\n");
	if(pet->is_busy() )
		return notify_fail(pet->name()+"正忙着呢，哪喝得下什么！\n");
	if(me->is_busy() )
		return notify_fail("你正忙着呢，什么也做不了！\n");
	if(pet->is_fighting() )
		return notify_fail("你没看道它正在打架吗？！\n");
	if(me->is_fighting() )
		return notify_fail("一边打架一边喂水？你真是活腻了！\n");
	if((string)me->query("id")!=(string)pet->query_temp("owner"))
		return notify_fail("你不是"+pet->query("name")+"的主人，人家不会理你的。\n");
	if(pet->query("water") >= pet->max_water_capacity() )
		return notify_fail(pet->name()+"已经喝得太多了，再也灌不下任何东西了。\n");

	me->start_busy(1);
	if(environment(me)->query("resource/water") )
	{
		if((string)pet->query("drink_msg"))
			message_vision(pet->query("drink_msg"), pet);
		else message_vision("$N伸长舌头舔了舔水面，一仰脖颈，喝了下去。\n", pet);
		pet->add("water", 30);
	}
	else
	{
		obj = all_inventory(environment(me));
		for (i = 0; i < sizeof(obj); i++)
		{
			if(obj[i]->query("liquid/remaining") )
			{
				break;
			}
		}
		if( i == sizeof(obj) )
			return notify_fail("这里没啥东西可以给"+pet->name()+"喂水。\n");
// 宠物饮水状态改变。
		pet->add("water", 10+obj[i]->query("liquid/drunk_apply"));
// 容器容量改变。
		obj[i]->add("liquid/remaining", -1);
// 吃的不busy，喂的busy，feed.c也一样。
		if((int)obj[i]->query("liquid/busy"))
			me->start_busy(obj[i]->query("liquid/busy"));
		if(obj[i]->query("liquid/remaining"))
			message_vision("$N伸长脖颈对着$n，唏唏嗦嗦地喝了几口"+obj[i]->query("liquid/name")+"。\n", pet, obj[i]);
		else
			message_vision("$N伸长脖颈对着$n，唏唏嗦嗦就把"+obj[i]->query("liquid/name")+"喝了个精光。\n", pet, obj[i]);
// 喝到毒药啦。
		if( obj[i]->query("liquid/poisontime") > 1 )
		{
			pet->apply_condition(obj[i]->query("liquid/poison"), obj->query("liquid/poisontime") );
			write(pet->query("name")+"突然觉得很难受地扭着腰挣扎了两下，好象喝的东西有点不对劲。\n");
		}
// 喝到酒啦。
		switch(obj[i]->query("liquid/type"))
		{
			case "alcohol": pet->apply_condition("drunk",(int)pet->query_condition("drunk")+ (int)obj[i]->query("liquid/drunk_apply"));
					break;
		}
	}

// 宠物升级，与驯兽无关。
	if(pet->query("owner") == me->query("id")) 
	{
// 食物作用改变，累计以便升级。
		pet->add("feed", 1);
		i = pet->query("feed");
		j = pet->query("level");
		if(i>=2+j*j)
		{
			tell_object(me,HIY"你喂了这一次饮水后，发觉"+pet->query("name")+"似乎更听话了！\n"NOR);
// 喂养长级别。
			pet->add("level",1);
			pet->set("feed",0);
// 喂养长驯服度。
			pet->add("obe", 1);
			lvl=pet->query("level");
		}
		pet->add("max_qi", lvl);
		pet->add("max_jing", lvl);
	}

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : imbibe <动物>

    此指令可用于喂养你所驯服的动物。

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

