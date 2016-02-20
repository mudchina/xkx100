// shi.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("Ê·µÇ´ï", ({ "shi dengda", "dengda", "shi" }) );
	set("nickname", HIG"Ç§ÕÉËÉ"NOR);
	set("gender", "ÄÐÐÔ");
	set("class", "swordsman");
	set("age", 25);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 30);
	set("max_qi",1000);
	set("max_jing",800);
	set("combat_exp", 200000);
	set("shen_type", -1);

	set_skill("literate", 50);
	set_skill("strike", 80);
	set_skill("hand", 80);
	set_skill("sword", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("songshan-sword", 120);
	set_skill("songyang-strike", 120);
	set_skill("poyun-hand", 120);
	set_skill("hanbing-zhenqi", 80);
	set_skill("fuguanglueying", 120);
	map_skill("strike", "songyang-strike");
	map_skill("hand", "poyun-hand");
	map_skill("sword", "songshan-sword");
	map_skill("parry", "songshan-sword");
	map_skill("dodge", "fuguanglueying");
	map_skill("force", "hanbing-zhenqi");
	prepare_skill("strike", "songyang-strike");
	prepare_skill("hand", "poyun-hand");
	create_family("áÔÉ½ÅÉ", 14, "µÜ×Ó");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.shuiyuan" :),
		(: perform_action, "sword.jianqi" :),
		(: perform_action, "sword.feiwu" :),
		(: perform_action, "strike.yinyang" :),
		(: perform_action, "hand.chanyun" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	setup();

	carry_object(WEAPON_DIR+"kuojian")->wield();
	carry_object(__DIR__"obj/yellow-cloth")->wear();
}

