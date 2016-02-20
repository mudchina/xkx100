// Filename : /cmds/std/feed.c
// Last Modified by winder on Aug. 5 2001
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	object obj, pet;
	string owner, food, ob;
	int i, j, lvl, effect;

	seteuid(getuid());

	if(!arg || sscanf(arg, "%s to %s", food, ob) !=2)
		return notify_fail("你要喂什么东西给谁？\n");
	if(!objectp(obj = present(food, me)) ) 
		return notify_fail("你身上没有这样东西啊。\n");
	if(!objectp(pet = present(ob, environment(me))) || !living(pet))
		return notify_fail("这里没有这样的动物。\n");
	if(pet->query("race") == "人类" )
		return notify_fail(pet->name()+"是宠物么？瞪大眼睛看看！\n");
	if(pet->is_busy() )
		return notify_fail(pet->name()+"正忙着呢，哪吃得下什么！\n");
	if(pet->is_busy() )
		return notify_fail(pet->name()+"正忙着呢，哪吃得下什么！\n");
	if(me->is_busy() )
		return notify_fail("你正忙着呢，什么也做不了！\n");
	if(pet->is_fighting() )
		return notify_fail("它正在打架呢，你难道没看见？！\n");
	if(me->is_fighting() )
		return notify_fail("一边打架一边喂食？你真是活腻了！\n");
	if(!wizardp(me) && pet->query_temp("feeded"))
		return notify_fail("人一次不能多吃东西，吃多了会拉肚子，"+pet->query("name")+"也一样。\n");
	if((string)me->query("id")!=(string)pet->query_temp("owner"))
		return notify_fail("你看到"+pet->query("name")+"上前闻了两下，结果一脚踢开了。\n");
	if(!obj->query("siliao_supply") )
		return notify_fail("似乎"+pet->query("name")+"对这样东西兴趣不大。\n");
	if(!obj->query("siliao_remaining") )
		return notify_fail( obj->name() + "已经没什么好吃的了。\n");
	if(pet->query("food") >= pet->max_food_capacity() )
		return notify_fail(pet->name()+"已经吃太饱了，再也塞不下任何东西了。\n");
	obj->set("value", 0);
	obj->add("siliao_remaining", -1);
	me->start_busy(1);
// 宠物食物状态改变。
	pet->add("food", obj->query("siliao_supply"));
// 延时进食，不能连续吃。刚吃完也不能让宠物退出。连续机器人喂76天达到100级。
// 9天可以达到50级。
	pet->set_temp("feeded","1");
	call_out("del", 20, pet);
// 宠物升级，与驯兽无关。
	if(pet->query("owner") == me->query("id")) 
	{
// 食物作用改变，累计以便升级。
		if(obj->query("siliao_effect"))
			pet->add("feed", obj->query("siliao_effect"));
// 喂养长经验。
		pet->add("combat_exp", 5+random(10));
		i = pet->query("feed");
		j = pet->query("level");
		if(i>=2+j*j)
		{
			tell_object(me, HIY"你喂了这一次食物后，发觉"+pet->query("name")+"似乎显得更强健、也更听话了！\n"NOR);
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
	if( !obj->query("siliao_remaining") )
	{
		obj->delete_temp("apply/long");
		if((string)obj->query("finish_msg"))
			message_vision(obj->query("finish_msg"), pet, obj);
		else
		{
			message_vision( "$N拿出一"+obj->query("unit")+obj->query("name")+"来，向$n招了招手。\n$n很驯顺的走了过去，一把叼起了"+obj->query("name")+"，吃了个干干净净。\n", me, pet);
		}
		if( !obj->finish_eat() ) destruct(obj);
	} 
	else
	{
		if((string)obj->query("eat_msg"))
			message_vision(obj->query("eat_msg"), pet, obj);
		else 
			message_vision( "$N拿出一"+obj->query("unit")+obj->query("name")+"来，向$n招了招手。\n$n很驯顺的走了过去，一把叼起了"+obj->query("name")+"，狠狠就是一口。\n", me, pet);
	}
	if( !obj ) return 1;
	
	return 1;
}

void del(object pet)
{
	pet->delete_temp("feeded");
}

int help(object me)
{
	write(@HELP
指令格式 : feed <饲料> to <动物名>

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

