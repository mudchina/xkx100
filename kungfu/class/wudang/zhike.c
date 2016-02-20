// zhike.c 灵虚

#include <ansi.h>
#include "daozhang.h"
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()  
{
	set_name("灵虚道长", ({ "lingxu daozhang", "lingxu", "daozhang" }));
	set("long", "他是武当山的知客道长，是宋远桥的弟子。守在山门迎接香客。\n");
	set("gender", "男性");
	set("nickname", "知客道长");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "taoist");
	set("no_get", 1);
	set("no_steal",1);
	set("owner","mud_os");
	set("quest_no_guard",1);

	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 300);
	set("max_neili", 300);

	set("combat_exp", 50000);
	set("score", 1000);

	set_skill("force", 60);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	set_skill("wudang-jian", 20);
	set_skill("wudang-quan", 20);
	set_skill("taoism", 20);

	map_skill("parry", "wudang-jian");
	map_skill("sword", "wudang-jian");
	map_skill("unarmed", "wudang-quan");

	set("chat_chance",2);
	set("chat_msg", ({
		 "灵虚道长说道：我武当地灵人杰，香火鼎盛，普天下的人都来朝拜敬香。\n",
		 "灵虚道长说道：玄岳门乃武当出入门户，我等一定要精心守卫(volunteer)，不可丝毫懈殆。\n"
		 "灵虚道长说道：香火练制不易，不能随便与人，虔诚奉献者方能得之。\n",
		 "灵虚道长说道：我武当地灵人杰，香火鼎盛，普天下的人都来朝拜敬香。\n",
		 "灵虚道长说道：听说山门前的松林里有异果，有砍树的道士进去找，就再也没有出来。\n",
	}));

	set("inquiry", ([
		"香火" : "香火练制不易，不能随便与人，虔诚奉献者方能得之。",
		"进香" : "进香？童言无忌！童言无忌！要说敬香才是！",
		"敬香" : "殿堂的香火能绵延不断，都因为我武当弟子和山外香客及时敬奉。",
		"虔诚奉献" : "虔诚奉献就是主动多捐献香火钱，多作义工。",
		"敬奉" : "虔诚奉献就是主动多捐献香火钱，多作义工。",
		"松林" : "武当松林在山门前面。",
		"柏林" : "武当柏林就在遇真宫后。",
		"name" : "我是武当的知客道长，负责守卫山门。",
		"here" : "这里是武当的玄岳门，一直南上就可到紫霄宫。",
		"rumors" : "听说山门前的松林里有异果，不知是真是假。"
		"可是有砍树的道士进去找，就再也没有出来。\n",
		"守卫" : "我这里的工作就是守卫(volunteer)山门，每次守一天。\n",
		"工作" : "我这里的工作就是守卫(volunteer)山门，每次守一天。\n",
		"干活" : "我这里的工作就是守卫(volunteer)山门，每次守一天。\n",
	]));
	create_family("武当派", 3, "弟子");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
	carry_object(CLOTH_DIR"dao-shoe")->wear();
}

void init()
{
	int i,flag=0;
	object *ob;
	object me = this_player();
	object daozhang= this_object();
	object meng;
	
	::init();
	if (environment() != load_object("/d/wudang/xuanyuegate") ) return;

	add_action("do_volunteer","volunteer");

	if( !is_fighting() && living(this_object()))
	{
		if(interactive(me))
		{
			if(meng=present("mengmian  ren", environment(me)))
			{
				flag=0;
				ob = all_inventory(environment(me)); 
				for(i=0; i<sizeof(ob); i++) 
				{
					if(ob[i]->query_temp("in_guard_wd"))
					flag=1;
				}
				if( flag==0 )			
				{
				message_vision("只听灵虚道长一声怒喝：大胆毛贼竟敢在武当山上行凶杀人，\n且让贫道手中长剑教训教训你！\n", me);
				daozhang->kill_ob(meng);
				meng->kill_ob(daozhang);
				}
			}
			else
			{
				remove_call_out("greeting");
				call_out("greeting", 1, me);
			}
		}
		else
			if(base_name(me) == "/clone/quest/questshouwei_wd")
			{
				message_vision("只听灵虚道长一声怒喝：大胆毛贼竟敢在武当山上行凶杀人，\n且让贫道手中长剑教训教训你！\n", me);
				flag=0;
				ob = all_inventory(environment(me)); 
				for(i=0; i<sizeof(ob); i++) 
				{
					if(ob[i]->query_temp("in_guard_wd"))
					flag=1;
				}
				if( flag==0 )			
				{
					me->kill_ob(this_object()); // me=mengmianren
				}
			}
	}
}

