// shu-qi.c

inherit NPC;

void create()
{
        set_name("舒奇", ({ "shu qi", "shu", "qi" }) );
        set("gender", "男性");
        set("age", 15);
        set("long",
                "舒奇是岳不群的最小的弟子。\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("int", 24);
        set("dex", 30);

        set("jing", 700);
        set("max_jing", 700);
        set("qi", 1700);
        set("max_qi", 1700);
        set("neili", 500);
        set("max_neili", 500);

        set("combat_exp", 20000);
        set("shen_type", 1);
        set("score", 2000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 30);
        set_skill("sword", 30);
        set_skill("force", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);
        set_skill("literate", 30);

        set_skill("huashan-sword", 30);
        set_skill("zixia-shengong", 30);
        set_skill("huashan-ken", 30);
        set_skill("feiyan-huixiang", 30);

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
