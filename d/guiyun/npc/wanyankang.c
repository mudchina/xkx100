// wanyankang.c

inherit NPC;

void create()
{
        set_name("完颜康", ({"wanyan kang", "kang", "wanyan"}));
        set("gender", "男性");
        set("title", "大金国小王爷");
        set("age", 24);
        set("class", "fighter");
        set("long",
                "他本名杨康。随母包惜弱嫁完颜洪烈后，成了小王子，
贪图富贵，至死不改。\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 26);
        set("per", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 26);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "sword.ding" :),
        }));

        set("qi", 500);
        set("max_qi", 500);
        set("jing", 400);
        set("max_jing", 400);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 10);

        set("combat_exp", 160000);
        set("score", 100000);

        set_skill("force", 40);
        set_skill("xiantian-qigong", 40);    //先天气功
        set_skill("sword", 40);
        set_skill("quanzhen-jian",40);  //全真剑
        set_skill("dodge", 40);
        set_skill("jinyan-gong", 40);   //金雁功
        set_skill("parry", 40);
        set_skill("strike",40);
        set_skill("unarmed",40);
        set_skill("haotian-zhang", 40);    //昊天掌
        set_skill("claw",40);
        set_skill("jiuyin-baiguzhao", 40);    //昊天掌
        set_skill("literate",40);
        set_skill("taoism",40);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        map_skill("claw", "jiuyin-baiguzhao");
        prepare_skill("claw", "jiuyin-baiguzhao");

        create_family("全真教", 3, "弟子");

        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄门正宗。\n",
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/male-cloth")->wear();

}

