// Room: /d/huijiang/npc/guanjia.c
// Last Modified by winder on Sep. 12 2001

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("心砚", ({ "xin yan", "xin", "yan" }) );
	set("title", "红花会总管");
	set("gender", "男性");
	set("age", 20);

	set("str", 22);
	set("int", 26);
	set("per", 23);
	set("kar", 25);
	set("con", 23);
	set("dex", 23);
	set("long","他也是红花会总舵主陈家洛的书童，看上去一副极为精明能干的模样，\n红花会中大大小小的琐碎事务全归他管。\n");
	set("combat_exp", 30000);
	set("attitude", "friendly");
	set("env/wimpy", 30);

	set("max_neili", 400);
	set("neili", 400);
	set("jiali", 70);

	set_skill("force", 100);
	set_skill("honghua-shengong",100);
	set_skill("dodge", 100);
	set_skill("youlong-shenfa", 100);
	set_skill("unarmed", 100);
	set_skill("parry",100);
	set_skill("sword",100);
	set_skill("zhuihun-jian",100);
	set_skill("literate",170);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("parry", "zhuihun-jian");
	map_skill("sword", "zhuihun-jian");

	create_family("红花会", 3, "弟子");
	setup();
	
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"cloth")->wear();
	add_money("gold", 1);
}
