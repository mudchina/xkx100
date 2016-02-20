// /NPC lisao.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("李嫂", ({ "li sao", "li", "sao" }));
	set("long",
		"她是 [灵鹫宫] 的厨师。\n");
	set("title", "灵鹫宫厨师");
	set("gender", "女性");
	set("class", "dancer");
	set("age", 30);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("per", 25);
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("qi", 800);
	set("max_qi", 800);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);

	set("combat_exp", 100000);
	set("score", 10000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
	set_skill("zhemei-shou",80);
	set_skill("liuyang-zhang",80);
	set_skill("yueying-wubu",80);
	set_skill("bahuang-gong", 70);
	map_skill("force", "bahuang-gong");
	map_skill("dodge", "yueying-wubu");
	map_skill("strike","liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand", "zhemei-shou");

	create_family("灵鹫宫",3,"弟子");
	setup();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/lingjiu/obj/doupeng")->wear();
	add_money("silver",10);
}

