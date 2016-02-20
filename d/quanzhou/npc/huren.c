// huren.c
// Last Modified by winder on May. 29 2001

inherit NPC;

void create()
{
	set_name("胡人", ({ "hu ren", "huren" }));
	set("shen_type", 1);
	set("gender", "男性");
	set("age", 35);
	set("long", "一个金发碧眼的胡人，正趾高气扬的吆喝着。\n");
	set("combat_exp", 3800);
	set("attitude", "friendly");
	setup();
}
