// yin.c 殷梨亭
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("殷梨亭", ({ "yin liting","yin"}));
	set("nickname", "武当六侠");
	set("long","他就是张三丰的最软弱的弟子、武当七侠之六的殷梨亭。\n身穿一件干干净净的青布长衫。\n他不过二十出头年纪，精明能干，嫉恶如仇，性如烈火，却一直一副不愉快的表情。\n只见他满脸风尘之色，两鬓微见斑白，\n在武当七侠中排名第六，对剑法尤为精通。\n");
	set("gender", "男性");
	set("age", 23);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("shen_type", 1);
	set("str", 26);
	set("int", 39);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jingli", 1000);
	set("max_jingli", 1000);
	set("jiali", 50);
	set("combat_exp", 250000);
	set("score", 60000);

	set_skill("force", 95);
	set_skill("taiji-shengong", 100);
	set_skill("dodge", 95);
	set_skill("tiyunzong", 130);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 150);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("liangyi-jian", 150);
	set_skill("taiji-jian", 150);
	set_skill("wudang-jian", 100);
	set_skill("wudang-quan", 100);
	set_skill("literate", 95);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "liangyi-jian");
	map_skill("sword", "taiji-jian");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "unarmed.zhen" :),
		(: perform_action, "unarmed.ji" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set("inquiry", ([
		"纪晓芙" : "可怜我那未过门的妻子，居然被杨逍那淫徒。。。",
		"杨逍"   : "总有一天我要手刃这魔教淫贼，以祭晓芙在天。。。",
		"神门十三剑" : "神门十三剑乃。。。唉，可怜晓芙居然被杨消那淫徒。。。",
	]));

	create_family("武当派", 2, "弟子");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("wudang/offerring") < 5) {
		command("say " + RANK_D->query_respect(ob) +
			"你对我武当派尽了多少心力，有几分忠心呢？");
		return;
	}
	if ((int)ob->query_skill("taiji-shengong", 1) < 40) {
		command("say 我武当派乃内家武功，最重视内功心法。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该在太极神功上多下点功夫？");
		return;
	}
	if ((int)ob->query("shen") < 80000) {
		command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
        command("sigh");
        command("say 虽然"+RANK_D->query_respect(ob)+"也是我辈中人，但自晓芙去后，我已无心收徒；不过你我今日相见也是有缘，我就传你一式“天地同寿”，也不枉你我相识一场。");
        ob->set("wudang/yinliting_teach", 1);
}
