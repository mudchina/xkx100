// shi-daizi.c

inherit NPC;

void create()
{
        set_name("施戴子", ({ "shi daizi", "shi", "daizi" }) );
        set("gender", "男性");
        set("age", 22);
        set("long",
                "施戴子是岳不群的第四位弟子。\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("int", 24);
        set("dex", 30);

        set("jing", 800);
        set("max_jing", 800);
        set("qi", 1800);
        set("max_qi", 1800);
        set("neili", 500);
        set("max_neili", 500);

        set("combat_exp", 50000);
        set("shen_type", 1);
        set("score", 2000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 60);
        set_skill("sword", 60);
        set_skill("force", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("literate", 60);

        set_skill("huashan-sword", 60);
        set_skill("zixia-shengong", 60);
        set_skill("huashan-ken", 60);
        set_skill("feiyan-huixiang", 60);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");

        create_family("华山派", 14, "弟子");

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
