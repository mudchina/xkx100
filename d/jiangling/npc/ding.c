//Edited by fandog, 01/31/2000

inherit NPC;
#include <ansi.h>

int ask_skill1();
int ask_skill2();
void create ()
{
	set_name("丁典", ({"ding dian","ding","dian"}));
	set("long", "
这人满脸虬髯，头发长长的直垂至颈，衣衫破烂不堪，简直如同荒山中
的野人。手上手铐，足上足镣，琵琶骨中穿着两条铁链。他脸上、臂上、
腿上，都是酷遭鞭打的血痕。\n");
	set("gender", "男性");
	set("age", 30);
	set("combat_exp", 5000000);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 28);
	set("per", 24);

	set_skill("force", 200);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("yanfly", 200);
	set_skill("shenzhao-jing", 300);
	map_skill("force", "shenzhao-jing");
	map_skill("parry", "shenzhao-jing");
	map_skill("unarmed", "shenzhao-jing");
	map_skill("dodge", "yanfly");
	set("chat_chance", 10);
	set("chat_msg", ({
"丁典轻轻叹了一口气。那叹息中，竟有忧伤、温柔之意。\n",
"丁典嘴角挂着一丝微笑，痴望远处高楼纱窗上那一盆鲜花。\n",
"丁典大声道：怎么会忘记？决不会的！难道……难道是生了病？\n",
"丁典喃喃道：就算是生了病，也会叫人来换花啊！\n",
}) );
	set("inquiry", ([
		"凌霜华" : "“唉……”，然后指了指牢外那座小楼的窗口，啥也不说了。\n",
		"唤醒"   : (: ask_skill1 :),
		"疗精"   : (: ask_skill2 :),
	]));

	setup();
	carry_object("/d/jiangling/obj/qiuyi")->wear();
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/丁"))
		return 0;
	ob->add_temp("mark/丁", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	object me = this_player();
	if (!(int)who->query_temp("mark/丁"))
		who->set_temp("mark/丁", 0);
	if (ob->query("id") == "green flower")
	{
		message_vision("看来$N有望得到丁典指点一些武功的问题。\n",who);
		who->add_temp("mark/丁", 1000);
		return 1;
	}
}

int ask_skill1()
{
	object ob = this_object();
	object who = this_player();
	
	if (!who->query_temp("mark/丁")) return 0;
	if (!who->query_skill("shenzhao-jing",1)) return 0;
	if (who->query("can_perform/shenzhao-jing/wakeup")) return 0;
	if (who->query_skill("shenzhao-jing",1) < 100)
	{
		command("say 你的神照经功力还不够高，多学学吧。");
		return 1;
	}
	command("sign");
	command("say 不知你学得神照经是福是祸了。也罢，随你去吧。");
	tell_object(who,HIC"丁典在你耳边悄悄说了几句运功的口诀，你急忙用心一一记下。\n"NOR);
	tell_object(who,HIC "你学会了「唤醒」。\n" NOR);
	who->set("can_perform/shenzhao-jing/wakeup",1);
	return 1;
}
int ask_skill2()
{
	object ob = this_object();
	object who = this_player();
	
	if (!who->query_temp("mark/丁")) return 0;
	if (!who->query_skill("shenzhao-jing",1)) return 0;
	if (who->query("can_perform/shenzhao-jing/jingheal")) return 0;
	if (who->query_skill("shenzhao-jing",1) < 50)
	{
		command("say 你的神照经功力还不够高，多学学吧。");
		return 1;
	}
	command("sign");
	command("say 不知你学得神照经是福是祸了。也罢，随你去吧。");
	tell_object(who,HIC"丁典在你耳边悄悄说了几句运功的口诀，你急忙用心一一记下。\n"NOR);
	tell_object(who,HIC "你学会了「疗精」。\n" NOR);
	who->set("can_perform/shenzhao-jing/jingheal",1);
	return 1;
}
