// duan.c

inherit NPC;
//inherit F_SKILL;
#include <ansi.h>
void create()
{

	set_name("段延庆", ({ "duan yanqing", "duan" }));
	set("gender", "男性");
	set("nickname", HIC"恶贯满盈"NOR);
	set("age", 54);
	set("str", 25);
	set("dex", 16);
	set("per", 21);
	set("long", "他一身青袍人，长须垂胸，面目漆黑，一双眼睁大大的，
一霎也不霎。\n");
	set("combat_exp", 500000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 50);

	set_skill("finger", 150);
	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("staff", 150);
	set_skill("parry", 150);
	set_skill("sun-finger", 150);
	set_skill("kurong-changong", 150);
	set_skill("tiannan-step", 150);
	set_skill("lingshe-zhangfa", 150);
	map_skill("dodge", "tianna-step");
	map_skill("force", "kurong-changong");
	map_skill("parry", "sun-finger");
	map_skill("staff", "lingshe-zhangfa");
	map_skill("finger", "sun-finger");
	prepare_skill("finger", "sun-finger");

	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}

