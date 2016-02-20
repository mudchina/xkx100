// zhike.c 知客道长

inherit NPC;

string ask_me();
string ask_for_join();
int do_kneel();

void create()
{
        set_name("知客道长", ({"zhike daozhang","zhike"}));
        set("gender", "男性");
        set("age", 42);
        set("class", "quanzhen");
        set("long",
                "他是全真教第四代弟子中年纪最大的一位，以前做过小买卖，\n"
                "走南闯北，见多识广，后来拜到全真门下。掌教见他岁数毕竟\n"
                "大了，不适宜再修练上乘功夫。且喜他能言善道，熟识礼节，\n"
                "就安排在山门处专事接待访客。\n");
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
        set_skill("quanzhen-jian", 40);  //全真剑
        set_skill("dodge", 50);
        set_skill("jinyan-gong", 40);   //金雁功
        set_skill("parry", 50);
        set_skill("strike", 50);
        set_skill("haotian-zhang", 50);    //昊天掌
        set_skill("cuff", 50);
        set_skill("chunyang-quan", 50);    //纯阳拳
        set_skill("literate", 60);
        set_skill("taoism", 50);

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
                "出家"   :  (: ask_for_join() :),
                "西毒"   :  (: ask_me :),
                "欧阳锋" :  (: ask_me :),
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/yellowrobe")->wear();
}

string ask_me()
{
        object me=this_player();
        me->set_temp("tmark/指",1);
        return("去年祖师假死以诱西毒来抢夺九阴真经，结果西毒被祖师以一阳指破了修
炼多年的蛤蟆功。\n");
}

void init()
{
	add_action("do_kneel", "kneel");
}

#include "qing.h"
