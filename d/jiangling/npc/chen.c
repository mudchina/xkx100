//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit NPC;
inherit F_BANKER;

void create()
{
	set_name("陈阿发", ({"chen afa", "chen", "afa"}));
	set("title", "钱庄老板");
	set("nickname", HIY"和气生财"NOR);
	set("gender", "男性");
	set("age", 34);
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
	set("chat_chance", 2);
	set("chat_msg", ({
	"陈阿发骄傲的说道：本银号已经有上百年的历史，在武汉可以说是第一家。\n",
	"陈阿发笑着说道：在本店存钱无利息，取钱收十分之一手续费，客官您看着办吧。\n"
	}));
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
