// honghua1.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("绿营会众", ({ "hong hua","hong","hua" }) );
	set("gender", "男性");
	set("age", 25);
	set("long",
		"这是位手执长枪的绿营清兵，红花会在江南声势大盛，绿营也
多有会众。\n");
	set("combat_exp", 20000);
        set("shen_type", 1);
	set("attitude", "heroism");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("club", 60);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);

	setup();

        carry_object("/clone/weapon/changqiang")->wield();
        carry_object("/d/city/obj/junfu")->wear();
	add_money("silver", 20);
}
void init()
{
	object ob;
	if (random(2) == 1)
	message_vision(HIY "绿营会众悄悄告诉$N：身在绿营心在汉！\n" NOR, 
		this_player());
	else
	message_vision(HIY "绿营会众冲着$N挤了挤眼说：狗皇帝是从青楼地道被当家的逮着的！\n" NOR, 
		this_player());
}
