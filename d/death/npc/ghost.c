// ghost.c 鬼魂

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIW "鬼魂" NOR, ({BLK "ghost" NOR,"ghost" }) );
	set("long",
		BLU "一个孤伶伶的鬼魂，正在黄泉大道上颤巍巍的行走。\n" NOR);
	set("chat_chance", 15);
	set("chat_msg", ({
		BLU "鬼魂叹了一口气......\n" NOR,
		HIY "鬼魂对你说：“想不到。。。。。。唉.....!”\n" NOR,
                GRN "鬼魂哭了起来.........\n" NOR,
	}) );
        set("age",30+random(40));
	set("combat_exp", random(10)*100000+random(10000));
    
	set_temp("apply/armor", random(60));
	set_temp("apply/damage", random(100));
        
	setup();
}

void init()
{
	command("tell " +this_player()->query("id")+" 你从哪儿来呀?......\n\n");
}
int is_ghost()
{  
	return 1;
}
int accept_fight(object me)
{    
	command("sigh " +(string)me->query("id"));
	command("say 都到这步田地了，你还想打呀？");
	return 0;
}
