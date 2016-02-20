inherit NPC;
#include <ansi.h>

void create()
{
       set_name("昆仑弟子", ({ "kunlun dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一个彪悍的昆仑弟子。\n");
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
			say( "昆仑派弟子说道：这位" + RANK_D->query_respect(ob)
            + "想加入昆仑派吗，可以看"BRED"(help kunlun)"NOR"。\n");
			break;
		case 1:
			say( "昆仑派弟子说道：习得本派拳腿双绝，定可笑傲武林。\n");
			break;
		case 2:
			say( "昆仑派弟子说道：祖师“昆仑三圣”何足道文武双全，刀枪剑戟，拳掌气功，琴棋
书画、诗歌词赋，无一不凌驾古今，冠绝天下。\n");
			break;
	}

}
