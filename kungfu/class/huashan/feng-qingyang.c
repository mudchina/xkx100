// feng-qingyang.c 风清扬
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
set_name("风清扬", ({ "feng qingyang", "qingyang", "feng" }) );
        set("gender", "男性");
        set("age", 70);
        set("class", "swordsman");
        set("long",
"风清扬乃当今武林一位不世出的高人，深得独孤九剑精髓，一柄长剑\n"
"神出鬼没，罕逢敌手\n");
        set("attitude", "peaceful");
        set("combat_exp", 2000000);
        set("score", 200000);
        set("shen_type", 1);

        create_family("华山派", 12, "弟子");
        assign_apprentice("弟子", 0);

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("neili", 4000);
        set("max_neili", 2200);
        set("jiali", 40);

        set("max_qi",3000);
        set("max_jing", 1000);

//        set("class", "huashan");
//        set("apprentice_available", 1);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 160);
        set_skill("sword", 200);
        set_skill("force", 200);
        set_skill("parry", 190);
        set_skill("dodge", 180);
        set_skill("literate", 200);

        set_skill("huashan-sword", 300);
        set_skill("zixia-shengong", 200);
        set_skill("huashan-ken", 300);
        set_skill("lonely-sword", 200);
        set_skill("yunu-sword", 300);
        set_skill("feiyan-huixiang", 250);

        map_skill("sword", "lonely-sword");
        map_skill("parry", "lonely-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");

        set("inquiry", ([
                "独孤九剑剑谱" : (: ask_me :),
        ]));
        set("book_count", 1);
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",2 , ob);
        }
}
void greeting(object ob)
{
   if ((string)ob->query("family/master_id")==(string)this_object()->query("id"))
   {
      say( "风清扬微笑道：“乖徒儿，你回来啦！”\n");
      call_out("goway",15,ob);
   }
   else if  ((int)ob->query("marks/feng-qingyang")==2)
       {
           say( "风清扬一脸笑意：“多谢你救了小徒!”\n");
           say( "风清扬说道：“如果不嫌弃老夫本事低微，就传你几手如何？”\n");
           command("recruit " + ob->query("id") );
           ob->delete("marks/feng-qingyang",0);
           call_out("goout",20,ob);
       }
        else
       {
            say(HIC"风清扬脸现怒容：“老夫生平不见外客，谁让你到这里来的？”\n"NOR);
            message_vision(HIC"风清扬一袖把$N拂到华山脚下去了。\n"NOR,ob);
            ob->move("/d/huashan/path1");
        }
}
int goway(object ob){
     object *ob1;
     int i,j;

     j=0;
     if ( environment(ob)==environment(this_object()))
         call_out("goway",15,ob);
     else{
         ob1 = all_inventory(environment(this_object()));
         for(i=0; i<sizeof(ob1); i++){
            if ( (userp(ob1[i]))
               && ((string)ob1[i]->query("family/master_id")=="master feng-qingyang") )
               j=1;
           }
        if (j==0){
         destruct(this_object());
         return 1;
         }
        else call_out("goway",15,ob);
      }
}
void goout(object ob){
    message_vision("风清扬大袖一挥，飘然离$N而去.\n",ob);
    destruct(this_object());
}

string ask_me()
{
    object me,ob;

    me = this_player();
    if ((string)me->query("family/master_id")==(string)this_object()->query("id"))
    {
         if (query("book_count") < 1) return "你来晚了，独孤九剑剑谱不在此处。";
         if ((int)me->query("marks/ls-book")==1) return "你已经取过一本独孤九剑剑谱了。";
         switch (random(10))
         {
              case 0:
                   me->set("marks/ls-book",1);
                   add("book_count", -1);
                   ob = new(__DIR__"ls_book");
                   ob->move(me);
                   return "好吧，这本「独孤九剑剑谱」你拿回去好好钻研。";
              default:
                   return "「独孤九剑剑谱」？这东西失传很久了。";
         }
    }
    else return RANK_D->query_respect(this_player()) + "不是我的徒弟吧？";
}

