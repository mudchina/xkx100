// Room: /d/xingxiu/npc/bing.c
// Last Modified by Winder on Apr. 25 2001

#include <ansi.h>
inherit NPC;
void create()
{
	set_name("边防官兵", ({ "guan bing", "bing" }));
	set("age", 32);
	set("gender", "男性");
	set("long", "他是个长年驻守这里的边防兵。\n");
	set("attitude", "peaceful");
	set("str", 33);
	set("int", 16);
	set("con", 25);
	set("dex", 20);
	set("no_get",1);
	set("combat_exp", 30000);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);	
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/d/city/obj/junfu")->wear();
}

int accept_fight(object me)
{
	command("say 大爷我守边关累得要死，没空和"+RANK_D->query_respect(me)+"过招玩。\n");
	return 0;
}

void init()
{
	object ob, me, money;

	::init();
	ob = this_player();
	if (!interactive(ob)) return;
	if (!living(ob)) return;
	if (ob->query_temp("ride_horse")) return;
	if((int)ob->query_condition("killer") || ob->query_temp("xx_rob"))
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 0, ob);
	}
	else if(random(50)<=1)
		{
			me=this_object();	 
			command("say 这个"+RANK_D->query_rude(ob)+"给我站住，例行检查！");
			if(ob->query("guanbing"))
			{
				ob->add("guanbing", -1);
				message_vision(HIY"$n对着$N看了半天，最后招了招手让$N快走。\n"NOR, ob, me);
				return;
			}
			message_vision(HIY"$n将$N拦住，在$N身上摸索了半天。\n"NOR, ob, me);
			ob->start_busy(5);
			if(money = present("gold_money", ob))
			{
				money->move(me);
				ob->add("guanbing", 2);
				tell_object(ob, HIR "结果你发现边防官兵将你身上的黄金拿走了！\n"NOR);
			}
			else if(money = present("silver_money", ob))
				{
					money->move(me);
					ob->add("guanbing", 1);
					tell_object(ob, HIR "结果你发现边防官兵将你身上的白银拿走了！\n"NOR);
				}
			else command("say 你这个穷光蛋，连点油水都没有，给我滚！");
			command("kick "+ ob->query("id"));		
		}
}
