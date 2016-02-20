// chuidutong.c 吹毒筒
#include <ansi.h>
inherit ITEM;

#define max_poison 15
#define least_poison 5

void init()
{
	add_action("do_shot","shot");
}

void create()
{
	set_name(HIW"吹毒筒"NOR, ({ "chuidu tong", "ct" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "支");
		set("value", 0);
		set("material", "steel");
		set("long", "这是一支黑黝黝的铁筒，不知道做什么用的。\n");
	}
	setup();
}

int do_shot(string arg)
{
	object obj,weapon;
	object me = this_player();
	int lv1,lv2,lv3,lv4,damage;
	string skill_type;
	int tired;

	if( !arg) return notify_fail("你要攻击谁？\n");
	if(!present(this_object(), me))
		return notify_fail("你要攻击谁？\n");
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");
	if( !objectp(obj = present(arg, environment(me)) ))
		return notify_fail("这里没有这个人！\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");
	if (obj == me) return notify_fail("对自己下毒手？别想不开啊。\n");

	message_vision(HIW "$N把吹毒筒放到嘴边，对着$n用力一吹，$n只觉得一阵头昏眼花，站立不稳，好象中毒了！\n" NOR, me, obj);
	tired = obj->query("total_tired");
	obj->apply_condition("xx_poison",random(max_poison) + random(least_poison * tired));
	destruct(this_object());
	return 1;
}

