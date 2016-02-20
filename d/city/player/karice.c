// karice.c
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("灵米", ({ "karice"}));
	set("gender", "男性");
	set("class", "beggar");
	set("title", "昆仑派第三代弟子");
	set("nickname", HIR"一生一火花"NOR);
	set("age", 26);
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 30);
	set("int", 24);
	set("dex", 11);
	set("con", 24);
	set("str", 26);
	set("weiwang", 80);
	create_family("昆仑派" , 3, "弟子");
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

