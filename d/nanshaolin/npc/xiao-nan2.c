// Last Modified by winder on May. 29 2001
// Npc: /d/nanshaolin/npc/xiao-nan.c

inherit NPC;

void create()
{
	set_name("小沙弥", ({ "xiao shami", "xiao", "shami"}));
	set("long", "他是一位未通世故的少年和尚，脸上挂着天真的稚笑。\n");

	set("nickname", "侍斋僧");
	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 10);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 500);
	set("score", 100);

	set_skill("force", 9);
	set_skill("dodge", 9);
	set_skill("unarmed", 9);
	set_skill("parry", 9);

        create_family("南少林派", 23, "弟子");
	setup();
}

void init()
{	
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say("小沙弥躬身说道：这位"+RANK_D->query_respect(ob)+"请先入座。\n");
}

void serve_food(object who)
{
	object ob;
	object room;

	if( !who || environment(who) != environment() ) return;
	if( !who->query_temp("marks/sit") ) return;
	if( !objectp(room = environment()) ) return;
 	ob = new(FOOD_DIR+"mizhi-tianou");
	ob->move(room);
	message_vision("小沙弥端来一盘蜜汁甜藕放在桌上．\n", who);
	
	return;
}

