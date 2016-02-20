// Npc: /gan.c
// Date: Oct.18 1999 by Winder

inherit NPC;
string ask_me();
void create()
{
	set_name("干光豪", ({ "gan guanghao", "gan", "guanghao"}));
	set("gender", "男性");
	set("attitude", "friendly");

	set("age", 20);
	set("shen_type", -1);
	set("per", 20);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 550);
	set("max_neili", 550);
	set("jiali", 40);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("changquan", 40);
	set_skill("parry", 40);
	set_skill("damo-jian", 40);
	set_skill("sword", 40);

	map_skill("unarmed", "changquan");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");
	set("inquiry", ([
		"葛光佩"    : (: ask_me :),
		"狗男女"    : (: ask_me :),
		"奸夫淫妇"  : (: ask_me :),
		"忘八"      : (: ask_me :),
		"无量玉壁"  : "那是本派禁地，任何外人不得擅入。干犯禁忌，可叫你死葬身之地。",
	]));

	create_family("无量剑东宗", 5, "弟子");
	setup();

        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

string ask_me()
{
	this_player()->set_temp("marks/wuliang", 1);
	return "既然被你撞破了我们的好事，也不用我们动手，自己到悬崖了断吧。";
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        tell_object(ob,
"\n干光豪道：“你依了我，若是我日后负心，就掉在这水里，变个大忘八。”
葛光佩格格娇笑，腻声道：“你做忘八，可不是骂我不规矩吗？”\n");
}

