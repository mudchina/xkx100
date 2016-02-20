//wpp.c
#include <ansi.h>

inherit NPC;
void create()
{       set_name("展昭", ({ "wpp"}));
	set("gender", "男性");
	set("class", "taoist");
	set("title", HIW"圣人"HIG"明教风字门教众"NOR"武林泰斗武当派掌门大师兄");
	set("nickname", HIW"玉猫"HIR"南侠"NOR);
	set("age", 51);
	set("attitude", "friendly");

	set("kar", 19);
	set("per", 13);
	set("int", 20);
	set("dex", 20);
	set("con", 20);
	set("str", 25);
	set("weiwang", 30);
	create_family("武当派" ,2, "弟子");	
	setup();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
        carry_object(CLOTH_DIR"dao-shoe")->wear();
}
