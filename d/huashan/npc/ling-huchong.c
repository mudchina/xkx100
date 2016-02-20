// ling-huchong.c

inherit NPC;

void create()
{
        set_name("令狐冲", ({ "ling huchong", "ling", "huchong" }) );

        set("gender", "男性");
        set("age", 29);
        set("long",
                "令狐冲是华山派的开门大弟子，也是风清扬独孤九剑在尘世中的唯一传人。\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 30);

        set("max_qi",2500);
        set("max_jing",1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 100);

        set("combat_exp", 1000000);
        set("shen_type", 1);
        set("score", 200000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 80);
        set_skill("sword", 150);
        set_skill("force", 100);
        set_skill("parry", 150);
        set_skill("dodge", 100);
        set_skill("literate", 50);

        set_skill("huashan-sword", 150);
        set_skill("lonely-sword", 150);
        set_skill("zixia-shengong", 100);
        set_skill("huashan-ken", 80);
        set_skill("feiyan-huixiang", 100);

        map_skill("sword", "lonely-sword");
        map_skill("parry", "lonely-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");

        create_family("华山派", 14, "弟子");

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();

}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",2 , ob);
        }
}
void greeting(object ob)
{
      if ( ((int)ob->query_int() >= 30) && ((int)ob->query_con() >= 30)
           && ((int)ob->query("marks/feng-qingyang")==1) )
      {
           ob->set("marks/feng-qingyang",2);
           say( "令狐冲说道：“我风太师叔住在南峰，这就去吧!”\n");
      }
      set("exits/southdown", __DIR__"sgyhole");

      remove_call_out("close_out");
      call_out("close_out", 5);
}
void close_out()
{
      if (query("exist/southdown")) delete("exist/southdown");
}
