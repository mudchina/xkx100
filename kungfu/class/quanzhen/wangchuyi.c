// wangchuyi.c 王处一

#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name("王处一", ({"wang chuyi", "wang"}));
        set("gender", "男性");
        set("age", 35);
        set("class", "quanzhen");
        set("nickname",RED"玉阳子"NOR);
        set("long",
                "他就是全真七子之五王处一王真人。他身材修长，服饰整洁，\n"
                "三绺黑须飘在胸前，神态潇洒。\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 32);
        set("int", 30);
        set("con", 32);
        set("dex", 30);

        set("title","全真七子之五");
//       set("env/wimpy", 60);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        	(: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: perform_action, "strike.ju" :),                
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.sanqing" :),                
        }));

 /*       set("chat_chance", 8);
        set("chat_msg", ({
                "王处一长叹一声，唉，可恨那杨康把我的药全都藏起来了。\n",
                "王处一道：谁能帮我找回药来，我一定重重酬谢他。\n",
        }));
*/
        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 100);

        set("combat_exp", 500000);
        set("score", 300000);

        set_skill("array", 100);
        set_skill("force", 150);
        set_skill("xiantian-qigong", 150);    //先天气功
        set_skill("sword", 150);
        set_skill("quanzhen-jian", 210);  //全真剑
        set_skill("dodge", 120);
        set_skill("jinyan-gong", 180);   //金雁功
        set_skill("parry", 140);
        set_skill("unarmed", 150);
        set_skill("strike", 140);
        set_skill("haotian-zhang", 200);    //昊天掌
        set_skill("cuff", 140);
        set_skill("chunyang-quan", 200);    //纯阳拳
        set_skill("literate", 100);
        set_skill("taoism", 100);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        map_skill("cuff", "chunyang-quan");
        prepare_skill("cuff", "chunyang-quan");
        prepare_skill("strike", "haotian-zhang");

        create_family("全真教", 2, "弟子");

        set("book_count",1);
        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄门正宗。\n",
                "南帝" : (: ask_me :),
                "段皇爷" : (: ask_me :),
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/greenrobe")->wear();
}

int accept_object(object who, object ob)
{
        object obj1,obj2,obj3,obj4;
        object me=this_player();

        if( !who || environment(who) != environment() ) return 0;
        if ( !objectp(ob) ) return 0;
        if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");

        if (  (string)ob->query("name") != HIR"熊胆"NOR
                && ob->query("name") != HIY"田七"NOR
                && ob->query("name") != HIW"没药"NOR
                && ob->query("name") != RED"血竭"NOR )
                    return 0;

        remove_call_out("destroying");
        call_out("destroying", 1, me, ob);
        message_vision("王处一看了看$N送去的药，点了点头道：难为你了，\n"
                       "我可以教你点功夫。\n", who);

        who->add_temp("tmark/王", 60);
        return 1;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

string ask_me()
{
        object me=this_player();

        if(me->query_temp("tmark/指")==1) {
                me->add_temp("tmark/指",1);
                return("去年师傅去过段皇爷那里，据说段皇爷把他最厉害的一阳指功夫
传授给我师傅了。\n");
        }
        else {
                me->set_temp("tmark/指",0);
                return("段皇爷遇上了一件大伤心事，现在出家做了和尚了，唉！");
        }
}

int recognize_apprentice(object ob)
{
        mapping fam;
        if (!(fam = this_player()->query("family")))
                return notify_fail("王处一道：你可还没拜过师啊，要学功夫还是先拜
个师父再说吧。\n");
        if (!(int)ob->query_temp("tmark/王"))
                return 0;
        if ( fam["family_name"] == "全真教") return 1 ;
        if ((int)ob->query_temp("tmark/王") == 1 )
        message_vision("王处一看看$N，说道：我能教你的东西到此为止，\n"
                          "你也不要再找我学功夫了。\n", ob);
        ob->add_temp("tmark/王", -1);
        return 1;
}

void attempt_apprentice(object ob)
{
        command("say 我不收弟子，你去找别的道长吧。");
}