void greeting(object ob)
{
	mapping myfam;
	if (environment(this_object())!=environment(ob))
	return;
	myfam = ob->query("family");
	if ( myfam && myfam["family_name"] == "武当派" )
		command("say 这位道"+(((string)ob->query("gender")=="女性")?"姑":"兄")+"辛苦了！");
	else if ( ob->query("title") == "武当道童" )
		say("灵虚道长对"+ob->name()+"说道：这位"+RANK_D->query_respect(ob)+"还要继续努力啊！\n");
	else if ( ob->query("shen") > -100 ) 
		say("灵虚道长作了个揖道：这位" + RANK_D->query_respect(ob) + "请了，欢迎来到武当山！\n");
	else	say("灵虚道长「唰」抽出长剑：这位" + RANK_D->query_respect(ob) + "满脸杀气，如果不是来武当敬香就请回吧！\n");
}

int do_volunteer()
{
	object me=this_player();
	object* ob;
	int i;

	if (me->query("class") == "office") 
		return notify_fail("灵虚道长对你说：你身入官府，贫道岂敢委曲你。\n");
	if (me->query_temp("in_guard_wd")) 
		return notify_fail("灵虚道长对你说：你专心守好山门，别想打两份工。\n");
	if (base_name(me) == "/d/taohuacun/npc/baby" 
	|| me->query("combat_exp")<100000)
		return notify_fail("灵虚道长说到：黄毛小儿怎能担此重任！\n");
	ob = users();
	for (i=sizeof(ob); i>0; i--)
	{
		if (ob[i-1]->query_temp("in_guard_wd"))
			return notify_fail("灵虚道长对你说：已经有人守山门了，你一会再来吧。\n");
	}
	tell_room(environment(me),me->query("name")+"开始在武当山门值守。\n");
	command("sys 武当守卫开始！");
	me->set("guard", HIG"山门守卫"NOR);
	me->set_temp("in_guard_wd","1");
	me->save();
	me->delete_temp("in_guard_wd_num");
	me->set_temp("in_guard_wd_num",0);
	remove_call_out("end_guard");
	call_out("end_guard", 245, me);
	remove_call_out("clone_meng");
	call_out("clone_meng", 5, me);
	remove_call_out("check_fight");
	call_out("check_fight",3,me);
	return 1;
}
void clone_meng(object me)
{
	mapping name, hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;	
	object obj, thief_master, weapon;
	object *ob_list;
	mapping skl;
	string *skillname;
	object where;
	int skilllvl,topexp;
	int i,j,k;
	object *inv;
	string *family, weapon_type;
  string *masters = ({
	"baituo/ouyangfeng",	//lingshe-zhangfa	shexing-diaoshou hamagong
	"dali/duanzc",	//duanyun-fu		sun-finger
	"dali/daobaifeng",	//feifeng-whip		jinyu-quan 	wuluo-zhang
	"dali/yideng",	//duanjia-sword		six-finger
	"emei/miejue",	//huifeng-jian		jinding-zhang 	tiangang-zhi
	"emei/feng",         //yanxing-dao		jinding-zhang 	tiangang-zhi
	"gaibang/hong",		//dagou-bang		xianglong-zhang	suohou-hand
	"gaibang/jian",		//fengmo-staff		jianlong-zaitian
	"gumu/longnv",	//yunv-jian		meinv-quan
	"gumu/limochou",	//qiufeng-chenfa	meinv-quan
	"gumu/yangguo",	//xuantie-sword		anran-zhang
	"heimuya/dongfang",	//bixie-jian		xuantian-zhi
	"heimuya/ren",		//wuyun-jian		xuantian-zhi
	"heimuya/weng",		//shigu-bifa		xuantian-zhi
	"hengshan/xian",		//hengshan-jian		tianchang-zhang	chuanyun-shou
	"henshan/moda",		//hengshan-sword	biluo-zhang	luoyan-hand
	"honghua/chen-jialuo",	//luohua-jian		benlei-shou	baihua-cuoquan
	"honghua/wu-chen",	//zhuihun-jian		benlei-shou
	"huashan/yue-buqun",	//huashan-sword		huashan-ken
	"huashan/feng-buping",	//kuangfeng-jian	poyu-quan	hunyuan-zhang
	"huashan/feng",		//lonely-sword		poyu-quan	hunyuan-zhang
	"kunlun/hezudao",	//liangyi-sword		kunlun-strike
	"kunlun/hetaichong",	//xunlei-sword		zhentian-cuff	chuanyun-leg
	"lingjiu/tonglao",	//tianyu-qijian		liuyang-zhang	zhemei-shou
	"lingxiao/bai",		//xueshan-sword		snow-strike
	"lingxiao/shipopo",	//jinwu-blade		snow-strike
	"mingjiao/zhangwuji",	//shenghuo-ling		qishang-quan
	"mingjiao/yintianzheng",	//lieyan-dao		sougu
	"mingjiao/weiyixiao",	//liehuo-jian		hanbing-mianzhang
	"murong/murong-fu",	//murong-sword		canhe-finger	xingyi-strike
	"nanshaolin/tianhong",	//weituo-chu		jingang-cuff
	"nanshaolin/tianjing",	//riyue-whip		wuxiang-finger
	"qingcheng/yu",		//songfeng-jian		wuying-leg	cuixin-strike
	"quanzhen/wang",		//quanzhen-jian		chunyang-quan	haotian-zhang
	"quanzhen/ma",		//duanyun-bian		chunyang-quan	haotian-zhang
	"shaolin/da-mo",	//			nianhua-zhi	sanhua-zhang
	"shaolin/xuan-nan",	//wuchang-zhang		yizhi-chan  banruo-zhang
	"shaolin/du-nan",	//riyue-bian		jingang-quan
	"shenlong/hong",		//ruyi-hook		yingxiong-sanzhao	shenlong-bashi
	"shenlong/su",		//meiren-sanzhao	jueming-leg	huagu-mianzhang
	"shenlong/pang",		//shenlong-staff	huagu-mianzhang	jueming-leg
	"songshan/zuo",		//songshan-sword	songyang-strike	poyun-hand
	"taishan/tianmen",	//taishan-sword		kuaihuo-strike
	"taohua/huang",	//yuxiao-jian		tanzhi-shentong	lanhua-shou
	"taohua/lu",		//luoying-shenjian	xuanfeng-leg	luoying-zhang
	"tiezhang/qqren",	//			tiezhang-zhangfa
	"tiezhang/qqzhang",	//tiexue-qiang		zhusha-zhang
	"wudang/zhang",	//taiji-jian		taiji-quan
	"wudang/yu",		//liangyi-jian		taiji-quan
	"wudujiao/hetieshou",	//wudu-goufa		wudu-zhang	qianzhu-wandushou
	"xiaoyao/xiaoyaozi",	//ruyi-dao		zhemei-shou	liuyang-zhang
	"xingxiu/ding",		//			chousui-zhang	sanyin-wugongzhao
	"xingxiu/chuchen",	//tianshan-zhang	chousui-zhang	sanyin-wugongzhao
	"xueshan/jiumozhi",	//			huoyan-dao
	"xueshan/fawang",	//riyue-lun		dashou-yin	yujiamu-quan
	"xueshan/xuedao",	//xue-dao		dashou-yin
	"yunlong/chen",		//yunlong-jian		yunlong-zhua	yunlong-shou
	});
	
	ob_list = children("/clone/quest/questshouwei_wd");
        for(i=0; i<sizeof(ob_list); i++) 
	if(environment(ob_list[i]))
	{
		message_vision(HIW"\n$N叫道：今日天色已晚，先放过你们。等我改日再来踏平武当！\n"NOR,ob_list[i]);
		destruct(ob_list[i]);
  }
  seteuid(getuid());
	obj = new("/clone/quest/questshouwei_wd");
	if (!clonep(obj)) 
	obj = new("/clone/quest/questshouwei_wd");
	obj ->set("owner", me->query("id"));
	obj ->set("quest", "guard_wd");
	if (random(2) == 0)
	{
		obj->set("gender", "女性");
	}
	else
	{
		obj->set("gender", "男性");
	}

	hp_status = me->query_entire_dbase();
	
//	obj->set("str", hp_status["str"]+ 15);
	obj->set("str", hp_status["dex"]+ 15);
	obj->set("int", hp_status["int"]);
	obj->set("con", hp_status["con"]);
//	obj->set("dex", hp_status["dex"]+ 15);
	obj->set("dex", hp_status["str"]- 5);
	obj->set("age", hp_status["age"]+ 2);

	obj->set("max_jing",  hp_status["max_jing"]*2);
	obj->set("eff_jing",  hp_status["max_jing"]*2);
	obj->set("jing",      hp_status["jing"]*2);

	obj->set("max_qi", hp_status["max_qi"]*2);
	obj->set("eff_qi", hp_status["max_qi"]*2);
	obj->set("qi",     hp_status["max_qi"]*2);//守门任务 不一定都要杀

	obj->set("max_neili", hp_status["max_neili"]);//*2
	if (hp_status["neili"] <= hp_status["max_neili"])
  obj->set("neili",      hp_status["max_neili"]);
	else if (hp_status["neili"] >= hp_status["max_neili"]*2)
  obj->set("neili",      hp_status["neili"]*5);
  else
	obj->set("neili",     hp_status["max_neili"]*2);
	obj->set("jiali",     hp_status["max_neili"]/30);// /40
	
	topexp = (int) me->query("combat_exp");
	obj->set("combat_exp", topexp*3/5 + random(topexp/2));
	
/* 1000万以上玩家，在此长正气或戾气 */
	if(me->query("combat_exp") > 10000000)
		obj->set("shen", hp_status["shen"]);
	
/* skill */
	skl = me->query_skills();
	skilllvl=50;	
	if (sizeof(skl))
	{
		skillname = sort_array( keys(skl), (: strcmp :) );
		for (j=0; j<sizeof(skl); j++)
		{
			if (skilllvl < skl[skillname[j]])
				skilllvl = skl[skillname[j]];
		}
		skilllvl = skilllvl*3/5+random(skilllvl/2);		
	}

	i = random( sizeof(masters) );
	thief_master = new ( CLASS_D(masters[i]) );
	if ( mapp(skill_status = thief_master->query_skills()) )
	{
		skill_status = thief_master->query_skills();
		sname = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++)
		{
			obj->set_skill(sname[i], skilllvl);
		}
	}
