//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("虫一居士"NOR, ({ "chongyi jushi", "chongyi" }));
	set("title", "茶馆老板");
	set("nickname", HIW"风月"HIY"无边"HIB"不见天"NOR);
	set("shen_type", 1);

	set("str", 30);
	set("gender", "男性");
	set("age", 25);
	set("long","
这位虫一先生可是个风雅之人，他不喜出门，成天在茶馆里
和来往的客人谈诗论画。\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	
	set("vendor_goods", ({
		"/d/jiangling/obj/jiuhuangb",
		"/d/jiangling/obj/babao",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

