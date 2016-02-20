// Obj: /d/nanshaolin/obj/gangchu.c
// Last Modified by winder on May. 29 2001

#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
	set_name(HIW"钢杵"NOR,({"gang chu","chu"}));
	set_weight(100000);
	if (clonep())
		set_default_object(__FILE__);
	else{
		set("unit","根");
		set("value",100);
		set("material","black_steel");
		set("long", HIW"这是一根精钢所铸的降魔杵，千锤百炼，反射出闪闪的寒光。\n"NOR);
	       set("unwield_msg","$N一声长啸，将钢杵放回背后。\n");
	}
	init_staff(30);

}
void init()
{
	add_action("do_wield","wield");
}
int do_wield(string arg)
{
	object me,ob;
	me=this_player();
	ob=this_object();
	if(!arg) return 0;
	if (arg =="gang chu"|| arg =="chu")
	{ 
		if((int)me->query_str() < 30)
		{
			tell_object(me,"你想举起钢杵，奈何过于沉重，拿不动。\n");
			return 1;
		}     
		ob->wield();
		message_vision( HIW"$N双手用力一举，将一根沉重的钢杵高高举了起来。\n"NOR, me);
		return 1; 
	}
	return 0;
}
