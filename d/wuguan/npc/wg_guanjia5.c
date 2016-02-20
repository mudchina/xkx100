
inherit NPC;
#include <ansi.h>

void create()
{
	set_name("菜园管事", ({ "caiyuan guanshi", "guanshi" }) );
	set("gender", "男性" );
	set("age", 50);
	set("long", "他是扬州武馆的一个小管家，专管菜园里大小杂事！\n");
	set("combat_exp", 55500);
	set("attitude", "friendly");
	set("inquiry", ([
		"锄草" : "你就在这老老实实给我锄清杂草，没有我的满意，你别想回去覆命！",
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
	 
	if(ob->query_temp("job_name")!="锄草") return; 

	if (!( present("chutou", ob)))
	{
		command("hmm "+ob->query("id"));
		command("say 你还没领工具吧，去东物品房找老李要。 \n");
		return;
	}

	if(!(ob->query_temp("job_name")!="锄草"))   
	{
		command("nod "+ob->query("id"));
		command("say "+RANK_D->query_respect(ob)+"，你就在这锄草(chu 草)吧。\n");
	}
}
