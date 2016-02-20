// zhangyao.c 掌药道长

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("掌药道长", ({"zhangyao"}));
        set("gender", "男性");
        set("age", 28);
        set("class", "quanzhen");
        set("long",
                "这是全真教中的掌管所有药物的道人。他年纪不大，但看起来\n"
                "显得少年老成。\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 21);
        set("int", 22);
        set("con", 23);
        set("dex", 22);

        set("qi", 600);
        set("max_qi", 600);
        set("jing", 400);
        set("max_jing", 400);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 0);

        set("combat_exp", 30000);
        set("score", 20000);

        set_skill("array", 30);
        set_skill("force", 60);
        set_skill("xiantian-qigong", 50);    //先天气功
        set_skill("sword", 60);
        set_skill("quanzhen-jian", 60);  //全真剑
        set_skill("dodge", 50);
        set_skill("jinyan-gong", 50);   //金雁功
        set_skill("parry", 60);
        set_skill("unarmed", 60);
        set_skill("strike", 60);
        set_skill("haotian-zhang", 50);    //昊天掌
        set_skill("cuff", 60);
        set_skill("chunyang-quan", 50);    //纯阳拳
        set_skill("literate", 50);
        set_skill("taoism", 40);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        map_skill("cuff", "chunyang-quan");
        prepare_skill("cuff", "chunyang-quan");
        prepare_skill("strike", "haotian-zhang");

        create_family("全真教", 4, "弟子");

        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄门正宗。\n",
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/yellowrobe")->wear();
}

int accept_object(object who, object ob)
{
        object obj,obj1,obj2;
        object me=this_player();

        if( !who || environment(who) != environment() ) return 0;
        if ( !objectp(ob) ) return 0;
        if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");

        if (  (string)ob->query("name") != HIB"乌龟甲"NOR
                && ob->query("id") != "fuling" )
                    return notify_fail("掌药道长摇头道：这不是配药的材料。\n");

        if  ((string)ob->query("name") == HIB"乌龟甲"NOR)
        {
                if(query_temp("fuling")) {
                        write(MAG"掌药道长大喜，龟甲和茯苓都有了，这副龟苓膏可炼成了。\n"NOR);
                        obj=new("/clone/medicine/nostrum/guilinggao");
                        obj->move(who);
                        delete_temp("guijia");
                        delete_temp("fuling");
                        if(!(obj2=present("gui jia", this_player())))
                        destruct(obj2);
                        remove_call_out("destroying");
                        call_out("destroying", 1, me, ob);

                        return 1;
                }
                else {
                        if(query_temp("guijia")) {
                                write(YEL"掌药道长摇了摇头道：“龟甲我已经有了。”\n"NOR);
                                return 0;
                        }
                        else {
                                set_temp("guijia",1);
                                write(WHT"掌药道长笑道：龟甲有了，就缺茯苓了。\n"NOR);
                                if(!(obj2=present("gui jia", this_player())))
                                destruct(obj2);
                                remove_call_out("destroying");
                                call_out("destroying", 1, me, ob);
                                return 1;
                        }
                }
        }
        if (ob->query("id") == "fuling")
        {
                if(query_temp("guijia")) {
                        write(MAG"掌药道长大喜，龟甲和茯苓都有了，这副龟苓膏可炼成了。\n"NOR);
                        obj=new("/clone/medicine/nostrum/guilinggao");
                        obj->move(who);
                        delete_temp("guijia");
                        delete_temp("fuling");
                        if(!(obj1=present("fuling", this_player())))
                        destruct(obj1);
                        remove_call_out("destroying");
                        call_out("destroying", 1, me, ob);
                        return 1;
                }
                else {
                        if(query_temp("fuling")) {
                                write(YEL"掌药道长摇了摇头道：“茯苓我已经有了。”\n"NOR);
                                return 0;
                        }
                        else {
                                set_temp("fuling",1);
                                write(WHT"掌药道长笑道：茯苓有了，就缺龟甲了。\n"NOR);
                                if(!(obj2=present("fuling", this_player())))
                                destruct(obj2);
                                remove_call_out("destroying");
                                call_out("destroying", 1, me, ob);
                                return 1;
                        }
                }
        }

}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
void attempt_apprentice(object ob)
{
        command("say 我不收弟子，你去找别的道长吧。");
}

