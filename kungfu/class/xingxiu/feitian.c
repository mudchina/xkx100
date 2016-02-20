// Room: /d/xingxiu/npc/feitian.c
// Last Modified by winder on Apr. 25 2001

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("飞天子", ({ "feitian zi", "feitian", "zi" }) );
	set("gender", "男性" );
	set("nickname", "星宿派七弟子");
	set("age", 28);
	set("long", 
"他绰号飞天，轻功的造诣已经到了很高的地步。\n");
	set("env/wimpy", 40);
	set("str", 20);
	set("dex", 30);
	set("con", 19);
	set("int", 15);
	set("shen", -1400);
	create_family("星宿派", 2, "弟子");

	set_skill("huagong-dafa", 40);
	set_skill("strike", 30);
	set_skill("chousui-zhang", 30);
	set_skill("force", 40);
	set_skill("dodge", 50);
	set_skill("zhaixinggong", 60);
	map_skill("dodge","zhaixinggong");
	map_skill("force","huagong-dafa");
	map_skill("strike","chousui-zhang");
	map_skill("parry","chousui-zhang");
	prepare_skill("strike", "chousui-zhang");

	set("combat_exp", 80000);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("attitude", "peaceful");
	setup();
	carry_object("/clone/cloth/dao-cloth")->wear();
	add_money("silver", 10);
}
void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object me)
{
	mapping myfam = (mapping)me->query("family");
	if(myfam && myfam["family_name"] == "星宿派")
		command("bow " + me->query("id"));
	else if(me->query("combat_exp") < 100000)
		command("hmm " + me->query("id"));
		else command("hi " + me->query("id"));
}
void attempt_apprentice(object ob)
{
	command("hehe");
	command("say 我可没功夫来教你。");
	return;
}

