// yu.c 点苍渔隐

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("点苍渔隐", ({ "diancang yuyin", "yu" }));
	set("title",  "大理国水军都督" );
	set("long", 
"他就是大理国的原水军都督，一灯大师的四大弟子之一。
他约莫四十来岁年纪，一张黑漆漆的锅底脸，虬髯满腮，
根根如铁。\n");
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
        set_skill("tiannan-step", 100);
        set_skill("jinyu-quan", 100);
        set_skill("wuluo-zhang", 100);
        set_skill("duanjia-sword", 100);
        set_skill("sun-finger", 100);
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

        set("inquiry", ([
                "一灯大师"   : "师父他老人家在上面。\n",
                "段智兴"     : "那是我师父俗世的名讳。\n",
                "刘瑛姑"     : "她是我师父俗世的妃子。\n",
        ]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/kungfu/class/dali/obj/diaogan")->wield();
	add_money("silver", 50);

	create_family("大理段家",25,"弟子");
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	mapping myfam;

	myfam = (mapping)ob->query("family");
	if( myfam["master_id"] == "yideng dashi")
	{
message_vision(HIY"点苍渔隐对$N说：你回来了。自己上去见师父吧。\n"NOR, ob);
		ob->set_temp("yu_allow", 1);
	}
	return;
}

int accept_object(object who, object ob)
{
	if ( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");

	if ( (string)ob->query("id") != "hong bu")
		return notify_fail("点苍渔隐不想要这件东西。\n");
	say( "点苍渔隐冲你点了点头：进屋去吧。\n");
	who->set_temp("yu_allow", 1);
	return 1;
}

