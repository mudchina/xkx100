// Room: /d/chengdu/npc/poorman.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;

void create()
{
	set_name("壮汉", ({ "man"}) );
	set("gender", "男性" );
	set("age", 33);
	set("long", "一个体格强壮的汉子。\n");
	set("attitude", "friendly");
	set("combat_exp", 750);
//	set("shen", 50);
	set("shen_type", 1);
	set("str", 20);
	set("dex", 18);
	set("con", 17);
	set("int", 13);
	setup();
	set("chat_chance", 15);
	set("chat_msg", ({
		"壮汉伸手打了个哈哈。\n",
		"壮汉伸手捉住了身上的虱子，骂道：老子身上没几两肉，全叫你们给咬了。 \n",
		(: random_move :)
	}) );
	carry_object(CLOTH_DIR"cloth")->wear();
}

