// yezhu.c

inherit NPC;

void create()
{
        set_name("野猪", ({ "pig", "yezhu" }) );
	set("race", "走畜");
        set("age", 4);
        set("long", 
"这是一只凶猛的野猪，长得极为粗壮，嘴里还不断发出可怕的哄声。\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);
        set("combat_exp", 1000);
        set("shen_type", -1);
        set("chat_msg_combat", ({
                (: this_object(), "random_move" :),
                "野猪大口大口地喘着气：呼哧！呼哧！呼哧！呼哧！\n",
                "野猪突然跳了起来，眼睛恶狠狠地盯着你，看样子想要扑过来。\n"
        }) );

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

        setup();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                random(ob->query_kar() + ob->query_per()) < 30) {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
        }
}
void die()
{
        object ob;
        message_vision("$N哇呀地惨嚎一声，死了！\n", this_object());
        ob = new("/d/xiakedao/obj/pigdie");
        ob->move(environment(this_object()));
        destruct(this_object());

}

