// npc: /d/xingxiu/npc/alamuhan.c
// Jay 3/17/96

inherit NPC;

int ask_me();
int do_qiecuo();

void create()
{
        set_name("阿拉木罕", ({ "alamuhan", "ala", "muhan" }));
        set("long", "她身段不肥也不瘦。她的眉毛像弯月，她的眼睛很多情。\n");
        set("title", "牧羊姑娘");
        set("gender", "女性");
        set("age", 17);

        set_skill("unarmed", 20);
        set_skill("dodge", 40);
        set_skill("parry", 20);
        set_skill("whip", 50);

        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 5);

        set("combat_exp", 5000);
        set("attitude","friendly");
        set("inquiry", ([
                "姑娘追" : (: ask_me :),
		"赛马" : (: ask_me :),
                "马" : (: ask_me :),
        ]) );

        set("shen_type", 1);
        setup();
        carry_object(__DIR__"obj/wcloth")->wear();
        carry_object(__DIR__"obj/changbian")->wield();
}

/*void init()
{
        ::init();
        add_action("do_qiecuo", "qiecuo");
}
*/
int ask_me()
{
        if ((int)this_player()->query_temp("marks/马")) {
                say(
"阿拉木罕对" + this_player()->name() + "说：你这孩子怎么老缠着本姑娘。\n");
                return 1;
        } else {
        say("阿拉木罕看了" + this_player()->name() + "一眼，用不太标准的汉话说道：\n本姑娘在这里的鞭法也小有点儿名气，这位汉族" + RANK_D->query_respect(this_player()) + "\n想不想和我切磋几下？\n");
        this_player()->set_temp("marks/马1", 1);
        return 1;
        }
}

int accept_fight(object ob)
{
        object me;

        me = this_object();
      
        if( ob->query_temp("marks/马1") ) {
           say(ob->name() + "对阿拉木罕说：好吧，那" 
             "我就同你切搓几招吧，点到为止。\n");
	  remove_call_out("checking");
          call_out("checking", 1, me, ob);
          ob->set_temp("marks/马1", 0);
          return 1;
        }
        else
    	  return 0;
}

int checking(object me, object ob)
{

        object horse;
        int my_max_qi, his_max_qi;
        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");

        if (me->is_fighting()) 
        {
                call_out("checking",2, me, ob);
                return 1;
        }

        if ( !present(ob, environment()) ) return 1; 

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
        {
                say(
                  "阿拉木罕说：中原武学果然不一般，小女子十分佩服。\n"
                  "送你一匹伊犁马略表寸心。\n"
                );
                horse = new(__DIR__"obj/horse"); 
                horse->move(ob);
                ob->set_temp("marks/马", 1);
                message_vision("$N交给$n一匹马。\n", me, ob);
                return 1;
        }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
        {
                say(
                   "阿拉木罕冲着" + ob->name() + "撇了撇嘴，说道：中原武学不过如此。\n"
                );
                message("vision",
                   ob->name() + "对阿拉木罕恭恭敬敬地磕了一个头，离开赛马场。\n", environment(ob), ({ob}) );
                ob->move("/d/xingxiu/beijiang");
                message("vision",
                   ob->name() + "从赛马场垂头丧气地走回来。\n", environment(ob), ({ob}) );
                return 1;
        }
        return 1;
}


