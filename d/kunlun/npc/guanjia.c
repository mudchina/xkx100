// Npc: /d/kunlun/npc/guanjia.c 管家
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("乔福", ({ "qiao fu", "qiao","fu" }));
	set("title",HIY"管家"NOR);
	set("gender", "男性");
	set("age", 65);

	set("combat_exp", 7500);
	set_skill("unarmed", 35);
	set_skill("force", 35);
	set_skill("dodge", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 40);
	set("shen_type", -1);
	setup();
}
	
