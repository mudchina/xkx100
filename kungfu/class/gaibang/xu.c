// xu.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("徐长老", ({"xu zhanglao", "xu", "zhanglao"}));
	set("gender", "男性");
	set("age", 85);
	set("long", "白须飘动，穿着一身补丁累累的鹑衣，是个年纪极高的老丐。\n");

	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	set("no_get", "1");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 900);
	set("max_qi", 900);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);

	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("force", 95);            // 基本内功
	set_skill("huntian-qigong", 90);   // 混天气功
	set_skill("hand", 90);             // 基本手法
	set_skill("suohou-hand", 85);      // 锁喉擒拿手
	set_skill("staff", 90);            // 基本杖法
	set_skill("fengmo-staff", 85);     // 疯魔杖法
	set_skill("dodge", 90);            // 基本躲闪
	set_skill("xiaoyaoyou", 95);       // 逍遥游
	set_skill("parry", 85);            // 基本招架
	set_skill("staff", 90);            // 基本棍杖
	set_skill("strike",85);  // 基本掌法
	set_skill("lianhua-zhang",85); // 莲花掌
	set_skill("xianglong-zhang",85);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");
	
	map_skill("force", "huntian-qigong");
	map_skill("staff", "fengmo-staff");
	map_skill("parry", "fengmo-staff");
	map_skill("hand", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("hand", "suohou-hand");

	set("party/party_name", HIC"丐帮"NOR);
	set("party/rank", RED"九袋长老"NOR);
	set("party/level", 9);
	create_family("丐帮", 8, "弟子");

	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(WEAPON_DIR"gangzhang")->wield();
}

#include "/kungfu/class/gaibang/gaibang.h"
