// hetieshou.c 何铁手
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
int ask_me();
int ask_box();
string ask_ling();

void create()
{
	object ob;
	set_name("何铁手", ({ "he tieshou", "he" }));
	set("nickname", HIG "五毒仙子" NOR);
	set("long",@LONG
你对面的是一个一身粉红纱裙，笑靥如花的少女。她长得肌肤雪白，眉目如画，
赤着一双白嫩的秀足，手脚上都戴着闪闪的金镯。谁能想到她就是五毒教的教
主何铁手，武林人士提起她无不胆颤心惊。
LONG
	);
	set("title","五毒教教主");
	set("gender", "女性");
	set("class", "shaman");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 36);
	set("max_qi", 5000);
	set("max_jing", 5000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("combat_exp", 3000000);
	set("score", 500000);
	set("box_count",1);
	set("ling_count",1);
	set("tieshao_count",1);

	set_skill("force", 200);
	set_skill("wudu-shengong", 200);
	set_skill("dodge", 200);
	set_skill("wudu-yanluobu", 300);
	set_skill("hand", 170);
	set_skill("qianzhu-wandushou", 250);
	set_skill("strike", 170);
	set_skill("wudu-zhang", 250);
	set_skill("parry", 190);
	set_skill("whip", 200);
	set_skill("wudu-whip", 300);
	set_skill("hook", 200);
	set_skill("wudu-goufa", 300);
	set_skill("sword", 200);
	set_skill("qingmang-sword", 300);
	set_skill("five-poison", 200);
	set_skill("literate", 100);
	map_skill("force", "wudu-shengong");
	map_skill("dodge", "wudu-yanluobu");
	map_skill("hand", "qianzhu-wandushou");
	map_skill("strike", "wudu-zhang");
	map_skill("whip", "wudu-whip");
	map_skill("parry", "wudu-goufa");
	map_skill("sword", "qingmang-sword");
	map_skill("hook", "wudu-goufa");
	prepare_skill("hand", "qianzhu-wandushou");
	prepare_skill("strike", "wudu-zhang");

	set("no_get",1);
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "hook.suo" :),
		(: perform_action, "unarmed.qzwd" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );	

	create_family("五毒教", 11, "教主");

	setup();
	set("inquiry", ([
		"万毒窟"    : (: ask_me :),
		"信物"      : (: ask_me :),
		"含沙射影"  : (: ask_box :),
		"五毒令"    : (: ask_ling :),
	]) );
  if (clonep())
  {
  	ob=new(WEAPON_DIR"treasure/jinfenggou");
  	if ( ob->violate_unique() )
  	 {
  	 	 destruct(ob);
  	 	 ob=new("/clone/weapon/hook");
  	 	}
  	 	ob->move(this_object());
  	 	ob->wield();
  }
	carry_object("/clone/armor/treasure/skirt")->wear();

	add_money("silver",50);
}

void init()
{
    add_action("do_qiecuo","qiecuo");
}

int ask_me()
{
	object ob;
	if ((string)this_player()->query("family/master_id")!="he tieshou")
	{
		command("say 万毒窟乃本教圣地，除本教长老之外别人不得进入。");
		return 1;
	}
	if(query("tieshao_count")< 1 )
	{
		command("say 你来晚了，信物我已经给别人了。");
		return 1;
	}
	command("say 万毒窟内凶险异常，千万要小心啊。\n");
	command("say 这只铁哨是我的信物，你可以凭此自由进入洞中！");
	ob = new("/d/wudujiao/npc/obj/tieshao");
	ob->move(this_player());
	add("tieshao_count",-1);
	remove_call_out ("give_tieshao");
	call_out ("give_tieshao", 900); // 15 分钟
	return 1;
}
int ask_box()
{
	object ob;
	if ((string)this_player()->query("family/master_id")!="he tieshou")
	{
		command("say 此乃本教重宝，轻易不会给人的。");
		return 1;
	}
	if(query("box_count")< 1 )
	{
		command("say 你来晚了，含沙射影我已经送给别人了。");
		return 1;
	}
	command("smile");
	command("say 怎么？是要和人打架吗？可别弱了我五毒教威风啊！");
	command("say 含沙射影你拿去吧，叫他们尝尝我们五毒教的厉害。");
	ob = new("/d/wudujiao/npc/obj/hanshasheying");
	ob->move(this_player());
	add("box_count",-1);
	ob->set("own_name",this_player()->query("id"));
	remove_call_out ("give_hssy");
	call_out ("give_hssy", 900); // 15 分钟
	return 1;
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender") == "无性")
	{
		command("say 这位公公不要开玩笑了。");
		command("say 这位" + RANK_D->query_respect(ob)+"还是快去伺候皇上吧！");
		return;
	}

	if ((int)ob->query("shen") > 1000)
	{
		command("say 做我五毒教弟子必须心狠手辣。");
		command("say 这位" + RANK_D->query_respect(ob) + "心慈手软，可惜与我教没有缘分啊！");
		return;
	}

	if ((string)ob->query("family/family_name") != "五毒教")
	{
		command("say 这位" + RANK_D->query_respect(ob) + "不是本教弟子，还是请回吧！");
		return;
	}

	if ((int)ob->query_skill("five-poison", 1) < 120)
	{
		command("say 我五毒教弟子以毒杀人，修习毒技是首要的。");
		command("say 这位" + RANK_D->query_respect(ob) + "是否还应该多多钻研本门的绝学？");
		return;
	}
	if ((int)ob->query_skill("wudu-shengong", 1) < 100)
	{
		command("say 你的五毒神功还学的不够啊。");
		return;
	}

//	command("chat 嘿嘿嘿嘿！！！！！");
	command("chat 好吧，既然如此本姑娘就收下你这个徒弟。");
	command("chat 终有一天，要让天下人都知道我们五毒教的厉害！！！");
	command("recruit " + ob->query("id"));
	ob->set("title",HIY"五毒教长老"NOR);
	return;
}
void give_hssy()
{
	set("box_count",1);
}
void give_tieshao()
{
	set("tieshao_count",1);
}
void give_wuduling()
{
	set("ling_count",1);
}
string ask_ling()
{
	mapping fam;
	object *allob,env,ob,me=this_player();
	string *sname;
	int i, count, here = 0;

	if (query("ling_count") < 1)
		return "你来晚了，五毒令别的教众正在用呢。\n";
	if (!(fam = me->query("family")) || fam["family_name"] != "五毒教")
		return RANK_D->query_respect(me) + "与本派素无来往，不知此话从何谈起？";

	if (me->query("duchong_cun") == 1)
		return "你的毒虫不是在毒叟那好好的么？";

	env = environment(me);
	allob = all_inventory(env);
	count = 0;
	for(i=0; i<sizeof(allob); i++)
		if(allob[i] != me && allob[i]!=this_object() )
		{
			if(allob[i]->query("host_id") == me->query("id"))
			{
				here = 1;
			}
			count++;
		}
	if (here == 1)
		return "你的毒虫不是带在身边了吗！？";
	if (me->query("duchong_cun") == 0 && count >= 1)
		return "现在人多眼杂，你回头再来吧！";

	if (!me->query("du/id"))
		return "你没养毒虫吧！";

	add("ling_count",-1);
	ob = new(__DIR__"obj/wudu-ling");
	ob->move(me);
	message_vision("$N获得一面五毒令。\n",me);
	remove_call_out ("give_wuduling");
	call_out ("give_wuduling", 600); // 10 分钟

	return "好吧，凭这面五毒令，你可去要回你的毒虫。";

}

