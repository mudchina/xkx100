// zhucong.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void create()
{
	set_name("朱聪",({"zhu cong","zhu","cong"}));
	set("gender","男性");
	set("long","江南七怪老二，手上功夫了得。\n");
	set("combat_exp", 300000);
	set("nickname","妙手书生");
	set("age",34);
	set("qi",1700);
	set("max_qi",1700);
	set("food",250);
	set("water",250);
	set("neili",1700);
	set("max_neili",1700);
	set_skill("dodge", 70);
	set_skill("force", 70);
	set_skill("parry", 70);
	set_skill("unarmed", 70);
	set_skill("sword", 70);
	setup();
	add_money("silver",70);
	carry_object("/clone/cloth/cloth")->wear();
}
