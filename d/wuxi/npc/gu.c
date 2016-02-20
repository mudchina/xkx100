// gu.c 顾宪成

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("顾宪成", ({ "gu xiancheng", "gu" }));
	set("gender", "男性");
	set("long", "顾宪成重于学识，讲究品行，受到各地学者仰慕。\n");
	set("age", 45);
	set("no_get", 1);
	set_skill("literate", 300);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400000);
	set("shen_type", 1);
	set("inquiry", ([
		"书"   : "唉！书到用时方恨少。",
		"借书" : "借？你不还我到哪里找你？哼！",
	]));
	setup();

}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/顾"))
		return 0;
	ob->add_temp("mark/顾", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	object me = this_player();
	if (!(int)who->query_temp("mark/顾"))
		who->set_temp("mark/顾", 0);
	if (ob->query("money_id") && ob->value() >= 1000)
	{
		message_vision("顾宪成同意指点$N一些读书写字的问题。\n", who);
		who->add_temp("mark/顾", ob->value() / 50);
		if( me->query_skill("literate", 1) > 21)
		{
			tell_object(me,"你现在已有一定的文化知识,也可以自己读书深造了。\n");
			return 1;
		}
		return 1;
	}
}


