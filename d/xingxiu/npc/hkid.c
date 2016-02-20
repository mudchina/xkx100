// Room: /d/xingxiu/npc/hkid.c
// Last Modified by Winder on Apr. 25 2001

inherit NPC;

void create()
{
	set_name("牧童", ({ "mutong", "kid"}));
	set("gender", "男性");
	set("age", 8 + random(5));
	set("long", "一个牧童，赶着十几只羊。\n");
	set("attitude", "friendly");
	set("env/wimpy", 60);
	set("combat_exp", 200);

	set_skill("unarmed", 5);
	set_skill("dodge", 5);
	set_skill("parry", 5);
	set_skill("whip", 5);

	set_temp("apply/attack", 5);
	set_temp("apply/defense", 5);
	
	setup();
	set("chat_chance", 2);
	set("chat_msg", ({
	      "牧童悲愤地嚷道：那帮星宿派弟子昨天拉走了我双亲。\n",
	      "牧童对天发誓：我大了一定要报仇。\n",
	}));
}

