// Obj: /d/nanshaolin/obj/kuchan.c
// Last Modified by winder on May. 29 2001

inherit NPC;
void create()
{
	set_name("枯禅石人", ({ "kuchan shiren", "kuchan", "shiren" }));
	set("long", "年代久远已无法看清他当年之相貌，\n"
		"但他身材高大遍体枯黄，便和一株枯树相仿。\n");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("age", 100);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1200);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 1200000);
	set("score", 200);
	set_skill("force", 140);
	set_skill("yijinjing",140);
	set_skill("jingang-cuff", 140);
	set_skill("dodge", 140);
	set_skill("yiwei-dujiang", 140);
	set_skill("cuff", 140);
	set_skill("parry", 140);
	set_skill("buddhism", 140);
	map_skill("force", "yijinjing");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("cuff", "jingang-cuff");
	map_skill("parry", "jingang-cuff");
	prepare_skill("cuff", "jingang-cuff");
	setup();
}
#include "chan.h" 
