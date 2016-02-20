inherit NPC;
#include <ansi.h>

void create()
{
       set_name("南少林弟子", ({ "nanshaolin dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一个身材魁梧的大和尚。\n");
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
			say( "南少林弟子说道：这位" + RANK_D->query_respect(ob)
            + "想加入南少林吗，可以看"BRED"(help nanshaolin)"NOR"。\n");
			break;
		case 1:
			say( "南少林弟子说道：《易筋》，《洗髓》二经向为少林镇寺之宝，相传为达摩祖师所创。\n");
			break;
		case 2:
			say( "南少林弟子说道：南少林武功博大精深，你如能学得一二，就能出人头地了。\n");
			break;
	}

}
