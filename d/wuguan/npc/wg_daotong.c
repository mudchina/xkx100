
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("武当道童", ({ "daotong", "tong" }) );
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
			say( "武当道童笑嘻嘻地说道：这位" + RANK_D->query_respect(ob)
          + "，想加入武当的话，可以看"BRED"(help wudang)"NOR"。\n");          
			break;
		case 1:
			say( "武当道童喃喃自语道：上次看见张真人已经是一年前了，想来他老人家
 武功境界更加深不可测了，江湖谁不对武当派刮目向待呢。\n");
			break;
		case 2:
			say( "武当道童得意地说道：我武当派的人参果是万木之祖，吃了对内力修为大有好处。\n");
			break;	
	
	}

}
