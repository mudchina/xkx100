//long.c
#include <ansi.h>
inherit NPC;

int ask_zhou();
int ask_taixuan();

void create()
{
        set_name("龙岛主", ( { "long daozhu", "long" }) );
        set("title", HIR"侠客岛岛主"NOR);
        set("gender", "男性" );
        set("age", 60);
        set("long",
              "这是个看起来五十来岁的汉子，面眉全面，脸色红润，着一袭黄袍，昂然挺立。\n"
        );

        set("int", 30);
        set("str", 25);
        set("con", 30);
        set("dex", 25);
        set("no_get",1);

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 100);

        set("qi",4000);
        set("max_qi", 4000);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 150);
        set("combat_exp", 5000000);
        set("score", 250000);

        set_skill("force", 180);
        set_skill("taiji-shengong", 150);
        set_skill("dodge", 120);
        set_skill("tiyunzong", 100);
        set_skill("unarmed", 180);
        set_skill("taiji-quan", 150);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("taiji-jian", 160);
        set_skill("taoism", 200);
        set_skill("literate", 100);
        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        set("chat_chance", 5);
        set("inquiry", ([
            "腊八粥" : (: ask_zhou :),
            "侠客岛" :  "\n这个岛是我和木兄弟无意中发现的。\n",
            "太玄功" : (: ask_taixuan :),
            "太玄神功" : (: ask_taixuan :),            
        ]));
        set("chat_msg", ({
"龙岛主忽然一怕脑袋，说：腊八粥可是好东西哇！\n",
"龙岛主说道：怎么这么多的英雄也不能领悟太玄经呢。\n",
        }) );
        create_family("侠客岛", 1, "岛主");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold",1);
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
        if( ob->query("combat_exp")< 10000)
              say ("龙岛主抬头望了你一眼，说道：经验尚浅。\n");
        return;
}

int ask_zhou()
{
        say("\n龙岛主对你说：这是本岛特有的东西，它主要由一味'断肠蚀骨腐心草'构成，\n"
"要开花后效力方著，但这种草每十年才开一次花，所以腊八粥很名贵，\n"
"一般人很难得到的，小兄弟想要就要看你的缘分了！\n");
        return 1;
}
int ask_taixuan()
{
	object me = this_player();
	if (me->query_skill("force",1) < 300 
	  || me->query("max_qi")<1300
	  || me->query("combat_exp")< 3000000
	  )
  {
  	command("say 这位"+RANK_D->query_respect(me)+"功力尚浅，还是多修炼修炼再来吧。");
    return 1;	
	}
	command("say 好，你先和木岛主比划一下。多加小心。");
	me->set_temp("pending/fight",1);
  return 1;
}
int accept_object(object who, object ob)
{
        object obn;

        if (  ob->query("id") != "shane bu" && ob->query("id") != "fuxin cao")
        {
                message_vision("\n龙岛主摇头道：这不是我想要的呀！\n",who);
                return 0;
        }
        if ( ob->query("id") == "shane bu" )
        {
                if (random((int)who->query("kar")) <=25 )
                {
                        message_vision("龙岛主摇头道：我看小兄弟今生于此无缘。\n",who);
                        return 1;
                }
                else
                {
                        remove_call_out("destroy");
                        call_out("destroy", 1, who, ob);

                        if(query_temp("cao"))
                        {
                                message_vision("\n龙岛主见是赏善罚恶簿，大喜道：恭喜这位小兄弟了!\n",who);
                                obn=new("/clone/medicine/nostrum/labazhou");
                                obn->move(who);
                                delete_temp("bu");
                                delete_temp("cao");
                                return 1;
                        }
                        else if(query_temp("bu"))
                        {
                                message_vision("\n龙岛主见是赏善罚恶簿，对$N摇头道：赏善罚恶簿我有了。\n",who);
                                return 0;
                        }
                        else
                        {
                                message("vision","龙岛主看见赏善罚恶簿，大喜道：现在只差腐心草了。\n",environment(who));
                                set_temp("bu",1);
                                return 1;
                        }
                }
        }
        if ( ob->query("id") == "fuxin cao")
        {
                if (random((int)who->query("kar")) <=25 )
                {
                        message_vision("龙岛主摇头道：我看小兄弟今生于此无缘。\n",who);
                        return 1;
                }
                else
                {
                        remove_call_out("destroy");
                        call_out("destroy", 1, who, ob);

                        if(query_temp("bu"))
                        {
                                message_vision("\n龙岛主见是腐心草，大喜道：恭喜这位小兄弟了!\n",who);
                                obn=new("/clone/medicine/nostrum/labazhou");
                                obn->move(who);
                                delete_temp("cao");
                                delete_temp("bu");
                                return 1;
                        }
                        else if(query_temp("cao"))
                        {
                                message_vision("\n龙岛主见是腐心草，对$N摇头道：腐心草我已经有了。\n",who);
                                return 0;
                        }
                        else
                        {
                                message("vision","龙岛主看见腐心草，大喜道：现在只差赏善罚恶簿了。\n",environment(who));
                                set_temp("cao",1);
                                return 1;
                        }
                }
        }
        return 1;
}

int recognize_apprentice(object ob)
{

    message_vision("$N摇了摇头。\n",this_object());
    command("tell "+ob->query("id")+"我是不收弟子的，你可以到石室中自学哇！ \n");
    return 0;

}

int do_skills(string arg)
{
        object ob ;
        ob = this_player () ;
        if( !arg || arg!="long" )
                return 0;
        if(wizardp(ob))
                return 0;
        if (ob->query("weiwang") <50 )
        {
        message_vision("$N摇了摇头。\n",this_object());
        write("龙岛主说道：你怎么能看我的武功呢？\n");
        return 1;
        }
        command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"  基本轻功 (dodge)                         - 一代宗师  100/    \n"+
"  基本内功 (force)                         - 一代宗师  100/    \n"+
"  读书写字 (literate)                      - 一代宗师  100/    \n"+
"  基本招架 (parry)                         - 一代宗师  100/    \n"+
"  基本剑法 (sword)                         - 一代宗师  100/    \n"+
"□太极剑法 (taiji-jian)                    - 深不可测  200/    \n"+
"□太极拳 (taiji-quan)                      - 登峰造极  150/    \n"+
"□太极神功 (taiji-shengong)                - 登峰造极  150/    \n"+
"  道学心法 (taoism)                        - 深不可测  200/    \n"+
"□梯云纵 (tiyunzong)                       - 登峰造极  100/    \n"+
"  基本拳脚 (unarmed)                       - 一代宗师  100/    \n");
        return 1;
}
