// Npc: /d/guiyun/npc/snake.c
// Last Modified by winder on Jul. 9 2001

inherit NPC;

void create()
{
	set_name("毒蛇", ({ "snake", "she" }) );
	set("race", "爬蛇");
	set("age", 4);
	set("long", "一只有着三角形脑袋的蛇，尾巴沙沙做响。\n");
	set("attitude", "peaceful");

	set("str", 26);
	set("con", 30);
	set("combat_exp", 2000);

	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	setup();
}

void init()
{
	object ob = this_player();

	::init();
	if (interactive(ob) && random(ob->query_kar() + ob->query_per()) < 20) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}
}

void die()
{
	object me = this_object();;

	message_vision("$N啪的一声断成两截！$N死了。\n", me);
	new("/d/guiyun/obj/shedan")->move(environment(me));
	destruct(me);
}

int hit_ob(object me, object victim, int damage)
{
	victim->apply_condition("snake_poison",	victim->query_condition("snake_poison") + 6);
	return 0;
}
