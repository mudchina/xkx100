// bagua.c 八卦弟子

#include <command.h>
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("八卦弟子", ( {"bagua dizi","dizi","bagu" }));
	set("age", 23);
	set("gender", "男性");
	set("long", "真武剑阵八卦方位弟子。\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 80000);
	set("shen_type", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("sword", 80);
	set_skill("force", 60);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 80);
	set("chat_chance", 5);
	set("chat_msg", ({
		"八卦弟子齐声吆喝：真武剑阵，天下第一！\n",
	}));
	create_family("武当派", 3, "弟子");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object("/d/wudang/obj/baguafu")->wear();
}
