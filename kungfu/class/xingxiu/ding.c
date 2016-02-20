// ding.c 丁春秋
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

#define YINLINFEN "/clone/medicine/poison/yinlinfen"
#define HONGLINFEN "/clone/medicine/poison/honglinfen"
#define DUCHONGFEN "/clone/medicine/poison/duchongfen"
#define BINGPOFEN "/clone/medicine/poison/bingpofen"

string ask_me();
string ask_du1();
string ask_du2();
string ask_ding();
string ask_azi();
string ask_job();
string ask_huoyan();
string ask_yinlinfen();
string ask_bingpofen();
string ask_duchongfen();
string ask_honglinfen();
 
void create()
{
	set_name("丁春秋", ({ "ding chunqiu", "ding" }));
	set("nickname", "星宿老怪");
	set("long", 
		"他脸色红润，满头白发，颌下三尺银髯，童颜鹤发，当真便如图\n"
		"画中的神仙人物一般。\n"
		"他就是星宿派开山祖师、令正派人士深恶痛绝的星宿老怪丁春秋。\n"
		"可是他看起来形貌清奇，仙风道骨。\n");
	set("gender", "男性");
	set("age", 60);
	set("per", 50);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", -1);
	set("shen", -150000);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 400000);

	set_skill("force", 200);
	set_skill("huagong-dafa", 200);
	set_skill("throwing", 200);
	set_skill("feixing-shu", 300);
	set_skill("dodge", 200);
	set_skill("zhaixinggong", 300);
	set_skill("strike", 200);
	set_skill("chousui-zhang", 300);
	set_skill("claw", 200);
	set_skill("sanyin-wugongzhao", 300);
	set_skill("parry", 200);
	set_skill("staff", 200);
	set_skill("poison", 150);
	set_skill("tianshan-zhang", 300);
	set_skill("literate", 100);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("book_count", 1);
	set("zhen_count", 1);
	set("san_count", 1);
	set("huoyan_count", 1);
	set("ding_count", 0);
	set("di_count", 10);
	set("no_get",1);
	set("chat_chance_combat", 70);  
	set("chat_msg_combat", ({
		(: perform_action, "strike.huoqiu" :),
		(: perform_action, "strike.huoqiang" :),
		(: perform_action, "strike.yinhuo" :),
		(: perform_action, "strike.biyan" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	set("inquiry", ([
		"阿紫" : (: ask_azi :),
		"神木王鼎" : (: ask_ding :),
		"毒经" : (: ask_me :),
		"星宿毒经" : (: ask_me :),
		"碧磷针" : (: ask_du1 :),
		"三笑逍遥散" : (: ask_du2 :),
		"逍遥三笑散" : (: ask_du2 :),
//		"火焰" : (: ask_huoyan :),
		"心情"  : (: ask_job :),
		"job"  : (: ask_job :),
		"木鼎" : "抓虫子练毒用的。你敢偷，就废了你。",
		"星宿派" : "我老仙乃是星宿派开山祖师, 还不赶快磕头。", 
		"星宿海" : "你瞎了眼啦, 这儿就是。",
		"星宿" : "这儿方圆几百里都是老仙的练功房。",
		"丁春秋" : "没大没小的。再叫我废了你。",
		"老仙" : "我星宿老仙比起古往今来的圣人怎么样啊？",
		"星宿老仙" : "以后叫老仙。",
		"吹捧" : "本来就是麽。",
		"银磷粉"	: (:ask_yinlinfen:),
		"yinlin fen" : (:ask_yinlinfen:),
		"红磷粉" : (:ask_honglinfen:),
		"honglin fen" : (:ask_honglinfen:),
		"冰魄粉" : (:ask_bingpofen:),
		"bingpo fen" : (:ask_bingpofen:),
		"毒虫粉": (:ask_duchongfen:),
		"duchong fen": (:ask_duchongfen:),
	]));
	create_family("星宿派", 1, "开山祖师");
	set("class", "taoist");
	setup();
//	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/dao-cloth")->wear();
}

void init()
{
	object me, ob;
	::init();
	ob = this_player();
	me = this_object();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}       
	add_action("do_flatter", "flatter");
	add_action("do_xian", "xian");
        add_action("do_qiecuo","qiecuo");
}

void greeting(object me)
{
	mapping myfam;
	int shen;
	
	if (!objectp(me) || environment(me)!=environment()) return;
	myfam = (mapping)me->query("family");
	shen = me->query("shen");

	if(!myfam) command("say 你千里迢迢来天山, 莫不是想加入我星宿派？");
	else if(myfam["family_name"] != "星宿派" && !me->query_temp("xx_job"))
		command("say 你千里迢迢来到天山，是仰慕本老仙我的仁德吧？");
	else if(myfam["family_name"] != "星宿派" && me->query_temp("xx_job"))
	command("nod " + me->query("id"));
	else if(shen > -1000 && shen < 0) command("say 你怎么搞的？搅和了一身的白道气息！");
	else if(shen > 0 && shen < 100000) command("say 好哇！你敢和白道的人搅和，不想活了是不是？");
	else if(shen > 100000)
	{
		command("say 你竟敢和白道的人搅和！从我这里滚出去吧！");
		command("expell " + me->query("id"));
	}
	else command("say 好徒儿，功夫练得怎么样了？");
	if((myfam["family_name"] == "星宿派")&&(!me->query_skill("huagong-dafa",1))&&(me->query("combat_exp")>500000))
        {
                command("say 你竟敢放弃本门心法！从我这里滚出去吧！");
                command("expell " + me->query("id"));
        }
}

void attempt_apprentice(object me)
{
	if ((int)me->query("shen") > -100) {
		command("say 老仙越看你越象白道派来卧底的。");
		return;
	}
	if ((int)me->query("combat_exp") < 10000) {
		command("say 你这点微末道行如何能学到老仙的神妙功夫。");
		return;
	}
	if( me->query_temp("pending/flatter") ) {
		command("say 你如此不把老仙放在眼里，老仙怎会收你？");
		return;
	} else {
		command("say 我星宿老仙比起古往今来的圣人怎么样啊？");
		message_vision("星宿老怪微闭双眼，手捻长须，一副等$N拍马(flatter)的样子。\n", me);
		me->set_temp("pending/flatter", 1);
	}
}

int do_flatter(string arg)
{
	object me=this_player(), ob=this_object();

/* 别派也要能拍他马屁！
	if( !me->query_temp("pending/flatter") )
		return 0;
*/
	if( !arg ) return notify_fail("你说老仙什么？\n");
//	ob->set_temp("pending/flatter", 0);
	switch(random(5))
	{
		case 0: message_vision("$N对$n大声赞道：您老人家一蹬足天崩地裂，一摇手日月无光！\n", me,ob); break;
		case 1: message_vision("$N对$n大声赞道：星宿老仙大袖摆动，口吐真言，叫旁门左道牛鬼蛇神，一个个死无葬身之地！\n", me,ob); break;
		case 2: message_vision("$N对$n大声赞道：这天下武林盟主一席，非老仙莫属。只须老仙下令动手，小人赴汤蹈火，万死不辞！\n", me,ob); break;
		case 3: message_vision("$N对$n大声赞道：日月无老仙之明，天地无老仙之大，自盘古氏开天辟地以来，更无第二人能有老仙的威德！\n", me,ob); break;
		case 4: message_vision("$N对$n大声赞道：老仙神功盖世，天下第一，战无不胜，功无不克！\n", me,ob); break;
	}
	message_vision("$N大声说道：" + arg + "\n", me);
	if( strsrch(arg, "星宿老仙") >=0 && (strsrch(arg, "德配天地") >=0 ||
		strsrch(arg, "威震寰宇") >=0 || strsrch(arg, "古今无比") >=0 ))
	{
		if(me->query_temp("pending/flatter"))
		{
			me->set_temp("pending/flatter", 0);
			me->set_temp("ding_flatter", 1);
			command("smile");
			command("say 这还差不多。\n");
			command("recruit " + me->query("id"));
			CHANNEL_D->do_channel(me, "chat",  "星宿老仙，德配天地，威震寰宇，古今无比！");
		}
		else
		{
			command("say 你对老仙我这么恭敬，今后前途不可限量啊！\n");
			me->set_temp("ding_flatter", 1);
			return 1;
		}
	} else
	{
		command("say 你如此不把老仙放在眼里，老仙怎会收你？");
	}
	return 1;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		add("apprentice_available", -1);
}

// 星宿老仙，德配天地，威震寰宇，古今无比

string ask_me()
{
	mapping fam; 
	object ob;
	
	if(!(fam = this_player()->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
	if(query("book_count") < 1) return "你来晚了，本派的内功心法不在此处。";
	add("book_count", -1);
	ob = new("/clone/book/dujing_2");
	ob->move(this_player());
	return "好吧，这本「星宿毒经」你拿回去好好钻研。";
}
string ask_du1()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
	if (this_player()->query_skill("poison",1)<50)
		return "你的毒技火候未到，用不了这种东西。";
	if (query("zhen_count") < 1) return "你来晚了，碧磷针都发完了。";
	add("zhen_count", -1);
	ob = new("/d/xingxiu/obj/bilinzhen");
	ob->move(this_player());
	return "好吧，那你就先用这些针吧。";
}
string ask_du2()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
	if (this_player()->query_skill("poison",1)<100)
		return "你的毒技火候未到，用不了这种东西。";
	if (query("san_count") < 1) return "你来晚了，现在没什么剩的了。";
	add("san_count", -1);
	ob = new("/clone/medicine/poison/sanxiaosan");
	ob->move(this_player());
	return "好吧，这包毒药你拿回去善加利用吧。";
}
string ask_huoyan()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
	if (this_player()->query_skill("poison",1)<100)
		return "你的毒技火候未到，用不了这种东西。";
	if (query("huoyan_count") < -100) return "你来晚了，现在没什么剩的了。";
	add("huoyan_count", -1);
	ob = new("/d/xingxiu/npc/obj/huoyan.c");
	ob->move(this_player());
	return "好吧，我就给你堆火焰吧。";
}

string ask_ding()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
	switch (query("ding_count") )
	{
		case 0:
			command("kick1 "+this_player()->query("id"));
			add("ding_count", 1);
			return "养你们这些忘恩负义的狗娘徒弟有什么用？连个小小的神木王鼎都会偷走！";
		case 1:
			command("sigh "+this_player()->query("id"));
			add("ding_count", 1);
			return "小阿紫把神木王鼎拿走了，谁把她抓回来，谁就是本门大弟子！";
		default: 
			command("grin");
			return "这事我正难受呢，你还这么没眼色老揭伤疤。活够了是不是？";
	}
	return "哼。";
}

