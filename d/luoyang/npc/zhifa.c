// zhifa.c 执法弟子

#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

int waiting(object me);
int checking(object me);
int do_chase(object me);
int do_kill(object me, object dest);
string ask_me();

void create()
{
	set_name("执法弟子", ({ "zhifa dizi", "dizi", "zhifa" }) );
	set("gender", "男性" );
	set("age", 40);
	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);
	set("no_clean_up",1);
	set("combat_exp", 50000);
	set("attitude", "peaceful");
	set("max_qi", 3000);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("shen_type", -1);
	set("env/wimpy", 60);

	set("chat_chance_combat", 70);  
	set("chat_msg_combat", ({
		(: command("wield changjian") :),
                (: perform_action, "sword.ren" :),
                (: perform_action, "parry.chan" :),
                (: perform_action, "parry.lian" :),
                (: perform_action, "parry.sui" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
	}) );
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/weapon/tiejia")->wear();
}

void init()
{
	object me = this_object();
        ::init();

	call_out("do_chase", 1, me);
}

int do_chase(object me)
{
	object dest;

	if(!objectp(dest = present(me->query("target"), environment(me))))
	{
		call_out("waiting", 0, me);
		return 1;
	}
	me->set_leader(dest);
	command("look " + dest->query("id"));
	command("grin " + dest->query("id"));

	if ( !environment(me)->query("no_fight"))
	{
		call_out("do_kill", 1, me, dest);
		return 1;
	}
	else
	{
		call_out("waiting", 0, me);
		return 1;
	}

	return 1;
}

int do_kill(object me, object dest)
{

	if( objectp(dest) && present(dest, environment(me))
		 && !environment(me)->query("no_fight"))
	{
		message_vision(HIR "$N对$n说道："+me->query("owner")+"指认你犯上做乱，"+RANK_D->query_rude(dest)+"，认命吧！\n" NOR, me, dest);
		me->set_leader(dest);
		me->kill_ob(dest);
		dest->fight_ob(me);

		call_out("checking", 0,  me); 	
	}
	else  
		call_out("waiting", 1, me); 	
	
	return 1;
}

int waiting(object me)
{
	object dest;
	dest = find_player(me->query("waiting_target"));
	
	if ( objectp(dest) )
	{
		if (dest->is_ghost())
		{
			me->delete("waiting_target");
			call_out("do_back", 1, me);
			return 1;
		}
		else if (me->is_fighting() && present(dest, environment(me)))
		{
			call_out("checking", 0, me);
			return 1;
		}
		else if (living(me) && !environment(dest)->query("no_fight"))
		{
			call_out("do_chase", 0, me);
			return 1;
		}
	}		
	
	remove_call_out("waiting");
	call_out("waiting", 60, me);
	return 1;
}

int checking(object me)
{
	object ob;

	if (me->is_fighting()) 
	{
		call_out("checking", 1, me);
		return 1;
	}

	if( objectp(ob = present("corpse", environment(me))))
	{
		me->delete("waiting_target");
		call_out("do_back", 1, me);
		return 1;
	}
	
	call_out("waiting", 0, me);
	return 1;
}

int do_back(object me)
{
	destruct(me);
}
