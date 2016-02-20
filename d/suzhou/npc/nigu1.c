// nigu1.c

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("尼姑", ({ "ni gu", "ni", "gu" }) );
	set("gender", "女性" );
	set("age", 22);
	set("long","这位尼姑正坐在铺垫上，双手捻着珠链，嘴中念念有词。 \n");
	set("combat_exp", 1000);
	set("attitude", "friendly");
	setup();
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
	if( !ob || environment(ob) != environment() ) return;
	say( "尼姑说道：这位" + RANK_D->query_respect(ob) + "，多谢捐赠，愿佛祖保佑。\n");
	return;
}

