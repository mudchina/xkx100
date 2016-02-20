// xiaosi.c
// Last Modified by winder on May. 29 2001

inherit NPC;

void create()
{
	set_name("药铺小厮", ({ "yaopu xiaosi", "xiaosi"}));
	set("long", "他肌肤黄瘦，脸有菜色，可知经常受掌柜的刻薄。\n");
	set("shen_type", 1);

	set("str", 20);
	set("age", 15);
	set("attitude", "friendly");
	set("combat_exp", 400);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

