// zhizhu.c

#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIB"毒蜘蛛"NOR, ({ "du zhizhu" }));
	set("long", "一只有毒蜘蛛。\n");
	set("race", "昆虫");
	set("subrace", "爬虫");
	set("age", 3);
	set("attitude", "peaceful");

	set("max_ging", 80);
	set("max_qi", 80);
	set("str", 10);
	set("cor", 50);
	set_temp("apply/attack", 10);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 10);

	set("combat_exp", 1000);
	setup();
}

int hit_ob(object me, object ob, int damage)
{
	if ((int)ob->query("combat_exp") > 10000) return 1 ;
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&  (int)ob->query_condition("scorpion_poison") < 10 )
	{
		ob->apply_condition("scorpion_poison", 20);
		tell_object(ob, HIG "你开始感到身体变得冰凉。！\n" NOR );
	}
}
