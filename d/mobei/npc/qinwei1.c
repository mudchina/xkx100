// qinwei1.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void create()
{
	set_name("Ñ²ÂßÇ×±ø",({"qin bing","bing"}));
	set("gender","ÄÐÐÔ");
	set("long","ÔÚÓªÕÊÖÐÑ²ÂßµÄÇ×ÎÀ±ø!\n");
	set("combat_exp", 80000);
	
	set("age",18+random(30));
	set("qi",1500);
	set("max_qi",1500);
	set("food",250);
	set("water",250);
	set("neili",1000);
	set("max_neili",1000);

	set_skill("dodge",50+random(50));
	set_skill("force",50+random(50));
	set_skill("parry",50+random(50));
	set_skill("unarmed",50+random(50));
	set_skill("blade",50+random(50));
	set("chat_chance",5);
	set("chat_msg",({
		(:random_move:),
	}));

	setup();
	add_money("silver",5+random(20));
	carry_object("/clone/armor/tengjia")->wear();
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
	if (!ob||environment(ob)!=environment())  return;
	if (ob->query("banghui")!=query("banghui"))
	{
		kill_ob(ob);
		return;
	}
	return;
}

