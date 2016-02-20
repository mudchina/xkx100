// ruidong.c

#include "ansi.h"

inherit NPC;

void create()
{
	set_name("瑞栋", ({"rui dong", "rui", "dong"}));
	set("long",
        "他是一位身材魁梧的豪爽汉子。\n");
                                                          
	set("title",HIY "大内副总管" NOR);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 35);
	set("shen_type", -1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 1200);
	set("max_jing", 1200);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("combat_exp", 700000);
	set("score", 10000);

	set_skill("force", 130);
	set_skill("dodge", 130);
	set_skill("unarmed", 130);
	set_skill("parry", 130);
	set_skill("claw", 130);
	set_skill("jiuyang-shengong", 130);
	set_skill("xiaoyaoyou", 130);
	set_skill("jiuyin-baiguzhao", 130);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("claw", "jiuyin-baiguzhao");
	map_skill("parry", "sougu");
	prepare_skill("claw", "jiuyin-baiguzhao");

	setup();

	carry_object("/d/city/obj/tiejia")->wear();
}

