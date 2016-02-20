// a-xiu.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>

inherit NPC;

string ask_staff();
void create()
{
	set_name("阿绣",({"a xiu","xiu"}));
	set("gender", "女性");
	set("age", 16);
	set("long", 
	       "她是凌霄城主的孙女，年方十多岁，聪明伶俐，天真可爱，\n简直便是大雪山凌霄城的小公主。\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("count",1);
	set("con", 30);
	set("per", 30);
	set("int", 24);
	set("dex", 30);
	set("neili", 1000);
	set("max_neili", 1000);
	set("qi", 800);
	set("max_qi", 800);
	set("jing", 500);
	set("max_jing", 500);
	set("inquiry", ([
		"石破天"   : "天哥去了侠客岛，不知道他现在怎么样了？",
		"大粽子"   : "只有我才能这么叫他，你怎么能这么叫他？",
		"石中玉"   : "我很讨厌他---你去把他给我杀了吧。",
		"白万剑"   : "那是我爹呀。",
		"白自在"   : "那是我爷爷呀。",
		"金乌杖" : (: ask_staff :),
	]) );
	set("combat_exp", 50000);
	set("shen_type", 0);
	set("chat_chance", 5);
	set("chat_msg", ({
		"阿绣凝视着平静的潭水，说：这潭很奇怪，里面好象有什么东西。\n",
		"阿绣看着远山的悠悠白云，叹道：你要什么时候才从侠客岛回来。\n",
		"阿绣忽然皱颦不快，好象想起了什么可气之事。\n",
	}) );
	set("score", 2000);
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :)
	}) );

	set_skill("strike", 40);
	set_skill("sword", 60);
	set_skill("force", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("literate", 40);

	set_skill("xueshan-sword", 60);
	set_skill("bingxue-xinfa", 60);
	set_skill("snow-strike", 60);
	set_skill("snowstep", 60);

	map_skill("sword", "xueshan-sword");
	map_skill("parry", "xueshan-sword");
	map_skill("force", "bingxue-xinfa");
	map_skill("strike", "snow-strike");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");

	create_family("凌霄城", 7, "弟子");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object(CLOTH_DIR+"bai")->wear();
}
string ask_staff()
{
	object ob;
	object me;
	me = this_player();

	if(query("count") < 1)
		return "这位" +RANK_D->query_respect(me)+"，真是抱歉，金乌杖已经有人帮我给奶奶带去了。";
	if(me->query("combat_exp")<200000)
		return "你武功尚未到家，我怎敢把金乌杖交给你？";
	add("count", -1);
	ob=new(WEAPON_DIR"treasure/jinwu-staff");
	if ( ob->violate_unique() )
	{
		destruct( ob );
		return "你武功尚未到家，我怎敢把金乌杖交给你？";
	}
	else
	{
		ob->move(this_player());
		return "这位" +RANK_D->query_respect(me)+"，请帮我把这把金乌杖带给我奶奶，真是多谢了。";
	}
}

void attempt_apprentice(object ob)
{
	command("say 我是不收徒的，你进城找我师兄们好了。");
}

