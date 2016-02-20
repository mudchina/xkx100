//Edited by fandog, 01/31/2000

inherit NPC;
#include <ansi.h>
void create ()
{
	set_name("言达平", ({"yan daping","yan"}));
	set("long", "
这人身形瘦削，双目炯炯有神，服饰极是华丽，一副大财主的模样儿。\n");
	set("gender", "男性");
	set("nickname", HIY"陆地神龙"NOR);
	set("age", 52);
	set("combat_exp", 1000000);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 25);
	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("sword", 120);
	set_skill("parry", 120);
	set_skill("yanfly", 120);
	set_skill("tangshi-jian", 120);
	map_skill("dodge", "yanfly");
	map_skill("parry", "tangshi-jian");
	map_skill("sword", "tangshi-jian");
	setup();

	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
}


