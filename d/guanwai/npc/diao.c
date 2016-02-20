//  /guanwai/npc/diao.c

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(HIY"金雕"NOR, ({ "diao"}));
	set("race", "飞禽");
	set("age", 3);
	set("long", "一只大金雕，正立在树枝上仰视长天。\n");
	set("attitude", "peaceful");

	set("combat_exp", 30000);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 150);
	set_temp("apply/armor", 50);

	setup();
}
