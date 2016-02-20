// yunbao.c 云豹

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("云豹", ({ "yun bao", "bao" }) );
	set("race", "走兽");
        set("gender", "雌性");
        set("age", 5);
        set("long", @LONG
这是一只艾叶花皮的云豹，它的毛皮极为雄美、厚实。
LONG);
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("combat_exp", 30000);
        set("neili",800);
        set("jiali",100);
        set("max_neili",800);
        set("jingli",500);
        set("max_jingli",500);

        set_temp("apply/attack", 20000);
        set_temp("apply/defense", 30000);
        set_temp("apply/armor", 1000);

        setup();
}

void die()
{
	object ob, corpse;
	message_vision("$N发出震天动地的一声大吼，轰地倒在地上，死了！\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
	ob = new("/clone/medicine/vegetable/baotai");
	ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
