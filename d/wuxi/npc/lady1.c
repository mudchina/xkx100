// lady1.c

inherit NPC;

void create()
{
	set_name("江南少女",({ "girl" }) );
	set("gender", "女性" );
	set("age", 16);
	set("long", 
"这是个十六、七岁的江南少女，清丽如水，温婉依人。\n");
	set_temp("apply/defense", 5);
	set("combat_exp", 500);
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

