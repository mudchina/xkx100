// zhangjing.c 掌经道长

inherit NPC;
string ask_me();
string ask_zhipu();

void create()
{
        set_name("掌经道长", ({"zhangjing"}));
        set("gender", "男性");
        set("age", 36);
        set("class", "quanzhen");
        set("long",
                "这位是全真教里掌管经书的道长。他以前是长安镇上一个私塾\n"
                "的夫子，因为仰慕大道，才拜到了全真门下。不过毕竟因为年\n"
                "岁大了，功夫的根基扎得不牢，这也正合他意，可以安安心心\n"
                "地研读经书了。\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 18);
        set("int", 18);
        set("con", 20);
        set("dex", 21);

        set("qi", 500);
        set("max_qi", 500);
        set("jing", 350);
        set("max_jing", 350);
        set("neili", 900);
        set("max_neili", 900);
        set("jiali", 0);

        set("combat_exp", 20000);
        set("score", 15000);

        set_skill("array", 20);
        set_skill("force", 40);
        set_skill("xiantian-qigong", 40);    //先天气功
        set_skill("sword", 40);
        set_skill("quanzhen-jian",40);  //全真剑
        set_skill("dodge", 50);
        set_skill("jinyan-gong", 40);   //金雁功
        set_skill("parry", 50);
        set_skill("unarmed", 50);
        set_skill("strike", 50);
        set_skill("haotian-zhang", 50);    //昊天掌
        set_skill("cuff", 50);
        set_skill("chunyang-quan", 50);    //纯阳拳
        set_skill("literate", 100);
        set_skill("taoism", 80);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        map_skill("cuff", "chunyang-quan");
        prepare_skill("cuff", "chunyang-quan");
        prepare_skill("strike", "haotian-zhang");

        create_family("全真教", 4, "弟子");

        set("book_count",1);
        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄门正宗。\n",
                "道德经" : (: ask_me :),
                "一阳指" : (: ask_zhipu :),
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/yellowrobe")->wear();
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
        ob = new("/clone/book/daodejing-i");
        ob->move(this_player());
        return "好吧，这本「道德经」你拿回去好好研读，有看不懂的地方来问我。";

}

string ask_zhipu()
{
        object me=this_player();
        if(me->query_temp("tmark/指")==2) {
                me->add_temp("tmark/指",1);
                return("一阳指的指法谱向来就是由本教祖师亲自收存，从不外传。\n")
;
        }
        else {
                me->set_temp("tmark/指",0);
                return("听说一阳指是天下最王道的指法，我也没有见过。\n");
        }
}

void attempt_apprentice(object ob)
{
        command("say 我不收弟子，你去找别的道长吧。");
}

