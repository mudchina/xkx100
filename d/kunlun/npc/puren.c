// Room: /d/kunlun/npc/puren.c
// Last Modified by winder on Nov. 14 2000

inherit NPC;

void create()
{
	set_name("仆人", ({"pu ren", "pu"}) );
	set("gender", "男性" );
	set("age", 50);
	set("long",
	"这是个老实巴交的老仆人，虽然衣服上打了很多补丁，却是十分的整洁。\n"
	"因为长期待在厨房里，眼睛被烟熏成了一条缝。\n");
	set("attitude", "friendly");
	set("shen_type", 1);

	set("str", 27);
	set("int", 25);
	set("con", 24);
	set("dex", 24);

	set("max_qi", 650);
	set("max_jing", 400);
	set("neili", 150);
	set("max_neili", 150);

       	set("combat_exp", 1000+random(800));
	set("score", 1000);

	set_skill("force", 40);
	set_skill("dodge", 30);
	set_skill("unarmed", 25+random(20));
	set_skill("parry", 30);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 4);
//	create_family("昆仑派", 24, "弟子");
	setup();
	carry_object("/d/kunlun/obj/cloth")->wear();
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

	say("仆人笑吟吟地说道：这位" + RANK_D->query_respect(ob)
		+ "请先入座，" + "我这就给您上茶。\n");
}

void serve_tea(object who)
{
	object obt, obc, obn;
	object room;

	if( !who || environment(who) != environment() ) return;

	if( !who->query_temp("marks/sit") ) return;

	if( !objectp(room = environment()) ) return;

	if ( (int)who->query_temp("tea_cup") <= 0 )
	{
		obn = new("/d/kunlun/obj/dawancha");
		obn->move(room);
		message_vision("仆人搬出个大茶壶来，将桌上的大碗茶倒满．\n",
			who);
	} else
	{
		who->add_temp("tea_cup", -1);
		obn = new("/d/kunlun/obj/xiangcha");
		obn->move(room);
		message_vision("仆人拿出个绍兴小茶壶，沏了杯香茶，放在桌上．\n",
			who);
	}

	obn = new("/d/kunlun/obj/rice");
	obn->move(room);
	message_vision("仆人盛了一碗刚蒸好的大米饭，放在桌上。\n", who);

	return;
}
