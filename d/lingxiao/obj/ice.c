// Obj: /d/lingxiao/obj/ice.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h> 
#include <weapon.h> 
inherit SWORD;


int do_make(string);

void create()
{
	set_name(HIW "冰柱" NOR, ({ "bing zhu", "bing", "ice" }) ); 
	set_weight(5000); 
	if (clonep())  
		set_default_object(__FILE__); 
	else { 
		set("unit", "柄"); 
		set("long","这是一片长长的冰柱，看起来晶莹剔透，锋锐无比，不知道能不能吃。\n");
		set("unit", "片" ); 
		set("value", 8); 
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n"); 
		set("unwield_msg", "$N小心将手中的$n放回怀中。\n");
		set("material", "ice");
	} 
	init_sword(25);
	setup(); 
}
void do_melt()
{
	if(this_object()) call_out("melt", 40+random(40));
}
void melt()
{
	object env;

	if(!this_object()) return;
	env=environment(this_object());
	if( env->is_character() )
	{
//a player or a NPC.
		if( (int)env->query_skill("bingxue-xinfa", 1) < 20 )
		{
			message_vision("$N觉得身上凉凉的，湿湿的，原来是冰柱化了。\n", env);
			destruct(this_object());
			return;
		}
	}
	else if( (int)env->query_max_encumbrance() > 0 && !environment(env) )
	{
//a room.
		if( (string)env->query("outdoors") != "lingxiao" )
		{
			tell_object(env,"冰柱终于化成了一滩水，流得到处都是。\n");
			destruct(this_object());
			return;
		}
	}

}

void init()
{                                             
	remove_call_out("do_melt");
	call_out("do_melt", 1);
	add_action("do_make", "make");
	add_action("do_make", "zuo");
	add_action("do_chi", "chi");
	add_action("do_chi", "eat");
}

int do_make(string arg)
{
	object ob, me = this_player();

	if( !arg || (arg != "sword" && arg != "jian" ) )
		return notify_fail("你要做什么？\n");
	if(!present(this_object(), me))
		return notify_fail("你要做什么？\n");

	if( (int)me->query("neili") < 200 ||
		(int)me->query_skill("bingxue-xinfa", 1) < 20 )
	{
		message_vision("$N拿起冰柱捏来捏去，结果冰柱很快就化掉了。\n", me);
		destruct(this_object());
		return 1;
	}   
	ob=new("/d/lingxiao/obj/icesword");
	ob->move(me);
	me->add("neili", -100);
	message_vision( HIW"$N拿起冰柱，暗运冰雪心法，只见冰柱透出一股清气，居然变成了一把剑！\n"NOR, me);
	destruct(this_object());
	return 1;
}

int do_chi(string arg)
{   
	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if(!arg) return notify_fail("你要吃什么？\n");
	message_vision( "$N拿起冰柱使劲一咬，只听嘎哒！一声，牙甭了。\n" , this_player());
	if( (int)this_player()->query("qi") > 20 )
		this_player()->add("qi", -20);
	else this_player()->unconcious();
	return 1;
}

