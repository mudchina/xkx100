// hu-wife.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("胡夫人", ({"hu furen", "huren", "wife"}));
	set("gender", "女性");
	set("age", 25);
	set("attitude", "peaceful");
        set("no_get", "1");
	set("str", 25);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 37);
	set("qi", 3000);
	set("max_qi", 3000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 190000);
	set("score", 20000);
	 
	set_skill("force", 110);             // 基本内功
	set_skill("hujia-daofa", 150);       // 胡家刀法	
	set_skill("blade", 120);             // 基本刀法
	set_skill("hunyuan-yiqi", 120);      // 混元一气功
	set_skill("dodge", 120);             // 基本躲闪
	set_skill("shaolin-shenfa", 120);    // 胡家身法
	set_skill("parry", 120);             // 基本招架
		
	map_skill("force", "hunyuan-yiqi");
	map_skill("blade", "hujia-daofa");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "hujia-daofa");
	setup();
	carry_object(CLOTH_DIR"female-cloth")->wear();
}

