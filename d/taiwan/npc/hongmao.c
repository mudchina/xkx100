// hongmao.c
// Last Modifyed by Ahda on Jan. 4 2002

inherit NPC;
//inherit F_SKILL;

void create()
{
	set_name("红毛鬼", ({ "hongmao gui", "gui"}));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long","入侵我天朝宝岛台湾的荷兰红毛鬼。他手上端着一支火枪，枪口还冒着青烟。\n");
	set("combat_exp", 25000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 30);

	setup();
	carry_object(__DIR__"obj/huoqiang")->wield();
	carry_object(__DIR__"obj/xifu")->wield();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( environment(ob) != environment() ) return;
	say("红毛鬼抬手就是一枪：砰！枪口一团火焰喷出。\n");
	ob->receive_damage("qi",50);
	ob->receive_wound("qi",50);
}

