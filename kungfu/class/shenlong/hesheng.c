// he sheng 何盛
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("何盛", ({ "he sheng","he" }));
	set("long", "无根道人的大弟子。\n");
	set("gender", "男性");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 28);
	set("int", 25);
	set("con", 26);
	set("dex", 26);
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 20);
	set("combat_exp", 20000);
	set("score", 50000);
	set("shen", -5000);

	set_skill("force", 40);
	set_skill("dulong-dafa", 40);
	set_skill("dodge", 40);
	set_skill("yixingbu", 30);
	set_skill("strike", 40);
	set_skill("huagu-mianzhang", 30);
	set_skill("parry", 30);
	set_skill("blade", 40);
	set_skill("xiuluo-dao", 40);
	set_skill("literate", 20);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "yixingbu");
	map_skill("strike", "huagu-mianzhang");
	map_skill("blade", "xiuluo-dao");
	map_skill("parry", "huagu-mianzhang");
	prepare_skill("strike", "huagu-mianzhang");

	set("party/party_name", HIY"神龙教"NOR);
	set("party/rank", HIR"赤龙门"NOR"教众");
	set("party/level", 1);
	create_family("神龙教", 3, "弟子");

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object(WEAPON_DIR"blade")->wield();
}
