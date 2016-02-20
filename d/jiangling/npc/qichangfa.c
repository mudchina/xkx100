//Edited by fandog, 02/13/2000
#include <ansi.h>
inherit NPC;

void create ()
{
	set_name("戚长发", ({"qi changfa","qi"}));
	set("nickname", HIB"铁锁横江"NOR);
	set("long", "一个老头儿，嘴里咬着一根短短的旱烟管。他满头白发、满脸皱
纹，但眼中神光炯然，凛凛有威。\n");
	set("gender", "男性");
	set("age", 48);
	set("combat_exp", 1000000);
	set("str", 25);
	set("int", 28);
	set("dex", 23);
	set("con", 18);
	set("per", 18);
	set("kar", 26);
  
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
}


