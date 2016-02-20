// /kungfu/class/xueshan/lingzhi.c  灵智上人
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("灵智上人", ({ "lingzhi shangren", "shangren", "lingzhi" }));
        set("long",@LONG
灵智上人是雪山寺中地位较高的喇嘛。
身穿一件青色袈裟，头带僧帽。
LONG
        );
        set("nickname",HIR"大手印"NOR);
        set("title",HIY "大喇嘛" NOR);
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 25);
        set("int", 27);
        set("con", 28);
        set("dex", 26);
        set("max_qi", 1500);
        set("max_jing", 800);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 20);
        set("combat_exp", 300000);
        set("score", 30000);

        set_skill("lamaism", 60);
        set_skill("literate", 60);
        set_skill("force", 100);
        set_skill("xiaowuxiang", 100);
        set_skill("dodge", 100);
        set_skill("shenkong-xing", 150);
        set_skill("parry", 80);
        set_skill("hand", 60);
        set_skill("dashou-yin", 90);
        set_skill("staff", 60);
        set_skill("xiangmo-chu", 90 );
        set_skill("unarmed", 110);
        set_skill("yujiamu-quan", 150);        

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "yujiamu-quan");
        map_skill("staff", "xiangmo-chu");
        map_skill("hand", "dashou-yin");
        prepare_skill("hand", "dashou-yin");
        prepare_skill("unarmed", "yujiamu-quan");
        
         set("env/wimpy", 60);

        create_family("雪山寺", 4, "大喇嘛");
        set("class", "lama");

        setup();

        carry_object("/d/xueshan/obj/c-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();

        add_money("silver",50);

}

void attempt_apprentice(object ob)
{

        if ((string)ob->query("gender") != "男性") {
                command("say 修习密宗内功需要纯阳之体。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
        }

        if ((string)ob->query("class") != "lama") {
                command("say 我西藏黄教门内的清规戒律甚多。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
        }

        if ((string)ob->query("family/family_name") != "雪山寺")        {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "既非本寺弟子，还是请回吧！");
                return;
                  }

        if ((int)ob->query_skill("lamaism", 1) < 40) {
                command("say 入我雪山寺，修习密宗心法是首要的。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "是否还应该多多钻研本门的心法？");
                return;
        }

        command("say 就传你一些武功吧！");
        command("recruit " + ob->query("id"));

        ob->set("title",HIY "喇嘛" NOR);
}
