// youfangdaoren.c

inherit NPC;

void create()
{
	set_name("游方道人", ({"youfang daoren","daoren"}));
	set("long", "他是一位未通世故的青年道人，脸上挂着孩儿般的微笑。\n");

	set("gender", "男性");
	set("attitude", "heroism");
	set("class", "quanzhen");

	set("age", 20);
	set("shen_type", 1);
	set("no_get", 1);
	set("str", 15);
	set("int", 30);
	set("con", 30);
	set("dex", 18);
	set("max_qi", 280);
	set("max_jing", 300);
	set("neili", 380);
	set("max_neili", 380);
	set("jiali", 27);
	set("combat_exp", 10000);
	set("shen_type", 1);
	set("chat_chance", 30);

	set("chat_msg", ({
		"游方道人说道: 请这位施主化几两银子给贫道，随喜随喜，造福众生。\n",
		(: random_move :)
	}) );

	set_skill("force", 41);
	set_skill("strike", 41);
	set_skill("dodge", 41);
	set_skill("parry", 41);
	set_skill("jinyan-gong", 42);
	set_skill("haotian-zhang", 41);
	set_skill("xiantian-qigong", 41);

	map_skill("force", "xiantian-qigong");
	map_skill("dodge", "jinyan-gong");
	map_skill("strike", "haotian-zhang");
	map_skill("parry", "haotian-zhang");
        create_family("全真教", 4, "弟子");
	setup();
	carry_object(CLOTH_DIR"daopao")->wear();

	setup();

}

int accept_object(object me, object ob)
{
	object ling;
	
	command("smile");
	command("say 无量寿佛，多谢这位" + RANK_D->query_respect(me) + " ！");

	if( ob->query("money_id") && ob->value() >= 10000 && me->query("class") != "bonze" ) 
	{
		command("say " + RANK_D->query_respect(me) + 
		"如此乐善好施，兼又身怀绝艺，全真祖师正欲一晤天下豪杰，不知可愿赴重阳宫内一游？");

		ling=new("/d/quanzhen/npc/obj/tie-ling");
		ling->move(me);
		message_vision("游方道人给$N一块铁铸令牌。\n", me);

		command("say 此牌限时一日，逾时失效，请于限时前离宫，否则多有不便，切记切记！"); 
		return 1;
	}

	return 1;
}

