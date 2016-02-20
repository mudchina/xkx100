// Last Modified by Winder on May. 29 2001
// Npc: /kungfu/class/nanshaolin/dachi.c

#include "/kungfu/class/nanshaolin/da.h"
#include "ansi.h"
inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("大痴大师", ({ "dachi dashi", "dachi", "dashi"}));
	set("long",
		"他是一位笑容可掬的老僧，身穿一袭青布镶边袈裟。他身材不高，\n"
		"太阳穴微凸，双目炯炯有神。\n");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 2000);
	set("max_jing", 1200);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali",200);
	set("combat_exp", 1000000);
	set("score", 5000);

	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 150);
	set_skill("force", 150);
	set_skill("zhanzhuang-gong", 150);
	set_skill("dodge", 150);
	set_skill("yiwei-dujiang", 220);
// basic skill begin
	set_skill("shaolin-cuff", 220);
	set_skill("luohan-cuff", 220);
	set_skill("weituo-strike", 220);
	set_skill("sanhua-strike", 220);
	set_skill("boluomi-hand", 220);
	set_skill("jingang-strike", 220);
	set_skill("nianhua-finger", 220);
	set_skill("boruo-strike", 220);
// basic skill end
// 指和鞭
	set_skill("finger", 150);
	set_skill("mohe-finger", 220);
	set_skill("duoluoye-finger", 220);
	set_skill("one-finger", 220);
	set_skill("wuxiang-finger", 220);
	set_skill("whip", 150);
	set_skill("jiujie-whip", 220);
	set_skill("xiangmo-whip", 220);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("finger", "wuxiang-finger");
	map_skill("whip", "xiangmo-whip");
	map_skill("parry", "xiangmo-whip");

	prepare_skill("finger", "wuxiang-finger");
	
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({		
		(: exert_function, "roar" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("南少林派", 19, "藏经阁首座");
	setup();
	carry_object(WEAPON_DIR+"whip/whip")->wield();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}
