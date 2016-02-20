inherit NPC;
#include <ansi.h>

void create()
{
       set_name("红花会帮众", ({ "honghuahui bangzhong", "bangzhong" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一个身材魁梧的红花会帮众。\n");
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
			say( "红花会帮众说道：这位" + RANK_D->query_respect(ob)
            + "想加入红花会吗，可以看"BRED"(help honghua)"NOR"。\n");
			break;
		case 1:
			say( "红花会帮众说道：七十二路追魂夺命剑天下无双，是二当家无尘道长的得意武功。\n");
			break;
		case 2:
			say( "红花会帮众说道：总舵主陈家洛的成名绝技，落花十三剑威震江湖，宵小之辈望风披靡。\n");
			break;
	}

}
