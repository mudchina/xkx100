// jianning.c

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;

void create()
{
	set_name(HIG"建宁公主"NOR,({"jianning gongzhu","jianning","gongzhu"}));
	set("gender", "女性");
	set("age", 16);
	set("str", 25);
	set("dex", 20);
	set("int", 28);
	set("con", 28);
	set("per", 28);
	set("long", "她一张瓜子脸儿，薄薄的嘴唇，眉目灵动，颇有英气。\n");

	set("combat_exp", 5000);
	set("score", 200);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("literate", 20);
	set_skill("force", 20);
	set_skill("hunyuan-yiqi", 20);
	set_skill("shaolin-shenfa", 20);
	set_skill("finger", 20);
	set_skill("nianhua-zhi", 20);
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "nianhua-zhi");
	map_skill("finger", "nianhua-zhi");
	prepare_skill("finger", "nianhua-zhi");

	set_temp("apply/attack", 50);
	set_temp("apply/defence", 50);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 35);

	set("qi", 600);
	set("max_qi", 600);
	set("jing", 200);
	set("max_jing", 200);
	set("neili", 20);
	set("max_neili", 20);

	setup();
	carry_object(__DIR__"obj/jinduan")->wear();
	add_money("silver", 10);
}

