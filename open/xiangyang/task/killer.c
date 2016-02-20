// Last Modified by winder on Apr. 25 2001
#include <ansi.h>
inherit NPC;

int do_copy(object me,int flag);
int do_back(object me);

void create()
{
	set_name("黑衣人", ({ "heiyi ren","ren"}));
	set("gender", "男性");
	seteuid(getuid());
	set("age", random(20) + 25);
	set("str", 23);
	set("con", 26);
	set("int", 20);
	set("dex", 23);
	set("long", "一个穿着黑色夜行衣的人。\n");
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

int do_copy(object me,int flag)
{
	int i,j;
	object ob;
	ob = this_object();

	i = me->query_skill("dodge",1);
	j = me->query_skill("force",1);
	i = i>j?i:j;
	if(flag==0) i = i - random(20);
	else i = i + random(20);
	if( i < 60) i = 60;
	ob->set("combat_exp", (me->query("combat_exp")+random(me->query("combat_exp")))*3/4);
	ob->set_skill("force", i);
	ob->set_skill("sword", i);
	ob->set_skill("blade", i);
	ob->set_skill("dodge", i);
	ob->set_skill("parry", i);
	ob->set_skill("yunlong-jian", i);	
	ob->set_skill("changquan", i); 
	ob->set("max_qi", ob->query_skill("force",1)*10); 
	ob->set("eff_jing", me->query("eff_jing")*2/3); 
	ob->set("max_neili", ob->query_skill("force",1)*8); 
	ob->set("jiali", ob->query_skill("force",1)/6);
	ob->reincarnate(); 
	ob->set("qi",ob->query_skill("force",1)*10);
	ob->set("neili",ob->query_skill("force",1)*8);
	call_out("do_back", 350,  ob);  
	return 1;
}
int do_back(object me)
{			
	tell_room(environment(me), me->query("name")+"匆匆忙忙的离开了。\n", ({me}));	
	destruct(me); 
	return 1;
}
void die()
{
	object corpse;
	mixed killer;
	if( !living(this_object()) ) revive(1);
	else delete_temp("faint_by");
	COMBAT_D->announce(this_object(), "dead");
	if( !(killer = query_temp("last_damage_from")) )
	killer = "莫名其妙地";
	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
	corpse->move(environment());
	set_temp("last_damage_from", "莫名其妙地");
	corpse->set_temp("must_killby",this_object()->query_temp("must_killby"));
	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());
	destruct(this_object());
}
