// cheng.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC;

string ask_pai();
void create()
{
	set_name("成自学",({"cheng zixue","cheng"}));
	set("gender", "男性");
	set("age", 40);
	set("long", "成自学是雪山派掌门人威德先生白自在的师弟。\n");
	set("attitude", "peaceful");

	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("qi", 2000);
	set("max_qi", 2000);
	set("jiali", 50);

	set("combat_exp", 1000000);
	set("inquiry", ([
		"玉牌"   : (:ask_pai:),
		"寒玉牌" : (:ask_pai:),
		"白自在" : "要见老爷子，就必须要有玉牌才进得去。玉牌就在我这。",
		"老爷子" : "要见老爷子，就必须要有玉牌才进得去。玉牌就在我这。",
	]) );
	set("shen_type", 0);
	set("score", 50000);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );

	set_skill("strike", 180);
	set_skill("sword", 180);
	set_skill("force", 180);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("literate", 180);

	set_skill("xueshan-sword", 180);
	set_skill("bingxue-xinfa", 180);
	set_skill("snow-strike", 180);
	set_skill("snowstep", 180);

	map_skill("sword", "xueshan-sword");
	map_skill("parry", "xueshan-sword");
	map_skill("force", "bingxue-xinfa");
	map_skill("strike", "snow-strike");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");

	create_family("凌霄城", 5, "弟子");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object(CLOTH_DIR+"bai")->wear();
}

string ask_pai()
{
	object me,ob;
	me=this_player(); 

	if(me->query("family/master_id")=="bai zizai")
	{
		command("say 城主有命，老夫岂敢不从。\n");
		message_vision(HIY"成自学拿出一块玉牌，交给$N \n\n"NOR,me);
		ob=new("/d/lingxiao/obj/yupai");
		ob->move(me);
		return "城主慢走。\n";
	}
	if(me->query("family/master_id")=="bai wanjian")
	{
		command("say 你既然是白万剑的弟子，拿去也无妨。");
		message_vision(HIY"成自学拿出一块玉牌，交给$N \n\n"NOR,me);
		ob=new("/d/lingxiao/obj/yupai");
		ob->move(me);
		return "此牌乃本派重宝，不可有失。\n";
	}
	command("say 你是什么身份，也想去见老爷子？");
	message_vision(HIY"成自学转过脸去，理都不理$N。\n\n"NOR,me);

	return "你还是先去努力练练吧。\n";
}
void attempt_apprentice(object ob)
{
	command("say 我是不收徒的，你去找我那些徒弟吧。");
}

