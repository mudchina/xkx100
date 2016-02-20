//wrong.c
#include <ansi.h>

inherit NPC;
void create()
{       set_name("懒虫", ({ "wrong"}));
	set("gender", "女性");
	set("class", "swordman");
	set("title", GRN"状元"HIG"明教地字门教众"NOR"华山派第十三代弟子");	
	set("age", 34);
	set("attitude", "friendly");

	set("kar", 19);
	set("per", 17);
	set("int", 20);
	set("dex", 20);
	set("con", 20);
	set("str", 20);
	set("weiwang", 80);
	create_family("华山派" ,13, "弟子");	
	setup();
	carry_object(CLOTH_DIR"female-cloth")->wear();
        carry_object(CLOTH_DIR"female-shoe")->wear();
}
