// Npc: /d/lingxiao/npc/qi.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("齐自勉",({"qi zimian","qi"}));
        set("gender", "男性");
        set("age", 40);
        set("long", 
               "齐自勉是雪山派掌门人威德先生白自在的师弟。\n");
        set("attitude", "peaceful");

        set("str", 30);
        set("con", 30);
        set("int", 30);
        set("dex", 30);
        set("neili", 2000);
        set("max_neili", 2000);
        set("max_jing", 1500);
        set("jing", 1500);
        set("max_qi", 2000);
        set("qi", 2000);
        set("jiali", 50);

        set("combat_exp", 1000000);
        set("shen_type", 0);
        set("score", 50000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("strike", 180);
        set_skill("sword", 180);
        set_skill("force", 180);
        set_skill("parry", 180);
        set_skill("dodge", 180);
        set_skill("literate", 180);

        set_skill("xueshan-sword", 180);
        set_skill("bingxue-xinfa", 180);
        set_skill("snow-strike", 180);
        set_skill("snowstep", 180);

        map_skill("sword", "xueshan-sword");
        map_skill("parry", "xueshan-sword");
        map_skill("force", "bingxue-xinfa");
        map_skill("strike", "snow-strike");
        map_skill("dodge", "snowstep");
        prepare_skill("strike", "snow-strike");

        create_family("凌霄城", 5, "弟子");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
	carry_object(CLOTH_DIR+"bai")->wear();
        carry_object("/clone/money/silver");
}

void attempt_apprentice(object ob)
{
        command("say 我是不收徒的，你去找我那些徒弟吧。");
}

