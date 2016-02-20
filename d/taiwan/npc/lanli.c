// lanli.c
// Last Modifyed by Ahda on Jan. 4 2002

#include "ansi.h"

inherit NPC;

void create()
{
	set_name("蓝理", ({"lan li", "lan", "li"}));
	set("long", "他是一位身材魁梧的豪爽汉子。\n");
                                                          
	set("title", HIY "左营游击" NOR);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 21);
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
//	set_skill("jiuyang-shengong", 150);
//	set_skill("xiaoyaoyou", 150);
//	set_skill("sougu", 150);

//	map_skill("force", "jiuyang-shengong");
//	map_skill("dodge", "xiaoyaoyou");
//	map_skill("claw", "sougu");
//	map_skill("parry", "sougu");
	prepare_skill("claw", "sougu");

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command("perform muyeyingyang") :),
	}) );
	setup();
	carry_object(ARMOR_DIR"tiejia")->wear();
}

