// Room: /d/huijiang/npc/zhanshi.c
// Last Modified by winder on Sep. 12 2001

inherit NPC;
void create()
{
	set_name("回族战士",({"zhan shi"}));
	set("gender","男性");
	set("combat_exp",4000+random(500000));
   
	set("age",19+random(30));
	set("qi",500+random(1000));
	set("max_qi",500+random(1000));
	set("neili",100+random(500));
	set("max_neili",100+random(500));

	set_skill("dodge",40+random(100));
	set_skill("force",40+random(100));
	set_skill("parry",40+random(100));
	set_skill("unarmed",40+random(100));
	set_skill("whip",40+random(100));
	set_skill("sword",40+random(100));
	set_skill("spear",40+random(100));
   
	set("chat_chance",5);
	set("chat_msg", ({
		(:random_move:),
	}));
	setup();
	add_money("silver",1);
	carry_object(ARMOR_DIR"tiejia")->wear();
	carry_object(WEAPON_DIR"spear/tieqiang")->wield();
}
