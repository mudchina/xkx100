// baidu1.c

inherit NPC;
#include <ansi.h>

string *first_name = ({ "花皮", "青竹", "四脚", "眼镜王"});
string *name_words = ({ "蛇"});

void create()
{
	string name;
	name = first_name[random(sizeof(first_name))];
	name += name_words[random(sizeof(name_words))];

	set_name(name,({"du she"}));

	set("race", "爬蛇");
	set("long", "一条一尺多长，鬼头鬼脑的小蛇。\n");
	set("age", 100);
	set("attitude", "peaceful");

	set("max_jing", 200);
	set("max_qi", 200);

	set("str", 20);
	set("con", 50);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);

	set("combat_exp", 10000);
	set_weight(500000);

	setup();
}
void init()
{
	object me,ob;
	add_action("do_train", "xun");

	if (interactive(me = this_player()) && 
		(string)me->query("family/family_name") != "五毒教")
	{
		if (!(ob = present("xionghuang", this_player())))
		{
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, me);
		}
	}

	::init();
}
int hit_ob(object me, object ob, int damage)
{
	if ((string)ob->query("family/family_name") != "五毒教")
	{
		ob->apply_condition("snake_poison", 20 +(int)ob->query_condition("snake_poison") );
		tell_object(ob, HIG "你觉得被咬中的地方一阵麻木！\n" NOR );
	}
}
#include "baidu.h";
