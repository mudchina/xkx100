// bangzhong.c

#include <ansi.h>
inherit NPC;
string *duo = ({ "ÈÊ", "Òå", "Àñ", "ÖÇ", "ÐÅ", "ÓÂ" });
void create()
{
	int level;
	level = random(7)+1;
	set_name("Ø¤°ï°ïÖÚ", ({"gaibang bangzhong", "bangzhong"}));
	set("gender", "ÄÐÐÔ");
	set("age", 15+level*5);
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 7);
	set("str", 23);
	set("int", 22);
	set("con", 18);
	set("dex", 25);

	set("max_qi", 200*level);
	set("qi", 200*level);
	set("max_jing", 100*level); 
	set("jing", 100*level); 
	set("neili", 150*level); 
	set("max_neili", 150*level); 
	set("jiali", 10*level);
	
	set("combat_exp", 3000 * level * level);
	
	set_skill("force", level*10); 
	set_skill("huntian-qigong", level*10); 
	set_skill("hand", level*10); 
	set_skill("suohou-hand", level*10); 
	set_skill("blade", level*10); 
	set_skill("liuhe-blade", level*10); 
	set_skill("dodge", level*10); 
	set_skill("xiaoyaoyou", level*10); 
	set_skill("parry", 70); 
	set_skill("begging", 70); 
	
	map_skill("force", "huntian-qigong");
	map_skill("blade", "liuhe-blade");
	map_skill("hand", "suohou-hand");
	map_skill("parry", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("hand", "suohou-hand");

	set("party/party_name", HIC"Ø¤°ï"NOR);
	set("party/rank", GRN+"´ó"+duo[random(6)]+"·Ö¶æ"HIY+chinese_number(level)+"´üµÜ×Ó"NOR);
	set("party/level", level);
	create_family("Ø¤°ï", 10+random(5), "µÜ×Ó");

	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(WEAPON_DIR"gangdao")->wield();
}
#include "/kungfu/class/gaibang/gaibang.h"
