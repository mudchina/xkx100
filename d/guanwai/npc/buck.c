// buck.c
// Date: Sep.22 1997

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(YEL"梅花雄鹿"NOR, ({ "meihua xionglu", "buck", "lu" }) );
	set("race", "走畜");
	set("gender", "雄性");
	set("age", 20);
	set("long", "一只温驯的梅花雄鹿，正在低头吃草。\n");
	set("attitude", "peace");
	set("shen_type", -1);

	set("combat_exp", 2000);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/armor", 10);

	setup();
}

void die()
{
	object ob, corpse;
	message_vision("$N发出凄婉的哀鸣，静静倒在地上，死去了。\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
		ob = new("/clone/medicine/vegetable/lurong");
	ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
