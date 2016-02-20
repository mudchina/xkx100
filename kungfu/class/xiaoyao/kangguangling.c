// kangguangling.c 康广陵
// Modified by Winder June 25. 2000
inherit NPC;
inherit F_MASTER;

#include <ansi.h>

void create()
{
	set_name("康广陵", ({ "kang guangling", "kang" }));
	set("long","只见他高额凸颡，容貌奇古，笑眯眯的脸色极为和谟，手中抱着一具瑶琴。\n");
	set("nickname","“函谷八友”琴颠");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 38);

	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 60);
	set("combat_exp", 400000);
	set("score", 50000);

	set_skill("luteplaying",150);
	set_skill("blade",100);
	set_skill("ruyi-dao",150);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("strike", 100);
	set_skill("parry", 100);
	set_skill("lingboweibu", 150);
	set_skill("beiming-shengong",100);
	set_skill("liuyang-zhang", 150);
	map_skill("strike", "liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("blade", "ruyi-dao");
	map_skill("parry", "ruyi-dao");
	prepare_skill("strike", "liuyang-zhang");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "dodge.lingbo" :),
		(: perform_action, "strike.zhong" :),		
		(: exert_function, "shield" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set("book_count", 1);

	create_family("逍遥派", 3, "弟子");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/food/jiudai");
}

void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你了，以后要多为逍遥派出力啊。");
	command("recruit " + ob->query("id"));
}
