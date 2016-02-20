// xuanmingzi.c 玄冥子

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("玄冥子", ({ "xuanming zi", "xuanming", "zi" }) );
	set("gender", "男性");
	set("title", "青藏派");
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
	set_skill("mingwang-jian", 80);
	set_skill("changquan", 50);
	set_skill("sanshou", 50);
	map_skill("sword", "mingwang-jian");
	map_skill("parry", "mingwang-jian");
	map_skill("cuff", "changquan");
	map_skill("hand", "sanshou");
	prepare_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");

	setup();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
	carry_object(WEAPON_DIR"sword")->wield();
}