string ask_azi()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
	if(query("ding_count") == 2 || this_player()->query_temp("smwd/step"))
	{
		this_player()->set_temp("smwd/step", 1);
		command("kick "+this_player()->query("id"));
		add("ding_count", 1);
		return "阿紫早她娘的跑了！你死人哪！还不快去追？";
	}
	else return "阿紫是个蛮可爱的小马屁精。老夫我喜欢！";
}

string ask_job()
{
	object ob,me = this_player();
 
	if(!me->query("family") || me->query("family/family_name") != "星宿派")
		return "看你对老仙态度恭敬，何不加入我星宿派呢？";
	if(me->query("combat_exp") < 100000) 
		return "哈哈哈，你再加把力练功，很快就可以为老仙我分忧了。";
	if(me->query("shen") >= 0 ||
		me->query("shen") > -(me->query("combat_exp")/10)) 
		return "徒儿，看来你的心肠还不够黑啊，有些事你不问也罢。";
	if(interactive(me) && me->query_temp("job_busy")) 
		return "你说要替老仙分忧，怎么还在这里发呆？";
	if(interactive(me) && me->query_condition("wait_xx_task")) 
		return "老仙现在心情还好，不用你来为我分忧。";
	if(query("di_count") < 1) 
		return "老仙现在心情还好，再来烦我就别怪老仙心情不好了。";

	ob = new(__DIR__"obj/di");
	add("di_count", -1);
	ob->move(me);
	ob->set("name", BLU"蓝玉短笛"NOR);
	ob->set("long", BLU"这玉笛短得出奇，只不来七寸来长、通体碧蓝，晶莹可爱。\n" NOR);
	ob->set("xx_user", getuid(me));
	me->set_temp("xx_job", 1);
	message_vision("$N拿出一只玉制短笛，交给$n。\n", this_object(), me);
	return "老仙我最近心情不佳，徒儿你要多多为我分忧才是！\n";    
}

