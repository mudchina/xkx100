// tufei4.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("麒麟花纹", ({ "picture"}) );
	set("gender", "男性" );
	set("age", 34);
	set("long",
	"这是一位西夏一品堂中精选出来的高手，他们的武功个个都突出一个狠字。\n");
	set("max_qi", 5000);
	set("max_jing", 5000);
	set("max_neili", 5000);
	set("jiali", 500);
	set("combat_exp", 4000000);
	set("attitude", "friendly");
	set("str", 20);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
	set_skill("dodge", 500);
	set_skill("unarmed",500);
	set_skill("parry", 500);
	set_skill("force",500);
	set_skill("hammer", 500);
	set_skill("hand", 500);
	set_skill("cuff", 500);
	set_skill("changquan", 500);
	set_skill("sanshou", 500);
	set_skill("xiaowuxiang", 500);
	set_skill("riyue-lun", 500);
	set_skill("shenkong-xing", 500);

	set("no_see", 1);
	set_weight(5);
	map_skill("force", "xiaowuxiang");
	map_skill("dodge", "shenkong-xing");
	map_skill("hammer", "riyue-lun");
	map_skill("parry", "riyue-lun");
	map_skill("hand", "sanshou");
	map_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");
	prepare_skill("cuff", "changquan");
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );
	setup();
}
int do_look(string arg)
{
	if (arg=="picture" && this_object()->query("id")=="picture")
    {
    	write("这是一张官府的"+this_object()->query("name")+"。\n");
    	destruct(this_object());
      return 1;
    }
  return 0;
}
void init()
{
	object ob,obj;
	mapping skl;
	string *skillname;
	int maxskill,j;
  ob = this_player();
	obj = this_object();
  add_action("do_look","look");
	if( !query_temp("bt_inited") && interactive(ob) && ob->query("id")==obj->query_temp("bt_ownname") )
	{
		
    maxskill=query("maxskill");
    if (!maxskill)
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
  	}
		obj->add_temp("bt_inited",1);
		set_skill("dodge", maxskill*5/6);
		set_skill("unarmed", maxskill*5/6);
		set_skill("parry", maxskill*5/6);
		set_skill("hammer", maxskill*5/6);
		set_skill("force", maxskill*5/6);
		set_skill("cuff", maxskill*5/6);
		set_skill("hand", maxskill*5/6);
		set_skill("riyue-lun", maxskill*5/6);
		set_skill("changquan", maxskill*5/6);
		set_skill("sanshou", maxskill*5/6);
		set_skill("shenkong-xing", maxskill*5/6);
		set_skill("xiaowuxiang", maxskill*5/6);
		if (!present("fa lun",obj))
			carry_object("/d/xueshan/obj/falun")->wield();
		obj->set("title","一品堂杀手");
		obj->set_weight(500000);
		set_name("西夏细作", ({ "xi zuo","xz"}) );
		remove_call_out ("destroy_npc");
		call_out ("destroy_npc", 900); // 15 min
	}
	if (ob->query("id")==obj->query_temp("bt_ownname"))
	obj->kill_ob(ob);
}
void destroy_npc()
{
	message_vision((string)this_object()->query("name") + "忽然打了个哆嗦，不由心生惧意，身形一晃，顿时混入莽莽人海之中。\n", environment(this_object()));
	destruct(this_object());
}
void die()
{
	object ob,me;
	string own;
	message_vision("$N倒在地上，死了！\n", this_object());
	ob = this_object();
	own = ob->query_temp("bt_ownname");
	if(own) me = find_player(own);
	if ( me && ob->query_temp("last_damage_from")==me
	&& (!ob->query_temp("faint_by") || ob->query_temp("faint_by")==me )
	&& ob->query_temp("bt_npc")==me->query_temp("bt/npc"))
			me->set_temp("bt/finish",1);
	destruct(this_object());
}
varargs int receive_damage(string type, int damage, mixed from)
{
  if (query_leader())
   set_leader(0);
	return ::receive_damage(type,damage,from);
}