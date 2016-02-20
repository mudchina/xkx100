// kuli.c
// Last Modified by winder on May. 29 2001

inherit NPC;

void create()
{
	set_name("苦力", ({ "ku li", "kuli" }));
	set("shen_type", 1);
	set("gender", "男性");
	set("age", 25);
	set("long", "这是个老实巴交的苦力，长得膀阔腰圆，一身肌肉。\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	setup();
}
