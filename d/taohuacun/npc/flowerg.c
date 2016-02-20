// flowerg.c

inherit NPC;
inherit F_DEALER;

int ask_for_h();

int heye = 1;

void create()
{
	set_name("卖花姑娘", ({ "flower girl","girl"}) );
	set("gender", "女性" );
	set("age", 18);
	set("long", "一个容貌清丽的小姑娘。\n");
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/baihe",
		__DIR__"obj/huaban"
	}));
	set("inquiry", ([
		"荷叶"	: (: ask_for_h :),
	]));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

int ask_for_h()
{
	object me = this_player(), ob;
	
	if ( heye == 0 || random(me->query("kar")) < 10 ) 
		return 0;
	else {
		message_vision("卖花姑娘看着$N吃吃的笑了起来。\n", me );
		command("say 我和姐妹们玩耍时摘的荷叶你也要？" );
		message_vision("卖花姑娘送给$N几片荷叶。\n", me );
		ob = new( __DIR__"obj/heye" );
		ob->move( me );
		heye = 0;
	}
	return 1;	
}
