// qinwei2.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void create()
{
	set_name("近卫兵",({"jinwei bing","bing"}));
	set("gender","男性");
	set("long","贴身保护铁木真的勇士！\n");
	set("combat_exp",200000);
	set("age",18+random(30));
	set("qi",1500);
	set("max_qi",1500);
	set("food",250);
	set("water",250);
	set("neili",1000);
	set("max_neili",1000);
	set_skill("dodge",80+random(50));
	set_skill("force",80+random(50));
	set_skill("parry",80+random(50));
	set_skill("unarmed",80+random(50));
	set_skill("blade",80+random(50));

	setup();
	add_money("silver",5+random(20));
	carry_object("/clone/armor/gujia")->wear();
	carry_object("/clone/weapon/blade")->wield();
}
void init()
{
	object ob;
	::init();
	if (interactive(ob=this_player())&&!is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}
void greeting(object ob)
{ 
	if (!ob||environment(ob)!=environment()) return;
	if (ob->query("banghui")!=query("banghui"))
	{
		kill_ob(ob);
		return;
	}
	return;
}

