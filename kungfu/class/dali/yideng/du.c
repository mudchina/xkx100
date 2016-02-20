// du.c 书生

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_reply1();
string ask_reply2();
string ask_reply3();

void create()
{
	set_name("朱子柳", ({ "zhu ziliu", "zhu", "ziliu" }));
	set("title",  "大理国大宰相" );
	set("long", 
"他就是大理国的原大宰相，一灯大师的四大弟子之一。
只见他四十来岁年纪，头戴逍遥巾，手挥折叠扇，颏下
一丛漆黑的长须，确是个饱学宿儒模样。\n");
	set("gender", "男性");
	set("age", 45);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 35);
	set("dex", 30);
	
	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("score", 10000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("cuff", 100);
        set_skill("strike", 100);
        set_skill("sword", 100);
        set_skill("staff", 100);
        set_skill("finger", 100);
	set_skill("kurong-changong", 100);
        set_skill("tiannan-step", 150);
        set_skill("jinyu-quan", 150);
        set_skill("wuluo-zhang", 150);
        set_skill("duanjia-sword", 150);
        set_skill("sun-finger", 150);
	set_skill("literate", 100);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("finger", "sun-finger");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "sun-finger");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");	
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jingtian" :),	
		(: perform_action, "finger.qiankun" :),			
		(: exert_function, "powerup" :),		
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

        set("inquiry", ([
                "一灯大师"   : "师父他老人家在里面。你答对了就可以见他了。\n",
                "段智兴"     : "那是我师父俗世的名讳。\n",
                "刘瑛姑"     : "她是我师父俗世的妃子。\n",
                "辛未状元"   : (: ask_reply1 :),
                "霜凋荷叶，独脚鬼戴逍遥巾"   : (: ask_reply2 :),
                "魑魅魍魉，四小鬼各自肚肠"   : (: ask_reply3 :),
        ]) );

        set("chat_chance", 3);
        set("chat_msg", ({
"朱子柳读道：“暮春者，春服既成，冠者五六人，童子六七人，浴
乎沂，风乎舞雩，咏而归。”读得兴高采烈，一诵三叹，确似在春
风中载歌载舞，喜乐无已。\n",
"朱子柳捻须吟道：
    “六经蕴籍胸中久，一剑十年磨在手。
      杏花头上一枝横，恐泄天机莫露口。
      一点累累大如斗，却掩半床无所有。
      完名直待挂冠归，本来面目君知否？”\n",
"朱子柳挥扇指着一排棕榈道：“风摆棕榈，千手佛摇折叠扇。”\n",
"朱子柳道：“我有一联，请你对个下联：‘琴瑟琵琶，八大王一般头面’。”\n",
        }) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/book/lbook4");
	add_money("silver", 50);

	create_family("大理段家",25,"弟子");
}


void greeting(object ob)
{
        mapping myfam;

        myfam = (mapping)ob->query("family");
        if( myfam["master_name"] == "yideng dashi")
              say ("朱子柳冲着你点了点头，说：你回来了。\n");
	ob->set_temp("du_allow", 1);
        return;
}

string ask_reply1()
{
	object me = this_player();
	me->set_temp("yideng_du1", 1);
	if (me->query_temp("yideng_du2") && me->query_temp("yideng_du3"))
	{
message_vision("\n朱子柳大惊，站起身来，长袖一挥，向$N一揖到地，说道：“在下拜服。”\n\n", me);
		me->set_temp("du_allow", 1);
		return RANK_D->query_respect(me) + "请。";
	}
	else
		return RANK_D->query_respect(me) + "果然文武全才。不过还有呢？";
}
string ask_reply2()
{
	object me = this_player();
	me->set_temp("yideng_du2", 1);
	if (me->query_temp("yideng_du1") && me->query_temp("yideng_du3"))
	{
message_vision("\n朱子柳大惊，站起身来，长袖一挥，向$N一揖到地，说道：“在下拜服。”\n\n", me);
		me->set_temp("du_allow", 1);
		return RANK_D->query_respect(me) + "请。";
	}
	else
		return RANK_D->query_respect(me) + "果然文武全才。不过还有呢？";
}
string ask_reply3()
{
	object me = this_player();
	me->set_temp("yideng_du3", 1);
	if (me->query_temp("yideng_du1") && me->query_temp("yideng_du2"))
	{
message_vision("\n朱子柳大惊，站起身来，长袖一挥，向$N一揖到地，说道：“在下拜服。”\n\n", me);
		me->set_temp("du_allow", 1);
		return RANK_D->query_respect(me) + "请。";
	}
	else
		return RANK_D->query_respect(me) + "果然文武全才。不过还有呢？";
}
