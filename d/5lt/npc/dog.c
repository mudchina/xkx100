//hapagou.c 哈巴狗
#include <ansi.h>
#include <command.h>
string ask_me();
inherit NPC;

void create()
{
	set_name("哈巴狗", ({ "dog" }) );
	set("title", "博饼屋宠物");
	set("race", "走畜");
	set("gender", "雄性" );
	set("age", 15);
	set("str", 22);
	set("int", 30);
	set("dex", 30);
	set("con", 30);

	set("long", "这是博饼屋里的小哈巴狗。\n");
	set("combat_exp", 2000000);
	set("attitude", "friendly");

	set("max_qi", 10000);
	set("max_jing", 10000);
	set("inquiry", ([
	"博饼屋" : "这儿就是，你要玩吗？\n",
	"博饼会" :  (: ask_me :),
	"博饼"   : "你（help bobing）就知道了。\n",
	]) );
	setup();
}

string ask_me()
{
	object* ob;
	int i;
	ob = users();

	if ( !wizardp(this_player()) ) return "你无权召开博饼会！\n";

	for ( i=sizeof(ob); i>0; i-- ) {
		ob[i-1]->move("/d/city/bobing");
	}
	command("chat 博饼屋要聚会了！大家快来！\n");
	return "好，现在博饼会正式开始，全体集合！\n";
}
void init()
{
	add_action("do_save","save");
	add_action("do_smash","smash");
	add_action("do_exert","call");
	add_action("do_exert","quit");
	add_action("do_exert","exert");
	add_action("do_exert","exercise");
	add_action("do_exert","dazuo");
	add_action("do_exert","respirate");
	add_action("do_exert","tuna");
	add_action("do_exert","practice");
	add_action("do_exert","lian");
	add_action("do_exert","study");
	add_action("do_exert","du");
	add_action("do_exert","come");
	add_action("do_exert","stay");
	add_action("do_exert","train");
	add_action("do_exert","attack");
	add_action("do_exert","shexin");
}

int do_save(string arg)
{
	command("say "+this_player()->query("name")+"，这儿不许存盘的。\n");
	return 1;
}
int do_smash(string arg)
{
	command("say "+this_player()->query("name")+"，巫师在这儿也不许杀人的。\n");
	return 1;
}
int do_exert(string arg)
{
	command("say "+this_player()->query("name")+"，专心博饼吧！\n");
	return 1;
}
