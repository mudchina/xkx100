
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("天龙寺弟子", ({ "tianlongsi dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 18);
       set("long",
               "他是一个天龙寺的小师傅。\n");
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
			say( "天龙寺弟子说道：这位" + RANK_D->query_respect(ob)
          + "加入大理天龙寺的话，可以看"BRED"(help dali)"NOR"。\n");
			break;
		case 1:
			say( "天龙寺弟子说道：一阳指，枯荣禅功可是佛门绝学，你要是再能学到六脉神剑的话，
  必能傲视群雄。\n");
			break;
		case 2:
			say( "天龙寺弟子说道：大理茶花天下闻名，练功之余去茶花园赏赏花、品品茶，倒也不失
为一件乐事。\n");
			break;	
	}
}
