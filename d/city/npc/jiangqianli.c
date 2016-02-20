// npc: /d/city/npc/jiangqianli.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>

inherit NPC;

void create()
{   
	set_name(YEL "江千里" NOR, ({ "jiang qianli","jiang" }) );
	set("gender", "男性");
	set("title", "江氏漆器作坊主");
	set("age", 38);
	set("long", @LONG
他是扬州城里最好的漆器手工艺人，中等身材，四方脸，看上去一团和气。
只有两手的手指纤细修长显出他是个手工艺人。
LONG
	);
	set("attitude", "peaceful");

	set("str", 17);
	set("int", 30);
	set("dex", 30);
	set("con", 30);
	set("per", 20);

	set("combat_exp", 100000);
	set("score", 9000);

	set("inquiry", ([
		"江千里" : "江千里就是我。本人姓江名千里，表字秋水。\n",
		"漆沙砚" : "此砚乃是先祖竭尽心思所创，历经十年才尽善尽美。",
		"螺钿杯" : "承蒙朋友捧场，送了一首诗：\n"+
			"			螺钿妆成翡翠光，紫霞秋澈婺州香\n"+
			"			形神俱美真通太，假寐仍期到梦乡\n",
	]) );


	setup();

}

