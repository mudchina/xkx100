// Room: /d/xingxiu/npc/obj/huoyan.c
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIR"火焰"NOR, ({ "huo yan"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",HIR"火焰高约尺，色作纯碧，鬼气森森，和寻常火焰大异。\n"NOR );
		set("no_get", 1);
		set("value", 1);
		set("unit", "堆");
		set("fire_name", "火焰");
		set("weight", 30000);
		set("location", 1);
	}
	setup();
}

void init()
{
	if(base_name(environment(this_object()))!="/d/xingxiu/riyuedong")
	call_out("dest", 300);   
	remove_call_out("change");
	call_out("change", 50); 
}

string *fire_msg = ({BLU"火焰"NOR,RED"火焰"NOR,WHT"火焰"NOR,GRN"火焰"NOR,MAG"火焰"NOR});

void change()
{
	string msg = fire_msg[random(sizeof(fire_msg))];
	tell_room(environment(this_object()),this_object()->name()+ HIR"豁然一暗，接着火光爆长，竟然变了颜色，看起来怪异无比！\n"NOR);    
	this_object()->set("name", msg);    
	remove_call_out("change");
	call_out("change", 50);  
}
 
void dest()
{
	tell_room(environment(this_object()),HIR"火焰渐渐地熄灭了。\n"NOR);
	destruct(this_object());
}