/* skill map*/
	if ( mapp(map_status = thief_master->query_skill_map()) )
	{
		mname = keys(map_status);

		for(i=0; i<sizeof(map_status); i++)
		{
			obj->map_skill(mname[i], map_status[mname[i]]);
		}
	}
/* skill prepare*/
	if ( mapp(prepare_status = thief_master->query_skill_prepare()) )
	{
		pname = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++)
		{
			obj->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}
	inv = all_inventory(thief_master);
	for ( i = 0; i < sizeof(inv); i++ )
		if( inv[i]->query("equipped") && stringp(weapon_type = inv[i]->query("skill_type")) )
		{
			weapon = new( "/clone/weapon/" + weapon_type );			
			weapon->set("value", 0);
			weapon->move( obj );			
			weapon->wield();
		}
 	destruct( thief_master );
 	where = find_object("/d/wudang/xuanyuegate");
 	if (!where) where = load_object("/d/wudang/xuanyuegate");
 	tell_room(where,"山下突然冲上来一伙蒙面人。\n");
 	obj->move(where);
 	if (environment(me) == where )
 	{ 
 		me->kill_ob(obj);
 		obj->kill_ob(me);
 		me->add_temp("in_guard_wd_num",1);
 	}
	call_out("clone_meng", 60, me);
	remove_call_out("check_fight");
	call_out("check_fight",5,me);
}
void end_guard(object me)
{
	int exp, pot, num, times, e_bonus, p_bonus, s_bonus,i;
	object *ob_list;
	mapping fam;
	object *ob;
	string err;
	ob = all_inventory(environment(me)); 
	for(i=0; i<sizeof(ob); i++) 
	{
		if (ob[i]->is_character() || ob[i]->query("no_get")||ob[i]->query("taskobj"))
		    continue;
		else destruct(ob[i]);
	}
	fam = me->query("family");
	ob_list = children("/clone/quest/questshouwei_wd");
  for(i=0; i<sizeof(ob_list); i++) 
	if(environment(ob_list[i]))
	{
		message_vision(HIW"\n$N叹道：武当果然名不虚传，我改日再来拜访！\n"NOR,ob_list[i]);
		destruct(ob_list[i]);
  }
  if (environment(me) != load_object("/d/wudang/xuanyuegate") ) 
  	{
  		remove_call_out("check_fight");
			remove_call_out("clone_meng");
	  	return;
	  }
	if (me->query_temp("in_guard_wd"))
	{
	        num=(int)me->query("perform/number")+1;
	        if (num<4) times=num;
	        else times=4;
		
		exp = (int) me->query("combat_exp");
		e_bonus = (int)me->query_temp("in_guard_wd_num")*150+random(30);
		exp += e_bonus;
		pot = (int) me->query("potential");
		p_bonus = (int)me->query_temp("in_guard_wd_num")*50+random(10);
		pot += p_bonus;	
	
    if (!(fam = me->query("family")) || fam["family_name"] != "武当派") 
    		s_bonus = 0;
     else  
     		s_bonus = random(10)+ 15 * times;                
		
		me->delete("guard");
		me->add("wudang/offerring", random(2));
    log_file("mission/ms_volunteer",sprintf("%20s做守山门任务，得到：%4i点EXP和%4i点潜能。\n",
       me->query("name")+"("+getuid(me)+")",e_bonus,p_bonus));
		me->set("combat_exp", exp);
		me->set("potential", pot);
    me->add("family/fealty", s_bonus);
	me->set_temp("prize_reason","山门");
	me->set_temp("can_give_prize",1);
	me->set_temp("prize_exp",e_bonus);
	me->set_temp("prize_pot",p_bonus);
		me->delete_temp("in_guard_wd");
		me->delete_temp("in_guard_wd_num"); 
		if (s_bonus > 0)
		tell_object(me, HIW + "经过这番历练，你获得了" + chinese_number(e_bonus) + "点实战经验，" + chinese_number(p_bonus) + "点潜能，" + chinese_number(s_bonus) + "点忠诚度。\n"NOR);
	  else 
		tell_object(me, HIW + "经过这番历练，你获得了" + chinese_number(e_bonus) + "点实战经验，" + chinese_number(p_bonus) + "点潜能。\n"NOR);
	}
	remove_call_out("clone_meng");
	remove_call_out("check_fight");
	tell_room(environment(me),me->query("name")+"在武当山门值守期已满。\n",({me}));
	tell_object(me,"你在武当山门值守期已满。\n");
}
void check_fight(object me)
{
	int i,flag=0;
	object *ob;
	object *ob_list;
	ob_list = children("/clone/quest/questshouwei_wd");
	
	flag=0;
	ob = all_inventory(environment(me)); 
	for(i=0; i<sizeof(ob); i++) 
	{
		if(ob[i]->query_temp("in_guard_wd") && ob[i]->is_fighting()) flag=1;
	}
	if( flag==0 )			
	{
		for(i=0; i<sizeof(ob_list); i++)
		{
			if (environment(ob_list[i]) == load_object("/d/wudang/xuanyuegate") )
				this_object()->kill_ob(ob_list[i]);
		}
//		message_vision("只听灵虚道长一声怒喝：大胆毛贼竟敢在武当山上行凶杀人，\n且让贫道手中长剑教训教训你！\n", me);
	}
	remove_call_out("check_fight");
	call_out("check_fight",5,me);
}
void die()
{
	object *me;
	int i;
	object *ob_list;
	
	ob_list = children("/clone/quest/questshouwei_wd");
  for(i=0; i<sizeof(ob_list); i++) 
	if(environment(ob_list[i]))
	{
		message_vision("$N叹道：哈哈，看来武当也不过是徒有虚名啊！\n",ob_list[i]);
		destruct(ob_list[i]);
  }

	me = users();
	for (i = 0; i < sizeof(me); i ++)
		me[i]->delete_temp("in_guard_wd"); 

	::die();
}

int accept_object(object who, object ob)
{
	object obn, wage;
	int i, j;
	string *wanted;
	if (ob->query("money_id") && ob->value() >= 100*(int)who->query("age") )
	{
		if ((string)(who->query("family/family_name")) == "武当派") 
			tell_object(who, "灵虚道长哈哈一笑：既然道"+(((string)who->query("gender")=="女性")?"姑":"兄")+"如此诚心向道，我这有新制香火一枝，请拿去贡奉吧。\n");
		else
			tell_object(who, "灵虚道长哈哈一笑：既然施主如此诚心向道，我这有新制香火一枝，请施主拿去贡奉吧。\n");
		obn = new("/d/wudang/obj/incense");
		obn->move(who);
		return 1;
	}
	else
		if (ob->query("money_id") )     
		{
			if((string)(who->query("family/family_name"))=="武当派")
				tell_object(who, "灵虚道长对你赞叹道：武当山香火鼎盛，全靠象道"+(((string)who->query("gender")=="女性")?"姑":"兄")+"你这样捐献香火啊！\n");
			else  
				tell_object(who, "灵虚道长对你赞叹道：武当山香火鼎盛，全靠象您这样的虔诚香客啊！\n");
			return 1;
		}
	return 0;
}

