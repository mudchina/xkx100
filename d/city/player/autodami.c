// autodami.c
#include <ansi.h>

inherit NPC;
void create()
{       set_name("哭三少", ({ "autodami"}));
	set("gender", "男性");
	set("class", "beggar");
	set("title", "丐帮第二十代弟子");
	set("nickname", HIY"我是武庙3楼的大名人笑三少的跟班"NOR);
	set("age", 14);
	set("attitude", "friendly");

	set("kar", 19);
	set("per", 26);
	set("int", 20);
	set("dex", 20);
	set("con", 20);
	set("str", 20);
	set("weiwang", 80);
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}
