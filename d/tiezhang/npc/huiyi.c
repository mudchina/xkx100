// Last Modified by winder on Nov. 17 2000
// huiyui.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("灰衣帮众", ({ "huiyi bangzhong", "huiyi", "bangzhong"}));
	set("long",
		"他是一个身行健壮的汉子，两臂粗壮，膀阔腰圆。满脸的凶相。\n");
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 40);
	set("shen_type", -1);
	set("str", 28);
	set("int", 23);
	set("con", 23);
	set("dex", 28);
	set("max_qi", 800);
	set("max_jing", 500);
	set("neili", 800);
	set("max_neili", 800);
	set("jiaji", 80);
	set("combat_exp", 40000);
	set("score", 1);

	set_skill("force", 70);
	set_skill("guiyuan-tunafa", 70);
	set_skill("dodge", 70);
	set_skill("shuishangpiao", 70);
	set_skill("spear", 70);
	set_skill("tiexue-qiang", 70);
	set_skill("strike", 70);
	set_skill("zhusha-zhang", 70);
	set_skill("parry", 70);

	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("spear", "tiexue-qiang");
	map_skill("strike", "zhusha-zhang");
	map_skill("parry", "tiexue-qiang");
	prepare_skill("strike", "zhusha-zhang");
	setup();
	carry_object(__DIR__"obj/huiyi")->wear();
	carry_object(WEAPON_DIR+"spear/tieqiang")->wield();
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
			command("say 识相的就快滚，惹得爷爷火起，打断你的狗腿！！");
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
