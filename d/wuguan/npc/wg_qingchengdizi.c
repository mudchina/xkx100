inherit NPC;
#include <ansi.h>

void create()
{
       set_name("青城弟子", ({ "qingcheng dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一个身材高挑的青城弟子。\n");
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
			say( "青城派弟子说道：这位" + RANK_D->query_respect(ob)
            + "想加入青城派吗，可以看"BRED"(help qingcheng)"NOR"。\n");
			break;
		case 1:
			say( "青城派弟子说道：青城派以剑法暗器见长，没有一定的膂力，是不能拜入青城门下的。\n");
			break;
		case 2:
			say( "青城派弟子说道：青字九打和城字十八破是武林中罕有的技能，学有大成后，如果你找到相应器械并
熟练使用的话，笑傲江湖是不远的梦了。\n");
			break;
	}

}
