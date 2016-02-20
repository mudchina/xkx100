// camel.c 白骆驼

#include <command.h>
#include <dbase.h>
#include <origin.h>
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"白骆驼"NOR, ({ "bailuotuo" }));
        set("long","一匹西域来的白骆驼，全身雪白，无一根杂毛。\n"
	"中土是没有这重骆驼的。玩家可以骑上它去指定的地方(ride)。\n");
	set("race", "走畜");
        set("age", 5);
	set("int", 30);
	set("qi", 300);
	set("max_qi", 300);
	set("jing", 100);
	set("max_jing", 100);
	set("shen_type", 0);
	set("combat_exp",50000);
	set("attitude", "peaceful");

	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);
	set("chat_chance", 3);
        set("chat_msg", ({
		HIW"白骆驼"NOR"挣了挣辔头，翻了翻白眼没理你。\n",
                HIW"白骆驼"NOR"站起来嚼了口干草，然后又屈腿蹲了下来。\n",
        }) );

	setup();
}
