// /kungfu/class/xueshan/baoxiang.c  宝象
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("宝象", ({ "bao xiang", "bao", "xiang" }));
        set("long",@LONG
一个极高极瘦的僧人，俩眼凶芒四射。此人在血刀老祖门下，最是心狠手辣。
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
        set("max_qi", 1500);
        set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);
        set("combat_exp", 250000);
        set("score", 35000);

        set_skill("lamaism", 50);
        set_skill("literate", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("blade", 80);
        set_skill("dodge", 80);
        set_skill("longxiang", 80);
        set_skill("shenkong-xing", 120);
        set_skill("hand", 80);
        set_skill("dashou-yin", 120);
        set_skill("xue-dao", 120);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        set("env/wimpy", 60);
        set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "blade.shendao" :),
		(: exert_function, "fenchang" :),
		(: exert_function, "shield" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

        create_family("雪山寺", 5, "弟子");
        set("class", "lama");

        setup();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/clone/weapon/gangdao")->wield();

        add_money("gold",1);
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("gender") != "男性")
        {
                command("say 我不收女徒弟。\n");
                return;
        }
        if (ob->query("shen") > 0)
        {
                command("say 我正想找你们侠义道的晦气。\n");
                this_object()->kill_ob(ob);
                return;
        }
        if ((int)ob->query_skill("longxiang", 1) < 30)
        {
                command("say 入我血刀门，修习龙象功法是首要的。\n");
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