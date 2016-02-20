inherit NPC;
#include <ansi.h>

void create()
{
       set_name("嵩山弟子", ({ "songshan dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一个年青的嵩山弟子。\n");
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
			say( "嵩山派弟子说道：这位" + RANK_D->query_respect(ob)
            + "想加入嵩山派吗，可以看"BRED"(help songshan)"NOR"。\n");
			break;
		case 1:
			say( "嵩山派弟子说道：五岳剑派共由江湖中的五大门派组成，即：恒山派、华山派、嵩山派、
衡山派及泰山派。我嵩山派为五岳剑派盟主。\n");
			break;
		case 2:
			say( "嵩山派弟子说道：我们嵩山剑法博大精深，你如能学得一二，就能出人头地了。\n");
			break;
	}

}
