// lingqing.c 灵清居士

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("灵清居士", ({ "lingqing jushi", "jushi", "lingqing" }) );
	set("gender", "男性");
	set("title", "昆仑派");
	set("class", "taoist");
	set("age", 43);
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
	set_skill("sword", 80);
	set_skill("liangyi-sword", 80);
	set_skill("changquan", 80);
	set_skill("sanshou", 80);
	map_skill("sword", "liangyi-sword");
	map_skill("parry", "liangyi-sword");
	map_skill("cuff", "changquan");
	map_skill("hand", "sanshou");
	prepare_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");

	setup();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
	carry_object(WEAPON_DIR"sword")->wield();
}
