// yuzu.c
#include <ansi.h>
#include <command.h>
inherit NPC;
void create()
{
	set_name("刑部狱卒", ({ "yu zu","zu" }) );
	set("title", HIR"八品"HIB"带刀侍卫"NOR);
	set("gender", "男性" );
	set("age", 32);
	set("str", 22);
	set("con", 25);
	set("dex", 20);
	set("int", 30);
	set("long","天子脚下北京城的刑部红顶狱卒，满脸横肉，刁狠苛毒。你看来要小心了。\n");
	set("combat_exp", 2000000);
	set("attitude", "heroism");

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("max_neili", 2000);
	set("neili", 2000);
	set("jiali", 100);
	set_skill("unarmed",200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("force", 200);
	set_skill("blade", 200);

	set("inquiry", ([
		"出狱" : "嘿嘿嘿嘿！想出狱啊？没圣上的旨意，今生没指望喽。\n",
	]) );
	setup();

	carry_object("/d/city/obj/yayifu")->wear();
	carry_object(WEAPON_DIR"gangdao")->wield();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_chat","chat");
	add_action("do_chat","rumor");
	add_action("do_chat","party");
	add_action("do_chat","xkx");
	add_action("do_chat","sing");
	add_action("do_chat","to");
	add_action("do_chat","chat*");
	add_action("do_chat","tell");
	add_action("do_chat","reply");
	add_action("do_chat","exert");
	add_action("do_chat","yun");
	add_action("do_chat","dazuo");
	add_action("do_chat","exercise");
	add_action("do_chat","tuna");
	add_action("do_chat","meditate");
	add_action("do_chat","lian");
	add_action("do_chat","practice");
	add_action("do_chat","du");
	add_action("do_chat","study");
	add_action("do_chat","xue");
	add_action("do_chat","learn");
	add_action("do_chat","vote");
	add_action("do_chat","finger");
	add_action("do_chat","suicide");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if( !wizardp(ob))
	command("rumor 江洋大盗" + ob->query("name") + "已被刑部锦衣卫籍拿归案！\n");
	ob->set("startroom","/d/beijing/jail");
}

int do_chat(string arg)
{
	object ob = this_player();
	switch(random(3))
	{
		case 1:
			command("say "+ob->query("name")+"！你敢再动一动！再动就给你一桶马尿！\n");
			break;
		case 2:
			command("say "+ob->query("name")+"！你是皮痒还是哪里不爽？\n");
			message_vision( HIR"刑部狱卒劈头盖脑就是一阵皮鞭，抽得$N皮开肉绽，再兜头一桶人尿，好不清爽！\n"NOR,ob);
			ob -> receive_damage("qi",10);
			break;
		default:
			command( "say "+this_player()->query("name")+"！你是不是觉得这里很舒服想多开心几天？\n");
			break;
	}
	return 0;
}
