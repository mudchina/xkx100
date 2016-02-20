//aiwoaini.c
#include <ansi.h>

inherit NPC;
void create()
{       set_name("爱我爱你", ({ "aiwoaini"}));
	set("gender", "女性");
	set("class", "swordman");
	set("title", HIR"内阁大学士"HIG"明教地字门教众"NOR"古墓派第二代弟子");	
	set("age", 48);
	set("attitude", "friendly");

	set("kar", 19);
	set("per", 23);
	set("int", 20);
	set("dex", 20);
	set("con", 20);
	set("str", 20);
	set("weiwang", 20);
	create_family("古墓派" ,2, "弟子");	
	setup();
	carry_object(CLOTH_DIR"female-cloth")->wear();
        carry_object(CLOTH_DIR"female-shoe")->wear();
}
