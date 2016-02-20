// npc: /d/city/npc/jiangong.c
// Last Modified by Winder on Jul. 15 2000

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL "监工" NOR, ({"jian gong", "jian"}));
	set("title", "扬州漕运码头");
	set("age", 33);
	set("gender", "男性");
	set("str", 26);
	set("dex", 25);
	set("long", "监工面无表情的站在码头边上，手里握着一根鞭子。\n");
	set("max_jing", 500);
	set("max_qi", 500);
	set("attitude", "heroism");
	set("combat_exp", 20000);

	set_skill("force", 50);
	set_skill("whip", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	setup();
	carry_object("/clone/weapon/changbian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/douli")->wear();
}
