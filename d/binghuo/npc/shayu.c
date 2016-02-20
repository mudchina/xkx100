// shayu.c
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("鲨鱼", ({ "sha yu", "sha" }) );
	set("race", "游鱼");
        set("age", 20);
        set("long", "一只生活在冰海的巨大鲸鲨。\n");
        set("attitude", "friendly");
        set("shen_type", 0);

        set("combat_exp", 100000);
        set_temp("apply/attack", 800);
        set_temp("apply/defense", 800);
        set_temp("apply/armor", 100);

        setup();
}


void die()
{
	object ob, corpse;
	message_vision("$N全身一阵剧烈的扭曲，终于安静了下来，翻白眼死了。\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
		ob = new("/clone/medicine/vegetable/shadan");
	ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
