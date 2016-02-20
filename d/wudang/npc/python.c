// animal: python.c
// Last Modified by winder on Aug. 18 2002

inherit NPC;

void create()
{
	set_name("蟒蛇", ({ "python", "she" }) );
	set_weight(1000000);
	set("race", "爬蛇");
	set("age", 110);
	set("long", "一条愈丈长的巨蟒，盘着身子睡觉。\n");
	set("attitude", "aggressive");

	set("str", 40);
	set("con", 30);
	set("int", 40);
	set("dex", 30);

	set("combat_exp", 35000);

	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 200);
	set_temp("apply/armor", 100);
	setup();
}

