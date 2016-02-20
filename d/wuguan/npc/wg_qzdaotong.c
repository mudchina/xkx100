
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("全真道童", ({ "daotong", "tong" }) );
       set("gender", "男性" );
       set("age", 16);
       set("long",
               "他是一个十七八岁的小道童，一幅天真的样子。\n");
       set("combat_exp", 2500);
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
			say( "全真道童含笑道：这位" + RANK_D->query_respect(ob)
          + "，想加入全真教的话，可以看"BRED"(help quanzhen)"NOR"。\n");
			break;
		case 1:
			say( "全真道童得意地说道：祖师王重阳，又号「中神通」，首次华山
论剑，连败东邪、西毒、南帝、北丐，夺得武功天下第一的称号。\n");
			break;
		case 2:			
			say( "全真道童喃喃自语道：修习先天功后，练得玄门定阳丹可以长内力，妙用无穷哦。\n");			
			break;	
	}

}
