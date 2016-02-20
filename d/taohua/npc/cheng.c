//yan.c
inherit NPC;

void create()
{
        object ob;

        set_name("程英", ({ "cheng ying","cheng" }) );
//        set_name("颜程英", ({ "yan ruofeng","yan","ruofeng" }) );
        set("gender", "女性" );
        set("age",18);
        set("long", @TEXT
程英是黄药师从小收养的孤女。由黄药师亲手教得了一手人人称绝的
烹调手法，因此桃花岛的膳食就由她负责。
TEXT );
        set("per", 30);
        set("class", "scholar");
        set("combat_exp", 10000);

        set_skill("unarmed",30);
        set_skill("luoying-zhang",30);
        set_skill("dodge", 30);
        set_skill("anying-fuxiang" , 30);
        set_skill("force",30);
        map_skill("dodge", "anying-fuxiang");
        map_skill("unarmed","luoying-zhang");

        set("force", 500);
        set("max_force", 500);
        set("force_factor",0);

        set("chat_chance", 7);
        set("chat_msg", ({
        "程英微笑著说道：我们桃花岛景色优美，欢迎来作客！\n",
        "程英高兴的说：有幸见到您真高兴！\n",
        "程英微笑著说道：您饿不饿？我桃花岛的烹调功夫可算天下第一呀。\n",
        }) );
        create_family("桃花岛", 3, "弟子");

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}

void greeting(object ob)
{
        object teatp,foodtp;
        if( !ob || environment(ob)!=environment() )
                return;
        if ( ob->query_temp("taohua/茶饭") )
                say("程英微笑着说： 这位"
                    +RANK_D->query_respect(ob)+"，你好！欢迎来到桃花岛！\n");
        else
        {
                tell_room(environment(this_object()),
                        "程英奉上茶饭，微笑着说道：这位" + RANK_D->query_respect(ob)
                        + "，你好！欢迎来到桃花岛。请用饭！\n");
                teatp = new("/d/taohua/obj/cha");
                teatp ->move(ob);
                foodtp= new("/d/taohua/obj/gao");
                foodtp->move(ob);

                command ("say 这是我亲手做的，请您品尝！\n");
                ob->set_temp("taohua/茶饭", 1);
        }
}
