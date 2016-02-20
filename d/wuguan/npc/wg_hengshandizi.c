inherit NPC;
#include <ansi.h>

void create()
{
       set_name("衡山弟子", ({ "hengshan dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一个清秀的衡山弟子。\n");
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
			say( "衡山派弟子说道：这位" + RANK_D->query_respect(ob)
            + "想加入衡山派吗，可以看"BRED"(help henshan)"NOR"。\n");
			break;
		case 1:
			say( "衡山派弟子说道：若能修习衡山派最高深的绝学--百变千幻衡山云雾十三式，一旦有日
练成此绝技，则笑傲武林的梦想不远矣！\n");
			break;
		case 2:
			say( "衡山派弟子说道：我们衡山剑法精妙绝伦，莫大掌门更是武林泰斗。\n");
			break;
	}

}
