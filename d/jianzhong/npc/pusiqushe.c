//jinshe.c

#include "ansi.h"
inherit NPC;

void create()
{
	set_name("菩斯曲蛇", ({ "pusi qushe", "she", "qushe" }) );
	set("race", "爬蛇");
	set("age", 2);
	set("long", @LONG
这毒蛇身上隐隐闪着金光，头顶生有肉角，形状十分怪异。
LONG
);
	set("attitude", "peaceful");
	set("str", 20);
	set("cor", 20);

	set("combat_exp", 15000+random(10000));

	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 18);
	set_temp("apply/defence",15);
	setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 40) 
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}
}

void die()
{
	object ob;
	message_vision("$N「嘶嘶」地叫了几声，断成两截，死了！\n", this_object());
	if(uptime() > 300)
	{
		ob = new("/clone/medicine/nostrum/guaishedan");
		ob->move(environment(this_object()));
	}
	destruct(this_object());
}

int hit_ob(object me, object ob, int damage)
{
	if ((int)ob->query("combat_exp") > 50000) return 1 ;
	if( random(damage) > (int)ob->query_temp("apply/armor")
		&& (int)ob->query_condition("snake_poison") < 10 )
	{
		ob->apply_condition("snake_poison", 20);
		tell_object(ob, HIG "你觉得被咬中的地方一阵麻木！\n" NOR );
	}
}