int do_xian(string arg)
{
	object who, me, ob;
	mapping quest;
	who = this_player();
	me = this_object();

	if(who->is_busy() || who->is_fighting()) 
		return notify_fail("你正忙着呢。\n");
	if(!arg) return notify_fail("你要献给老仙什么东西？\n");
	if(!objectp(ob = present(arg, who)))
		return notify_fail("你身上没有这样东西。\n");
	if(!who->query_temp("xx_job"))
		return notify_fail("连老仙现在的心情还没摸清楚就乱献东西？\n"); 
	message_vision(HIY "\n$n毕恭毕敬地将"+ob->query("name")+HIY"拿出，双手捧上，想要献给$N。\n\n"NOR, me, who);
	if(me->is_busy())
	{
		"/cmds/std/say"->main(this_object(),"我正忙着呢，你等等。");
		return notify_fail("老仙让你等等。\n");
        }
	if(!mapp(quest = who->query_temp("quest")) )
	{
		"/cmds/std/say"->main(this_object(),"你拿个"+ob->name()+CYN"给我干嘛？"NOR);
		return notify_fail("老仙对这东西不感兴趣。\n");
	}
	if( quest["time"] < time())
	{
		"/cmds/std/say"->main(this_object(),"嗯，这么久才办完，你干什么去了？给我滚一边去！");
		who->apply_condition("wait_xx_task", 40);
		return notify_fail("完了，老仙生气了。\n");
	}
	if(userp(ob))
	{
		command("stare " + who->query("id"));
		"/cmds/std/say"->main(this_object(),"竟敢用假货来欺骗本老仙，给我滚出去！");
		message_vision("\n说完$N长袖一挥，一股内劲拂出，就将$n扫出洞外！\n\n", me, who);
		who->move("/d/xingxiu/riyuedong1");
		message("vision","只听“呼”地一声，紧接着"+who->query("name")+"从日月洞里直飞了出来，摔了个四脚朝天！\n", environment(who), who);
		who->receive_wound("jing", 200);
		who->receive_wound("qi", 250);
		who->apply_condition("wait_xx_task", 30);
		who->delete_temp("quest");
		who->set_temp("last_id", quest["last_id"]);  
		who->start_busy(5);
		return notify_fail("糟糕，穿邦了！\n");
	}
	if(ob->query("id") != quest["id"])
	{
		command("hmm " + who->query("id"));
		"/cmds/std/say"->main(this_object(),"你拿个"+ob->query("name")+CYN"给老仙我有什么用？");
		return notify_fail("好象是你献错东西了。\n");
	}
	ob->move(me);
	me->start_busy(2);
	call_out("destroying", 0, ob, me);
	call_out("done", 3, who);       
	return 1;
}

