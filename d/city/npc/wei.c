// npc: /d/city/npc/wei.c
// Dec.12.1997 by Venus
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("韦春芳", ({ "wei chunfang", "chunfang", "wei" }) );
	set("gender", "女性" );
	set("title", "丽春院老板娘");
	set("age", 42);
	set("long", "韦春芳是当朝鹿鼎公兼天地会青木堂香主韦小宝他娘，虽是徐\n娘半老，但风韵犹存。\n");
	set("no_get", "1");
	set("no_get_from", 1);
	set("str", 25);
	set("dex", 25);
	set("con", 25);
	set("int", 25);
	set("shen_type", 1);

	set_skill("unarmed", 20);
	set_skill("force", 20);
	set_skill("dodge", 35);

	set("combat_exp", 25000);

	set("max_qi", 300);
	set("max_jing", 100);
	set("neili", 500);
	set("max_neili", 500);

	set("attitude", "friendly");
	set("inquiry", ([
		"name"   : "老娘我就是韦春芳。",
		"韦小宝" : "那是我的乖儿子，长得就像你。",
		"丽春院" : "我们丽春院可是扬州城里头一份的找乐子去处。",
		"here"   : "我们丽春院可是扬州城里头一份的找乐子去处。",
	]) );

	setup();
	set("chat_chance", 15);
	set("chat_msg", ({
		"韦春芳得意地说道：当年老娘我标致得很，每天有好几个客人。\n",
		"韦春芳怒骂道：辣块妈妈，要是罗刹鬼、红毛鬼子到丽春院来，老娘用
大扫帚拍了出去。\n",
		"韦春芳对你说道：你一双眼睛贼忒嘻嘻的，真像那个喇嘛！\n",
	}) );
	carry_object("/d/city/obj/flower_shoe")->wear();

	carry_object("/d/city/obj/pink_cloth")->wear();
}
void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_sell", "sell");
}

void greeting(object me)
{
	command("look " + me->query("id"));

	if ((me->query("gender")=="无性") &&
		(file_name(environment())=="/d/city/lichunyuan"))
	{
		command("say 你当老娘是烂婊子吗？辣块妈妈，老娘满汉蒙藏回都接，
就是不伺太监！\n");
		command("kick " + me->query("id"));
		message("vision", me->name() +"被韦春芳一脚踢出门外。\n", environment(me), ({me}));
		me->move("/d/city/beiliuxiang");
		message("vision", me->name() + "被人从丽春院里踢了出来，栽倒在地上，磕掉两颗门牙。\n",environment(me), ({me}));
	}
	else
	{
		if (me->query("class") =="bonze")
		{
			command( "say 呦，" + RANK_D->query_respect(me)+"也来光顾我们丽春院啊。");
			command( "say 想当年我接过一个西藏喇嘛，他上床前一定要念经，一面念经，眼珠子就骨溜溜的瞧着我。");
		}
		if (me->query("gender")=="女性")
		{
			command("say 哎呀，这年月大姑娘也逛窑子，成何体统。");
			command("sigh");
			command("say 可惜我儿子不在，不然让他伺候你。");
		}
		command("say 楼上楼下的姑娘们，客人来了！");
	}
	return ;
}

int do_sell(string arg)
{
	object ob, myenv;
	int value;
	object *inv;
	
	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("你要卖什么？\n");
	if (!userp(ob))
		return notify_fail("老娘只买「人」。你这是要给我什么东东？\n");
	if( query_ip_name(this_player()) == query_ip_name(ob))
		return notify_fail("自己卖自己？实在是发财有道了。\n");
	if (ob->query_condition("prostitute") > 1)
		return notify_fail("这人已经是老娘的人了。你还敢来骗钱？\n");

	ob->set("value", ob->query("per") * 800);
	command("rumor "+ob->query("name")+"被拐卖到丽春院了，不多不少，正好" +
		CHINESE_D->chinese_number(ob->query("value")) + "个铜板哪。\n");

	message_vision("$N把" + ob->query("name") + "卖给韦春芳。\n", this_player());
	command("sys "+ob->query("name")+"被" +this_player()->query("name")+"("+this_player()->query("id")+")。");
	log_file("sell",sprintf("%-20s sell %-20s [%s]\n",this_player()->query("name")+"("+this_player()->query("id")+")",ob->query("name")+"("+ob->query("id")+")",ctime(time())));
	MONEY_D->pay_player(this_player(), value * 70 / 100);
	myenv = environment (this_player());
	tell_room(myenv,"韦春芳开心大笑：老娘要发财了。\n");
	ob->move("/d/city/lichunyuan2");
	ob->set("startroom","/d/city/lichunyuan2");
	ob->apply_condition("prostitute", 50);
	ob->set_temp("selled");
	ob->set("class", "prostitute");
	return 1;
}

