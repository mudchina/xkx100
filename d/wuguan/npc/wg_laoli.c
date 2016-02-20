#include <ansi.h>

inherit NPC;

int give_tools();

void create()
{
	set_name("老李",({ "lao li", "li" }) );
	set("gender", "男性" );
	set("age", 45);
	set("long","他是扬州武馆里管物品工具的，人们都习惯称他老李，真名反而倒没什么人知道了。\n");
	set("combat_exp", 25000);
	set("attitude", "friendly");
	set("inquiry", ([
		"工具" : (: give_tools :),
	]) );
	setup();
	carry_object("clone/cloth/cloth")->wear();
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
	
int give_tools()
{
	object tools,ob,me;
	me = this_object();
	ob = this_player();

	if(ob->query_temp("mark/工具"))
		return notify_fail("老李说：你已经领了工具了，怎么没还又来领了？");
	if(ob->query_temp("mark/还了"))
		return notify_fail("老李说：你还没覆命领新活吧，跑来要什么工具。");

	if(!((ob->query_temp("job_name")=="锯木头" ) ||
		(ob->query_temp("job_name")=="锄草" ) ||
		(ob->query_temp("job_name")=="浇菜地" ) ||
		(ob->query_temp("job_name")=="劈柴" ) ||
		(ob->query_temp("job_name")=="挑水" ) ||
		(ob->query_temp("job_name")=="打扫马房")))
		return notify_fail("老李说：你没跟张总管领活吧，跑来要什么工具。");
 
	if(ob->query_temp("job_name")=="锄草")
		tools = new((__DIR__"obj/wg_chutou"));
	else if(ob->query_temp("job_name")=="浇菜地")
		tools = new((__DIR__"obj/wg_piao"));
	else if(ob->query_temp("job_name")=="锯木头")
		tools = new((__DIR__"obj/wg_juzi"));
	else if(ob->query_temp("job_name")=="劈柴")
		tools = new((__DIR__"obj/wg_chaidao"));
	else if(ob->query_temp("job_name")=="挑水")
		tools = new((__DIR__"obj/wg_shuitong"));
	else tools = new((__DIR__"obj/wg_saozhou"));
	tools->move(this_player());
	command("say 既然你已经领了活，我就给你这把工具，小心保管，别弄丢了。");
	message_vision("$N交给$n一把工具。\n", me, ob);
	ob->set_temp("mark/工具",1);
	return 1;
}

int accept_object(object me, object obj)
{
	object ob;
	me=this_object();
	ob=this_player();

	if(!(ob->query_temp("mark/劈完了") ||
		ob->query_temp("mark/浇完了") ||
		ob->query_temp("mark/锄完了") ||
		ob->query_temp("mark/挑完了") ||
		ob->query_temp("mark/锯完了") ||
		ob->query_temp("mark/扫完了")))
	{
		command("say 你还没完成工作，怎么就回来还工具了，偷懒吗？");
		return 0;
	}
	if ((obj->query("id")!="juzi") &&
		(obj->query("id")!="chutou") &&
		(obj->query("id")!="piao") &&
		(obj->query("id")!="saozhou") &&
		(obj->query("id") != "shuitong") &&
		(obj->query("id") != "chaidao"))
	{
		command("say 你还错东西了吧，我从没有发过这样工具。");
		return 0;
	}
	if(!ob->query_temp("job_name"))
	{
		command("shake");
		command("say 我没有发给你过东西，你是不是还错了？");
		return 0;
	}
	command("nod");
	command("say 欢迎下次再来！");
	ob->set_temp("mark/还了",1);
	call_out("destroying", 1, me, obj);	   
	return 1;
}
void destroying(object me, object obj)
{
	destruct(obj);
	return;
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if(ob->query_temp("mark/工具")) return 0; 

	if(ob->query_temp("mark/劈完了") ||
		ob->query_temp("mark/浇完了") ||
		ob->query_temp("mark/锄完了") ||
		ob->query_temp("mark/锯完了") ||
		ob->query_temp("mark/扫完了") ||
		ob->query_temp("mark/挑完了"))
	{
		command("smile"+ob->query("id"));
		command("say 工作做完了，可以还工具"HIR"(give xxx to laoli)"NOR"给我了! \n");
		return; 
	}
	if((ob->query_temp("job_name")=="锯木头" ) ||
		(ob->query_temp("job_name")=="锄草" ) ||
		(ob->query_temp("job_name")=="浇菜地" ) ||
		(ob->query_temp("job_name")=="劈柴" ) ||
		(ob->query_temp("job_name")=="挑水" ) ||
		(ob->query_temp("job_name")=="打扫马房" ))
	{
		command("bow "+ob->query("id"));
		command("say 这位" + RANK_D->query_respect(ob) + "，到我这领工具(ask li about 工具)吧。\n");
	}
}				

