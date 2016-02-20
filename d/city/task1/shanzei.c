// shanzei.c 山贼
inherit NPC;
 
void create()
{
	set_name("山贼", ({ "shan  zei"}));
//	set("nickname", "");
	set("long", 
	"一个专门打家劫舍的山贼。\n"
	"一幅贼眉鼠眼的样子。\n");
	set("gender", "男性");
	set("age", random(10) + 25);
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1500);
	set("max_jing", 800);
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 50);
	set("combat_exp", 100000 + random(40000)); 
/*	set_skill("force", 60);
	set_skill("xuantian-wuji", 70);
	set_skill("dodge", 80);
	set_skill("kunlun-shenfa", 120 + random(50));
	set_skill("strike", 80 + random(50));
	set_skill("parry", 80 + random(50));
	set_skill("kunlun-strike", 120 + random(50));
	set_skill("literate", 20);
	set_skill("sword",80 + random(50));
	set_skill("changge-jian",120 + random(50));*/
	set_skill("force", 60);
	set_skill("xuantian-wuji", 70);
	set_skill("dodge", 80);
	set_skill("kunlun-shenfa", 75 + random(50));
	set_skill("strike", 80 + random(50));
	set_skill("parry", 80 + random(50));
	set_skill("kunlun-strike", 75 + random(50));
	set_skill("literate", 20);
	set_skill("sword",80 + random(50));
	set_skill("changge-jian",75 + random(50));
	map_skill("sword","changge-jian");
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "kunlun-shenfa");
	map_skill("strike", "kunlun-strike");
  	map_skill("parry", "kunlun-strike");
  	prepare_skill("strike", "kunlun-strike");
 
	setup(); 
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
  	add_money("silver", 50);
}
#include "npc.h"
