// daotong1.c 道童

inherit NPC;

void create()
{
        set_name("小道童", ({"tong", "dao tong"}));
        set("gender", "男性");
        set("class", "quanzhen");
        set("age", 14);
        set("long",
                "这是一位小道童，看来年纪不大，脸上稚气犹存，整天笑嘻嘻\n"
                "的无忧无虑。\n");
        set("attitude", "friendly");

        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        set("qi", 300);
        set("max_qi", 300);
        set("jing", 200);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 0);

        set("combat_exp", 15000);

        set_skill("force", 50);
        set_skill("xiantian-qigong", 40);    //先天气功
        set_skill("dodge", 50);
        set_skill("jinyan-gong", 50);   //金雁功
        set_skill("parry", 50);
        set_skill("unarmed",50);

        map_skill("force", "xiantian-qigong");
        map_skill("dodge", "jinyan-gong");

        create_family("全真教", 5, "弟子");

        setup();

        carry_object(__DIR__"obj/greyrobe")->wear();
        carry_object("/clone/medicine/vegetable/xiongdan");
}

