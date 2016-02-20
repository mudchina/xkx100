// feng.c
#include <command.h>
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()                                                                   
{
        set_name( "冯默风" ,({ "feng mofeng", "feng" }));
        set("gender", "男性");
        set("age", 39);
        set("long",
            "冯默风是黄药师最小的一个徒弟，他的根基不错，但性子较为愚鲁。\n"
            "他的基本功扎实，一副忠厚老实的样子。\n");
        set("attitude", "friendly");
        set("class", "scholar");
        set("str", 30);
        set("int", 29);
        set("con", 35);
        set("dex", 25);
        set("env/wimpy", 60);
        set("chat_chance", 1);
        set("chat_msg", ({
            "冯默风说道：“师父疼爱小师妹，他的软猬甲一直由小师妹穿着。”\n",
            "冯默风自言自语地说道：“这个桃花阵，嗨，不简单！”\n",
        }));
        set("max_qi",1000);
        set("max_jing",500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 100);
        set("shen_type",1);
        set("combat_exp", 200000);
        set_skill("force", 70);             // 基本内功
        set_skill("bibo-shengong", 60);     // 碧波神功
        set_skill("unarmed", 60);           // 基本拳脚
        set_skill("xuanfeng-leg", 90);      // 旋风扫叶腿
        set_skill("strike", 60);            // 基本掌法
        set_skill("luoying-zhang", 90);     // 落英神剑掌
        set_skill("dodge", 50);             // 基本躲闪
        set_skill("anying-fuxiang", 70);    // 暗影浮香
        set_skill("parry", 70);             // 基本招架
        set_skill("sword", 70);             // 基本剑法
        set_skill("luoying-shenjian", 100);  // 落英神剑
        set_skill("literate",50);           // 读书识字

        map_skill("force"  , "bibo-shengong");
        map_skill("unarmed", "xuanfeng-leg");
        map_skill("strike" , "luoying-zhang");
        map_skill("dodge"  , "anying-fuxiang");
        map_skill("parry"  , "luoying-shenjian");
        map_skill("sword"  , "luoying-shenjian");

        create_family("桃花岛", 2, "弟子");

        set("inquiry", ([
           "桃花岛":   "这儿就是桃花岛，你若不是本派弟子，要过桃花阵。",
           "桃花阵":   "往南就是了。",
           "东邪":     "家师人称东邪！呵呵。",
           "西毒":     "欧阳锋是与家师并世齐名的高手，人称老毒物。",
           "南帝":     "听家师说段王爷现在出家当了和尚，法名一灯。",
           "北丐":     "北丐洪七公是丐帮帮主，现在扬州城外。",
           "黄蓉":     "她是师父的爱女。",
           "黄药师":   "你要拜访家师？"
        ]) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian");
}                                                                               

void attempt_apprentice(object ob)
{
    if (ob->query_dex() < 20)
    {
       command("say 我派武功讲究轻灵巧捷。");
       command("say 这位"+RANK_D->query_respect(ob)+"可能是白来桃花岛一趟了。");
       return;
    }
    if (ob->query("gender") == "无性")
    {
       command("say 师父最讨厌不男不女的东西了，这位"+RANK_D->query_respect(ob)+"赶快请吧。");
       return;
    }
    if (ob->query("class") == "bonze")
    {
       command("say 师父最爱非僧抑道了，这位"+RANK_D->query_respect(ob)+"还是请回吧。");
       return;
    }
    if (ob->query_skill("bibo-shengong",1) <= 30)
    {
       command("say 你进桃花岛之前没去我陆师兄那儿么？");
       return;
    }
    if (ob->query_skill("literate",1) <= 10)
    {
       command("say 桃花岛只收读书人作弟子，这位"+RANK_D->query_respect(ob)+"是否去读点书再来。");
       return;
    }
    command("smile");
    command("say " + RANK_D->query_respect(ob) + "入我门下，需努力不堕。");
    command("recruit " + ob->query("id"));
}
int accept_fight(object ob)
{
   command("wield jian");
}
