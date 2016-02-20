// zhuye.c
// Last Modified by winder on May. 15 2001

inherit NPC;
#include <ansi.h>
void create()
{
	set_name(HIG"竹叶青"NOR, ({ "zhuye qing", "zhuye", "snake", "she" }) );
	set("race", "爬蛇");
	set("age", 4);
	set("long", "一条碧绿的蛇，不仔细，会将它和周边碧绿的树叶混为一体。\n");
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("combat_exp", 6000);
	set_temp("apply/attack", 20);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 1);
	setup();
}

void init()
{
	object ob = this_player();
	::init();
	if (interactive(ob) && !ob->query_skill("hamagong", 1))
	{
		this_object()->kill_ob(this_player());
	}
}

int hit_ob(object me, object victim, int damage)
{
	victim->apply_condition("snake_poison",
		victim->query_condition("snake_poison") + 12);
	return 0;
}  
