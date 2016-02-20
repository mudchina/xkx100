// piaoxue.c
#include <ansi.h>

inherit NPC;
void create()
{       set_name("Æ®Ñ©", ({ "piaoxue"}));
	set("gender", "ÄÐÐÔ");
	set("class", "swordman");
	set("title", GRN"Ì½»¨"NOR"Îäµ±ÅÉµÚÈý´úµÜ×Ó");
	set("nickname", HIC"Æ®"MAG"Ïã"HIY"½£"HIG"Óê"NOR);
	set("age", 16);
	set("attitude", "friendly");

	set("kar", 19);
	set("per", 26);
	set("int", 20);
	set("dex", 20);
	set("con", 20);
	set("str", 20);
	set("weiwang", 80);
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}
