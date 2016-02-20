inherit NPC;
#include <ansi.h>

void create()
{
       set_name("铁掌帮弟子", ({ "tiezhang dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "一个一脸阴沉的铁掌帮弟子。\n");
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
			say( "铁掌帮弟子说道：这位" + RANK_D->query_respect(ob)
            + "想加入铁掌帮吗，可以看"BRED"(help tiezhang)"NOR"。\n");
			break;
		case 1:
			say( "铁掌帮弟子说道：本帮每代帮主临终之时，必带着他心爱的宝刀宝剑、珍物古玩上峰，
一代又复一代，石室中宝物自是不少。。\n");
			break;
		case 2:
			say( "铁掌帮弟子说道：本帮以铁掌驰名天下，掌力浑厚恶毒，与降龙十八掌、黯然销魂掌并称
天下。\n");
			break;
	}

}
