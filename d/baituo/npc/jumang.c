// jumang.c
// Last Modified by winder on May. 15 2001

inherit NPC;
void create()
{
	set_name("巨蟒", ({ "ju mang", "mang" }) );
	set("race", "爬蛇");
	set("age", 70);
	set("long", "一条五丈来长的蟒！！！\n");
	set("attitude", "aggressive");
	set("str", 150);
	set("con", 150);
	set("combat_exp", 250000);
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 200);
	set_temp("apply/armor", 200);
	setup();
}

void die()
{
	object ob;
	message_vision("$N垂死挣扎了几下就不动了。\n", this_object());
	ob = new("/d/baituo/obj/shepi");
	ob->move(environment(this_object()));
	destruct(this_object());
}

