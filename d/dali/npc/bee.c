// bee.c 毒蜂
// Date: Sep.22 1997

inherit NPC;

void create()
{
	set_name("毒蜂", ({ "dufeng", "bee" }) );
	set("race", "昆虫");
	set("subrace", "飞虫");
	set("age", 20);
	set("long", "一只色彩斑斓大个野蜂，成群结队的。\n");
	set("attitude", "aggressive");
	set("shen_type", -1);

	set("combat_exp", 500);
	set("neili",80);
	set("max_neili",80);
	set("jingli",50);
	set("max_jingli",50);

	set_temp("apply/attack", 20);
	set_temp("apply/defense", 30);
	set_temp("apply/armor", 10);
	setup();
}

