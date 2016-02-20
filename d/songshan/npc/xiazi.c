// xiazi.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("瞎子", ({ "xia zi", "xia", "zi" }) );
	set("long", "这就是被令狐冲刺瞎的瞎子。");
	set("gender", "男性");
	set("class", "swordsman");
	set("age", 25);
	set("attitude", "aggressive");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("max_qi",1000);
	set("max_jing",800);
	set("combat_exp", 100000);
	set("shen_type", -1);

	set_skill("literate", 50);
	set_skill("strike", 50);
	set_skill("hand", 50);
	set_skill("sword", 50);
	set_skill("force", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	set_skill("songshan-sword", 50);
	set_skill("songyang-strike", 50);
	set_skill("poyun-hand", 50);
	set_skill("hanbing-zhenqi", 50);
	set_skill("fuguanglueying", 50);
	map_skill("strike", "songyang-strike");
	map_skill("hand", "poyun-hand");
	map_skill("sword", "songshan-sword");
	map_skill("parry", "songshan-sword");
	map_skill("dodge", "fuguanglueying");
	map_skill("force", "hanbing-zhenqi");
	prepare_skill("strike", "songyang-strike");
	prepare_skill("hand", "poyun-hand");
	create_family("嵩山派", 14, "弟子");
	setup();

	carry_object(WEAPON_DIR+"kuojian")->wield();
	carry_object(CLASS_D("songshan")+"/obj/yellow-cloth")->wear();
}

