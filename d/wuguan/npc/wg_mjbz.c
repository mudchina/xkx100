
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("明教帮众", ({ "mingjiao bangzhong", "bangzhong" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一个身强力壮汉子。\n");
       set("combat_exp", 12500);
       set("attitude", "friendly");
 
       setup();
 carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
	 

	if (!ob || !present(ob, environment())) return;
	switch( random(3) ) {
		case 0:
			say( "明教帮众说道：天下第一教, 就是我们明教。。这位" + RANK_D->query_respect(ob)
              + "，若想入明教，可以看"BRED"(help mingjiao)"NOR"。\n");
			break;
		case 1:
			say( "明教帮众说道：乾坤大挪移，圣火令神功可是独步武林的绝学啊。\n");
			break;
		case 2:
			say( "明教帮众说道：本教四大护教法王各有一种护身绝技！\n");
			break;	
	}

}
