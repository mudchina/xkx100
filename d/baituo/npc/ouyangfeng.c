// /kungfu/class/baituo/ouyangfeng.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

int ask_help();
int do_accept();

void create()
{
	set_name("欧阳锋", ({ "ouyang", "feng" }));
	set("long", "他是白驼山庄主，号称“西毒”的欧阳锋。\n"
		   +"由于习练「九阴真经」走火入魔，已变得精\n"
		   +"神错乱，整日披头散发。\n");
	set("title", "白驼山庄主");
	set("gender", "男性");
	set("age", 53);
	set("nickname", HIR "西毒" NOR);
	set("shen_type",-1);
	set("shen", -150000);
	set("attitude", "peaceful");

	set("str", 30);
	set("int", 29);
	set("con", 30);
	set("dex", 28);

	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 900);
	set("max_jing", 900);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);

	set("combat_exp", 1500000);
	set("score", 200000);

	set_skill("force", 200);
	set_skill("unarmed", 170);
	set_skill("dodge", 200);
	set_skill("parry", 180);
	set_skill("hand",170);
	set_skill("training",200);
	set_skill("staff", 200);
	set_skill("hamagong", 200);
	set_skill("chanchu-bufa", 170);
	set_skill("shexing-diaoshou", 200);
	set_skill("lingshe-zhangfa", 180);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");

	create_family("白驼山派",1, "开山祖师");
	set("chat_chance",2);
	set("chat_msg",({
		"欧阳锋自言自语道：何日白驼山派才能重霸江湖呢…\n",
		"欧阳锋道：我儿欧阳克必能够重振白驼山派雄风！\n",
		"欧阳锋道：江湖险恶，困难重重哪！\n",
	}));
	setup();
	carry_object("/d/baituo/obj/shezhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",50);
}

void init()
{
}

void attempt_apprentice(object ob)
{
	message_vision("欧阳锋瞪了$N一眼道：“我白驼山不世艺业岂可轻传。”\n", ob); 	
}


