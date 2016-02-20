// tufei3.c
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
int ask_me();

void create()
{
	set_name("飞凤花纹", ({ "picture"}) );
	set("gender", "男性" );
	set("age", 34);
	set("long",
		"他就是大名鼎鼎的四大恶人之一的云中鹤。\n");
	set("max_qi", 5000);
	set("max_jing", 5000);
	set("max_neili", 5000);
	set("jiali", 500);
	set("combat_exp", 4000000);
	set("attitude", "friendly");
	set("str", 20);
	set("dex", 30);
	set("con", 20);
	set("int", 20);
	set("title", "");
	set_skill("dodge", 500);
	set_skill("unarmed",500);
	set_skill("parry", 500);
	set_skill("force",500);
	set_skill("hand", 500);
	set_skill("cuff", 500);
	set_skill("blade", 500);
	set_skill("literate", 500);
	set_skill("yunlong-shengong", 500);
	set_skill("wuhu-duanmendao", 500);
	set_skill("changquan", 500);
	set_skill("sanshou", 500);
	set_skill("qingfu-shenfa", 500);

	set("no_see", 1);
	set_weight(5);
	map_skill("force", "yunlong-shengong");
	map_skill("dodge", "qingfu-shenfa");
//	map_skill("blade", "wuhu-duanmendao");
	map_skill("parry", "changquan");
	map_skill("hand", "sanshou");
	map_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");
	prepare_skill("cuff", "changquan");
	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
//	      (: perform_action, "blade.duan" :),
		(: exert_function, "recover" :),
	}) );
	setup();
}

void init()
{
	object ob,obj;
	mapping skl;
	string *skillname;
	int maxskill,j;
//      ::init();
	if( interactive(ob = this_player()) && !this_object()->query_temp("bt_in
ited"))
	{
		
	   skl = ob->query_skills();
	   maxskill =10;
	   if (sizeof(skl))
	     { 
		skillname = sort_array( keys(skl), (: strcmp :) );
		for (j=0; j<sizeof(skl); j++)
		{
			if (maxskill < skl[skillname[j]])
				maxskill = skl[skillname[j]];
		}
	     }
		this_object()->set_temp("bt_inited",1);
		obj=this_object();
//	        maxskill=query("maxskill");
		set_skill("dodge", maxskill*3/2);
		set_skill("unarmed", maxskill);
		set_skill("parry", maxskill);
//		set_skill("blade", maxskill);
		set_skill("force", maxskill);
		set_skill("cuff", maxskill);
		set_skill("hand", maxskill);
//		set_skill("wuhu-duanmendao", maxskill);
		set_skill("changquan", maxskill);
		set_skill("sanshou", maxskill);
		set_skill("qingfu-shenfa", maxskill*3/2);
		set_skill("yunlong-shengong", maxskill);
		obj->set("title","穷凶极恶");
		obj->set_weight(500000);
		set_name("云中鹤", ({ "yun zhonghe","yz"}) );
		if (ob->query("id") == obj->query_temp("bt_ownname"))
			obj->kill_ob(ob);
		remove_call_out ("destroy_npc");
		call_out ("destroy_npc", 900); // 15 min
	}
}
void destroy_npc()
{
	message_vision("" + (string)this_object()->query("name") + "忽然打了个哆嗦，不由心生惧意，身形一晃，顿时混入莽莽人海之中。\n", environment(this_object()));
	destruct(this_object());
}
//int active_died()
void die()
{
	object ob,me;
	string own;
	message_vision("$N倒在地上，死了！\n", this_object());
	ob = this_object();
	own = ob->query_temp("bt_ownname");
	if(own) me = find_player(own);
	if ( me && ob->query_temp("last_damage_from")==me)
	{
		if (ob->query_temp("bt_npc")==me->query_temp("bt/npc"))
			me->set_temp("bt/finish",1);
	}
	destruct(this_object());
}

