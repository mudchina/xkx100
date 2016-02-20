// zu.c

#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
string ask_me();

void create()
{
	set_name("祖千秋", ({ "zu qianqiu", "zu", "qianqiu" }) );
	set("nickname", "黄河老祖");
	set("gender", "男性" );
	set("age", 52);
	set("long", "一个衣衫褴褛的落魄书生。焦黄脸皮，一个酒糟鼻，疏疏落落的
几根胡子，两眼无神。衣衫上一片油光，右手拿了一把破折扇。\n");
	set("combat_exp", 400000);
	set("attitude", "friendly");

	set("max_jing",500);
	set("max_qi",500);
	set("per", 17);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	set("no_get", 1);

	set_skill("literate", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	set("inquiry", ([
		"续命八丸" : (: ask_me :),
		"8wan"     : (: ask_me :),
	]));

	set("book_count", 1);
	setup();
	add_money("gold", 1);
	carry_object("d/city/obj/cloth")->wear();
}

string ask_me()
{
	object ob;
	string wan_num;
	int wannum;

	wan_num = read_file("/data/XUMING", 1, 1);
	wannum = atoi(wan_num);
	if (uptime() < 1000)
		return "这位"+RANK_D->query_respect(this_player()) + 
		"，续命八丸还在老头子那里，我怎么给你？";
	if (wannum == 0)
		return "这位"+RANK_D->query_respect(this_player()) + 
		"，续命八丸还在老头子那里呢，我怎么给你？";
	if (random(10) < 3)
		return "这位"+RANK_D->query_respect(this_player()) + 
		"，续命八丸给令狐公子吃掉了，我拿什么给你？";
	if (random(10) < 6)
		return "这位"+RANK_D->query_respect(this_player()) + 
		"，吃了续命八丸就要给老不死贤侄女放血治病，你能成么？";
	if (random(10) < 9)
		return "这位"+RANK_D->query_respect(this_player()) + 
		"，给了你续命八丸，岂不伤了我和老头子的黄河老祖的义气？";
	ob = new("/clone/medicine/nostrum/xuming8wan");
	ob->move(this_player());
	write_file("/data/XUMING", "0", 1);
	command("rumor "+this_player()->query("name")+"拿到续命八丸了啦。\n");
	return "好吧，看在圣姑份上就给你尝尝续命八丸的味道吧。";
}

