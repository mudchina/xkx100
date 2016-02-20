// yunyan.c
// Last Modifyed by Winder on Dec. 24 2001

inherit NPC;

void create()
{
	set_name("Ğ»ÔÆÑÌ", ({ "xie yunyan", "xie", "yunyan" }));
	set("long", "ËıÃæÈİ½¿ÃÄ£¬Æ¤·ô¹â»¬°×ÄÛ£¬Ò»Ë«ºÚíø¹ËÅÎÁôÇé£¬Ã÷Ä¿ÉÆíù¡£\n");
	set("title", "Ç§½¿°ÙÃÄ");
	set("gender", "Å®ĞÔ");
	set("age", 17);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("combat_exp", 20000);
	set("shen_type", 1);
	setup();
	carry_object("/d/city/obj/necklace")->wear();
	carry_object("/d/city/obj/pink_cloth")->wear();
	carry_object("/d/city/obj/flower_shoe")->wear();
	carry_object("/d/city/obj/goldring")->wear();
}

