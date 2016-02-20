// qiner.c ÇÙ¶ù

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("ÇÙ¶ù", ({ "qin er", "qiner", "qin" }) );
	set("gender", "Å®ÐÔ");
	set("age", 16);
	set("long","ËýÊÇÃçÈôÀ¼µÄÌùÉíÊÌæ¾¡£\n");
	set("attitude", "friendly");
	set("str", 15);
	set("int", 15);
	set("con", 19);
	set("dex", 17);
	set("per", 30);
	set("combat_exp", 1000);

	setup();
	carry_object(CLOTH_DIR"diaopi")->wear();
}
