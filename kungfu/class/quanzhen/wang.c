// wang.c 王重阳

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

string ask_jiuyin();
string ask_zhipu();
string ask_duan();

void create()
{
	set_name("王重阳", ({"wang chongyang", "wang"}));
	set("gender", "男性");
	set("age", 66);
	set("class", "quanzhen");
	set("nickname",HIW"中神通"NOR);
	set("long",
		"他就是全真教的开山祖师、首代掌教王重阳王真人。他白须飘\n"
		"飘，宽袍缓袖，眉目清癯，颇有些仙风道骨的味道。他本来一\n"
		"腔热血欲报效国家力抗金兵，可惜朝廷腐败，于是心灰意冷，\n"
		"又从道德经中悟得了天地滋生的大道，手创全真教。\n");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 45);
	set("int", 45);
	set("con", 45);
	set("dex", 45);

	set("no_get",1);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: perform_action, "strike.ju" :),	      
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.sanqing" :),		
		(: command("unwield changjian") :),		
		(: command("wield changjian") :),
		(: perform_action, "finger.qiankun" :),		
		(: perform_action, "strike.ju" :),
	}));

	set("qi", 6500);
	set("max_qi", 6500);
	set("jing", 2400);
	set("max_jing", 2400);
	set("neili", 9000);
	set("max_neili", 9000);
	set("jiali", 100);

	set("combat_exp", 3000000);
	set("score", 500000);

	set_skill("array", 150);
	set_skill("force", 200);
	set_skill("xiantian-qigong", 200);    //先天气功
	set_skill("sword", 200);
	set_skill("quanzhen-jian", 300);  //全真剑
	set_skill("dodge", 200);
	set_skill("jinyan-gong", 300);   //金雁功
	set_skill("parry", 200);
	set_skill("unarmed", 200);
	set_skill("strike", 200);
	set_skill("haotian-zhang", 300);    //昊天掌
	set_skill("cuff", 200);
	set_skill("chunyang-quan", 300);    //纯阳拳
	set_skill("whip", 200);
	set_skill("duanyun-bian", 300);    //断云鞭
	set_skill("literate", 140);
	set_skill("taoism", 150);
	set_skill("finger", 200);
	set_skill("sun-finger", 200);  //一阳指
	map_skill("force", "xiantian-qigong");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("finger","sun-finger");
	map_skill("whip", "duanyun-bian");
	map_skill("strike", "haotian-zhang");
	map_skill("cuff", "chunyang-quan");
	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "haotian-zhang");

	create_family("全真教", 1, "掌教");

	set("book_count",1);
	set("inquiry", ([
		"全真教" :  "我全真教是天下道家玄门正宗。\n",
		"九阴真经" : (: ask_jiuyin :),
		"一阳指" : (: ask_zhipu :),
		"段皇爷" : (: ask_duan :),
	]) );

	setup();

	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(__DIR__"obj/whiterobe")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}
void attempt_apprentice(object ob)
{
	string new_name;
/*
	if (!ob->query("qixing"))
	{
		command("say 你要先过天罡北斗阵，再来找我学艺。");
		return;
	}
*/
	if (ob->query("class") != "quanzhen")
	{
		command("say 你不是玄门清修之士，所以，请回吧。");
		return;
	}
	if (ob->query_int() < 30)
	{
		command("say 你的资质不够，还是先找我那几个徒弟学习吧。");
		return;
	}
	if ((int)ob->query_skill("xiantian-qigong",1) < 140 )
	{
		command("say 你的本门内功心法火候不足，难以领略更高深的武功。");
		return;
	}
	if ((int)ob->query("shen")<100000)
	{
		command( "say 我辈武人份当行侠仗义除暴安良，你若能多为侠义之举，当能承我衣钵。\n");
		return;
	}
	command("say 好吧，依你资质，定可传我衣钵，我就收下你这个徒弟了。");
	command("recruit " + ob->query("id"));
	new_name=ob->query("name");
	if(new_name[2..3]=="志")
	{
		new_name=new_name[0..1]+"处"+new_name[4..5];
		ob->set("name", new_name);
		command("say 从今以后你的道号叫做"+new_name+ "，你现在是全真教处字辈弟子了。");      
	}
}

string ask_jiuyin()
{
	mapping fam;
	int lvl_force;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "全真教")
		return RANK_D->query_respect(this_player()) +"与本教毫无瓜葛，这话从何说起？";
	if (!(lvl_force = this_player()->query_skill("force",1)) ||
		lvl_force < 50)
		return RANK_D->query_respect(this_player()) +"的基本内功火候如此之浅，强练真经上的上乘武功有害无益。";
	return "九阴真经是天下武学正宗，我已交给我师弟周伯通保管，\n不过....在古墓派的石棺内，我还刻着一些图形。\n";
}

string ask_duan()
{
	object me=this_player();
	if(me->query_temp("tmark/指")==2)
	{
		me->add_temp("tmark/指",1);
		return("段皇爷号称‘南帝’，家传的一阳指是天下最厉害的指法。\n");
	}
	else {
		me->set_temp("tmark/指",0);
		return("你问段皇爷做甚么，莫非想与他为难？\n");
	}
}

string ask_zhipu()
{
	object ob,me=this_player();
	if(me->query_temp("tmark/指")==3)
	{
		me->set_temp("tmark/指",0);
		if(query("book_count")>0)
	{
			ob=new(BOOK_DIR"sun_book");
			ob->move(me);
			add("book_count",-1);
message("channel:rumor",MAG"【谣言】某人："+this_player()->query("name")+"拿了一阳指诀啦。\n"NOR, users());
			return("好吧，你历经艰苦，意志甚坚，这本指法谱就交给你了。\n");
		}
		else return("你来晚了，指法谱已经被人取走了。\n");
	}
	else {
		me->set_temp("tmark/指",0);
		return  RANK_D->query_respect(me) + "不是想跟我较量较量吧？\n";
	}
}
