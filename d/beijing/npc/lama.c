// lama.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("喇嘛", ({"lama"}));
	set("long", "这是一个高大喇嘛，两臂粗壮，膀阔腰圆，似乎不是中土人士。\n");
	set("gender", "男性");
	set("attitude", "aggressive");
	set("class", "bonze");

	set("age", 20+random(30));
	set("shen_type", -1);
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiaji", 50+random(50));
	set("combat_exp", 50000);
	set("score", 1);

	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("unarmed", 70);
	set_skill("parry", 70);
	set_skill("blade", 70);

	setup();

	carry_object(WEAPON_DIR"blade/jiedao")->wield();
	carry_object(CLOTH_DIR"jia_sha")->wear();
}

void init()
{
	::init();
	remove_call_out("greeting");
	call_out("greeting", 1, this_player());
}

void greeting(object ob)
{
	object me = this_object();

	if(ob->query_temp("hastrystab")==6) return;	
	if (interactive(ob) && !environment(ob)->query("no_fight"))
	{
		if( !ob->query_temp("warned2") )
		{
			if(ob->query_temp("hastrystab")) 
				command("say 气死我了，你居然暗算我兄弟！");
			else
				command( "say 你是谁，居然敢破坏大爷的好事，不想活了是不是？！");
			ob->set_temp("warned2", 1);
		}
		else
		{
			if(ob->query_temp("hastrystab")) 
				command(" say 我...我...一定要杀了你这背后捅人的江湖败类！");
			else
				command(" say 你这家伙不要跑，让佛爷我宰了你！！！\n");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}

}
