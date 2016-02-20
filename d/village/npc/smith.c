// smith.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("冯铁匠", ({ "feng", "smith" }) );
	set("gender", "男性" );
	set("age", 53);
	set("long", 
"冯铁匠想是常年弯腰打铁，背已驼了，双眼被烟火薰的又红又细，\n"
"左腿残废，肩窝下撑著一根拐杖。\n");
	set("combat_exp", 50000);

	set("str", 24);
	set("dex", 17);
	set("con", 28);
	set("int", 27);
	set("shen_type", 1);

	set("attitude", "friendly");
	set_skill("dodge", 70);
	set_skill("hammer", 40);
	set_skill("parry", 60);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set("vendor_goods", ({
		__DIR__"obj/hammer",
	}));
//	set("chat_chance", 50);
//	set("chat_msg_combat", (: add_hammer :));
	set("inquiry", ([
		"name": "小人姓冯，村里人都叫我冯铁匠。",
		"here": "这里是小人糊口的铺子，小人就住在後边的屋子。",
		"锄头": "锄头... 抱歉，锄头已经卖光了...",
		"铁锤": "铁锤？小人做的铁锤坚固又耐用，一把只要三百文钱。",
		"剑"  : "哦，那是给华山派岳掌门打的，小人用了三个月，总算没浪费那块好铁。\n"
		"嗯，岳掌门前不久率门徒下山去了，不知什麽时候才会派人来取剑。",
		"取剑": "小人一定要见了岳掌门的手信才能给剑。",
		"冯默风" : "唉～，这个名字小人已经好久没有听到过了...",
		"奇门遁甲" : "那都是小时候学的，平时没事解解闷罢了。",
	]) );
	setup();
	add_money("coin", 50);
	carry_object(__DIR__"obj/hothammer")->wield();
}
void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

int accept_object(object who, object ob)
{
	object sword;

	sword = new(WEAPON_DIR"treasure/youlong-jian");
	if ( sword->violate_unique() ) destruct( sword );
	else
	{
		if ((string)ob->query("id")=="hand letter")
		{
			if(!query("yl_trigger"))
			{
				say( "冯铁匠说道：这把剑虽不起眼，可也是小人的心血，总算对得起岳掌门。\n冯铁匠把" + sword->query("name") + "交给了" + who->query("name") + "。\n");
				sword->move(who);
				set("yl_trigger", 1);
			}
			else say("冯铁匠眼也不抬，说道：要剑自己进去拿。\n");
			call_out("destroy", 1, ob);
			return 1;
		}
	}
	return 0;
}
void destroy(object ob)
{
	destruct(ob);
	return;
}
