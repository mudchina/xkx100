inherit NPC;
#include <ansi.h>

void create()
{
       set_name("恒山女尼", ({ "hengshan nvni", "nvni" }) );
       set("gender", "女性" );
       set("age", 26);
       set("long",
               "这是是一位恒山的小师太，长的眉清目秀。\n");
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
			say( "恒山女尼微笑着说道：这位" + RANK_D->query_respect(ob)
            + "想入我恒山派吗，可以看"BRED"(help hengshan)"NOR"。\n");
			break;
		case 1:
			say( "恒山女尼说道：恒山派为五岳剑派中的一支，武功以剑法为主，
手上功夫更为武林一绝。\n");
			break;
		case 2:
			say( "恒山女尼正颜道：“恒山三定”威镇江湖，宵小之辈无不闻风而逃。
恒山弟子若得三位师太真传，学成之日定能傲视武林。\n");
			break;
	}

}
