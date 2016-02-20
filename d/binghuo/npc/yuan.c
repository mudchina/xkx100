// yuan.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("元广波", ({ "yuan guangbo", "yuan", "guangbo" }));
	set("title", HIB"海沙派总舵主"NOR);
	set("long", "海沙派武艺平常，专靠毒盐害人。\n");
	set("gender", "男性");
	set("age", 22);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("per", 20);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 600);
	set("max_jing", 600);
	set("neili", 600);
	set("max_neili", 600);
	set("combat_exp", 70000);
	set_skill("parry", 30);
	set_skill("unarmed", 30);
	set_skill("changquan", 30);
	map_skill("parry", "changquan");
	map_skill("unarmed", "changquan");

	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}

