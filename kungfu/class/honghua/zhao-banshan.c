// Last Modified by winder on Sep. 12 2001
// zhaobanshan.c 赵半山

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
	set_name("赵半山", ({ "zhao banshan", "zhao", "banshan" }));
	set("nickname", HIM"千手如来"NOR);
	set("title", HIR"红花会"HIG"三当家"NOR);
	set("long","他是红花会的三当家，\n他年纪好像在五十上下，他一张胖胖的脸，笑起来给人一副很慈祥的感觉。\n他原是温州王氏太极门掌门大弟子。\n豪迈豁达，行侠江湖，一手暗器功夫和太极剑少有能匹敌。\n屠龙帮风流云散之后，投入红花会。很得被红花会老当家于万亭赏识。\n");
	set("gender", "男性");
	set("class", "swordman");
	set("age", 52);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 2000);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 100000);

	set_skill("force", 150);
	set_skill("honghua-shengong", 150);
	set_skill("dodge", 150);
	set_skill("youlong-shenfa", 200);
	set_skill("throwing", 180);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("cuff", 150);
	set_skill("zhuihun-jian", 220);
	set_skill("wuying-feidao", 220);
        set_skill("hanxing-bada",220);
	set_skill("baihua-cuoquan", 220);
	set_skill("literate", 100);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("cuff", "baihua-cuoquan");
	map_skill("parry", "zhuihun-jian");
	map_skill("sword", "zhuihun-jian");
	map_skill("throwing", "wuying-feidao");
	prepare_skill("cuff", "baihua-cuoquan");
	
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({	
		(: perform_action, "sword.zhuihun" :),
		(: perform_action, "cuff.cuo" :),			
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("红花会", 2, "弟子");
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
        carry_object("/clone/weapon/jili")->wield();
}

void init()
{
	object ob = this_player();

	::init();

	if((int)ob->query("shen") < -1000 &&
		ob->query("family/master_id")=="zhao banshan")
	{
		command( "chat "+ob->query("name")+"！你这等邪恶奸诈之徒，我岂能仍是你的师父！\n");
		command("expell "+ ob->query("id"));
		this_player()->set("title","红花会" + RED + "弃徒" NOR);
	}
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 10000)
	{
		command("say 我红花会收徒极严。");
		command("say 这位" + RANK_D->query_respect(ob) + "平时还要多做一些行侠仗义之事！");
		return;
	}
	command("say 好，你这个年青人还不错，我收下你了！");
	command("recruit " + ob->query("id"));
}


