inherit NPC;
#include <ansi.h>

void create()
{
       set_name("神龙教弟子", ({ "shenlong dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long", "他是一个满脸瘴气的神龙教弟子。\n");
       set("combat_exp", 25000);
       set("attitude", "friendly");
       setup();
        carry_object("clone/cloth/cloth")->wear();

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
		case 0: say("神龙教弟子嘿嘿说道：加入神龙教，心慈手软可不行。这位"+RANK_D->query_respect(ob)
+"，想通的话，可以看"BRED"(help shenlong)"NOR"。\n");
			break;
		case 1: say("神龙教弟子嘿嘿说道：蛇岛奇功，乃天下第一险毒的武功。哈哈哈..........\n");
			break;	
		case 2: say("神龙教弟子奸笑道：如果被我们神龙教的化骨绵掌打中，非要哀号数月而死。\n");
			break;
	}

}
