// wokuotai.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void create()
{
	set_name("窝阔台",({"wo kuotai","wo","kuotai"}));
	set("gender","男性");
	set("long","铁木真的三儿子，他为人宽厚，甚得人心。\n");
	set("combat_exp",150000);
	set("age",29);
	set("qi",1200);
	set("max_qi",1200);
	set("food",250);
	set("water",250);
	set("neili",900);
	set("max_neili",900);
	set_skill("dodge", 60);
	set_skill("force", 60);
	set_skill("parry", 60);
	set_skill("unarmed", 60);
	set_skill("spear", 60);
	setup();
	add_money("silver",30);
	carry_object("/clone/armor/yinjia")->wear();
	carry_object("/clone/weapon/spear/jinqiang")->wield();
}

