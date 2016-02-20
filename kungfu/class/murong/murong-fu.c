// murong-fu.c 

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
string ask_me();

void create()
{
	set_name("慕容复", ({ "murong fu", "murong","fu" }));
	set("nickname", HIG"南慕容"NOR);
	set("gender", "男性");
	set("class", "scholar");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 3000000);
	set("score", 500000);
	set("san_count", 1);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("blade", 200);
	set_skill("strike", 200);
	set_skill("finger", 200);
	set_skill("murong-sword", 300);
	set_skill("murong-blade", 300);
	set_skill("canhe-finger", 300);
	set_skill("xingyi-strike", 300);
	set_skill("shenyuan-gong", 200);
	set_skill("yanling-shenfa", 300);
	set_skill("douzhuan-xingyi", 150);
	map_skill("parry", "douzhuan-xingyi");
	map_skill("sword", "murong-sword");
	map_skill("blade", "murong-blade");
	map_skill("force", "shenyuan-gong");
	map_skill("parry", "douzhuan-xingyi");
	map_skill("finger", "canhe-finger");
	map_skill("strike", "xingyi-strike");
	prepare_skill("finger", "canhe-finger");
	prepare_skill("strike", "xingyi-strike");
	set("inquiry",([
		"王语嫣"    : "语嫣是我表妹，我一直把她当小妹妹看待。\n",
		"南慕容"    : "“南慕容北乔峰”，那是江湖上的朋友抬爱了！\n",
		"慕容复"    : "那是贱名。请教尊驾是？\n",
		"邓百川"    : "你问邓大哥啊？他在他青风庄上呢。\n",
		"公冶乾"    : "公冶二哥把信鸽传书一编码，就没几个人读得懂了。\n",
		"包不同"    : "包三哥最爱抬杠了，你见了他还是闭嘴的好。\n",
		"风波恶"    : "风四哥最是豪爽了，他从不与人计较什么。\n",
		"风波恶"    : "风四哥最是豪爽了，他从不与人计较什么。\n",
		"玉露清新散": (: ask_me :),
	]) );
	set("no_get",1);
	set("chat_chance_combat", 60);  
	set("chat_msg_combat", ({
		(: perform_action, "parry.xingyi" :),
		(: perform_action, "sword.lianhuan" :),
		(: perform_action, "finger.dian" :),
		(: exert_function, "powerup" :),
		(: exert_function, "reserve" :),
		(: exert_function, "recover" :),
	}) );
	create_family("姑苏慕容",33, "弟子");
 	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("betrayer") > 0)
	{
		command("say 这位" + RANK_D->query_respect(ob) +
			"，我慕容家复国乃至为要事，你心志不坚，无缘我门。");
		return;
	}
	if ((int)ob->query_skill("shenyuan-gong", 1) < 100)
	{
		command("say 姑苏慕容家武功，以内功为根基。");
		command("say "+RANK_D->query_respect(ob)+"还应该多加努力！");
		return;
	}
	command("say 好吧我就收你为徒吧。");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "姑苏慕容")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (query("san_count") < 1)
		return "你来晚了，本派的玉露清新散不在此处。";
	add("san_count", -1);
	ob = new("/clone/medicine/nostrum/yulusan");
	ob->move(this_player());
	return "好吧，这玉露清新散你拿去吧。";
}
