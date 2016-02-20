// wuaer.c 瓦耳拉齐

#include <ansi.h>

inherit NPC;
int ask_baozang();
int ask_back();
int ask_wuaer();

void create()
{
	set_name("瓦耳拉齐", ({ "wuaer laqi", "wuaer"}));
	set("gender", "男性");
	set("age", 45);
	set("long", "他就是装神弄鬼的瓦耳拉齐。他面容枯槁，由于长期不见阳光，皮肤惨白。\n");

	set("combat_exp", 150000);
	set("shen_type", 1);

	set("max_neili", 500);
	set("neili", 500);
	set("jiali", 10);

	set_skill("force", 40);
	set_skill("sword", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);

	set("inquiry", ([
		"宝藏" : (: ask_baozang :),
		"回去" : (: ask_back :),
		"瓦耳拉齐" : (: ask_wuaer :),
		"李文秀" : "瓦耳拉齐说道：这是一个好姑娘。何时能再见到她。\n",
	]) );


	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 15);

	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_back()
{    
	object ob;
	object me=this_player();
	if ( present("map", me))
	{
		say("瓦耳拉齐说道：好吧，这次我送你回去，高昌迷宫你以后再也不要来了。下次来我就要杀了你。\n");
		me->move("/d/gaochang/entrance");
		return 1;
	}
	else
	{
		say("瓦耳拉齐哼道：你是自作自受，在这陪我一辈子吧!\n");
		return 1;
	}
	return 1;
}

int ask_baozang()
{
	say("瓦耳拉齐说道：高昌迷宫一无所有，这一个房间是我住的。说完闪身让出一条路。\n");
	return 1;
}    
int ask_wuaer()
{
	message("vision", HIY "瓦耳拉齐勃然大怒，喝道：你也佩直呼我的名字？！我要杀了你！\n" NOR, environment(), this_object() );
	this_object()->kill_ob(this_player());
	return 1;
}

