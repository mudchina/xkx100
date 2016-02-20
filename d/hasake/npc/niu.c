
inherit NPC;

void create()
{
    set_name("牛", ({ "niu" }) );
	set("race", "野兽");
	set("age", 5);
    set("long", "一头健壮的牛。\n");
	set("attitude", "peaceful");
	
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
    set("verbs", ({ "kick", "bite" }) );

    set("max_qi", 300);
    set("max_jing", 100);
    set("eff_jingli", 100);

    set("combat_exp", 1200);
	
    set_temp("apply/attack", 5);
	set_temp("apply/defense", 10);
    set_temp("apply/damage", 5);
    set_temp("apply/armor", 5);

	setup();
}