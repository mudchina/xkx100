// npc: /d/city/npc/bookboss.c
// Last Modified by Winder on Jul. 15 2000

inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("冯老狗", ({ "feng laogou","feng" }) );
	set("title","书局老板");
	set("gender", "男性" );
	set("age", 38);
	set("long", "冯老板小名老狗，可你一看就知道他是个清心寡欲之人，一世卖书贩画为生，也颇为自得。\n");
	set("attitude","friendly");
	set("inquiry",([
		"书"   : "我这里什么书都有，你想买什么？\n",
		"here" : "这是我花了三百两银子买来的店铺。\n",  
	]));
	set("vendor_goods",({
		"/clone/book/lbook1",
		"/clone/book/lbook2",
		"/clone/book/lbook6",
		"/clone/book/lbook7",
		"/clone/book/lbook8",
		"/clone/book/blade_book0",
		"/clone/book/blade_book1",
		"/clone/book/dodge_book1",
		"/clone/book/dodge_book2",
		"/clone/book/sword_book1",
		"/clone/book/cuff_book",
		"/clone/book/unarmed_book",
	}));
	set("chat_chance", 15);
	set("chat_msg",(
	{
	    "老板手里拿着一把鸡毛掸子，轻轻掸去墙上，书架上的尘土。\n",
	    "老板笑着问道：“买书？还是看看字画儿？”\n",
	}));
     
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
}
void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
}
