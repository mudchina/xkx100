// wuzhirong.c
inherit NPC;

void create()
{
	set_name("吴之荣", ({ "wu zhi rong", "wu" ,"rong"}) );
	set("gender", "男性" );
	set("age", 40);
	set("int", 28);
	set("long",
		"他原是归安县的知县，因贪赃枉法，百姓恨之切齿，终被告发革职。\n"
               +"他长得尖嘴猴腮，一看就知不是好人 。\n");
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 5000);
	set("score", 5000);
        set_skill("literate", 100);

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object("/d/beijing/obj/goldleaf");
}
