// cheng-buyou.c  成不忧
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("成不忧", ({ "cheng buyou", "cheng" }) );
        set("gender", "男性");
        set("class", "swordsman");
        set("title", "华山剑宗第十三代弟子");
        set("age", 41);
        set("long",
                "一个白净面皮的矮子，可也不能小看他。\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 4000);
        set("max_neili", 2400);
        set("jiali", 30);
        set("max_qi",2000);
        set("max_jing",1200);

        set("combat_exp", 1000000);
        set("shen", -200000);
        set("apprentice_available", 3);

        set("env/wimpy", 60);
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.feilong" :),
                (: exert_function, "powerup" :),
                (: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
        }) );

        set_skill("unarmed", 80);
        set_skill("sword", 150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("literate", 100);
        set_skill("kuangfeng-jian", 220);
        set_skill("huashan-sword", 220);
        set_skill("huashan-neigong", 150);
        set_skill("huashan-ken", 120);
        set_skill("hunyuan-zhang", 100);
        set_skill("huashan-shenfa", 120);

        map_skill("sword", "kuangfeng-jian");
        map_skill("parry", "huashan-sword");
        map_skill("force", "huashan-neigong");        
        map_skill("dodge", "huashan-shenfa");

        create_family("华山派剑宗", 13, "弟子");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if(ob->query("family/master_id") != "yue buqun")
              say ("成不忧说：这位"+RANK_D->query_respect(ob) + "，来投我剑宗吧。\n");
        else
        {
              message_vision("成不忧一见$N就大怒：我最讨厌伪君子的徒弟了。\n", ob);
              this_object()->kill_ob(ob);
        }
        return;
}

void attempt_apprentice(object ob)
{
        command("say 老夫从不收徒，你找我封师兄好了。");
}