void done(object me)
{
	int hgdf, poison;
	mapping fam;
  
	if(!me) return;
	hgdf = me->query_skill("huagong-dafa",1);
	poison = me->query_skill("poison",1);
	fam = (mapping)me->query("family");

	command("pat " + me->query("id"));       
	command("say 不错不错，既然你找到了老仙我想要的东西，我就指点指点你吧。");
	if(fam["family_name"] == "星宿派")
	{
		if(hgdf < 180 && SKILL_D("huagong-dafa")->valid_learn(me))
			me->improve_skill("huagong-dafa", me->query("xx_points")*5);   
		if(poison < 150 && SKILL_D("poison")->valid_learn(me))
			me->improve_skill("poison", me->query("xx_points")*5);
		me->add("xx_points", 1);          
		tell_object(me, "你目前已经为老仙分担了"+chinese_number(me->query("xx_points"))+"次忧愁。\n");
		me->add("family/fealty",me->query("xx_points"));
		tell_object(me, "你的门派忠诚度上升了。\n");
	}
	call_out("ok", 0, me);                    
}

void destroying(object obj, object me)
{
	message_vision("$N拿起$n仔细地端详了一会儿，满意地点了点头，脸上露出了笑容。\n", me, obj);
	destruct(obj);
}

void ok(object me)
{
	mapping quest;
	if(!me) return;
   
	quest = me->query_temp("quest");
	tell_object(me, "你听了老仙的指点，功夫进步了不少！\n"); 
	tell_object(me, GRN"你获得出"+chinese_number(quest["pot_reward"])+"点潜能和"+chinese_number(quest["exp_reward"])+"点经验的奖励！\n"NOR);
	me->add("combat_exp", quest["exp_reward"]);
	me->add("potential", quest["pot_reward"]);
	me->add("shen", -(quest["exp_reward"]*15));
	me->delete_temp("quest");
	me->set_temp("last_id", quest["last_id"]);     
//	me->apply_condition("job_busy", 3);  
	me->clear_condition("job_busy");
	return;
}

