// jiang.c 蒋老拳师

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("蒋老拳师", ({ "jiang" }) );
	set("gender", "男性");
	set("title", "河南无极门弟子");
	set("age", 63);
	set("attitude", "friendly");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 400000);
	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("cuff", 80);
	set_skill("hand", 80);
	set_skill("changquan", 80);
	set_skill("sanshou", 80);
	map_skill("cuff", "changquan");
	map_skill("hand", "sanshou");
	map_skill("parry", "sanshou");
	prepare_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}
