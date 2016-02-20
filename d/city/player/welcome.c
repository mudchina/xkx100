//welcome.c
#include <ansi.h>

inherit NPC;
void create()
{       set_name("星志星", ({ "welcome"}));
	set("gender", "男性");
	set("class", "quanzhen");
	set("title", "全真教第二代弟子");
	set("nickname", HIR"侠客行笑笑生"NOR);
	set("age", 50);
	set("attitude", "friendly");

	set("kar", 19);
	set("per", 30);
	set("int", 20);
	set("dex", 20);
	set("con", 20);
	set("str", 20);
	set("weiwang", 80);
	create_family("全真教" ,2, "弟子");	
	setup();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
        carry_object(CLOTH_DIR"dao-shoe")->wear();
}
