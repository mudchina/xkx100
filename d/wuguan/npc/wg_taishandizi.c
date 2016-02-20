inherit NPC;
#include <ansi.h>

void create()
{
       set_name("泰山弟子", ({ "taishan dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一个英俊的泰山弟子。\n");
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
			say( "泰山派弟子说道：这位" + RANK_D->query_respect(ob)
            + "想加入泰山派吗，可以看"BRED"(help taishan)"NOR"。\n");
			break;
		case 1:
			say( "泰山派弟子说道：入我泰山方可习得江湖中唯一百发百中的绝招“岱宗如何”。\n");
			break;
		case 2:
			say( "泰山派弟子说道：泰山派自百年前东灵祖师立派以来，代有才人，功夫自可傲立江湖。\n");
			break;
	}

}
