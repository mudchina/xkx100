// hongma.c 枣红马

#include <command.h>
#include <dbase.h>
#include <origin.h>
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(RED"枣红马"NOR, ({ "zaohongma" }));
        set("long","一匹骏马，全身火红，无一根杂毛。\n"
		"玩家可以骑上它去指定的地方(ride)。\n");
	set("race", "走畜");
        set("age", 5);
	set("ridable", 1);
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
		RED"枣红马"NOR"抖抖长毛，扬颈「吁嘘嘘」一阵嘶鸣。\n",
                RED"枣红马"NOR"扯了扯缰绳，然后不耐地在地上刨着蹄子。\n",
        }) );

	setup();
}
