// yu-hx.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("余洪兴", ({"yu hongxing", "yu", "hongxing"}));
	set("gender", "男性");
	set("nickname", "小吴用");
	set("age", 30);
	set("long", 
		"这是位笑眯眯的丐帮七袋弟子，生性多智，外号小吴用。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
	set("beggarlvl", 7);
	set("str", 20);
	set("int", 30);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 420);
	set("max_jing", 330);
	set("neili", 780);
	set("max_neili", 780);
	set("jiali", 42);
	
	set("combat_exp", 82000);
	
	set_skill("force", 78); 
	set_skill("huntian-qigong", 76); 
	set_skill("hand", 78); 
	set_skill("suohou-hand", 80); 
	set_skill("blade", 78); 
	set_skill("liuhe-blade", 80); 
	set_skill("dodge", 70); 
	set_skill("xiaoyaoyou", 82); 
	set_skill("parry", 81); 
	set_skill("begging", 80); 
	set_skill("stealing", 90); 
	set_skill("checking", 70); 
	set_skill("strike",70);
	
	set_skill("lianhua-zhang",70);
	set_skill("shicheng-liulong",70);
	map_skill("strike","shicheng-liulong");
	prepare_skill("strike", "shicheng-liulong");
	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "liuhe-blade");
	map_skill("dodge", "xiaoyaoyou");
	
	set("party/party_name", HIC"丐帮"NOR);
	set("party/rank", GRN"七袋弟子"NOR);
	set("party/level", 7);
	create_family("丐帮", 19, "弟子");

	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(WEAPON_DIR"gangdao")->wield();
}

void attempt_apprentice(object ob)
{
	if( ob->query("int") < 25 ) return;
	command("say 唉，本帮诚信为本，只有七公他老人家和我才特别收些聪明徒儿，");
	command("say 大家都要为长远着想啊！");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
