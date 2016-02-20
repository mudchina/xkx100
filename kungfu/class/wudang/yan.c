// yan.c 俞岱岩

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_yao1();
string ask_yao2();

void create()
{
	set_name("俞岱岩", ({ "yu daiyan", "yu" }));
	set("nickname", "武当三侠");
	set("long","他就是张三丰的弟子、武当七侠之三的俞岱岩。\n身穿一件干干净净的青布长衫。\n他不过三十出头年纪，双腿残废，张真人命他主持真武剑阵。\n");
	set("gender", "男性");
	set("age", 31);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("shen_type", 1);
	set("no_get", "1");
	set("str", 28);
	set("int", 30);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jingli", 1000);
	set("max_jingli", 1000);
	set("jiali", 50);
	set("combat_exp", 250000);
	set("score", 60000);

	set_skill("force", 100);
	set_skill("taiji-shengong", 100);
	set_skill("dodge", 50);
	set_skill("tiyunzong", 70);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 150);
	set_skill("taiji-jian", 150);
	set_skill("wudang-quan", 100);
	set_skill("wudang-jian", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "unarmed.zhen" :),
		(: perform_action, "unarmed.ji" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set("inquiry", ([
		"延年聚精丹" : (: ask_yao1 :),
		"九转结气丸" : (: ask_yao2 :),
	]));
	set("yao1_count", 1);
	set("yao2_count", 1);
	create_family("武当派", 2, "弟子");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting",2 , ob);
	}
}

void greeting(object ob)
{
	int i;
	if (((int)ob->query_skill("taiji-shengong", 1) == 0))
	{
		message_vision( CYN"十三弟子对$N齐声喝道：你这个邪魔外道，敢来真武剑阵？\n\n"NOR,ob);
		ob->set("qi",30);
		if ((int)ob->query("combat_exp") <2000) ob->set("combat_exp",1);
		else ob->add("combat_exp",0);
		message_vision( CYN"真武剑阵顿时启动，高台上剑气纵横，把$N围在中央。\n"NOR,ob);
		message_vision( CYN"十三口长剑齐出，在$N身上划出了十三道口子，鲜血淋漓。\n"NOR,ob);
		message_vision("俞岱岩居高临下，起手一掌把$N劈落高台。\n\n\n"NOR,ob);
		ob->move("/d/wudang/nanyangong");
	}
}

void attempt_apprentice(object me)
{
	command("say " + RANK_D->query_respect(me) + "，我是个废人了，怎么能收徒呢？");
	return;
}

string ask_yao1()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "武当派")
		return RANK_D->query_respect(this_player()) +"与本派素无来往，不知此话从何谈起？";
	if (ob = present("jujing dan", this_player()))
		return "你身上不是带着本门延年聚精丹？！";
	if (query("yao1_count") < 1)
		return "你来晚了，本门延年聚精丹已尽数给了本派弟子。";
	add("yao1_count", -1);
	ob = new("/clone/medicine/nostrum/jujingdan");
	ob->move(this_player());
	return "我这里有本门延年聚精丹，你拿去吧。";
}

string ask_yao2()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "武当派")
		return RANK_D->query_respect(this_player()) +
		"与本派素无来往，不知此话从何谈起？";
	if (ob = present("jieqi wan", this_player()))
		return "你身上不是带着本门九转结气丸？！";
	if (query("yao2_count") < 1)
		return "你来晚了，本门九转结气丸已尽数给了本派弟子。";
	add("yao2_count", -1);
	ob = new("/clone/medicine/nostrum/jieqiwan");
	ob->move(this_player());
	return "我这里有本门九转结气丸，你拿去吧。";
}

