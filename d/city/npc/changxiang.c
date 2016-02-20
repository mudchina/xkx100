// changxiang.c

inherit NPC;

void create()
{
	set_name( "常翔", ({"chang xiang", "chang", "changxiang"}) );
	set( "title", "媚香院龟奴" );
	set( "gender", "男性" );
	set( "age", 33 );
	set( "str", 26 );
	set( "dex", 25 );	 
	set( "per", 26 );
	set( "attribute", "heroism" );
	set( "long", @LONG
一个高大威猛的汉子，郁闷的一人坐在一旁。看他的样子是该笑傲江湖的
人，不知为何要在此干这等差事。
LONG
	);
	set( "max_qi", 500 );
	set( "max_jing", 500 );
	set( "attitude", "heroism" );
	set( "combat_exp", 50000 );
	set("inquiry", ([
		"陆丽仙" : "不要问我，我是看门的。\n",
	]));
	set("chat_chance", 3);
	set("chat_msg", ({
		"常翔道：小姐多才多艺，自己做了几个谜语，可惜没人能猜中！\n",
		"常翔道：小姐才貌双绝，可恨我愚鲁不能和她同赏(enjoy)琴韵！\n",
	}) );
	set_skill("parry", 80);
	set_skill("blade", 80);
	set_skill("dodge", 80);
	set_skill("wuhu-duanmendao", 80);
	map_skill("blade", "wuhu-duanmendao");
	map_skill("parry", "wuhu-duanmendao");
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/male-cloth")->wear();
}

int accept_object(object me, object ob)
{
	int val, money;
	val = ob->value();
	money = ( 8 + 2 * me->query("lu_sing") ) * 1000;
	if ( val >= money )
	{
		write("常翔对你点了点头，示意你可以走了。\n");
		me->delete("lu_sing");
		return 1;
	}
	if ( val > 0 )
	{
		command( "look " + me->query("id") );
		write("常翔面无表情的说道：我告诉过你要交多少钱的。\n");
	}
	return 0;
}


