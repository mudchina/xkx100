// shusheng.c

inherit NPC;

void create()
{
	set_name("卖画书生", ({ "maihua shusheng", "shusheng" }) );
	set("gender", "男性" );
	set("age", 32);
	set("int", 28);
	set("long", "一个穷魄聊倒的书生，只能靠一手丹青在风景区四周卖卖字画为生，眼中常流出一些无奈的神情。\n");

	set("attitude", "peaceful");
	set_skill("literate", 40);
	setup();
}

