// likuilei.c 李傀儡
// Modified by Winder June 25. 2000
inherit NPC;
inherit F_MASTER;

#include <ansi.h>

void create()
{
	set_name("李傀儡", ({ "li kuilei", "li" }));
	set("long","他看起来青面獠牙，红发绿须，形状可怕之极，直是个妖怪，身穿一件亮光闪闪的锦袍。他一生沉迷扮演戏文，疯疯颠颠，于这武学一道，不免疏忽了。\n");
	set("nickname","“函谷八友”戏迷");
	set("gender", "男性");
	set("age", 30);
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
	set("combat_exp", 200000);
	set("score", 50000);

	set_skill("dramaturgy",150);
	set_skill("blade", 30);
	set_skill("ruyi-dao", 30);
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("strike", 30);
	set_skill("parry", 30);
	set_skill("lingboweibu", 100);
	set_skill("beiming-shengong",30);
	set_skill("liuyang-zhang", 30);
	map_skill("parry", "ruyi-dao");
	map_skill("strike", "liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("blade", "ruyi-dao");
	prepare_skill("strike", "liuyang-zhang");
	set("book_count", 1);
	set("env/wimpy", 60);

	create_family("逍遥派", 3, "弟子");
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你了，以后要多为逍遥派出力啊。");
	command("recruit " + ob->query("id"));
}
