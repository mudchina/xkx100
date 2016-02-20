// batwing.c
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("柳随风", ({ "batwing"}));
	set("gender", "男性");
	set("title", HIB"文盲"NOR"天下鬼门副门主白驼山派第四代弟子"NOR);
	set("nickname", HIR"不看不知道→Look Batwing」"NOR);
	set("age", 56);
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 26);
	set("int", 24);
	set("dex", 11);
	set("con", 24);
	set("str", 26);
	set("weiwang", 80);
	create_family("白驼山派" ,4, "弟子");
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}
