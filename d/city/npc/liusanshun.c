// liusanshun.c 刘三顺
// Last Modified by Winder on Jul. 15 2000

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("刘三顺", ({ "liu sanshun","liu" }) );
	set("title","伙计");
	set("gender", "男性" );
	set("age", 18);
	set("long", "刘三顺是这里竹器店刚雇的伙计，手脚麻利，跑前跑后的，替老板省了不少心。\n");
	set("attitude","friendly");
	set("inquiry",([
		"竹器":"小店专卖竹器，您随便挑！\n",
		"here":"这是我家老爷的店铺，小的是新来的，还请多多照顾生意。\n",
		"此处":"这是我家老爷的店铺，小的是新来的，还请多多照顾生意。\n",
	]));
	set("vendor_goods",({
		__DIR__"obj/zhubang2",
		__DIR__"obj/zhudao2",
		__DIR__"obj/zhujian2",
	}));
	set("chat_chance", 15);
	set("chat_msg",({
		"伙计手里拿着一把鸡毛掸子，麻利地掸去墙上、架上的尘土。\n",
		"伙计笑着问道：“客官想买点什么？”\n",
	}));
	setup();
	carry_object("clone/cloth/male-cloth")->wear();
}
void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
}	  
