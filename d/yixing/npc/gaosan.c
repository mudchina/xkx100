// /d/yixing/npc/gaosan.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit F_UNIQUE;
inherit NPC;

void create()
{
	set_name("高三娘子", ({ "gao san", "gao"}));
	set("title", HIR "万马庄女庄主" NOR);
	set("long", "这女子颇有几分姿色，两幅罗裙外面系着绣花鸾带。
腰间整整齐齐插着两排短刀。\n");
	set("gender", "女性");
	set("age", 31);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 22);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	
	set("max_qi", 1000);
	set("max_jing", 200);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 50000+random(10000));
	set("score", 20000);

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("throwing", 50);
	set_skill("feixing-shu", 50);
	set_skill("lingxu-bu",50);
	map_skill("dodge", "lingxu-bu");
	map_skill("parry", "feixing-shu");
	map_skill("throwing", "feixing-shu");

	set_temp("apply/attack", 25);
	set_temp("apply/attack", 25);
	set_temp("apply/damage", 25);
	set("chat_chance", 3);
	set("chat_msg", ({
		"高三娘子怒道：丁不四这老贼，总有一天要找他算帐！\n",
	}) );

	set("inquiry",([
		"丁不四" : "下次再遇到这老贼，定在他身上插几把飞刀。",
		"长乐帮" : "我也正要到长乐帮拜山。",
		"司徒横" : "听说长乐帮的奸贼作乱饭上害死了他。",
	]));

	setup();
	carry_object(__DIR__"obj/shortblade")->wield();
	carry_object(CLOTH_DIR"cloth")->wear();
}

