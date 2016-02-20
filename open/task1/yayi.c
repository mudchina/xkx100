// yayi.c  官府衙役

inherit NPC;

void create()
{
	set_name("衙役", ({ "ya yi", "ya" }));
	set("gender", "男性");
	set("age", 25);
	set("long","一个高大威猛的汉子，因为久在官府做事，脸上已经磨炼得毫无表情。\n");
	set("combat_exp", 7500);
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set("inquiry", ([
		"工作" : "那还不简单？你只要有胆量把文书揭下来(jie wenshu)，然后把目标杀了就可以。",
	]) );
	set("chat_chance", 20);
	set("chat_msg", ({
		"衙役小声嘀咕道：“常听人说武林之中藏龙卧虎，也不知道是真是假？”\n",
		"衙役朗声说道：“各路英雄，本城目前悬赏捉拿江洋大盗，望各位能协助官府，惩治凶徒。”\n",
	}) );
	setup();
	carry_object("/d/city/npc/obj/yayifu")->wear();
}
