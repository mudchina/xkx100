// shifu.c 大师傅

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("大师傅", ({ "shi fu", "shifu" }) );
	set("gender", "男性" );
	set("age", 42);
	set("long","这位大师傅是随红花会从江南来的，做得一手好苏杭菜。\n他的绝活是东坡肉。可惜地处西北，回民禁猪，连猪肉都找不到。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");
	set("vendor_goods", ({
		"/d/hangzhou/npc/obj/fish",
		"/d/hangzhou/npc/obj/shrimp",
		"/d/hangzhou/npc/obj/chicken",
		"/d/hangzhou/npc/obj/geng",
		"/d/hangzhou/npc/obj/jiuping",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
