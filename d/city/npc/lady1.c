// lady1.c

inherit NPC;

void create()
{
	set_name("踏青少女",({ "girl" }) );
	set("gender", "女性" );
	set("age", 16);
	set("long", 
"这是个十六、七岁的扬州踏青少女，清丽绝俗，一脸天真的颜色。\n");
	set_temp("apply/defense", 5);
	set("combat_exp", 200);
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

