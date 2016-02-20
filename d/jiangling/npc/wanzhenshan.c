//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit NPC;

void create ()
{
	set_name("万震山", ({"wan zhenshan","wan"}));
	set("nickname", HIR"五云手"NOR);
	set("long", "
一位身形魁梧的老者，精神矍铄，步履沉稳，丝毫不见苍老之态。\n");
	set("gender", "男性");
	set("age", 50);
	set("combat_exp", 1000000);
	set("str", 25);
	set("int", 28);
	set("dex", 23);
	set("dex", 26);
	set("per", 24);
  
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
	carry_object("/clone/cloth/male-cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}


