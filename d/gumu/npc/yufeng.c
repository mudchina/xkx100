// yufeng.c 玉蜂

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIW "玉蜂" NOR, ({"yufeng","feng","bee"}) );
	set("race", "昆虫");
	set("subrace", "飞虫");
	set("age", 8);
	set("long","这是一只玉色的蜜蜂，个头比普通蜜蜂大得多，\n翅膀上被人用尖针刺有字。\n");

	set("no_train", 1);
	set("str", 40);
	set("dex", 50);

	set_temp("apply/attack", 35);
	set_temp("apply/armor", 25);

	set("chat_chance", 2);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
"玉蜂在你头顶转了一圈，似乎发现这不是可采蜜的地方，就嗡嗡嗡地飞走了。\n",
"玉蜂围绕着鲜花飞飞停停，似乎也不着重在采蜜上。\n",
	}) );

	setup();
}

void init()
{
	mapping fam;
	object ob;

	::init();
	if (interactive(ob = this_player()) &&
		(fam = ob->query("family")) && fam["family_name"] != "古墓派")
	{
		message_vision(HIR"$N擅自闯入古墓禁地。\n"NOR,ob);
		remove_call_out("killob");
		call_out("killob", 1, ob); 
	}
}

void die()
{
	message_vision("$N猛地振翅，飞走了。\n", this_object());
	destruct(this_object());
}
void killob(object ob)
{
	if (environment(ob)==environment())
	 kill_ob(ob);
}
