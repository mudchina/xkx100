// ji.c 姬清虚

inherit NPC;
string ask_for_join();
int do_kneel();

void create()
{
        set_name("姬清虚", ({"ji qingxu", "ji"}));
        set("gender", "男性");
        set("age", 24);
        set("class", "quanzhen");
        set("long",
                "他是一位体格强健的青年道士，似乎身怀武艺。\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 26);
        set("int", 25);
        set("con", 25);
        set("dex", 26);

        set("env/wimpy", 60);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        	(: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
        }));

        set("qi", 500);
        set("max_qi", 500);
        set("jing", 400);
        set("max_jing", 400);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 10);

        set("combat_exp", 60000);
        set("score", 10000);

        set_skill("array", 20);
        set_skill("force", 40);
        set_skill("xiantian-qigong", 40);    //先天气功
        set_skill("sword", 40);
        set_skill("quanzhen-jian",40);  //全真剑
        set_skill("dodge", 40);
        set_skill("jinyan-gong", 40);   //金雁功
        set_skill("parry", 40);
        set_skill("unarmed", 40);
        set_skill("strike", 40);
        set_skill("haotian-zhang", 40);    //昊天掌
        set_skill("cuff", 40);
        set_skill("chunyang-quan", 40);    //纯阳拳
        set_skill("literate", 40);
        set_skill("taoism", 40);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        map_skill("cuff", "chunyang-quan");
        prepare_skill("cuff", "chunyang-quan");
        prepare_skill("strike", "haotian-zhang");

        create_family("全真教", 4, "弟子");

        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄门正宗。\n",
                "出家"   :  (: ask_for_join() :),
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/yellowrobe")->wear();
}

void init()
{
	add_action("do_kneel", "kneel");
}

#include "qing.h"
