// gaoshengtai.c 高升泰

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void upgrade_title(object me,string arg);
string clear_title(string arg);
int ask_me();
void create()
{
	set_name("高升泰", ({ "gao shengtai", "gao" }));
	set("title",  "大理善阐侯" );
	set("long", "大理国侯爷，这是位宽袍大袖的中年男子，三缕长髯，形貌高雅。\n");
	set("gender", "男性");
	set("age", 33);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 25);
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 25);
	set("env/wimpy", 60);	
	
	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 80);
	set("combat_exp", 800000);
	set("score", 150000);

	set_skill("force", 110);
	set_skill("dodge", 110);
	set_skill("parry", 100);
	set_skill("cuff", 110);
	set_skill("strike", 110);
	set_skill("sword", 120);
	set_skill("staff", 120);
	set_skill("kurong-changong", 110);
	set_skill("tiannan-step", 160);
	set_skill("jinyu-quan", 150);
	set_skill("wuluo-zhang", 150);
	set_skill("duanjia-sword", 180);
	set_skill("literate", 60);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jingtian" :),				
		(: exert_function, "powerup" :),		
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );


	set("inquiry", ([
		"指点武功" : (: ask_me :),
	]));
	setup();
	carry_object(__DIR__"obj/magcloth")->wear();
	carry_object(__DIR__"obj/tiedi")->wield();
	add_money("silver", 20);

	create_family("大理段家",19,"武将");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("kurong-changong",1) < 30 )
	{
		command("say 你的本门内功心法太低了，还是努努力先提高一下吧。");
		return;
	}
	if ((int)ob->query("shen") < 10000  )
	{
		command("say 我大理段氏向来行侠仗义，您请回吧！");
		return;
	}
	if (strsrch(ob->query("guard"), "镇南王府") >= 0) 
	{
		command("say 很好，既然入我门来就得终身为奴供我驱使。");
		command("recruit " + ob->query("id"));
	}
	else
	{
		command("say 你是何人，如此大胆，假冒我府中厮仆！");
		return;
	}
}
 
int ask_me()
{
	object ob, me;
	me = this_object();
	ob = this_player();
	if ((int)ob->query_skill("kurong-changong",1) < 80)
	{
		command("say 你的武功恐怕是不能胜任武将的薪俸，再练几年功夫吧。\n");
		return 1;
	}
	if (ob->query("guard") == "镇南王府卫士")
	{
		ob->set_temp("fight_ok",1);
		command("say 好，既然如此想切磋，那就看你的本事如何了。\n");
		return 1;
	}
	else
	{
		command("say 只有卫士才能升武将。\n");
		return 1;
	}
}

int accept_fight(object ob)
{
        object me  = this_object();
        if ( !ob->query_temp("fight_ok") ) return 0;

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        ob->delete_temp("fight_ok");
        return 1;
}

int checking(object me, object ob)
{
	object obj;
	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting()) 
	{
		call_out("checking",2, me, ob);
		return 1;
	}

	if ( !present(ob, environment()) ) return 1; 

	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
	{
		command("say 青出於蓝胜於蓝，不愧是大理段家的好弟子！恭喜你了！\n");
		command("say 你的已经可以胜任大理武将！\n");
		upgrade_title(ob, "镇南王府武将");
		return 1;
	}
	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
	{
		command("say 看来" + RANK_D->query_respect(ob) + 
			"还得多加练习，方能在大理段家诸多弟子中出人头地！\n");
		return 1;
	}
	return 1;  
}
void upgrade_title(object ob,string arg)
{
//	string title;
//	title=arg+clear_title(ob->query("title"));
	ob->set("guard", arg);
}
/*
string clear_title(string arg)
{
	if (strsrch(arg, "大理镇南王府卫士") >= 0)
	{
		arg = replace_string(arg, "大理镇南王府卫士","");
	}
	return arg;
}
*/
