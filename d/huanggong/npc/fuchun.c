// fuchun.c

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;

void create()
{
	set_name("富春", ({"fu chun", "fu", "chun"}));
	set("title", HIY"骁骑营参领"NOR);
	set("gender", "男性");
	set("age", 36);
	set("str", 25);
	set("dex", 20);
	set("int", 28);
	set("con", 28);
	set("per", 20);

	set("combat_exp", 250000);
	set("score", 200);
	set("shen_type", 1);
	set("attitude", "peaceful");

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

