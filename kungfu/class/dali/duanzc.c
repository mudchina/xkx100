// duanzc.c 段正淳
//last modified 01/05/05

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
string ask_me();

void create()
{
	object ob;
	set_name("段正淳", ({ "duan zhengchun", "duan" }));
	set("title",  "大理镇南王" );
	set("long", "他就是大理国的镇南王，当今皇太弟，是有名的爱情圣手。\n");
	set("gender", "男性");
	set("age", 45);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 35);
	set("dex", 30);
	set("no_get",1);

        set("inquiry", ([
                  "秘籍"     : (: ask_me :),
                  "段家斧法"  : (: ask_me :),
                  "shu" : (: ask_me :),
                       ]));
	
	set("max_qi", 2200);
	set("max_jing", 600);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 3000000);
	set("score", 300000);
        set("book_count",1);
       
        set_skill("force", 150);
        set_skill("axe", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("cuff", 140);
        set_skill("strike", 150);
        set_skill("sword", 150);
        set_skill("staff", 150);
        set_skill("finger", 120);
	set_skill("kurong-changong", 150);
        set_skill("tiannan-step", 210);
        set_skill("duanyun-fu", 210);
        set_skill("jinyu-quan", 220);
        set_skill("wuluo-zhang", 220);
        set_skill("duanjia-sword", 225);
        set_skill("sun-finger", 180);
	set_skill("literate", 100);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("finger", "sun-finger");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "sun-finger");
	map_skill("sword", "duanjia-sword");
	map_skill("axe", "duanyun-fu");
	map_skill("staff", "duanjia-sword");
	prepare_skill("finger", "sun-finger");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "axe.duan" :),
                (: perform_action, "axe.hongtianza" :),
                (: perform_action, "axe.tiaoyan" :),			
		(: perform_action, "finger.qiankun" :),				
		(: exert_function, "powerup" :),		
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
	if (clonep())
	{
	 ob=new(WEAPON_DIR"treasure/duanyun-axe");
   if ( ob->violate_unique() )
   {
     destruct(ob);
     ob = new(WEAPON_DIR"axe");
   }
   ob->move(this_object());
   ob->wield();
 }
add_money("silver", 50);

	create_family("大理段家",18,"镇南王");
}

void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("kurong-changong",1) < 100 )
	{
		command("say 你的本门内功心法太低了，还是努努力先提高一下吧。");
		return;
	}
	if ((int)ob->query("shen") < 10000  ) {
		command("say 我大理段氏向来行侠仗义，您请回吧！");
		return;
	}
	if (strsrch(ob->query("guard"), "镇南王府") >= 0) 
	{
		command("say 很好，既然入我门来就得忠心为主。");
		command("recruit " + ob->query("id"));
	}
	else
	{
		command("say 你是何人，如此大胆，假冒我府中厮仆！");
		return;
	}
}
string ask_me()
{
	object ob;
	
	if (this_player()->query("family/master_id")!="duan zhengchun")
		return RANK_D->query_respect(this_player()) + 
		"非我弟子，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，本派的秘籍不在此处。";
	add("book_count", -1);
	ob = new("/clone/book/axe");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到段家斧法啦。\n");
	return "好吧，这本「段家斧法」你拿回去好好钻研，光大我大理段家武学。";
}
