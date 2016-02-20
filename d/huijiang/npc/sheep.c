// Room: /d/huijiang/npc/sheep.c
// Last Modified by winder on Sep. 12 2001

inherit NPC;

void create()
{
	set_name("绵羊", ({ "sheep","yang" }) );
	set("race", "走畜");
	set("age", 22);
	set("long", "白色的羊毛卷曲，温柔的眼波，千万不要被外表迷糊。\n");

	set("str", 13);
	set("cor", 24);
	set("combat_exp",5000);
	set_temp("apply/attack", 15);
	set_temp("apply/armor", 20);

	set("chat_chance",5);
	set("chat_msg", ({
		"绵羊吃了一会草，抬头呆呆的看着头顶飘过的白云。\n",
		"绵羊摆摆蹄子，动动腿，低头向你撞来。\n",
	}));

	setup();
}

void die()
{
	message_vision("$N侧身倒下，四肢抽搐一阵，死了。\n",this_object());
	new(__DIR__"obj/yangrou")->move(environment(this_object()));
	destruct(this_object());
	return;
}
