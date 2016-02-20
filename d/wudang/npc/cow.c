// cow.c 大黄牛

#include <command.h>
#include <dbase.h>
#include <origin.h>
#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIW"大黄牛"NOR, ({ "cow" }));
	set("long","一头大黄牛。\n");
	set("race", "走畜");
	set("age", 5);
	set("int", 30);
	set("qi", 300);
	set("max_qi", 300);
	set("ridable", "1");
	set("jing", 100);
	set("max_jing", 100);
	set("shen_type", 0);
	set("combat_exp",50000);
	set("attitude", "peaceful");
	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);

	setup();
}

void die()
{
	object ob, corpse;
	message_vision("$N哞地一声，静静倒在地上，死去了。\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
		ob = new("/clone/medicine/vegetable/niuhuang");
	ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
