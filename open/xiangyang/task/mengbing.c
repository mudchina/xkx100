// Last Modified by winder on Apr. 25 2001
#include <ansi.h>
inherit NPC;

int do_copy(object me,int maxpot,int type);

void create()
{
	set_name("ÃÉ¹Å´óºº", ({ "menggu dahan","dahan"}));
	set("gender", "ÄÐÐÔ");
	seteuid(getuid());
	set("age", random(20) + 25);
	set("str", 23);
	set("con", 26);
	set("int", 20);
	set("dex", 23);
	set("combat_exp", 80000 + random(40000)); 
	set("attitude", "friendly");
	set_skill("force", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("cuff", 50);
	set_skill("changquan", 50);
	set_skill("yunlong-jian", 50); 
	set_skill("yunlong-shenfa", 50); 
	set_skill("yijinjing",50);
	map_skill("dodge", "yunlong-shenfa");
	map_skill("sword", "yunlong-jian");
	map_skill("parry", "yunlong-jian");
	map_skill("cuff", "changquan");
	map_skill("force", "yijinjing");
	prepare_skill("cuff", "changquan");	 
	set_temp("apply/damage", 150);
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
//		(: perform_action, "blade.leitingpili" :),
//		(: perform_action, "blade.kuang" :),
	}) );
	set("max_qi", 450); 
	set("eff_jing", 400); 
	set("neili", 700); 
	set("max_neili", 700);
	set("jiali", 30);
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

int do_copy(object me,int maxpot,int type)
{
	int i,j;
	object ob;
	ob = this_object();
	i=maxpot;
	if(type==1) i = i - random(20);
	else i = i +10+ random(10);
	if( i < 100) i = 100;
	ob->set("combat_exp", (me->query("combat_exp")+random(me->query("combat_exp")))*3/4);
	ob->set_skill("force", i);
	ob->set_skill("sword", i);
	ob->set_skill("cuff", i);
	ob->set_skill("blade", i);
	ob->set_skill("dodge", i);
	ob->set_skill("parry", i);
	ob->set_skill("yunlong-jian", i);	
	ob->set_skill("changquan", i); 
	ob->set_skill("yijinjing",i);
	ob->map_skill("force", "yijinjing");
	ob->map_skill("sword", "yunlong-jian");
	ob->map_skill("cuff", "changquan");
	ob->prepare_skill("cuff", "changquan");
	ob->set("max_qi", i*10); 
	ob->set("eff_jing", me->query("eff_jing")*2/3); 
	ob->set("max_neili", i*10); 
	ob->set("jiali", i/6);
	if(type==3)
	{
		ob->set("max_qi", i*30);
		ob->set("max_neili", i*15); 
	}
	if(type==2)
	ob->set("max_qi", i*20); 
	ob->reincarnate(); 
	ob->set("qi",ob->query("max_qi"));
	ob->set("neili",ob->query("max_neili"));
	return 1;
}
