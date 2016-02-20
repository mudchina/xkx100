// caoyunqi.c 曹云奇

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("曹云奇", ({ "cao yunqi", "yunqi", "cao" }) );
	set("gender", "男性");
	set("title", "辽东天龙门北宗第六代掌门人");
	set("nickname", "腾龙剑");
	set("age", 43);
	set("attitude", "friendly");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 300000);
	set_skill("dodge", 50);
	set_skill("force", 50);
	set_skill("cuff", 50);
	set_skill("hand", 50);
	set_skill("sword", 50);
	set_skill("liehuo-jian", 50);
	set_skill("changquan", 50);
	set_skill("sanshou", 50);
	map_skill("sword", "liehuo-jian");
	map_skill("parry", "liehuo-jian");
	map_skill("cuff", "changquan");
	map_skill("hand", "sanshou");
	prepare_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object(WEAPON_DIR"sword")->wield();
}
