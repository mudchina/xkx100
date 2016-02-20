// baima.c 白马

#include <command.h>
#include <dbase.h>
#include <origin.h>

inherit NPC;

void create()
{
	set_name("白马", ({ "bai ma" }));
	set("long","一匹骏马，全身雪白，无一根杂毛。\n");
	set("race", "走畜");
	set("age", 5);
	set("attitude","heroism");
	set("str", 30);
	set("dex", 35);
	set("con", 30);
	set("int", 18);
	set("shen", 1);
	set("combat_exp", 1000);
	setup();
}
