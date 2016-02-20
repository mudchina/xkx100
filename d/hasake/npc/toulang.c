inherit NPC;
inherit F_UNIQUE;
void create()
{
        set_name("头狼", ({ "toulang", "lang" }) );
	set("race", "野兽");
	set("age", 10);
        set("unique", 2);
        set("long", "狼以群居，这只带头的大灰狼比其它的大一倍以上，低沉地吼着。\n");
        set("attitude", "aggressive");	
	set("limbs", ({ "头部", "牙齿", "前脚", "后脚", "前爪" }) );
	set("verbs", ({ "bite", "claw" }) );
        set("max_qi", 450);
        set("max_jing", 200);
        set("eff_jingli", 200);
	set("combat_exp", 9500);
        set("chat_chance", 20);
	set("chat_msg", ({
                "头狼的双目在黑暗中闪着红光，紧紧地注视着你的一举一动。\n",
		(: random_move :),
                "头狼发出一声嗥叫，好象随时都要扑上来！\n",
	}) );
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 14);        
        set("senlin", 1);
	setup();
}

void die()
{
	object ob;
    message_vision("$N凄惨的嚎了几声, 在地上打了几个滚，仰天死了。\n", this_object());
	ob = new(__DIR__"obj/langpi");
	ob->move(environment(this_object()));
	destruct(this_object());
}
	
