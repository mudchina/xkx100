// Last Modified by Winder on May. 29 2001
// Npc: /kungfu/class/nanshaolin/tianhong.c

#include "/kungfu/class/nanshaolin/tian.h";
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
string ask_me();

void create()
{
	set_name("天虹大师", ({ "tianhong dashi", "tianhong", "dashi"}));
	set("long",
		"他是一位白须白眉的老僧，身穿一袭金丝绣红袈裟。\n"
		"他身材略显佝偻，但却满面红光，目蕴慈笑，显得神完气足。\n");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 71);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 3000);
	set("max_jing", 1200);
	set("neili", 3000);
	set("max_neili", 5000);
	set("jiali",200);
	set("combat_exp", 2000000);
	set("score", 10000);

	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 200);
	set_skill("yijinjing", 200);
	set_skill("force", 200);
	set_skill("zhanzhuang-gong", 200);
	set_skill("dodge", 200);
	set_skill("yiwei-dujiang", 300);
	set_skill("cuff", 200);
	set_skill("shaolin-cuff", 300);
	set_skill("luohan-cuff", 300);
	set_skill("jingang-cuff", 300);
	set_skill("leg", 200);
	set_skill("shaolin-leg", 300);
	set_skill("ruying-leg", 300);
	set_skill("hand", 200);
	set_skill("fengyun-hand", 300);
	set_skill("boluomi-hand", 300);
	set_skill("qianye-hand", 300);
	set_skill("strike", 200);
	set_skill("weituo-strike", 300);
	set_skill("sanhua-strike", 300);
	set_skill("jingang-strike", 300);
	set_skill("boruo-strike", 300);
	set_skill("finger", 200);
	set_skill("mohe-finger", 300);
	set_skill("duoluoye-finger", 300);
	set_skill("nianhua-finger", 300);
	set_skill("one-finger", 300);
	set_skill("wuxiang-finger", 300);
	set_skill("claw", 200);
	set_skill("jimie-claw", 300);
	set_skill("eagleg-claw", 300);
	set_skill("dragon-claw", 300);
	set_skill("staff", 200);
	set_skill("pudu-staff", 300);
	set_skill("wuchang-staff", 300);
	set_skill("blade", 200);
	set_skill("cibei-blade", 300);
	set_skill("xiuluo-blade", 300);
	set_skill("club", 200);
	set_skill("weituo-club", 300);
	set_skill("zui-club", 300);
	set_skill("weituo-chu", 300);
	set_skill("sword", 200);
	set_skill("damo-sword", 300);
	set_skill("fumo-sword", 300);
	set_skill("whip", 200);
	set_skill("jiujie-whip", 300);
	set_skill("xiangmo-whip", 300);

	map_skill("force", "yijinjing");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("cuff", "jingang-cuff");
	map_skill("leg", "ruying-leg");
	map_skill("hand", "boluomi-hand");
	map_skill("strike", "boruo-strike");
	map_skill("finger", "wuxiang-finger");
	map_skill("claw", "dragon-claw");
	map_skill("staff", "wuchang-staff");
	map_skill("blade", "xiuluo-blade");
	map_skill("club", "weituo-chu");
	map_skill("sword", "fumo-sword");
	map_skill("whip", "xiangmo-whip");
	map_skill("parry", "weituo-chu");

	prepare_skill("cuff", "jingang-cuff");
	
	set("no_get",1);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({		
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("南少林派", 18, "方丈");
	setup();
	carry_object(WEAPON_DIR+"wtgun")->wield();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}
void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_nod", "nod");
        add_action("do_qiecuo","qiecuo");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	if(ob->query_temp("job_name") == "服侍方丈")
	{
		command("pat "+ob->query("id"));
		command("say " + RANK_D->query_respect(ob) + "你就给我按摩一下吧(massage 方丈)呵呵呵。\n");
	}
	return;
}
