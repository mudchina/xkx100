inherit NPC;
#include <ansi.h>

void create()
{
       set_name("五毒弟子", ({ "wudu dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long", "他是一个满脸瘴气的五毒弟子。\n");
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
		case 0: say("五毒教弟子嘿嘿说道：加入五毒，心慈手软可不行。这位"+RANK_D->query_respect(ob)
+"，想通的话，可以看"BRED"(help wudujiao)"NOR"。\n");
			break;
		case 1: say("五毒教弟子嘿嘿说道：本门毒药毒虫，防不胜防，乃天下第一险毒的门派。哈哈哈..........\n");
			break;	
		case 2: say("星宿弟子奸笑道：听说万毒窟某处藏有五毒教的宝物。\n");
			break;
	}

}
