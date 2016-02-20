//NPC:  laozhe.c

inherit NPC;
 
void create()
{
        set_name("老者", ({ "lao zhe", "oldman" }) );
        set("gender", "男性" );
        set("age", 70);
        set("long",
"这个老头正抽旱烟抽得上瘾呢,怎样才能和他搭上话呢?\n");
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("rank_info/respect", "老大爷");
       set("inquiry", ([
                
                "黑木崖" : "黑木崖上有一个穿女人衣裳的吃人恶魔，你可千万不能去！\n",
               "旱烟"   : "青年人,难得你有这份孝心,你若替我买包上好的烟草,我就给你一样东西\n",
                "东西"   : "我所说的东西就是上黑木崖的令牌啦,快去买上好烟草,我等不及了...\n",   
        ]) );

        setup();
}
 
void init()
{
        object ob,me,what;
 
        ::init();
        ob = this_player();
        me = this_object();
        what=new(__DIR__"obj/yancao");
        sprintf("%s \n",what);
        command("give yancao to",me);  
        if( interactive(ob) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "老人家头也不回说道：这位" + RANK_D->query_respect(ob)
                                + "，不要乱跑,小心野兽。\n");
                        break;
                case 1:
                        say( "老人家对你说到:我也一大把年纪了,就好那一口,你就行行好吧。\n");
                        break;
        }
}
 
/*int accept_object(object who, object ob)
{ 
        if (ob->query("money_id") && ob->value() >= 5000)
        {
                tell_object(who, "老头对你说:好，好，真是个好孩子。\n");
                
                who->set_temp("rent_paid",1);
   
                return 1;
        }
 
        return 0;
}*/

 
