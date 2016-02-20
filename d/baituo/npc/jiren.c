// jiren.c 
// Last Modified by Winder on May. 15 2001

inherit NPC;

void create()
{
	set_name("白衣姬人", ({ "white jiren", "jiren", "white" }) );
	set("gender", "女性" );
	set("age", 18);
	set("long", "
一个身披白袍、颈围貂裘、体态婀娜、笑容冶艳的西域美貌少女，
肤色白晰，身材高大，金发碧眼，果然和中土女子大不相同。但容
貌艳丽，姿态妖媚，亦自动人。\n");
	set("shen_type", -1);
	set("combat_exp", 1000);
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
	set("attitude", "friendly");
	set("max_qi", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("score", 800);

	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("cuff", 30);
	set_skill("staff", 30);
	set_skill("hamaquan", 30);
	set_skill("hamagong", 30);
	set_skill("chanchu-bufa", 30);
	set_skill("lingshe-zhangfa", 30);
	map_skill("force", "hamagong");
	map_skill("cuff", "hamaquan");
	map_skill("dodge", "chanchu-bufa");
	map_skill("parry", "hamaquan");
	prepare_skill("cuff", "hamaquan");
	create_family("白驼山派", 3, "弟子");
	setup();
	carry_object("/d/baituo/obj/baipao")->wear();
	carry_object("/d/baituo/obj/diaoqiu")->wear();
}
