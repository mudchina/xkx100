// buck.c
// Date: Sep.22 1997

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(YEL"梅花雌鹿"NOR, ({ "meihua cilu", "doe", "lu" }) );
	set("race", "走畜");
	set("gender", "雌性");
	set("age", 20);
	set("long", "一只温驯的梅花雌鹿，正在低头吃草。\n");
	set("attitude", "peace");
	set("shen_type", -1);

	set("limbs", ({ "鹿头", "鹿身", "前腿", "后腿", "臀部" }) );
	set("verbs", ({ "hoof" }) );

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
	destruct(ob);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
