// Room: /d/nanshaolin/npc/slseng.c
// Last Modified by Winder on May. 29 2001

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("守律僧", ({ "shoulu seng", "seng", "shoulu" }));
	set("long",
		"他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他手持兵\n"
		"刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。\n"
	);

	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 25);
	set("shen_type", 1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiaji", 50);
	set("combat_exp", 10000);
	set("score", 1);

	set("chat_chance", 20);

	set_skill("force", 40);
	set_skill("zhanzhuang-gong", 40);
	set_skill("dodge", 40);
	set_skill("yiwei-dujiang", 40);
	set_skill("strike", 40);
	set_skill("boruo-strike", 40);
	set_skill("claw", 40);
	set_skill("dragon-claw", 40);
	set_skill("blade", 40);
	set_skill("cibei-blade", 40);
	set_skill("parry", 40);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("strike", "boruo-strike");
	map_skill("claw", "dragon-claw");
	map_skill("parry", "cibei-blade");
	map_skill("blade", "cibei-blade");
	prepare_skill("strike", "boruo-strike");
	prepare_skill("claw", "dragon-claw");

        create_family("南少林派", 22, "弟子");
	setup();

	carry_object(WEAPON_DIR+"blade/jiedao")->wield();
	carry_object("/d/shaolin/obj/dao-cloth")->wield();
}

void init()
{
	object me, ob;
	ob = this_player();
	me = this_object();
	
	::init();

	if ( interactive(ob) && !environment(ob)->query("no_fight") )
	{
		if ( ob->query("guilty") == 1 )
		{
			if ( random(2) ==1 )
				command("say 你这佛门败类，哪里逃！ 还不速到戒律院领罪！\n");
			me->set_leader(ob);
			remove_call_out("fight_ob");
			call_out("fight_ob", 1, ob); 
		}       
		if ( ob->query("guilty") >= 2 )
		{
			if ( random(2) ==1 )
			command("say 戒律院大癫大师请你去陈述此次下山经过 ！\n");
			me->set_leader(ob);
		}       
	}
	else if( environment(ob)->query("no_fight") ) me->set_leader(0);
}
