// heiyiren.c 日月神教教徒
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("黑衣人", ({ "heiyi ren", "ren" }));
	set("gender", "男性");
	set("age", 25);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);	
        set("apply/attack", 50);
	set("apply/defense", 50);
	set("apply/damage", 25);
	set("combat_exp", 30000);
	set("shen_type", -1);
	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIC"风雷堂教众"NOR);
	setup();
}	
