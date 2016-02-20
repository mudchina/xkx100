// Npc: /d/kunlun/npc/yao.c
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("姚清泉", ({ "yao qingquan", "yao" }));
	set("nickname",HIC"千里追风"NOR);
	set("gender", "男性");
	set("age", 45);

	set_skill("finger", 90);
	set_skill("sun-finger", 90);
	set_skill("dagger", 100);
	set_skill("shigu-bifa", 100);
	set_skill("dodge", 100);
	set_skill("tiannan-step", 100);
	set_skill("parry", 100);
	map_skill("parry", "sun-finger");
	map_skill("finger", "sun-finger");
	map_skill("dodge", "tiannan-step");
	map_skill("dagger", "shigu-bifa");
	prepare_skill("finger", "sun-finger");

	set("combat_exp", 20000);
	set("shen_type", -1);
	setup();
	add_money("silver", 50);
	carry_object("/d/meizhuang/npc/obj/panguan-bi")->wield();
	carry_object(CLOTH_DIR+"choupao")->wear();
}

