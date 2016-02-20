// Room: /d/nanyang/npc/man.c
// Last Modified by winder on Nov. 20 2001

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("大汉", ({ "da han","man" }) );
	set("title","");
	set("long","一位彪形大汉。\n");
	set("age", 20+random(20));
	set("gender", "男性");
	seteuid(getuid());
	set_skill("unarmed",60);
	set_skill("blade",50);
	set("combat_exp", 1000);
	set("talk_msg",({
		"这里是南阳城",
		"这里是诸葛亮的故乡",
		"柯府老爷为民除害，大家都感恩待德呀！",
		"南阳城北接中原，南渡汉水。",
	}));
	setup();
	carry_object(WEAPON_DIR"blade")->wield();
	carry_object(CLOTH_DIR"cloth")->wear();
}
