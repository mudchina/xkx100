// monk.c

inherit NPC;
void create()
{
	set_name("空光", ({ "shaolin monk", "monk"}) );
	set("gender", "男性" );
	set("age",random(10)+ 32);
	set("long", "这是少林寺出外化斋的和尚。\n");
	set("combat_exp", random(10000)+10000);
	set("attitude", "friendly");
	set("chat_chance", 20);
	set("chat_msg", ({
		"空光唱了个肥诺道：“施主捐点香火钱吧！”\n",
	}) );
	set_skill("unarmed", 5+random(40));
	set_skill("dodge",40);
	set_skill("force",20);
	set("force",100);
	set("max_neili",100);
	create_family("少林寺", 41, "弟子");
	setup();
	carry_object(CLOTH_DIR"sengpao")->wear();
	carry_object(__DIR__"obj/bowl");
}

int accept_object(object me, object obj)
{
	command("sigh");
	command("say 日子难过呀！\n");
	command("say 寺内的藏经楼总是丢书，方丈现在动不动就责罚弟子面壁十年！\n");
	command("thank " + me->query("id"));
	return 1;
}
