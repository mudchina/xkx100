// stone.c
// 各种原料初始状态

#include <ansi.h>

inherit ITEM;

int do_yelian();
int do_eat(string stone);

void init()
{
	add_action("do_yelian","yelian");
	add_action("do_eat","eat");
}

void create()
{
	set_name( "补天石", ({ "butian shi","shi","butian"}));
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long","这是一块五彩的石头，光华闪烁，叫人爱不释手，久久把玩不愿放下。\n"
			+"这块石头似乎包含着什么，你不由想冶炼(yelian)一下，可能会有些什\n"
			+"么新奇的东西出现\n");
		set("value", 0);
		set("material", "iron");
	}
}

int do_yelian()
{
	object me,stone,new_ob;
	int n;
	me=this_player();
	stone=this_object();

	if( (int)me->query("neili") < 50 )
		return notify_fail("你的内力不够无法锻炼补天石！\n");
	message_vision(HIR "$N盘膝而坐，手托补天石，真气游走，开始冶炼补天石。\n" NOR, me);
	me->add("neili",-50);
	switch(random(4) )
	{
		case 0:
			new_ob=new("/d/npc/m_weapon/tan/item/jinmu",1);
			new_ob->move(me);			
			message_vision(HIY "补天石渐渐变形，终于成了一块紫色的金属！！\n" NOR, me );
//			destruct(stone);
			stone->move("/u/java/room/readroom");
			break;
		case 1:
			new_ob=new("/d/npc/m_weapon/tan/item/shenmu",1);
			new_ob->move(me);			
			message_vision(HIY "补天石层层剥落，终于成了一块黑中透红的木头！！\n" NOR, me );
//			destruct(stone);
			stone->move("/u/java/room/readroom");
			break;
		case 2:
			new_ob=new("/d/npc/m_weapon/tan/item/hanzhu",1);
			new_ob->move(me);			
			message_vision(HIY "补天石啪的一声爆响听起来竟象是竹子燃烧的声音！！\n" NOR, me );
//			destruct(stone);	
			stone->move("/u/java/room/readroom");
			break;
		default:
			message_vision(HIY "补天石渐渐变软，终于化做一滩泥水渗入地下，不见了。\n" NOR, me );
//			destruct(stone);
			stone->move("/u/java/room/readroom");
	}
	return 1;
}

int do_eat(string arg)
{
	object me;
	int n;
	string stone_name;
	me=this_player();
	if( !id(arg) )
		return notify_fail("你要吃什么?\n");
	n=random(3);
	switch(n) {
		case 0:
			message_vision(HIY "$N看来急坏了，拿起补天石就啃，结果当场大牙蹦掉了十二颗!这也算冶炼？真傻！\n" NOR,me);
			me->add("food",200);
			me->add("water",200);
			break;
		default:
			message_vision(HIY "$N看来饿坏了，拿起补天石就啃，结果当场大牙蹦掉了十二颗!\n" NOR,me);
		}
//	destruct(this_object() );
	this_object()->move("/u/java/room/readroom");
	return 1;
}

