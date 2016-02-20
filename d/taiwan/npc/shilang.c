// shilang.c
// Last Modifyed by Ahda on Jan. 4 2002

#include "ansi.h"

inherit NPC;

void create()
{
	set_name("施琅", ({"shi lang", "shi", "lang"}));
	set("long",
        "他是一位身材魁梧的豪爽汉子。\n");
                                                          
	set("title", HIB "靖海侯"HIY "征台大将军" NOR);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 42);
	set("shen_type", 1);
	set("per", 22);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 500000);
	set("score", 10000);

	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("unarmed", 150);
	set_skill("parry", 150);
	set_skill("claw", 150);
	set_skill("blade", 150);

	setup();
	carry_object(ARMOR_DIR"tiejia")->wear();
	carry_object(WEAPON_DIR"gangdao")->wield();
}

