// yang.c 杨老板 

inherit NPC;
inherit F_DEALER;
string ask_mask();

void create()
{
	set_name("杨永福", ({ "Yang yongfu", "yang" }));
	set("title", "杂货铺老板");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 45);
	set("long",
		"杨老板是土生土长的扬州人，做了几十年的小买卖。
听说他最近得了一样宝物，却不知是什么好东西。\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("inquiry", ([
		"宝物" : (: ask_mask :),
		"宝贝" : (: ask_mask :),
		"mask" : (: ask_mask :),
		"面具" : (: ask_mask :),
	]));
	set("vendor_goods", ({
		"/clone/misc/chutou",
		"/clone/misc/fire",
		"/clone/misc/shihui",
		"/clone/misc/yanwu",
		WEAPON_DIR"muchui",
		WEAPON_DIR"club",
		FOOD_DIR+"sugar/xitang",
		__DIR__"obj/mabudai",
		__DIR__"obj/beixin",
		__DIR__"obj/toukui",
		__DIR__"obj/cycle",
		__DIR__"obj/surcoat",
		__DIR__"obj/shield",
		__DIR__"obj/huwan",
		__DIR__"obj/zhitao",
		__DIR__"obj/huyao",
		__DIR__"obj/caoxie",
		__DIR__"obj/pixue",
		__DIR__"obj/shoutao",
		__DIR__"obj/tieshou",
		__DIR__"obj/jinsijia",
		__DIR__"obj/hongbao", 
		__DIR__"obj/lan",
		__DIR__"obj/marrybox",
		__DIR__"obj/map",
	}));
	
	setup();
	set("count",1);
	carry_object(CLOTH_DIR"cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
string ask_mask()
{
	object me, ob;
	
	me = this_player();
	ob = this_object();
	if (query("count")>0)
	{
		message("vision",ob->name()+"在"+me->name()+"耳边嘀咕了几句什么。\n",me,({me}));
		tell_object(me,ob->name()+"悄悄告诉你：我是有样上古宝贝，给我五百两黄金就转让给你。\n");
	}
	return "没有没有，我什么都不知道啊。";
}
int accept_object(object who,object ob)
{
	object obj;
	
	if (!query("count") || !ob->query("money_id") || ob->value()<5000000)
	{
		message_vision("$N说道：你给我这个做什么？\n",this_object());
		return 0;
	}
	if (query("count")>0)
	{
		obj = new("/clone/misc/mask1");
		obj->move(this_player());
		add("count",-1);
		message_vision("$N取出一个包裹，交给$n。\n",this_object(),who);
		tell_object(who,"你急忙打开包裹，竟然是一个精致的人皮面具。\n");
		return 1;
	}
}