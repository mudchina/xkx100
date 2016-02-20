// chilaowen.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void create()
{
	set_name("赤老温",({"chi laowen","chi","laowen"}));
	set("gender","男性");
	set("nickname","蒙古四杰");
	set("long","铁木真手下四杰之一，草原上的雄鹰，大汗的猛将。\n");
	set("combat_exp", 300000);
	set("age",45);
	set("qi",2000);
	set("max_qi",2000);
	set("food",250);
	set("water",250);
	set("neili", 1500);
	set("max_neili", 1500);
	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("unarmed", 80);
	set_skill("spear", 80);

	setup();
	add_money("silver",20);
	carry_object("/clone/armor/tongjia")->wear();
	carry_object("/clone/weapon/spear/tieqiang")->wield();
}
