// shiqinglu.c 石清露
// Modified by Winder June 25. 2000
inherit NPC;
inherit F_MASTER;

#include <ansi.h>

void create()
{
	set_name("石清露", ({ "shi qinglu", "shi" }));
	set("long","她是函谷八友的七师妹，精于莳花，天下的奇花异卉，一经她的培植，无不欣欣向荣。\n");
	set("nickname","“函谷八友”花痴");
	set("gender", "女性");
	set("age", 34);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 38);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 60);
	set("combat_exp", 250000);
	set("score", 50000);

	set_skill("horticulture", 150);
	set_skill("blade", 40);
	set_skill("ruyi-dao", 40);
	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("strike", 40);
	set_skill("parry", 40);
	set_skill("lingboweibu", 40);
	set_skill("beiming-shengong", 40);
	set_skill("liuyang-zhang", 40);
	map_skill("strike", "liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("blade", "ruyi-dao");
	map_skill("parry", "ruyi-dao");
	prepare_skill("strike", "liuyang-zhang");
	set("book_count", 1);
	set("env/wimpy", 60);

	create_family("逍遥派", 3, "弟子");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你了，以后要多为逍遥派出力啊。");
	command("recruit " + ob->query("id"));
}
