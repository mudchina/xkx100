//Edited by fandog, 02/15/2000
inherit NPC;

string ask_me();

void create()
{
	set_name("厨娘", ({ "chu niang", "chu" }));
	set("title", "知府衙门");
	set("long",
		"知府衙门的厨娘，笑眯眯地看着你，看来很和善的样子。\n");
	set("gender", "女性");
	set("age", 34);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("dex", 28);

	set("max_qi", 200);
	set("max_jing", 50);
	set("neili", 0);
	set("max_neili", 0);
	set("jiali", 0);
	set("combat_exp", 500);
	set("shen",0);
	set("score", 0);
	set("no_get",1);
	set_skill("force", 10);
	set_skill("dodge", 10);
	set_skill("cuff", 10);
	set_skill("parry", 10);

	set("inquiry", ([
		"吃饭" : (: ask_me :),
	]));
	setup();
}

string ask_me()
{
	mapping fam, skl;
	object ob;
	string *sname;
	int i;

	object me=this_player();
	me->set("food", (int)me->max_food_capacity());
	me->set("water", (int)me->max_water_capacity());
	return "慢慢吃！别噎住了。";
}

