// zhuanghan.c

inherit NPC;

void create()
{
        set_name("壮汉", ({ "zhuang han", "han" }));
        set("long",
                "他是一个守门壮汉。\n");
        set("gender", "男性");
        set("age", 30);
        set("attitude", "friendly");
        set("shen_type", 1);

        set("str", 30);
        set("int", 30);
        set("con", 35);
        set("dex", 30);

        set("max_qi", 400+random(200));
        set("max_jing", 200);
        set("neili", 500);
        set("max_neili", 300);

        set("combat_exp", 2000+random(2000));
        set("score", 1000);

        set_skill("force", 60);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("parry", 40);
        set_skill("blade", 40);
        set_skill("yanxing-dao", 20);
        set_skill("taoism", 20);

        map_skill("parry", "yanxing-dao");
        map_skill("blade", "yanxing-dao");

        setup();
        carry_object("/clone/weapon/gangdao")->wield();
}

