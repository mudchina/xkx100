// Last Modified by winder on Nov. 17 2000
// mayi.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("麻衣长老", ({ "mayi zhanglao", "mayi", "zhanglao"}));
	set("long",
	"他是一个年约六旬的老者，满头花发，两鬓斑白。\n"
	"他两侧的太阳穴高高鼓起，微闭的双目中时而闪过凌厉的眼神，似乎身怀绝技。\n");
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 60);
	set("shen_type", 1);
	set("str", 28);
	set("int", 23);
	set("con", 23);
	set("dex", 28);
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiaji", 120);
	set("combat_exp", 500000);
	set("score", 10000);

	set_skill("force", 100);
	set_skill("guiyuan-tunafa", 100);
	set_skill("dodge", 100);
	set_skill("shuishangpiao", 100);
	set_skill("strike", 100);
	set_skill("tiezhang-zhangfa", 100);
	set_skill("parry", 100);

	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("strike", "tiezhang-zhangfa");
	map_skill("parry", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");

	setup();
	carry_object(__DIR__"obj/mayi")->wear();
}

void init()
{
	object me, ob;
	mapping fam;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& !present("tiezhang ling", ob) 
	&& ( (fam = ob->query("family")) && fam["family_name"] != "铁掌帮" ) 
	&& (int)ob->query("combat_exp", 1) >= 10000 ) 
	{
		if( !ob->query_temp("warned") )
		{
			command("say 站住！你不是铁掌帮弟子，不能在此久留！！");
			command("say 你还是速速离开此地吧，不然老朽可要对你不客气了！！");
			command("hehe");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay") < 3 ) ob->add_temp("stay", 1);
			else
			{
				command("say 你活得不耐烦了，竟敢到铁掌帮来撒野！！！\n");
				remove_call_out("hiting_ob");
				call_out("hiting_ob", 1, ob);
			}
	}       

}
int hiting_ob(object ob)
{
	object me;
	me=this_object();
	ob->kill_ob(me);
        me->fight_ob(ob);
}