string ask_yinlinfen()
{
	mapping fam; 
	object ob;
	object owner;
	object temp;
	object me=this_player();
	if (!(fam = me->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
	if (me->query_skill("poison",1)<100)
		return "你的毒技火候未到，用不了这种东西。";
	ob=new(YINLINFEN);
	if (temp=ob->violate_unique())
	 {
	 	destruct(ob);
	 	ob=temp;
  	owner = environment(ob);
  	if (owner == me)
     return ob->query("name")+"不就在你手中吗？";
  	if (objectp(owner) && owner != this_object())
     {
      if (! owner->is_character())
           return "你来晚了，"+ob->query("name")+"现在不在我手中。";
      if (owner->query("family/family_name") == "星宿派")
           return ob->query("name")+"现在在本派" + owner->query("name") +"手中，你要用就去找他吧。";
      else
           return "我正为此事担忧呢，"+ob->query("name")+"现在落入了" + owner->query("name") +"之手，你快去把他杀了，把东西取回来！";
     }
  }
	command("nod");
  ob->move(this_object());
  command("give fen to " + me->query("id"));
  return "这"+ob->query("name")+"你便拿去，希望你能好好利用。";
}

string ask_duchongfen()
{
	mapping fam; 
	object ob;
	object owner;
	object temp;
	object me=this_player();
	if (!(fam = me->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
	if (me->query_skill("poison",1)<100)
		return "你的毒技火候未到，用不了这种东西。";
	ob=new(DUCHONGFEN);
	if (temp=ob->violate_unique())
	 {
	 	destruct(ob);
	 	ob=temp;
  	owner = environment(ob);
  	if (owner == me)
     return ob->query("name")+"不就在你手中吗？";
  	if (objectp(owner) && owner != this_object())
     {
      if (! owner->is_character())
           return "你来晚了，"+ob->query("name")+"现在不在我手中。";
      if (owner->query("family/family_name") == "星宿派")
           return ob->query("name")+"现在在本派" + owner->query("name") +"手中，你要用就去找他吧。";
      else
           return "我正为此事担忧呢，"+ob->query("name")+"现在落入了" + owner->query("name") +"之手，你快去把他杀了，把东西取回来！";
     }
  }
	command("nod");
  ob->move(this_object());
  command("give fen to " + me->query("id"));
  return "这"+ob->query("name")+"你便拿去，希望你能好好利用。";
}

string ask_honglinfen()
{
	mapping fam; 
	object ob;
	object owner;
	object temp;
	object me=this_player();
	if (!(fam = me->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
	if (me->query_skill("poison",1)<100)
		return "你的毒技火候未到，用不了这种东西。";
	ob=new(HONGLINFEN);
	if (temp=ob->violate_unique())
	 {
	 	destruct(ob);
	 	ob=temp;
  	owner = environment(ob);
  	if (owner == me)
     return ob->query("name")+"不就在你手中吗？";
  	if (objectp(owner) && owner != this_object())
     {
      if (! owner->is_character())
           return "你来晚了，"+ob->query("name")+"现在不在我手中。";
      if (owner->query("family/family_name") == "星宿派")
           return ob->query("name")+"现在在本派" + owner->query("name") +"手中，你要用就去找他吧。";
      else
           return "我正为此事担忧呢，"+ob->query("name")+"现在落入了" + owner->query("name") +"之手，你快去把他杀了，把东西取回来！";
     }
  }
	command("nod");
  ob->move(this_object());
  command("give fen to " + me->query("id"));
  return "这"+ob->query("name")+"你便拿去，希望你能好好利用。";
}

string ask_bingpofen()
{
	mapping fam; 
	object ob;
	object owner;
	object temp;
	object me=this_player();
	if (!(fam = me->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
	if (me->query_skill("poison",1)<100)
		return "你的毒技火候未到，用不了这种东西。";
	ob=new(BINGPOFEN);
	if (temp=ob->violate_unique())
	 {
	 	destruct(ob);
	 	ob=temp;
  	owner = environment(ob);
  	if (owner == me)
     return ob->query("name")+"不就在你手中吗？";
  	if (objectp(owner) && owner != this_object())
     {
      if (! owner->is_character())
           return "你来晚了，"+ob->query("name")+"现在不在我手中。";
      if (owner->query("family/family_name") == "星宿派")
           return ob->query("name")+"现在在本派" + owner->query("name") +"手中，你要用就去找他吧。";
      else
           return "我正为此事担忧呢，"+ob->query("name")+"现在落入了" + owner->query("name") +"之手，你快去把他杀了，把东西取回来！";
     }
  }
	command("nod");
  ob->move(this_object());
  command("give fen to " + me->query("id"));
  return "这"+ob->query("name")+"你便拿去，希望你能好好利用。";
}
