
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("小叫化", ({ "xiao jiaohua", "xiao" }) );
       set("gender", "男性" );
       set("age", 16);
       set("long",
               "他是一个很机灵的小叫化，穿的破破烂烂。\n");
       set("combat_exp", 10500);
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
			say( "小叫化歪着头，说道：这位" + RANK_D->query_respect(ob)
                   + "，想加入我们丐帮吗，可以看"BRED"(help gaibang)"NOR"。\n");
			break;
		case 1:
			say( "小叫化眉飞色舞的说道： 天下第一帮么, 自然是我们丐帮了。
 降龙十八掌，打狗棒是我们丐帮的绝学。\n");
			break;
		case 2:
			say( "小叫化眉飞色舞的说道： 天下第一帮么, 自然是我们丐帮了。
丐帮暗道四通八达，唯有本帮弟子才能使用。\n");
			break;	
	}

}
