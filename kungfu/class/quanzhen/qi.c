// qi.c 祁志诚

inherit NPC;
string ask_me();

void create()
{
        set_name("祁志诚", ({"qi zhicheng", "qi"}));
        set("gender", "男性");
        set("age", 24);
        set("class", "quanzhen");
        set("long",
                "他就是全真教第三代弟子中的好手，谭处端的大弟子祁志诚。\n"
                "他相貌英俊，精明能干，深受长辈的信任，派遣他去掌管教中\n"
                "的经书典籍。\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 25);
        set("int", 25);
        set("con", 24);
        set("dex", 24);

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
        set_skill("quanzhen-jian",120);  //全真剑
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

        set("book_count",1);
        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄门正宗。\n",
                "道德经" : (: ask_me :),
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/greyrobe")->wear();
}

string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "全真教")
                return RANK_D->query_respect(this_player()) +
                "与本教毫无瓜葛，你这话可叫我弄不明白了。";
        if (query("book_count") < 1)
                return "你来晚了，道德经已经被人取走了。";
        add("book_count", -1);
        ob = new("/clone/book/daodejing-ii");
        ob->move(this_player());
        return "好吧，这本「道德经」你拿回去好好研读。";

}

#include "zhi.h";
