// baishou.c 白自在
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("白自在", ({ "bai zizai", "bai" }));
        set("nickname", "雪山剑派掌门人");
        set("title", "铁剑无敌");
        set("long",
                "他就是雪山剑派的掌门人，习武成性，自认为天下武功第一，\n"
                "他大约五十多岁，精明能干，嫉恶如仇，性如烈火。\n");
        set("gender", "男性");
        set("age", 55);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 2000);
        set("qi", 2000);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);
        set("combat_exp", 125000);
        set("score", 60000);

        set_skill("force", 100);
        set_skill("hand", 170);
        set_skill("dodge", 100);
        set_skill("staff", 170);
        set_skill("unarmed", 100);
        set_skill("hamagong", 200);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("chanchu-bufa", 150);
        set_skill("shexing-diaoshou", 100);
        set_skill("literate", 80);
        set_skill("lingshe-zhangfa", 150);

        map_skill("force", "hamagong");
        map_skill("dodge", "chanchu-bufa");
        map_skill("unarmed", "shexing-diaoshou");
        map_skill("parry", "lingshe-zhangfa");
        map_skill("hand", "shexing-diaoshou");
        map_skill("staff", "lingshe-zhangfa");


        setup();
        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
        add_money("gold",2);
}
void init()
{
        object ob;
        ob = this_player();
        ::init();
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
}


void greeting(object ob)
{
        mapping fam;
        int i ;
        object me;
        object* obj;
        object obn;
        me = this_object();
        if (interactive(ob)
                && !environment(ob)->query("no_fight"))
        {
                if (ob->query("shen")>0)
                {
                        command("say 我辈练功学武，所为何事?");
                        command("say 行侠仗义，济人困厄固然是本分，但却是使之小者。");
                        command("say 为国为民，侠之大者，这八个字，日后名扬天下，成为万民敬仰的大侠。");

                        obj = all_inventory(environment(me));
                        for(i=0; i<sizeof(obj); i++)
                        {
                                if(obj[i]==me)
                                        continue;
                                if (random((int)ob->query("kar"))>28)
                                {
command("say 既能到此，既为你我有缘，我这有样东西，你拿去吧。\n");
                                        obn = new("/d/xiakedao/obj/shane-bu");
                                        obn->move(ob);
command("say 到侠客岛来，想必是学武功吧，我在助你一臂之力。\n");
                                        ob->move("/d/xiakedao/neiting");
tell_object(ob,HIR"你只觉眼前一黑，什么也不知道了，醒来却神秘的出现在一个大厅内。\n"NOR);
                                }
command("say 既能到此，既为有缘，在后洞有一把剑，如有缘，你拿去吧。\n");
                        }
                }
                else
                {
                        command("say 年轻人应该走正路，你去吧。");
                }
        }
}
