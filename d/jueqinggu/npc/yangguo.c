// yangguo.c 杨过
// Last Modified by winder on Mar. 8 2001

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
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
	map_skill("force", "yunv-xinfa");
	map_skill("sword", "yunv-jian");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "anran-zhang");

	create_family("古墓派", 4, "弟子");
	set("letter_count", 1);

	set("inquiry", ([
		"小龙女"   :  "你也在找我的龙儿？\n",
		"玉女剑法" : "玉女剑法和全真剑法合壁，天下无敌！\n",
		"古墓派"   : "我的林祖师爷爷本来和重阳先师是一对璧人，可是..\n",
		"郭靖"     : "我郭伯父是当世一代大侠。\n",
		"黄蓉"     : "我郭伯母确实是算无遗策。\n",
		"雕兄"     : "雕兄既是我师，亦复我友。\n",
		"神雕"     : "你问雕兄？\n",
		"玄铁剑"   : "玄铁剑在高昌古城。\n",
		"独孤剑冢" : "独孤剑冢嘛，自己找吧。\n",
		"dan"      : (: ask_me :),
		"回春丹"   : (: ask_me :),
	]) );
	set("env/wimpy", 40);
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
	carry_object("/kungfu/class/gumu/obj/junzijian");
}

string ask_me()
{
	object ob;
	string wan_num;
	int wannum;

	wan_num = read_file("/data/HUICHUN", 1, 1);
	wannum = atoi(wan_num);
	if (wannum == 0)
		return "这位"+RANK_D->query_respect(this_player())+"，回春丹需经一年养炼，方克有成。你再等"RED+ chinese_number(12-(int)(uptime()/7200))+CYN"个月再来吧！\n";
	if (wannum == 2)
		return "这位"+RANK_D->query_respect(this_player())+"，回春丹早给别人拿走了。你以后再来吧！\n";
	ob = new("/clone/medicine/nostrum/huichundan");
	ob->move(this_player());
	write_file("/data/HUICHUN", "2", 1);
	command("rumor "+this_player()->query("name")+"拿到回春丹了啦。\n");
	return "好吧，不给你尝尝回春丹，你也不知道它的味道吧。";
}

