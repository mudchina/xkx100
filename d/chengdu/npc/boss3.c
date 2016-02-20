// Room: /d/chengdu/npc/boss3.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;
inherit F_BANKER;

void create()
{
	set_name("马有财", ({"ma youcai", "ma", "youcai"}));
	set("title", "钱庄老板");
	set("nickname", "三只眼");
	set("gender", "男性");
	set("age", 45);
	set("str", 22);
	set("int", 24);
	set("dex", 18);
	set("con", 18);
	set("qi", 500);
	set("max_qi", 500);
	set("jing", 100);
	set("max_jing", 100);
	set("shen", 0);

	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);
	setup();
	add_money("gold", 5);
}

void init()
{
	add_action("do_check", "check");
	add_action("do_check", "chazhang");
	add_action("do_convert", "convert");
	add_action("do_convert", "duihuan");
	add_action("do_deposit", "deposit");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "qu");
	delete_temp("busy");
}

