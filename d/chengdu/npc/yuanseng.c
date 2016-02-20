// Room: /d/chengdu/npc/yuanseng.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;

void create()
{
	set_name("Ô²¾õìøÊ¦", ({ "Yuan chanshi", "yuan", "chanshi" }));
	set("title","ÕÑ¾õËÂÖ÷³Ö");
	set("long", "ÕÑ¾õËÂµÚ¾Å´úÖ÷³Ö£¬´ÈÃ¼ÉÆÄ¿£¬Ñ©°×µÄ³¤Ğë¹ÒÔÚĞØÇ°¡£\n");
	set("gender", "ÄĞĞÔ");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 68);
	set("shen_type", 1);
	set("str", 26);
	set("int", 23);
	set("con", 29);
	set("dex", 19);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("combat_exp", 18000);
	set("score", 1000);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	setup();
	carry_object(CLOTH_DIR"seng-cloth")->wear();
	carry_object(CLOTH_DIR"seng-shoe")->wear();
}

