// zhao.c 赵志敬

inherit NPC;

void create()
{
        set_name("赵志敬", ({"zhao zhijing", "zhao"}));
        set("gender", "男性");
        set("age", 26);
        set("class", "quanzhen");
        set("long",
                "他就是全真教第三代弟子中的好手，王处一的大弟子赵志敬。 \n"
                "他相貌端正，但眉宇间似乎隐藏着一丝狡猾的神色。\n"
		"他是一个长须道人，看起来却有些煞气。\n");
        set("attitude", "friendly");
        set("shen_type",-1);
        set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 25);

        set("env/wimpy", 60);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        	(: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
        }));

        set("qi", 1500);
        set("max_qi", 1500);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 60);

        set("combat_exp", 160000);
        set("score", 100000);

        set_skill("array", 40);
        set_skill("force", 80);
        set_skill("xiantian-qigong", 80);    //先天气功
        set_skill("sword", 80);
        set_skill("quanzhen-jian", 120);  //全真剑
        set_skill("dodge", 70);
        set_skill("jinyan-gong", 100);   //金雁功
        set_skill("parry", 80);
        set_skill("unarmed", 80);
        set_skill("strike", 80);
        set_skill("haotian-zhang", 120);    //昊天掌
        set_skill("cuff", 80);
        set_skill("chunyang-quan", 120);    //纯阳拳
        set_skill("literate", 60);
        set_skill("taoism", 60);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        map_skill("cuff", "chunyang-quan");
        prepare_skill("cuff", "chunyang-quan");
        prepare_skill("strike", "haotian-zhang");

        create_family("全真教", 3, "弟子");

        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄门正宗。\n",
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/greyrobe")->wear();
}

#include "zhi.h";
