// Room: /d/xingxiu/npc/xxdizi1.c
// Last Modified by Winder on Apr. 25 2001

inherit NPC;

void create()
{
	set_name("星宿派弟子", ({ "xingxiu dizi", "dizi"}));
	set("gender", "男性" );
	set("age", 26);
	set("long","他是星宿派的恶徒, 烧杀抢奸赌, 无恶不作。\n");

	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set("combat_exp", 2000);
	set("shen", -200);
	set("str", 25);
	set("dex", 20);
	set("con", 18);
	set("int", 18);
	set("max_qi", 200);
	set("max_jing", 200);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 5);
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 25);
	set_skill("staff", 20);
	set_skill("parry", 20);
	set_skill("tianshan-zhang", 10);
	map_skill("staff", "tianshan-zhang");
	create_family("星宿派", 3, "弟子");
	setup();
	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object(__DIR__"obj/changpao")->wear();
	add_money("silver", 5);
	set("chat_chance", 5);
	set("chat_msg", ({
		"星宿派弟子一会儿吹奏丝竹箫管, 一会儿高声颂道，“星～宿～老～仙，古～今～无～比”。\n",
		"星宿派弟子一会儿吹奏丝竹箫管, 一会儿高声颂道，“星～宿～老～仙，威～震～寰～宇”。\n",
		"星宿派弟子一会儿吹奏丝竹箫管, 一会儿高声颂道，“星～宿～老～仙，德～配～天～地”。\n",
	}) );
}

void init()
{
	object ob;
	mapping fam;
	::init();

	ob = this_player();
	if (interactive(ob) &&
		( (fam = ob->query("family")) &&
		fam["family_name"] != "星宿派" ) )
	{
		command("say 大胆狂徒，竟敢闯到天山脚下来撒野！！！\n");
		remove_call_out("kill_ob");
		call_out("kill_ob", 2, ob);
	}
}
