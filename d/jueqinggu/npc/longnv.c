// longnv.c 小龙女
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>
inherit F_MASTER;
inherit NPC;
string ask_me();

void create()
{
	set_name("小龙女", ({"long nv", "long"}));
	set("gender", "女性");
	set("age", 18);
	set("long",
	"盈盈而站着一位秀美绝俗的女子，肌肤间少了一层血色，显得苍白异常。\n"
	"披著一袭轻纱般的白衣，犹似身在烟中雾里。\n"
	"当真如风拂玉树，雪裹琼苞，兼之生性清冷，\n"
	"实当得起“冷浸溶溶月”的形容。\n");
	set("attitude", "friendly");

	set("per", 30);
	set("str", 30);
	set("int", 37);
	set("con", 36);
	set("dex", 38);

	set("chat_chance_combat", 9);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: perform_action, "sword.he" :),
	}) );

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1600);
	set("max_jing", 1600);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 800000);
	set("score", 0);
	set_skill("force", 150);
	set_skill("yunv-xinfa", 150);    //玉女心法
	set_skill("sword", 150);
	set_skill("yunv-jian", 150);     //玉女剑
	set_skill("quanzhen-jian",140);  //全真剑
	set_skill("dodge", 160);
	set_skill("yunv-shenfa", 160);   //玉女身法
	set_skill("parry", 150);
	set_skill("hubo", 120);	  //双手互搏
	set_skill("unarmed",150);
	set_skill("meinv-quan", 160);    //美女拳法
	set_skill("literate",120);
	set_skill("qufeng",200);	 //驱蜂之术

	map_skill("force", "yunv-xinfa");
	map_skill("sword", "yunv-jian");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "meinv-quan");

	create_family("古墓派", 3, "弟子");
	set("inquiry", ([
		"杨过"     :"过儿不就在这么？\n",
		"玉女剑法" :"玉女剑法和全真剑法合壁，天下无敌！\n",
		"古墓派"   :"我的林祖师爷爷本来和重阳先师是一对璧人，可是...\n",
		"养颜丹"   :(: ask_me :),
		"dan"      :(: ask_me :),
	]) );

	set("env/wimpy", 40);
	setup();
	carry_object("/kungfu/class/gumu/obj/shunvjian")->wield();
	carry_object("/kungfu/class/gumu/obj/baipao")->wear();
}

string ask_me()
{
	object ob;
	string wan_num;
	int wannum;

	wan_num = read_file("/data/YANGYAN", 1, 1);
	wannum = atoi(wan_num);
	if (wannum == 0)
		return "这位"+RANK_D->query_respect(this_player())+"，养颜丹是经我半年呵养而成的。你再等"GRN+chinese_number(6-(int)(uptime()/7200))+CYN"个月再来吧！\n";
	if (wannum == 2)
		return "这位"+RANK_D->query_respect(this_player())+"，养颜丹早给别人拿走了。你以后再来吧！\n";
	ob = new("/clone/medicine/nostrum/yangyandan");
	ob->move(this_player());
	write_file("/data/YANGYAN", "2", 1);
	command("rumor "+this_player()->query("name")+"拿到养颜丹了啦。\n");
	return "好吧，这粒养颜丹经我玉女心经半年修炼而得，你既有缘，就拿去吧。";
}

