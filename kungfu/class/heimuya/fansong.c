// fansong.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("范松", ({"fan song", "fan", "song"}));
	set("nickname", HIW "大力神魔" NOR );
	set("gender", "男性");
	set("age", 42);
	set("shen_type", -1);
	set("long", "他是日月神教前辈长老。\n");
	set("attitude", "peaceful");
	set("env/wimpy", 40);

	set("per", 21);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 3000);
	set("max_qi", 3000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 300);

	set("combat_exp", 1500000);
	set("score", 0);

	set_skill("force", 150);
	set_skill("kuihua-xinfa", 150);
	set_skill("unarmed", 150);
	set_skill("changquan", 150);
	set_skill("dodge", 150);
	set_skill("lingxu-bu", 150);
	set_skill("parry", 150);
	set_skill("axe", 150);
	set_skill("duanyun-fu", 150);

	map_skill("force", "kuihua-xinfa");
	map_skill("axe", "duanyun-fu");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "lingxu-bu");
	map_skill("parry", "duanyun-fu");

	set("inquiry", ([
		"日月神教" : "你想加入我日月神教，就得找四大堂长老。",
		"入教"     : "你想加入我日月神教，就得找四大堂长老。",
	]));

	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIR"前辈长老"NOR);
	create_family("黑木崖", 4, "弟子");

	setup();
	carry_object("/d/heimuya/npc/obj/dafu")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
void attempt_apprentice(object ob)
{
	command("say 老夫向不收徒。\n");
	return;
}

