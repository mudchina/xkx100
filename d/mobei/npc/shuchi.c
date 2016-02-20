// shuchi.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void create()
{
	set_name("术赤",({"shu chi","shu","chi"}));
	set("gender","男性");
	set("long","铁木真的大儿子，他脸形瘦削，生性险诈。\n");
	set("combat_exp",150000);
	set("age",39);
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
	set("chat_chance",5);
	set("chat_msg",({
		"术赤嘿嘿冷笑两声：察合台是个笨蛋，这[汗]的位置迟早是我的。\n",
		"术赤举起桌上的金樽，把血色的葡萄酒一饮而尽。\n",
	}));
	setup();
	add_money("silver",30);
	carry_object("/clone/armor/yinjia")->wear();
	carry_object("/clone/weapon/spear/jinqiang")->wield();
}

