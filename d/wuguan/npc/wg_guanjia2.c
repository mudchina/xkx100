
inherit NPC;
#include <ansi.h>

void create()
{
	set_name("木房管事", ({ "mufang guanshi", "guanshi" }) );
	set("gender", "男性" );
	set("age", 50);
	set("long", "他是扬州武馆的一个小管家，专管木房！\n");
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("inquiry", ([
		"锯木头" : "你就在这老老实实给我锯木头，没有我的满意，你别想回去覆命！",
	]) );
	setup();

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
	if( !ob || environment(ob) != environment() ) return;
	 
	if(ob->query_temp("job_name")!="锯木头") return; 

	if (!( present("juzi", ob)))
	{
		command("hmm "+ob->query("id"));
		command("say 你还没领工具吧，去东物品房找老李要。 \n");
		return;
	}
	if(!(ob->query_temp("job_name")!="锯木头"))   
	{
		command("nod "+ob->query("id"));
		command("say "+RANK_D->query_respect(ob)+"，你就在这锯木头(ju 木头)吧。\n");
	}
}
