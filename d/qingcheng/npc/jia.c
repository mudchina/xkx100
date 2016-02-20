// jia.c 

inherit NPC;
//inherit F_SKILL;

void create()
{
	set_name("贾人达", ({ "jia renda", "jia", "renda" }));
	set("gender", "男性");
	set("age", 25);
	set("long", "他就是「青城派」中最为同门不齿、最下达的家伙。\n");

	set("combat_exp", 30000);
	set("shen_type", -1);

	set_skill("sword", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("strike", 30);
	set_skill("unarmed", 30);
	set_skill("force", 30);
	set_skill("bixie-sword", 30);
	set_skill("songfeng-jian", 30);
	set_skill("chuanhua", 30);
	set_skill("wuying-leg", 30);
	set_skill("cuixin-strike", 30);
	set_skill("qingming-xuangong", 30);
	map_skill("force", "qingming-xuangong");
	map_skill("unarmed", "wuying-leg");
	map_skill("strike", "cuixin-strike");
	map_skill("dodge", "chuanhua");
	map_skill("parry", "bixie-sword");
	map_skill("sword", "songfeng-jian");
	prepare_skill("unarmed", "wuying-leg");
	prepare_skill("strike", "cuixin-strike");
	create_family("青城派", 6, "弟子");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}
void init()
{
	object ob;

	::init();
	if( interactive(ob=this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if (ob->query("gender")=="女性")
		say("贾人达嬉皮笑脸道：这位花姑娘身材硬是要得。一张脸蛋嘛，
却是钉鞋踏烂泥，翻转石榴皮，格老子好一张大麻皮！\n");
	else say("贾人达白了白眼：格老子的，你这兔儿爷骂谁？\n");
	return;
}
