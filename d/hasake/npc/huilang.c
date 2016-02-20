inherit NPC;
void create()
{
    set_name("大灰狼", ({ "huilang", "lang" }) );
    set("race", "野兽");
    set("age", 10);
    set("long", "一头高大的恶狼, 来势如电, 露出白森森的獠牙。\n");
    set("attitude", "aggressive");
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
        set("max_qi", 300);
        set("max_jing", 200);
        set("eff_jingli", 200);
	set("combat_exp", 3000);
	set("chat_chance", 5);
	set("chat_msg", ({
                "「嗥~~~~」大灰狼发出一声嗥叫。\n",
                "大灰狼发出一声嗥叫，好象随时都要扑上来！\n",
	}) );
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 8);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 4);
        set("senlin", 1);
	setup();
}
/*
void die()
{
        object ob;
        seteuid(getuid());
        message_vision("$N长啸一声，倒在地上，死了！\n", this_object());
        ob = new(__DIR__"obj/langpi");
        ob->move(environment(this_object()));
        destruct(this_object());

}
*/