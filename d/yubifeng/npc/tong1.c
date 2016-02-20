// tong1.c 左僮

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("左僮", ({ "zuo tong", "zuo", "tong" }) );
	set("gender", "男性");
	set("age", 13);
	set("long","他是雪山飞狐胡斐的童子。\n");
	set("attitude", "friendly");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 200000);
	set_skill("dodge", 100);
	set_skill("force", 100);
	set_skill("sword", 100);
	set_skill("cuff", 100);
	set_skill("hand", 100);
	set_skill("changquan", 1000);
	set_skill("sanshou", 100);
	set_skill("changge-jian", 100);
	map_skill("sword", "changge-jian");
	map_skill("parry", "changgejian-jian");
	map_skill("cuff", "changquan");
	map_skill("hand", "sanshou");
	prepare_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");

	setup();
	carry_object(CLOTH_DIR"jinduan")->wear();
	carry_object(__DIR__"obj/jinjian")->wield();
}
