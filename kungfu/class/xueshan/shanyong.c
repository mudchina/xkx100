// /kungfu/class/xueshan/shanyong.c  善勇
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("善勇", ({ "shan yong", "shan", "yong" }));
        set("long",@LONG
一个胖胖的西藏僧人，面带笑容，却常干笑里藏刀的事。
LONG
        );
        set("title",HIR"血刀门第五代弟子"NOR);
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 800);
        set("max_jing", 400);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 50);
        set("combat_exp", 200000);
        set("score", 20000);

        set_skill("lamaism", 50);
        set_skill("literate", 60);
        set_skill("force", 60);
        set_skill("parry", 60);
        set_skill("blade", 60);
        set_skill("dodge", 60);
        set_skill("longxiang", 60);
        set_skill("shenkong-xing", 60);
        set_skill("hand", 60);
        set_skill("dashou-yin", 60);
        set_skill("xue-dao", 30);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        
         set("env/wimpy", 60);

        create_family("雪山寺", 5, "弟子");
        set("class", "lama");

        setup();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("gender") != "男性")
        {
                command("say 我不收女徒弟。\n");
                return;
        }
        command("haha");
        command("recruit " + ob->query("id"));

}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
		       {
        ob->set("title", HIR "血刀门第六代弟子" NOR);
 				  }
}