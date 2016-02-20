// Obj: /d/nanshaolin/obj/zhuang.c
// Last Modified by winder on May. 29 2001

inherit ITEM;
void setup()
{}

void create()
{
	set_name("梅花桩", ({"meihua zhuang", "zhuang"}));
	set_weight(2000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一组青竹制成的木桩，高一丈两寸，状成梅花排列。\n");
		set("unit", "组");
		set("material", "wood");
		set("no_get", "这样东西不能离开那儿。\n");
	}
	setup();
}
void init()
{
	add_action("do_jump","jump");
}
int do_jump(string arg)
{
	object me = this_player();
	int exp = me->query("combat_exp"), lvl = me->query_skill("dodge",1);
	if (!id(arg)) return 0;
	 
	if(!(living(this_player()) || arg=="zhuang")) return 0;
	if (me->is_busy() || me->is_fighting())
	{
		write("你正忙着呢。\n");
		return 1;
	}
	if((int)me->query_skill("dodge",1)>101)
	{
		write("你在梅花桩上不停的穿梭来去，但已无法再提高轻功了。\n");
		return 1;
	}
	if((int)me->query("qi")<30)
	{
		me->receive_damage("qi",10);
		write("你脚下一个不稳，从梅花桩上栽了下去。\n");
		me->unconcious();
		return 1;
	}
	if(lvl * lvl * lvl / 10 > exp)
		return notify_fail("这样再走下去已无法再提高了。\n");
	if (me->query_skill("dodge",1)<31)
	{
		me->receive_damage("qi",random(30)); 
		me->receive_damage("jing",random(30)); 
		write("你在梅花桩上不停的穿梭来去，对基本轻功有所领悟。\n");
		message_vision("$N纵身一跃上了梅花桩，在桩上回旋来去。\n", me);
		me->improve_skill("dodge", me->query_dex());
		return 1;
	}
	if ( present("sha dai", this_player()) &&
		((int)me->query_skill("dodge",1)>30) && 
		((int)me->query_skill("dodge",1)<101))
	{
		me->receive_damage("qi",random(30)); 
		me->receive_damage("jing",random(30)); 
		write("你在梅花桩上不停的穿梭来去，对基本轻功有所领悟。\n");
		message_vision("$N纵身一跃上了梅花桩，在桩上回旋来去。\n", me);
		me->improve_skill("dodge", me->query_dex());
		return 1;
	}
	return 1;
}

