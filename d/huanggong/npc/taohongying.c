// taohongying.c
inherit NPC;

void create()
{
	set_name("陶红英", ({ "tao hongying", "tao", "hongying"}) );
	set("gender", "女性" );
	set("age", 41);
	set("long", "她是前明长公主留在宫里的贴身宫女. \n");
	set("shen_type", 1);
	set("combat_exp", 200000);
	set("per", 25);
	set("str", 25);
	set("dex", 25);
	set("con", 25);
	set("int", 25);
	set("attitude", "friendly");
	set("score", 1000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("whip", 150);
	set_skill("force", 90);
	set_skill("unarmed", 90);
	set_skill("dodge", 150);
	set_skill("parry", 90);
	set_skill("qiufeng-chenfa", 150);
	set_skill("shenxing-baibian", 150);
	map_skill("whip", "qiufeng-chenfa");
	map_skill("parry", "qiufeng-chenfa");
	map_skill("dodge", "shenxing-baibian");

	set_temp("apply/armor", 40);
	set_temp("apply/damage", 100);
	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 100);
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changbian")->wield();
}

