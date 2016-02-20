// getong.c

#include "ansi.h"

inherit NPC;

void create()
{
	set_name("¸ðÍ¨", ({"ge tong", "ge", "tong", }));
	set("title",HIY "À¤Äþ¹¬´øµ¶ÊÌÎÀ" NOR);
	set("gender", "ÄÐÐÔ");
	set("attitude", "peaceful");

	set("age", 28);
	set("shen_type", 1);
	set("per", 22);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);

	set("qi", 1500);
	set("max_qi", 1500);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 300000);
	set("score", 1000);

	set_skill("blade", 100);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("jiuyang-shengong", 100);
	set_skill("xiaoyaoyou", 100);
	set_skill("changquan", 100);
	set_skill("wuhu-duanmendao", 100);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("unarmed", "changquan");
	map_skill("parry", "wuhu-duanmendao");
	map_skill("blade", "wuhu-duanmendao");

	setup();

	carry_object("/d/city/obj/tiejia")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

