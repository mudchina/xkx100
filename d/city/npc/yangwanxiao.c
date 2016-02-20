// yangwanxiao.c

inherit NPC;
#include <ansi.h>

string ask_room1();

void create()
{
	set_name( YEL "杨万萧" NOR, ({"yang wanxiao", "yang", "wanxiao"}) );
	set( "age", 48 );
	set( "int", 25 );
	set( "con", 26 );
	set( "per", 22 );
	set( "attribute", "peaceful" );

	set( "long", @LONG
杨家是扬州名门望族，杨万萧是杨府现今的主人，五柳长须，
看上去很是儒雅，据说杨万萧诗文做的极好，和现任知州是
好友，经常是做诗相和。
LONG);
	set( "combat_exp", 10000 );
	set_skill( "literate", 100);

	set("chat_chance", 30);
	set("chat_msg", ({
		"杨万萧只是冲从你微微一笑，却什么也不说。\n",
	}) );
	set( "inquiry", ([
		"小玲珑山馆" : (: ask_room1 :),
		"杨府" : (: ask_room1 :),
		"扬州" : "天下三分明月夜，无奈二分在扬州，哈哈。。。\n",
	]) );
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
	carry_object(__DIR__"obj/chuan")->wear();
}


string ask_room1()
{
	return "那是祖上留下的，不过却也是有些特色了。\n";
}

