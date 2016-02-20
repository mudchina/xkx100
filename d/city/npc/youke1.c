//Npc youke1.c

inherit NPC;


void create()
{
	set_name( "游客", ({"you ke","ke"}) );
	set( "gender", "男性" );
	set( "age", 28 );
	set("attribute", "heroism");

	set_skill( "force", 20 );
	set_skill( "unarmed", 20 );
	set_skill( "dodge", 30 );

	set( "combat_exp", 2000 );

	set( "str", 25 );
	set( "per", 25);
	set( "con", 26);
	set( "inquiry", ([
		"籍贯" : "我是大理人。\n",
		"家乡" : "我的家乡是大理，大宋国南边的大理。\n",
		"扬州" : "扬州果真是个繁华的城市啊。\n",
	]) );
	set( "no_leave_yangzhou", 1);

	setup();
	set( "chat_chance", 10);
	set( "chat_msg", ({
		(:random_move:),
	}) );
	carry_object("/clone/cloth/male-cloth" )->wear();
}

