// bear.c
// Date: Sep.22 1997

inherit NPC;
#include <ansi.h>

void create()
{
        set_name(BLK"黑熊"NOR, ({ "hei xiong", "bear","xiong" }) );
	set("race", "走兽");
        set("age", 20);
        set("long", "一只凶猛的黑熊，形体硕大，人立而行。\n");
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("combat_exp", 30000);
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 250);
        set_temp("apply/armor", 100);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "黑熊冲着你摇头摆尾地，不知道是什么意思。\n",
                "黑熊挤了挤鼻子，你觉得它好象在笑，顿时一阵紧张。\n",
        }) );
}

void die()
{
	object ob, corpse;
	message_vision("$N震天动地一声惨嚎，慢慢委顿在地，死了！\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
	if(uptime() > 300)
	{
		ob = new("/clone/medicine/nostrum/xiongdan");
		ob->move(corpse);
	}
	corpse->move(environment(this_object()));
	destruct(this_object());
}
