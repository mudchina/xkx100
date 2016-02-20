// Last Modified by winder on Feb. 28 2001
// yangguo.c 杨过

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
string ask_me();

void create()
{
	set_name("杨过", ({"yang guo", "yang", "guo"}));
	set("nickname", HIB"神雕大侠"NOR);
	set("gender", "男性");
	set("age", 26);
	set("long",
	"他就是神雕大侠杨过，一张清癯俊秀的脸孔，剑眉入鬓，凤眼生威。\n"
	"虽然他只有一只胳膊，但是魁伟的身材仍让人感觉英气逼人。\n");
	set("attitude", "friendly");

	set("per", 28);
	set("str", 30);
	set("int", 37);
	set("con", 36);
	set("dex", 38);
	set("chat_chance", 1);
	set("chat_msg", ({
		"杨过叹了口气道：“不知龙儿现在可好？十六年了，她一直在哪里？”\n", 
		"杨过喃喃道：“独孤求败！独孤求败！求一败而不可得？”\n", 
	}));
	set("chat_chance_combat",50);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.anran" :),
		(: command("wield jian") :),
		(: command("unwield jian") :),
	}));

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1600);
	set("max_jing", 1600);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 0);

	set_skill("force", 200);
	set_skill("yunv-xinfa", 200);
	set_skill("sword", 200);
	set_skill("yunv-jian", 200);
	set_skill("quanzhen-jian",200);
	set_skill("dodge", 200);
	set_skill("anran-zhang",220);
	set_skill("yunv-shenfa", 200);
	set_skill("parry", 200);
	set_skill("unarmed",200);
	set_skill("meinv-quan", 200);
	set_skill("literate",120);
	set_skill("qufeng",120);
	set_skill("tanzhi-shentong",200);
	set_skill("iron-sword",200);
	map_skill("force", "yunv-xinfa");
	map_skill("sword", "iron-sword");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "anran-zhang");

	create_family("古墓派", 4, "弟子");
	set("letter_count", 1);

	set("inquiry", ([
		"龙儿"     :(: ask_me :),
		"小龙女"   :"你知道我龙儿的下落？\n",
		"玉女剑法" :"玉女剑法和全真剑法合壁，天下无敌！\n",
		"古墓派"   :"我的林祖师爷爷本来和重阳先师是一对璧人，可是...\n",
		"郭靖"     :"我郭伯父是当世一代大侠。\n",
		"黄蓉"     :"我郭伯母确实是算无遗策。\n",
		"雕兄"     :"雕兄既是我师，亦复我友。\n",
		"神雕"     :"你问雕兄？\n",
		"玄铁剑"   :"玄铁剑在独孤剑冢。\n",
		"独孤剑冢" :"独孤剑冢嘛，自己找吧。\n",
	]) );
	set("env/wimpy", 40);
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/male-cloth")->wear();
}
void init()
{
	add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	mapping myfam;
	myfam = (mapping)ob->query("family");
	if ( myfam["family_name"] != "古墓派") return;
	if ((int)ob->query_temp("marks/小龙女") == 1 )
	{
		if (ob->query_int() < 40)
		{
			message_vision("杨过看了看$N说道：看你笨头笨脑的，还是先去读点书吧。\n", ob);
			return;
		}
		if (ob->query_skill("yunv-xinfa",1) < 150)
		{
			message_vision("杨过看了看$N说道：你的本门心法还差点火候，再努力一把吧。\n", ob);
			return;
		}
		if (ob->query_skill("yunv-jian",1) < 150)
		{
			message_vision("杨过看了看$N说道：你的本门剑法还差点火候，再努力一把吧。\n", ob);
			return;
		}
		if (ob->query_skill("quanzhen-jian",1) < 150)
		{
			message_vision("杨过看了看$N说道：你的全真剑法还差点火候，再努力一把吧。\n", ob);
			return;
		}
//message_vision("杨过叹了口气，看看$N，说道：你没找到我的龙儿么？\n", ob);
		command("say 好吧，我就收下你这个徒弟了。\n");
		command("recruit " + ob->query("id"));
		return;
	}
	else
	{
		message_vision("杨过叹了口气，看看$N，说道：你没找到我的龙儿么？\n", ob);
		return;
	}
}

int accept_object(object me, object ob)
{
	object obn;
	if ( (string) ob->query("id") =="junzi jian" )
	{
		message_vision("杨过说道：这位"+ RANK_D->query_respect(me)+"，我实在高兴你带来我的龙儿的信物，她现在好吗？\n",me);
		if(query("letter_count") > 0)
		{
			message_vision("杨过又对$N说道：麻烦你帮我把信交给她，告诉她我等她等了十六年了，带她来我这里。\n" , me);
			obn=new("/d/gumu/npc/obj/letter");
			obn->move(me);
			add("letter_count", -1);
		}
		return 1;
	}
	return 0;
}

string ask_me()
{
	object me=this_player();
	if(present("junzi jian",this_object()))
		return "多谢你的关心啦，我已经有龙儿的消息了。\n";
	else
	{
		me->set_temp("mark/杨",1);
		return "你有龙儿的消息吗？\n";
	}	
}

