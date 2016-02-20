inherit NPC;
#include <ansi.h>

void create()
{
       set_name("天地会帮众", ({ "tiandihui bangzhong", "bangzhong" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一个身材矮小的天地会帮众。\n");
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
			say( "天地会帮众说道：这位" + RANK_D->query_respect(ob)
            + "想加入天地会吗，可以看"BRED"(help tiandihui)"NOR"。\n");
			break;
		case 1:
			say( "天地会帮众说道：加入天地会即成为反抗清廷的义士。\n");
			break;
		case 2:
			say( "天地会帮众说道：总舵主陈近南的成名绝技，凝血神抓威震江湖，宵小之辈望风披靡。\n");
			break;
	}

}
