// tiemuzhen.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void create()
{
	set_name("铁木真",({"tie muzhen","tie","muzhen"}));
	set("gender","男性");
	set("long","铁木真是草原上的英雄。\n");
	set("combat_exp", 300000);
	set("nickle","成吉思汗");
	set("age", 35);
	set("qi", 2000);
	set("max_qi", 2000);
	set("food", 250);
	set("water", 250);
	set("neili", 1500);
	set("max_neili", 1500);
	set_skill("dodge", 60);
	set_skill("force", 60);
	set_skill("parry", 60);
	set_skill("unarmed", 60);
	set_skill("blade", 60);

	setup();
	add_money("gold",1);
	carry_object("/clone/weapon/blade/gudingdao")->wield();
	carry_object("/clone/armor/jinjia")->wear();
}
