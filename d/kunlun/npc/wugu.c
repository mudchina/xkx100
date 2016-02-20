// wugu.c
// Last Modified by Winder on Nov. 15 2000

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("五姑", ({ "wu gu", "wugu" }));
	set("long",
"她是何太冲最钟爱的小妾，原本长得倒也仪态万方。
现在一张脸肿得犹如猪八戒一般，双眼深陷肉里，几
乎睁不开来，喘气甚急，像是扯着风箱。\n");
	set("gender", "女性");
	set("age", 24);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 12);
	set("str", 25);
	set("int", 24);
	set("con", 28);
	set("dex", 26);

	set("max_qi", 100);
	set("max_jing", 100);
	set("combat_exp", 500);
	setup();
	carry_object("/clone/cloth/female-cloth")->wear();
}

