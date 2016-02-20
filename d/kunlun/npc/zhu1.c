// Npc: /d/kunlun/npc/zhu1.c 朱九真
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("朱九真", ({ "zhu jiuzhen", "zhu"}));
	set("long", "她长得极美，容貌娇媚，又白又腻。\n");
	set("nickname", HIW"雪岭双姝"NOR);
	set("gender", "女性");
	set("per", 30);
	set("age", 17);

	set_skill("finger", 40);
	set_skill("sun-finger", 40);
	set_skill("dodge", 40);
	set_skill("tiannan-step", 40);
	set_skill("parry", 40);
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "sun-finger");
	map_skill("finger", "sun-finger");
	prepare_skill("finger", "sun-finger");

	set("combat_exp", 100000);
	set("shen_type", 1);
	setup();
	carry_object(__DIR__"obj/whitecloth")->wear();
	carry_object(__DIR__"obj/necklace")->wear();
}

