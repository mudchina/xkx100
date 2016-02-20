// Last Modified by winder on Sep. 12 2001
// chen-jialuo.c 陈家洛

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

string ask_me();
string ask_ling();
int count=1;

void create()
{
	set_name("陈家洛", ({ "chen jialuo", "chen" }));
	set("title", HIR"红花会"HIG"总舵主"NOR);
	set("nickname", HIY"玉面神龙"NOR);
	set("long","他就是天下闻名的红花会的总舵主陈家洛。\n身穿一件干干净净的青色长袍。\n他一副模样直是个富贵人家的纨裤子弟，丰姿如玉，目朗似星，神采飞扬，气度闲雅，吐属斯文。服饰俨然是个贵介公子。\n");
	set("gender", "男性");
	set("age", 22);
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 5000);
	set("max_jing", 5000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali",100);
	set("combat_exp", 3000000);
	set("score", 700000);

	set_skill("force", 200);
	set_skill("honghua-shengong", 200);
	set_skill("dodge", 200);
	set_skill("youlong-shenfa", 300);
	set_skill("hand", 200);
	set_skill("benlei-shou", 300);
	set_skill("cuff", 200);
	set_skill("baihua-cuoquan", 300);
	set_skill("strike", 200);
	set_skill("heisha-zhang", 300);
	set_skill("throwing", 200);
	set_skill("wuying-feidao", 300);
	set_skill("blade", 200);
	set_skill("qiuge-dao", 300);
	set_skill("sword", 200);
	set_skill("luohua-jian", 300);
	set_skill("zhuihun-jian", 300);
	set_skill("parry", 200);
	set_skill("literate", 100);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("cuff", "baihua-cuoquan");
	map_skill("hand", "benlei-shou");
	map_skill("strike", "heisha-zhang");
	map_skill("throwing", "wuying-feidao");
	map_skill("sword", "luohua-jian");
	map_skill("blade", "qiuge-dao");
	map_skill("parry", "luohua-jian");
	prepare_skill("cuff", "baihua-cuoquan");
	prepare_skill("hand", "benlei-shou");

	set("inquiry", ([
		"红花会" : (: ask_me :),
	]));
	set("chat_chance", 5);	 // 随机动作概率 25%
	set("chat_msg", ({
		"陈家洛叹了一口气道：唉....想不到乾隆竟是我兄弟，这可如何是好？\n",
		"陈家洛恨声说道：我们汉人的江山，一定要从满清手中夺回来。\n",
		"陈家洛说道：这位兄弟，可要加入我们红花会吗？\n",
	}) );
	set("no_get",1);
	set("chat_chance_combat", 50); // 战斗中随机动作概率
	set("chat_msg_combat", ({
		"陈家洛说道：你敢惹我，追到天涯海角我都要杀了你！\n",
		(: perform_action, "sword.beng" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "cuff.cuo" :),
		(: perform_action, "hand.yunkai" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
	create_family("红花会", 2, "总舵主");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(__DIR__"obj/yaodai")->wear();
	carry_object(__DIR__"obj/bluecloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 50000)
	{
		command( "say 红花会中皆是敢作敢当的好汉子，你这小贼也想混进来么？");
		command("say 想要加入红花会"+RANK_D->query_respect(ob) + "你先去杀几个清狗再说！");
		return;
	}
	command("say 在下对"+RANK_D->query_respect(ob)+"已是神交已久，从今而后咱们就是一家人了！");
	command("recruit " + ob->query("id"));
}

void init()
{
	object ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

	if((int)ob->query("shen") < -1000 &&
		ob->query("family/master_id")=="chen jialuo")
	{
		command( "chat "+ob->query("name")+"！你这等邪恶奸诈之徒，红花会岂能再容你！\n");
		command("expell "+ ob->query("id"));
		this_player()->set("title","红花会" + RED + "弃徒" NOR);
	}
	add_action("do_say", "say");
        add_action("do_qiecuo","qiecuo");
}

void greeting(object me)
{
       
       	mapping myfam;
	myfam = (mapping)me->query("family");
	if((myfam["family_name"] == "红花会")&&(!me->query_skill("honghua-shengong",1))&&(me->query("combat_exp")>500000))
        {
                command("say 你竟敢放弃本门心法！从我这里滚出去吧！");
                command("expell " + me->query("id"));
        }
        
}

int do_say(string arg)
{
	if( !arg || arg=="" ) return 0;
 
	if( arg=="青叶红花白莲藕") 
	{
		write("陈家洛说道：天下英雄是一家。\n");
		message("vision", "陈家洛低声道：原来是自家弟兄，不知有何见教？\n", this_player());
		set("inquiry", ([
			"红花令" : (: ask_ling :),
		]));
	}
}
string ask_me()
{
	return RANK_D->query_respect(this_player())+ "，我红花会乃天下第一大帮，专与清狗作对，哈...哈...";
}
string ask_ling()
{
	object ob,me;

	if (count == 0) return "红花令已经传出去了！\n";
	message_vision(HIR"陈家洛说道：“想要红花令吗？，先接我三招！\n"NOR,this_player());
	ob = this_object();
	me = this_player();
	COMBAT_D->do_attack(ob, me, query_temp("weapon") );
	COMBAT_D->do_attack(ob, me, query_temp("weapon") );
	COMBAT_D->do_attack(ob, me, query_temp("weapon") );

	me->set_temp("fighter", 1);
	ob->fight_ob(me);
	me->fight_ob(ob);
	command("halt");

	if (( (int)me->query("qi")*100 / (int)me->query("max_qi") ) >= 30 )
	{
		ob = new(__DIR__"obj/honghua-ling");
		ob->move(this_player());
		count=0;
		message_vision(HIY"陈家洛交给$N一支红花令！\n"NOR, me);
		return "好，这是红花令，兄弟你要好好保管！\n";
	}
	else return "你这样武功怎能掌管红花令？";	
}

