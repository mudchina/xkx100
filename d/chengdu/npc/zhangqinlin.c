// zhangqinlin.c 张禽林 
// Last Modifyed by Winder on Dec. 24 2001

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("张禽林", ({ "zhangqinlin", "zhang", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long", "由于生意不大好，所以他脸上也没什么笑容。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "阿林");
	set("vendor_goods", ({
		__DIR__"obj/zongzi",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		if ( (myfam = ob->query("family")) &&
			myfam["family_name"] == "丐帮" &&
			ob->query_skill("begging",1) > 10 )
		{
			remove_call_out("saying");
			call_out("saying", 0, ob);
		}
		else
		{ 
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}


void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	say("\n只听阿林大喝一声：你这臭要饭的进来干什么？给我滚出去！\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/chengdu/xiaojie1");
	message("vision", "只听“乒”地一声，" + ob->query("name") + "被人从粽子店里一脚踢了出来，狼狈万状的逃开了。\n", environment(ob), ob);
}
