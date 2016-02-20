// Last Modified by Sir on 9/17/2001
inherit NPC;
#include <ansi.h>
void create()
{
	int age = 20 + random(20);
	set_name("武馆门卫", ({ "men wei", "menwei", "wei" }));
	set("gender", "男性");
	set("age", age);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set("apply/attack", 30);
	set("apply/defense", 30);
	set("apply/damage", 35);
	set("combat_exp", 150+age*10);
	set("shen_type", 1);
	setup();
	add_money("silver", 3+age/10);
        carry_object("clone/cloth/cloth")->wear();
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
          {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
          }
}
	
void greeting(object ob)
{
       if( !ob || environment(ob) != environment() ) return;
                 
       if ( ob->query("combat_exp") < 1000)  

           command("say 这位" + RANK_D->query_respect(ob)+"，武功这么差，怎么闯江湖呢？\n");
       
       if ( ob->query("combat_exp") > 1000  && ob->query("combat_exp") < 50000 )
          
           command("say 你武功已有根基，正好来武馆历练，这位" + RANK_D->query_respect(ob)+"你我也算是有缘一场。\n");
          
       if ( ob->query("combat_exp") > 50000)  
         
          command("say 这里只收留江湖新手，武功高强就不要再回来了！");
}

