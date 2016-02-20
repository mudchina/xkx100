// qu.c
inherit NPC;
inherit F_UNIQUE;

void greeting(object);
void create()
{
	set_name("曲洋", ({ "qu yang", "qu"}) );
	set("gender", "男性" );
	set("age", 45);
	set("long", "他就是日月神教十大长老之一，琴技天下无双。\n" );
	set("attitude", "friendly");
	set("shen_type", 1);

        set("per", 20);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 29);

	set("max_qi", 1000);
	set("max_jing",1000);
	set("neili", 300);
	set("max_neili", 300);
	set("combat_exp", 350000);
	set("score", 30000);
	set("jiali",50);
	set_skill("force", 140);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("blade",100);
	set_skill("taiji-shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji-dao", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji-dao");
	map_skill("blade", "taiji-dao");
	create_family("日月神教",2,"长老");

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object(__DIR__"obj/blackcloth")->wear();
}
