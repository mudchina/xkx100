// Last Modified by Sir 11/20/2003
// jianxi.c

#include <ansi.h>
inherit NPC;
int do_copy(int maxpot);
int do_back(object me);
void create()
{
	set_name("蒙面人", ({ "menggu jianxi","jianxi"}));
	set("gender", "男性");
	seteuid(getuid());
	set("age", random(30) + 25);
	set("str", 26);
	set("con", 26);
	set("int", 20);
	set("dex", 30);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
	::init();
	add_action("do_go","go");
}
int do_go(string arg)
{
	if (this_player()->query_condition("guojx_mis"))
	{
		write(HIR"蒙古奸细就在眼前，怎可临阵脱逃！\n"NOR);
		return 1;
	}
}

int accept_hit(object who)
{
	object me=this_object();
	if (who->query_condition("guojx_mis")) 
	{
		message_vision(CYN"$N加油！$N加油！\n"NOR,who);
		me->kill_ob(who);
		who->kill_ob(me);
		return 1;
	}
	else return notify_fail(HIY"想对付"HIR"蒙古奸细"HIY"？快去找郭靖大侠！\n"NOR);
}
int accept_fight(object who)	{return accept_hit(who);}
int accept_kill(object who)		{return accept_hit(who);}
int accept_ansuan(object who) {return accept_hit(who);}
int accept_touxi(object who)	{return accept_hit(who);}
int do_copy( int maxexp )
{
	int skt,skl,temp;
	object ob,weapon;
	ob = this_object();
//	skl = 200 + random(100);
	ob->set("combat_exp", ( maxexp +random( maxexp )));
//	temp=ceil( pow( ob->query("combat_exp")*10.0, 0.333333))-30;
	skl=ceil( pow( query("combat_exp")*10.0, 0.333333));
	ob->set("max_qi", 5000);
	ob->set("eff_qi", 5000);
	ob->set("qi",     5000);
	ob->set("max_jing", 2500);
	ob->set("eff_jing", 2500);
	ob->set("jing",     2500);
//	ob->set("max_neili",3500);
//	ob->set("neili",3500);
	ob->set("max_neili",skl*15);
	ob->set("neili",skl*15);
	ob->set("jiali", skl*3/4);
	skt=random(5);
	if( skt == 0 )
	{
		ob->set_skill("force", skl);
		ob->set_skill("strike", skl);
		ob->set_skill("hand",skl);
		ob->set_skill("blade", skl);
		ob->set_skill("dodge", skl);
		ob->set_skill("parry", skl);	
		ob->set_skill("yujiamu-quan", skl);
		ob->set_skill("huoyan-dao", skl);
		ob->set_skill("shenkong-xing",skl);
		ob->set_skill("xue-dao",skl);
		ob->set_skill("xiaowuxiang",skl);
		ob->map_skill("force", "xiaowuxiang");
		ob->map_skill("blade", "xue-dao");
		ob->map_skill("cuff", "yujiamu-quan");
		ob->map_skill("strike", "huoyan-dao");
		ob->map_skill("dodge", "shenkong-xing");
		ob->map_skill("parry", "huoyan-dao");
		ob->prepare_skill("cuff", "yujiamu-quan");
		ob->prepare_skill("strike", "huoyan-dao");
		weapon = new( "/clone/weapon/blade");
		weapon->set("value", 0);
		weapon->move( ob );
		weapon->wield();
	}
	else if( skt == 1 )
	{
		ob->set_skill("force", skl);
		ob->set_skill("strike", skl);
		ob->set_skill("spear", skl);
		ob->set_skill("dodge", skl);
		ob->set_skill("parry", skl);	
		ob->set_skill("zhusha-zhang", skl);
		ob->set_skill("tiezhang-zhangfa", skl);
		ob->set_skill("shuishangpiao",skl);
		ob->set_skill("tiexue-qiang",skl);
		ob->set_skill("guiyuan-tunafa",skl);
		ob->map_skill("force", "guiyuan-tunafa");
		ob->map_skill("spear", "tiexue-qiang");
		ob->map_skill("strike", "tiezhang-zhangfa");
		ob->map_skill("dodge", "shuishangpiao");
		ob->map_skill("parry", "zhusha-zhang");
		ob->prepare_skill("strike", "tiezhang-zhangfa");
		weapon = new( "/clone/weapon/spear");
		weapon->set("value", 0);
		weapon->move( ob );
		weapon->wield();
	}
	else if ( skt == 2)
	{
		ob->set_skill("force", skl);
		ob->set_skill("strike", skl);
		ob->set_skill("claw", skl);
		ob->set_skill("staff", skl);
		ob->set_skill("dodge", skl);
		ob->set_skill("parry", skl);	
		ob->set_skill("huagong-dafa", skl);
		ob->set_skill("sanyin-wugongzhao", skl);
		ob->set_skill("chousui-zhang",skl);
		ob->set_skill("tianshan-zhang",skl);
		ob->set_skill("zhaixinggong",skl);
		ob->map_skill("force", "huagong-dafa");
		ob->map_skill("staff", "tianshan-zhang");
		ob->map_skill("strike", "choushui-zhang");
		ob->map_skill("claw", "sanyin-wugongzhao");
		ob->map_skill("dodge", "zhaixinggong");
		ob->map_skill("parry", "choushui-zhang");
		ob->prepare_skill("strike", "chousui-zhang");
		ob->prepare_skill("claw", "sanyin-wugongzhao");
		weapon = new( "/clone/weapon/staff");
		weapon->set("value", 0);
		weapon->move( ob );
		weapon->wield();
	}
	else if ( skt == 3)
	{
		ob->set_skill("force", skl);
		ob->set_skill("strike", skl);
		ob->set_skill("sword", skl);
		ob->set_skill("dodge", skl);
		ob->set_skill("parry", skl);	
		ob->set_skill("jinshe-zhang", skl);
		ob->set_skill("jinshe-jian", skl);
		ob->set_skill("shuishangpiao",skl);
		ob->set_skill("guiyuan-tunafa",skl);
		ob->map_skill("force", "guiyuan-tunafa");
		ob->map_skill("sword", "jinshe-jian");
		ob->map_skill("strike", "jinshe-zhang");
		ob->map_skill("dodge", "shuishangpiao");
		ob->map_skill("parry", "jinshe-zhang");
		ob->prepare_skill("strike", "jinshe-zhang");
		weapon = new( "/clone/weapon/sword");
		weapon->set("value", 0);
		weapon->move( ob );
		weapon->wield();
	}
	else 
	{
		ob->set_skill("force", skl);
		ob->set_skill("strike", skl);
		ob->set_skill("cuff", skl);
		ob->set_skill("whip", skl);
		ob->set_skill("dodge", skl);
		ob->set_skill("parry", skl);	
		ob->set_skill("xiantian-qigong", skl);
		ob->set_skill("duanyun-bian", skl);
		ob->set_skill("jinyan-gong",skl);
		ob->set_skill("haotian-zhang",skl);
		ob->set_skill("chunyang-quan",skl);
		ob->map_skill("force", "xiantian-qigong");
		ob->map_skill("whip", "duanyun-bian");
		ob->map_skill("strike", "haotian-zhang");
		ob->map_skill("cuff", "chunyang-quan");
		ob->map_skill("dodge", "jinyan-gong");
		ob->map_skill("parry", "chunyang-quan");
		ob->prepare_skill("strike", "haotian-zhang");
		ob->prepare_skill("cuff", "chunyang-quan");
		weapon = new( "/clone/weapon/whip");
		weapon->set("value", 0);
		weapon->move( ob );
		weapon->wield();
	}
	return 1;
}
int do_back(object me)
{			
	tell_room(environment(me), me->query("name")+"匆匆忙忙的离开了。\n", ({me}));	
	destruct(me); 
	return 1;
}

