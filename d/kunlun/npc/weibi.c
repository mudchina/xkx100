// Npc: /d/kunlun/npc/weibi.c 卫璧
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("卫璧", ({ "wei bi", "wei"}));
	set("long","他容貌英俊，长身玉立，虽在这等大寒天候，却只\n穿了一件薄薄的淡黄色缎袍，显是内功不弱。\n");
	set("gender", "男性");
	set("per", 30);
	set("age", 18);

	set_skill("finger", 40);
	set_skill("sun-finger", 40);
	set_skill("dodge", 40);
	set_skill("tiannan-step", 40);
	set_skill("parry", 40);
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "sun-finger");
	map_skill("finger", "sun-finger");
	prepare_skill("finger", "sun-finger");

	set("combat_exp", 150000);
	set("shen_type", 1);
	setup();
	carry_object(__DIR__"obj/yellowcloth")->wear();
}

