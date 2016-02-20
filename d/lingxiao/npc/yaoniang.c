// Npc: /d/lingxiao/npc/yaoniang.c
// Last Modified by winder on Jul. 15 2001

inherit NPC;

void create()
{
	set_name("窈娘", ({ "yao niang", "yao" }) );
	set("gender", "女性" ); 
	set("long", "窈娘是白自在的妾侍，很得白自在宠信。\n");
	set("title", "白自在妾侍");
	set("age", 17);
	set("per", 30);
	set("str", 16);
	set("age", 30);
	set("con", 24);
	set("dex", 30);
	set("int", 27);

	set("attitude", "friendly");
	set("inquiry", ([
		"白自在" : "老爷子不知为什么，把自己关到监狱里，说思什么过。",
		"监狱"   : "没少爷同意，你是进不去的。",
	]) );

	set("max_qi",800);
	set("max_jing",500);
	set("combat_exp", 10000);
	setup();
	carry_object(CLOTH_DIR+"bai")->wear();
}

