// xianhe.c

inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIR"丹"NOR"顶鹤", ({ "danding he", "he"}));
	set("race", "飞禽");
        set("age", 3);
        set("long", "一只全身洁白的丹顶鹤，看来是修了翅膀，没法高飞了。\n");
        set("attitude", "peaceful");

        set("combat_exp", 300);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 7);
        set_temp("apply/armor", 7);

        setup();
}
