// honghua1.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("红花会众", ({ "hong hua","hong","hua" }) );
	set("gender", "男性");
	set("age", 25);
	set("long",
		"这是位青年壮汉，虎背熊腰，胸前配带一朵大红花。\n");
	set("combat_exp", 20000);
	set("shen_type", 1);
	set("attitude", "heroism");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("sword", 60);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);

	setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 20);
}
void init()
{
	object ob;
	if (random(2) == 1)
	message_vision(HIY "红花会众兴奋地悄悄告诉$N：总舵主把狗皇帝扣在六和塔上了！\n" NOR, 
		this_player());
	else
	message_vision(HIY "红花会众冲着$N说：十几个当家的分层把守，狗皇帝跑不了的！\n" NOR, 
		this_player());
}
