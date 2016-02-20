// shanzei3.c
// Last Modified by Winder on May. 15 2001

inherit NPC;

void create()
{
	set_name("山贼头", ({ "shanzei tou","tou" }) );
	set("gender", "男性" );
	set("age", 29);
	set("long", "这是个粗鲁的山贼头。\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 24);
	set("int", 23);
	set("con", 24);
	set("dex", 23);

	set("max_qi", 200);
	set("max_jing", 200);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 30000+random(5000));
	set("score", 2000);
	setup();
	add_money("silver", 11);
	carry_object("/d/baituo/obj/dadao")->wield();
}

