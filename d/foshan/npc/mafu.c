// mafu1.c 马夫

inherit NPC;
#include <ansi.h>
int do_ride();

void create()
{
        set_name("马夫", ({ "ma fu","ma fu"}));
        set("age", 32);
        set("gender", "男性");
        set("long","驯马和租马的小贩，给他租金就可以雇到马。\n");
        set("attitude", "peaceful");
        set("str", 24);
        set("dex", 16);
        set("combat_exp", 50000);
        set("shen_type", 1);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("force", 60);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/armor", 30);
        set("chat_chance",2);
        setup();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
               remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_rideyz", "rideyz");
}
void greeting(object ob)
{	
	int chance;
	chance = random(10);		
        if( !ob || environment(ob) != environment() ) return;
        ob->set_temp("ridechance",chance);        
        say( "马夫点头哈腰地说道：这位客官，是想到这里挑一匹好马吧？\n");
}

int accept_object(object who, object ob)
{
	
	object myenv ;		
	if (ob->query("money_id") && ob->value() >= 100)
	{
	  if ((int)this_player()->query_temp("ridechance")<=2)
	  {
	    message_vision("马夫惊慌地对$N说：对不起大爷，最近道上不太平，小的可不敢担这个险。\n", who); 
	    return 0;
	   }
	  else  
	   {     
	        message_vision("马夫对$N说：好！这位"+RANK_D->query_respect(who) +
		"现在就出发吗？那就上马吧。\n", who);
		this_player()->set_temp("marks/horserent",1);		
 	      	return 1;
 	    }  	
	}
	else  
		message_vision("马夫皱眉对$N说：您给的也太少了吧？\n", who);
	return 1;
}

#include "mafuyz.h"
