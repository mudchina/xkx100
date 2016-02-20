// guducheng.c 古笃诚

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void upgrade_title(object me,string arg);
string clear_title(string arg);
int ask_me();
void create()
{
	set_name("古笃诚", ({ "gu ducheng", "gu" }));
	set("title",  "大理护卫" );
	set("long", "他是大理国四大护卫之一。\n");
	set("gender", "男性");
	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 20);
	set("con", 25);
	set("dex", 25);
	set("env/wimpy", 60);	
	
	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 300000);
	set("score", 100000);

        set_skill("force", 50);
        set_skill("dodge", 55);
        set_skill("parry", 55);
        set_skill("unarmed", 50);
        set_skill("axe", 50);
        set_skill("staff", 50);
	set_skill("kurong-changong", 50);
        set_skill("tiannan-step", 75);
        set_skill("jinyu-quan", 70);
        set_skill("duanyun-fu", 75);
	set_skill("literate", 35);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("axe", "duanyun-fu");
	map_skill("parry", "duanyun-fu");
	prepare_skill("cuff", "jinyu-quan");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "axe.duan" :),                							
		(: exert_function, "powerup" :),		
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

	set("inquiry", ([
		"指点武功" : (: ask_me :),
	]));
	setup();
	carry_object("/d/dali/npc/obj/junfu")->wear();
	carry_object("/kungfu/class/dali/obj/axe")->wield();
	add_money("silver", 10);

	create_family("大理段家",19,"护卫");
}
#include "/kungfu/class/dali/weishi.h"; 
