inherit NPC;
#include <ansi.h>

void create()
{
       set_name("逍遥弟子", ({ "xiaoyao dizi", "dizi" }) );
       set("gender", "男性" );
       set("age", 26);
       set("long",
               "他是一个清秀的逍遥弟子。\n");
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
			say( "逍遥派弟子说道：这位" + RANK_D->query_respect(ob)
            + "想加入逍遥派吗，可以看"BRED"(help xiaoyao)"NOR"。\n");
			break;
		case 1:
			say( "逍遥派弟子说道：凌波微步，按伏羲六十四卦而排，内劲行遍一周天，
脚步亦踏遍六十四卦一周天。步法轻灵迅捷，有如凌波而行，罗袜生尘，巧妙已极。\n");
			break;
		case 2:
			say( "逍遥派弟子说道：北冥神功博大精深，天羽奇剑曼妙非凡，学成之后定可独步武林。\n");
			break;
	}

}
