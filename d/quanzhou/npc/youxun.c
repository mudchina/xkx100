// youxun.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

int ask_news();
int ask_meeting();

void create()
{
        set_name("游讯", ({ "you xun", "you", "xun" }) );
        set("nickname", "滑不留手");
        set("gender", "男性" );
        set("age", 42);
        set("long", "他就是专门打探、贩卖消息的游讯。\n");
        set("combat_exp", 100000);
        set("attitude", "friendly");

	set("max_jing",500);
	set("max_qi",500);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 30);

        set("inquiry", ([
		"name"   : "小的就是游讯，不知您要打听点什么？",
		"欧冶子" : "您问可以帮玩家造兵器的欧冶老爷子呀！据说他现在带着徒弟到西域去\n居住了，有人说他现在本事更大了，也不知真假。\n",
		"news" : (: ask_news :),
		"新闻" : (: ask_news :),
        ]) );

        set_skill("literate", 100);
        set_skill("dodge", 500);
        set_skill("unarmed", 300);
        setup();
        add_money("gold", 5);
	carry_object("/clone/cloth/male-cloth")->wear();
	carry_object("/clone/cloth/male-shoe")->wear();
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
	if( environment(ob) != environment() ) return;
	command("hi "+ob->query("id"));
}

int ask_news()
{
	int rows;
	string temp;

	temp = read_file(__DIR__"news.txt", 2, 1);
	rows = atoi(temp);
	temp = read_file(__DIR__"news.txt", 3, rows);
	temp = "游讯说道：\n"+temp+"\n";
	write(temp);

	return 1 ;

}
