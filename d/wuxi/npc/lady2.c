// lady1.c

inherit NPC;

void create()
{
	set_name("风雨少女",({ "girl" }) );
	set("gender", "女性" );
	set("age", 16);
	set("long", 
"这是个十六、七岁风华正茂的少女，山样清丽，水样温柔。\n");
	set_temp("apply/defense", 5);
	set("combat_exp", 400);
//	set("shen", 100);
	set("shen_type", 1);
	set("str", 14);
	set("per", 28);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/cloth/female-cloth")->wear();
}

