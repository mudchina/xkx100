inherit NPC;
#include <ansi.h>

void create()
{
       set_name("白驼弟子", ({ "baituo dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一位相貌古怪的白驼山弟子。\n");
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
			say( "白驼山弟子说道：这位" + RANK_D->query_respect(ob)
            + "想加入白驼山吗，可以看"BRED"(help baituo)"NOR"。\n");
			break;
		case 1:
			say( "白驼山弟子说道：掌门西毒欧阳锋的独门绝技蛤蟆功乃是天下武学中的绝顶功夫，
其中内功变化精微，奥妙无穷；外功掌法则刚中有柔，柔中有刚，招式奇特且威力巨大。\n");
			break;
		case 2:
			say( "白驼山弟子说道：少庄主欧阳克风流成性，终日在扬州城内游逛，你可以拜他，
然后他会把你带到白驼山。\n");
			break;
	}

}
