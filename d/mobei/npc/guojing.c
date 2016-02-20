// guojing.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void create()
{
	set_name("郭靖",({"guo jing","guo","jing"}));
	set("gender","男性");
	set("long","郭靖出生在蒙古，现在正随江南六怪学艺。\n");
	set("combat_exp", 100000);
	
	set("age",17);
	set("qi",900);
	set("max_qi",900);
	set("food",250);
	set("water",250);
	set("neili",500);
	set("max_neili",500);
	set_skill("dodge",50);
	set_skill("force",50);
	set_skill("parry",50);
	set_skill("unarmed",50);
	set_skill("spear",50);
	set_skill("whip",50);
	set_skill("sword",50);
	set_skill("blade",50);

	setup();
	add_money("silver",20);
	carry_object("/clone/cloth/beixin")->wear();
	carry_object(__DIR__"obj/jindao")->wield();
}
