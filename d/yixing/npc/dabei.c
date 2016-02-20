// /d/yixing/npc/dabei.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("大悲老人", ({"dabei laoren", "dabei" }));
	set("long", "他是个红面老者，白发拂胸，甚是雄伟。\n");
	set("title", "白鲸岛主");
	set("gender", "男性");
	set("attitude", "friendly");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 500000);

	set_skill("force", 120);
	set_skill("hunyuan-yiqi", 120);
	set_skill("dodge", 120);
	set_skill("shaolin-shenfa", 120);
	set_skill("hand", 120);
	set_skill("claw", 120);
	set_skill("parry", 120);
	set_skill("qianye-shou", 120);
	set_skill("longzhua-gong", 120);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("hand", "qianye-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "longzhua-gong");

	prepare_skill("hand", "qianye-shou");
	prepare_skill("claw", "longzhua-gong");

	setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/book/18niou");
}
