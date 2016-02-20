//Edited by fandog, 02/15/2000

inherit NPC;

void create()
{
	set_name("桃红",({ "tao hong", "hong" }) );
	set("gender", "女性" );
	set("age", 25);
	set("long", 
"一位年轻女人，却象是个丐妇。她蓬头垢面，容色憔悴，衣襟上满是污秽油腻。\n");
	set_temp("apply/defense", 5);
	set("combat_exp", 70);
	set("shen_type", 1);
	set("str", 14);
	set("per", 28);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	set("chat_chance", 5);
	set("chat_msg", ({
		"桃红垂泪道：我也不知道老爷为什么忽然不喜欢我了。\n",
		"桃红抹了抹眼泪，黯然道：那个湖南佬……那个姓狄的事，又不是我不好。\n",
		"桃红喃喃道：老爷晚上见鬼，要砌墙，怎么怪得我？又……又不是我瞎说。\n",
	}) );

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

