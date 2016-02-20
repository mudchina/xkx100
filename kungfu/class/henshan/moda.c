// moda.c 衡山派掌门 莫大
// Last Modified by ahda on Sep.1 2001
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
#define ZHENYUE "/clone/weapon/treasure/zhenyue"
mixed ask_jian();
#include <ansi.h>
void create()
{
	object ob;
	set_name("莫大", ({ "mo da", "mo" }) );
	set("nickname", "潇湘夜雨");
	set("gender", "男性");
	set("class", "swordsman");
	set("age", 55);
	set("attitude", "peaceful");
	set("per", 22);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 60);
	set("max_qi",2500);
	set("max_jing",1800);
	set("combat_exp", 3000000);
	set("shen_type", 1);

	set_skill("hand", 200);
	set_skill("unarmed",200);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("strike", 200);
	set_skill("hengshan-sword", 300);
	set_skill("huiyan-xinfa",200);
	set_skill("luoyan-hand",300);
	set_skill("biluo-zhang",300);
	set_skill("qiuyan-nanhui",300);
	set_skill("literate",180);
	set_skill("luteplaying",180);

	map_skill("sword", "hengshan-sword");
	map_skill("parry", "hengshan-sword");
	map_skill("dodge", "qiuyan-nanhui");
	map_skill("force", "huiyan-xinfa");
	map_skill("hand", "luoyan-hand");
	map_skill("strike", "biluo-zhang");
	prepare_skill("hand", "luoyan-hand");
	prepare_skill("strike", "biluo-zhang");
  set("inquiry", ([
			"镇岳尚方" : (: ask_jian :),
			"宝剑" : (: ask_jian :),
			"祝融剑法" : "本门剑法之一的祝融剑法，自师尊华山一役后便失传了。",
			]));	 
	set("env/wimpy", 60);
	set("chat_chance_combat", 70);
	set("chat_msg_combat", ({
		(: command("haha") :),
		(: perform_action, "sword.luoyan" :),
		(: perform_action, "sword.luoyan" :),
		(: perform_action, "sword.yunwu" :),
		(: perform_action, "hand.jinghan" :),
		(: perform_action, "strike.huan" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
	create_family("衡山派", 13, "掌门");
	setup();
	set("count",1);
  if (clonep())
  {
     	ob=new(ZHENYUE);
     	if ( ob-> violate_unique())
     	{
     		destruct(ob);
     		ob=new(__DIR__"obj/qinjian");
    		}
     ob->move(this_object());
     ob->wield();
  }

//  carry_object(__DIR__"obj/qinjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	if((int)ob->query("int")<20)
	{
		command("say 你的悟性太低了，不适合学习我的功夫。");
		return;
	}
	if((int)ob->query_skill("literate",1) < 150)
	{
		command("say 你的读书写字太低了，还是先多加修习吧。");
		return;
	}
/*
	if((int)ob->query("kar")<25)
	{
		command("say 你与衡山绝学无缘，请回吧。");
		return;
	}
*/
	if ((int)ob->query_skill("huiyan-xinfa",1) < 180 ) 
	{
		command("say 你的本门内功心法火候不足,难以领略更高深的武功。");
		return;
	}
	if((string)ob->query("gender")=="无性")
	{
		command("say 你秉性阴阳不定，习我功夫恐将走火如魔。");
		return;
	}
	if((int)ob->query("shen") <= 50000)
	{
		command("say 你应当多作些行侠仗义的事，以修身心。");
		return;
	}

	command("say 入我门来，定须光大我衡山一派。");
	command("recruit " + ob->query("id"));
}

mixed ask_jian()
{
        object me;
        object ob;
        object owner;
        object *oblist;
        object temp;
        int i;

        me = this_player();
        if (me->query("shen")<0)
        {
                if (me->query("family/family_name") == "衡山派")
                        message_vision(CYN "$N" CYN "大怒，对$n" CYN "道：“你身为衡山弟子，"
                                       "反而误入魔道，还不快快醒转？”\n" NOR,
                                       this_object(), me);
                else
                        message_vision(CYN "$N" CYN "大怒，对$n" CYN "喝道：“好一个邪魔外"
                                       "道，居然敢窥我镇岳尚方？”\n" NOR,
                                       this_object(), me);
                return 1;
        }

        if (me->query("family/family_name") != "衡山派")
                return "镇岳尚方是我护身之宝，你打听它干什么？";

        if (me->query("family/master_id") != query("id"))
                return "只有我的弟子才能用镇岳尚方，你还是请回吧。";

        if (me->query("shen") < 60000)
                return "你行侠仗义的事情做得不够，我不能把镇岳尚方交给你。";
				if (present("zhenyue shangfang",me))
								return "镇岳尚方不是在你的手中么，怎么反而来找我呢？";

        ob=new(ZHENYUE);
        if ( temp=ob->violate_unique())
         {
         destruct(ob);
         ob=temp;
				 owner = environment(ob);
  			 if (owner == me)
	         	return "镇岳尚方不是在你的手中么，怎么反而来找我呢？";
        if ( owner->is_character() && owner!= this_object())
           {
                if (owner->query("family/family_name") == query("family/family_name"))
                        return "镇岳尚方现在在" + owner->query("name") +
                               "手中，你要想用就去找他吧。";
                else
                        return "本派至宝镇岳尚方现在落在" + owner->query("name") +
                               "手中，你快去杀了他把剑拿回来。";
        	 }
         }
        	
				ob->move(this_object());
        message_vision(CYN "$N" CYN "点点头道：“好，你用这镇岳尚方要多作一些行"
		       "侠仗义的事情！”\n" NOR, this_object(), me);
        command("give zhenyue shangfang to " + me->query("id"));
        add("count",-1);
        return 1;
}

