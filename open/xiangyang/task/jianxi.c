// Last Modified by winder on Apr. 25 2001
// jianxi.c

#include <ansi.h>
inherit NPC;
int do_copy(object me,int maxpot);
int do_back(object me);
void create()
{
	set_name("蒙面人", ({ "mengmian ren","ren"}));
	set("gender", "男性");
	seteuid(getuid());
	set("age", random(30) + 25);
	set("str", 23);
	set("con", 26);
	set("int", 20);
	set("dex", 23);
	//set("long", "一个穿着黑色夜行衣的人。\n");
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
	set("max_qi", 450); 
	set("eff_jing", 400); 
	set("neili", 700); 
	set("max_neili", 700);
	set("jiali", 30);
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

int do_copy(object me,int maxpot)
{
	int i,j;
	object ob;
	ob = this_object();
	i=maxpot;
	i = i +10+ random(10);
	if( i < 100) i = 100;
	
	ob->set("combat_exp", (me->query("combat_exp")+random(me->query("combat_exp")))*3/4);
	ob->set_skill("force", i);
	ob->set_skill("sword", i);
	ob->set_skill("blade", i);
	ob->set_skill("cuff", i);
	ob->set_skill("dodge", i);
	ob->set_skill("parry", i);
	ob->set_skill("yunlong-jian", i);	
	ob->set_skill("changquan", i); 
	set_skill("yijinjing",i);
	ob->set("max_qi", 2000+i*30); 
	ob->set("eff_jing", me->query("eff_jing")*2/3); 
	ob->set("max_neili", 1000+i*15); 
	ob->set("jiali", i/6);
	ob->reincarnate(); 
	ob->set("qi",ob->query("max_qi"));
	ob->set("neili",ob->query("max_neili"));
	call_out("do_back", 200,  ob);  
	return 1;
}
int do_back(object me)
{			
	tell_room(environment(me), me->query("name")+"匆匆忙忙的离开了。\n", ({me}));	
	destruct(me); 
	return 1;
}

