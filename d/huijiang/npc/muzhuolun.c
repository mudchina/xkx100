// muzhuolun.c
// Last Modified by winder on Sep. 12 2001

inherit NPC;

void create()
{
	set_name("木卓伦", ({"mu zhuolun", "mu", "zhuolun"}));
	set("gender","男性");
	set("long","回疆回部族长。\n");
	set("combat_exp",50000);

	set("age",29);
	set("neili",500);
	set("max_neili",500);

	set_skill("dodge", 40);
	set_skill("force", 40);
	set_skill("parry", 40);
	set_skill("unarmed", 40);
	set_skill("whip", 40);
	set_skill("sword", 40);
	set_skill("spear", 40);

	setup();
	add_money("silver",30);
	carry_object(ARMOR_DIR"tiejia")->wear();
	carry_object(WEAPON_DIR"spear/tieqiang")->wield();
}
