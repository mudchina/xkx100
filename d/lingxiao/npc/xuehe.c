// Npc: /d/lingxiao/npc/xuehe.c
// Last Modified by winder on Jul. 15 2001

inherit NPC;
#include <ansi.h>
void create()
{
	set_name(HIW"雪鹤"NOR, ({ "xue he", "he"}));
	set("race", "飞禽");
	set("age", 3);
	set("long", "一只全身洁白的雪鹤，是大雪山的特产。\n");
	set("attitude", "peaceful");
	set("combat_exp", 300);
	set_temp("apply/attack", 5);
	set_temp("apply/defense", 7);
	set_temp("apply/armor", 7);

	setup();
}

