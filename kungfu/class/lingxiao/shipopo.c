// Npc: /d/lingxiao/npc/shipopo.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();
string ask_book();
string ask_skill();
void create()
{
	set_name("史婆婆",({"shi popo","popo","shi"}));
	set("gender", "女性");
	set("age", 50);
	set("long", "她是雪山派掌门人白自在的妻子，虽说现在人已显得苍老，\n"
		"但几十年前提起“江湖一枝花”史小翠来，武林中却是无人不知。\n");
	set("attitude", "friendly"); 

	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("qi", 2000);
	set("max_qi", 2000);
	set("jiali", 50);

	set("combat_exp", 2000000);
	set("inquiry", ([
		"金乌刀谱":(:ask_book:),
		"金乌坠地":(:ask_skill:),
	]) );
	set("shen_type", 0);
	set("score", 50000);

	set("env/wimpy", 60);
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) ); 
	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("blade", 200);
	set_skill("parry", 120);
	set_skill("strike", 100);
	set_skill("jinwu-blade", 200);
	set_skill("snowstep", 150); 
	set_skill("bingxue-xinfa", 150); 
	set_skill("snow-strike", 120);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 35);
	set("count", 1);

	map_skill("blade", "jinwu-blade"); 
	map_skill("force", "bingxue-xinfa"); 
	map_skill("strike", "snow-strike");
	map_skill("parry", "jinwu-blade");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");
	create_family("凌霄城", 5, "弟子");
	setup();

	carry_object("/clone/weapon/gangdao")->wield();
	carry_object(CLOTH_DIR+"bai")->wear();
}

string ask_book()
{
	object me,ob;
	ob=this_player(); 
	
	if(ob->query("family/master_id")=="bai wanjian")
	{
		if (query("count") == 1)
		{
			command("say 你是万剑的弟子吗？那就给你吧。");
			message_vision(HIG"史婆婆掏出一本小册子，交给$N。\n\n"NOR,ob);
			me=new(BOOK_DIR+"jinwu-book");
			me->move(ob);
			add("count", -1);
			return "你好好读读，比老鬼的剑法好多了。\n";
		}
		else return"你来晚啦，刀谱已经让人拿走了。\n";
	}
	if(ob->query("family/master_id")=="bai zizai")
	{
		if (query("count") == 1)
		{
			command("say 你是老鬼的弟子吗？那就给你吧。");
			message_vision(HIG"史婆婆掏出一本小册子，交给$N。\n\n"NOR,ob);
			me=new(BOOK_DIR+"jinwu-book");
			me->move(ob);
			add("count", -1);
			return "你好好读读，比老鬼的剑法好多了。\n";
		}
		else return "你来晚啦，刀谱已经让人拿走了。\n";
	}

	command("say 走开，不然老太婆要发火了？");
	message_vision(HIG"史婆婆哼了一声，不理$N。\n\n"NOR,ob);

	return "我虽离开了凌霄城，却也不会乱传人武功。\n";
}

int recognize_apprentice(object ob)
{
	mapping myfam;
	myfam = (mapping)ob->query("family");
//	if ( myfam["family_name"] == "凌霄城") return 1 ;
	if ((int)ob->query_temp("tmark/shi") == 1 )
	message_vision("史婆婆哼了一声，对$N说道：老身今天不想再教了，你下次再来吧。\n", ob);
	if (!(int)ob->query_temp("tmark/shi")) return 0; 
	ob->add_temp("tmark/shi", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	
	if ( (string) ob->query("id") =="jinwu-staff" )
	{
		if (!(int)who->query_temp("tmark/shi"))
			who->set_temp("tmark/shi", 0);
		message_vision("史婆婆接过金乌杖，“呵呵”笑了两声，摸摸杖身，说道：\n好！好！好！难得你帮我乖孙女办事，真不错，好吧！\n老身今天正好有空，就教你一会工夫吧。\n", who);
		who->add_temp("tmark/shi", 900);
		return 1;
	}
	return 0;
}

void attempt_apprentice(object ob)
{
	if (ob->query_int() < 30)
	{
		command("say 你这种资质，一边去吧！");
		return;
	}
	if ((int)ob->query_skill("bingxue-xinfa",1) < 80 )
	{
		command("say 你的本门内功心法太低了，还是努努力先提高一下吧！");
		return;
	} 
	if ((int)ob->query("shen") < 0 )
	{
		command("say 你这种人，再不滚，我马上宰了你。"); 
		return;
	} 
	if ((int)ob->query("max_neili") < 800 )
	{
		command("say 你内力不足，先去打熬打熬内力吧。"); 
		return;
	}
	if ((int)ob->query_skill("xueshan-sword",1) < 100 )
	{
		command("say 你的本门剑法太低了，还是先找你师父提高吧！"); 
		return;
	}
	if ((int)ob->query_skill("sword",1) < 100 )
	{  
		command("say 你的基本剑法太低了，还是先提高基本功吧！");
		return; 
	}
	command("say 很好，很好，老身就收你为徒吧。");
	command("recruit " + ob->query("id"));
} 
string ask_skill()
{
	object me=this_object();
	object ob= this_player();
	
	if ((int)ob->query("can_perform/jinwu-blade/jinwu"))
		return "你不是已经学会了吗，还找我做什么。";

	if ((string)ob->query("family/master_id") != "shi popo")
		return "你不是我的弟子，走开！";
	
	if ((int)ob->query_skill("jinwu-blade",1) < 100)
		return "你的金乌刀法还不到家，用不了这招。";

	if ((int)ob->query_skill("bingxue-xinfa",1) < 100)
		return "你的冰雪心法法火候不够，用不了这招。";

	if ((int)ob->query("max_neili")<1000)	
		return "你的内力还差一些，加油吧。";
		
        message_vision( HIY "$n" HIY "道：“你能有今日这个地步，也"
                       "算不错。今日我\n传你雪山剑法的破解之法，你"
                       "可记牢了。雪山派剑法有\n七十二招，我金乌派"
                       "武功处处胜他一筹，却有七十三招。\n咱们七十"
                       "三招破他七十二招，最后一招瞧仔细了！”说\n"
                       "着拔出腰间柴刀从上而下直劈下来，又道：“你"
                       "使这招\n之时，须得跃起半空，和身直劈！”当"
                       "下又教将如何运\n劲，如何封死对方逃遁的空隙"
                       "等窍门慢慢传给$N" HIY "，$N" HIY "凝\n思半"
                       "晌，依法施为，纵身跃起，半空中挥刀直劈，呼"
                       "的\n一声，刀锋离地尚有数尺，地下已是尘沙飞"
                       "扬，败草落\n叶被刀风激得团团而舞，果然威力"
                       "惊人。\n" NOR, ob, this_object());
        command("heng");
        tell_object(ob, HIC "你学会了「金乌坠地」。\n" NOR);
				ob->set("can_perform/jinwu-blade/jinwu",1);
        return "这一招可尽破雪山剑法，你自己下去练吧。";
}
