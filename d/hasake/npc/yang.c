inherit NPC;
void create()
{
    set_name("绵羊", ({ "mian yang", "yang" }) );
	set("race", "野兽");
	set("age", 5);
    set("long", "一头雪白可爱的又肥又壮的绵羊。\n");
	set("attitude", "peaceful");
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
    set("verbs", ({ "kick", "bite" }) );
    set("max_qi", 100);
    set("max_jing", 100);
    set("eff_jingli", 100);
    set("combat_exp", 500);
    set_temp("apply/attack", 1);
	set_temp("apply/defense", 5);
    set_temp("apply/damage", 3);
    set_temp("apply/armor", 2);
	setup();
}

void die()
{
	object ob;
    message_vision("绵~~，$N倒在地上死了。\n", this_object());
        ob = new(__DIR__"obj/yangpi");
	ob->move(environment(this_object()));
	destruct(this_object());
}
	
