// zhudanchen.c 朱丹臣

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void upgrade_title(object me,string arg);
string clear_title(string arg);
int ask_me();
string ask_job();
string ask_cancle();
void create()
{
	set_name("朱丹臣", ({ "zhu danchen", "zhu" }));
	set("title",  "大理护卫" );
	set("long", "他是大理国四大护卫之一。一副书生酸溜溜的打扮行头。\n");
	set("gender", "男性");
	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 30);
	set("con", 25);
	set("dex", 25);
	set("no_get",1);
	
	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 350000);
	set("score", 110000);

	set_skill("force", 55);
	set_skill("dodge", 50);
	set_skill("parry", 55);
	set_skill("cuff", 50);
	set_skill("sword", 55);
	set_skill("staff", 80);
	set_skill("kurong-changong", 55);
	set_skill("tiannan-step", 70);
	set_skill("jinyu-quan", 70);
	set_skill("duanjia-sword", 75);
	set_skill("literate", 90);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jingtian" :),				
		(: exert_function, "powerup" :),		
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

	set("inquiry", ([
		"指点武功" : (: ask_me :),
		"巡城" : (: ask_job :),
		"取消" : (: ask_cancle :),
	]));
	setup();
	carry_object("/d/dali/npc/obj/junfu")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 10);

	create_family("大理段家",19,"护卫");
}
void init()
{
	add_action("do_task","xuncheng");
}
object create_thief( )
{
	mapping name, hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;	
	object obj, thief_master, weapon;
	mapping skl;
	string *skillname;
	int skilllvl,topexp;
	int inc_exp,inc_lvl,i,j,k;
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
	seteuid(getuid());
	obj = new("/clone/quest/questxuncheng");
	if (random(2) == 0)
	{
	    	name = NAME_D->woman_name();
		obj->set("gender", "女性");
	}
	else
	{
		name = NAME_D->man_name();
		obj->set("gender", "男性");
	}       
/* skilllvl && exp */
      skilllvl=80;
      topexp=150000;            		
      obj->set("combat_exp", topexp); 
/* skill */	
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
	return obj;
}
string ask_job()
{
	string *file;
	object me=this_object();
	object ob=this_player();
	object thief , room;
	mapping skill_status,skl;
        string *sname;
        string *skillname;
        int i,j,skilllvl,num_thief,t;
        
	if (ob->query_temp("xuncheng"))
		return ("你不是已经领了巡城的任务吗？还不快去做。\n");
	if (ob->query("combat_exp")<100000 && !wizardp(ob))
		return ("你武功太低，无法胜任。\n");
	if (me->query("xuncheng_star")==1)
		return ("现在已经有人前去巡城，你等等再来吧！\n");
//同时出现5－10个npc 
	num_thief=5+random(6);
	for( t=0;t<num_thief;t++)
	{
	    thief=create_thief();
	    file = get_dir("/d/dali/");
	    j = random(sizeof(file));
  		 if (		sscanf(file[j],"%*s.c") !=1  )
 	  	 		file[j]="/d/dali/taihejiekou";
     if(!( room = find_object("/d/dali/"+file[j]) ))
	  	 		room = load_object("/d/dali/"+file[j]);
     if( room->query("no_fight")|| room->query_max_encumbrance() < 10000000)	        
		 room = load_object("/d/dali/taihejiekou");	      
 	    thief->set("combat_exp",ob->query("combat_exp")*6/5);
	    thief->set("max_neili",ob->query("max_neili"));
	    thief->set("neili",ob->query("max_neili"));
	    thief->set("jiali",(int)ob->query("max_neili")/25);
	    thief->set("max_qi",ob->query("max_qi")*2);
	    thief->set("qi",ob->query("max_qi")*2);	    
	    skl = ob->query_skills();
            skilllvl=50;	
	    if (sizeof(skl))
	       {
	        skillname = sort_array( keys(skl), (: strcmp :) );
	        for (j=0; j<sizeof(skl); j++)
		    {
		     if (skilllvl < skl[skillname[j]])
			skilllvl = skl[skillname[j]];
		    }				
	        }
        //   if (skilllvl>=300)  skilllvl=skilllvl*5/6;
             skill_status = thief->query_skills();
	     sname = keys(skill_status);
	     for(i=0; i<sizeof(skill_status); i++)	        
	         thief->set_skill(sname[i], skilllvl);
	     thief->set("owner",ob->query("id"));	     
	     thief->add_temp("apply/dodge",50);
	     thief->move(room);
	 }
    	ob->set_temp("xuncheng",1);
    	me->set("xuncheng_star",1);
    	me->remove_call_out("new_give_job");
	call_out("new_give_job",420,me);
	if (!wizardp(ob)) ob->delete_temp("dali_xc");
	ob->apply_condition("dali_xuncheng",random(6)+15);
	return "好吧，最近大理城内治安混乱，你就在代我四处查看一下，巡城时应当留心体察民情，为民除害！";
}

string ask_cancle()
{
	object me=this_object();
	object ob=this_player();
	
	if (!ob->query_temp("xuncheng"))
		return ("你并没有领任务！取消什么？\n");
	if (ob->query_condition("dali_xuncheng"))
	        return ("你任务时间还没过！取消什么？\n");
	ob->delete_temp("xuncheng");
	ob->delete_temp("dali_xc");
	ob->delete_temp("xuncheng_kill_num");
	return "好吧，看来你不能胜任这项任务，我再找他人吧！";
}

int do_task(string arg)
{
	object ob,me;
	mapping fam;
	int pot,exp,sil,score,s_bonus,num,times;
	string t;
	ob=this_player();
	me=this_object();
	if(!(arg||arg=="ok")) return 0;
	if(!ob->query_temp("xuncheng")) 
		return notify_fail("你没巡城跑来领什么功？\n");
	if (interactive(ob) && (int)ob->query_condition("dali_xuncheng"))
	{
		command("angry "+ob->query("id"));
		return notify_fail(RED "你这么快回来了，是不是有些地方只是马马虎虎看看？\n"NOR);
	}
	if (!wizardp(ob))
	{
	if(!(ob->query_temp("dali_xc/yxs") &&
		ob->query_temp("dali_xc/dlg2") &&
		ob->query_temp("dali_xc/sl") &&
		ob->query_temp("dali_xc/lg2") &&
		ob->query_temp("dali_xc/lg4")))
		return notify_fail("你是不是偷懒，城东漏了些地方没巡？\n");

	if(!(ob->query_temp("dali_xc/ddh") &&
		ob->query_temp("dali_xc/wymj1") &&
		ob->query_temp("dali_xc/wymj2") &&
		ob->query_temp("dali_xc/cwcp") &&
		ob->query_temp("dali_xc/sl1") &&
		ob->query_temp("dali_xc/sl2") &&
		ob->query_temp("dali_xc/zyd")))
		return notify_fail("你是不是偷懒，城北漏了些地方没巡？ \n");

	if(!(ob->query_temp("dali_xc/qzl") &&
		ob->query_temp("dali_xc/nt1") &&
		ob->query_temp("dali_xc/zl2") &&
		ob->query_temp("dali_xc/zl5") &&
		ob->query_temp("dali_xc/yl") &&
		ob->query_temp("dali_xc/st") &&
		ob->query_temp("dali_xc/lk") &&
		ob->query_temp("dali_xc/flh") &&
		ob->query_temp("dali_xc/yj")))
		return notify_fail("你是不是偷懒，城南漏了些地方没巡？ \n");

	if(!(ob->query_temp("dali_xc/nh1") &&
		ob->query_temp("dali_xc/bls") &&
		ob->query_temp("dali_xc/wymj4") &&
		ob->query_temp("dali_xc/gls") &&
		ob->query_temp("dali_xc/tt") &&
		ob->query_temp("dali_xc/mnd") &&
		ob->query_temp("dali_xc/jsdw")))
		return notify_fail("你是不是偷懒，城西漏了些地方没巡？ \n");
	}
	if(arg=="ok")
	{
		command("pat "+ob->query("id"));
		command("say 哈哈，真难为你了，"+RANK_D->query_respect(ob)+"，你做得好！");

                num=(int)ob->query("perform/number")+1;
                if (num<4) times=num;
                 else times=4;
                if (!(fam = ob->query("family")) || fam["family_name"] != "大理段家") s_bonus = 0;
                 else s_bonus=random(10)+ 15 * times;
		
		sil=(int)(ob->query_skill("force",1)/10)+random(5);
		pot=12+random(12)+100*(int)ob->query_temp("xuncheng_kill_num");
		exp=30+random(30)+200*(int)ob->query_temp("xuncheng_kill_num");
		score= 10 + 30*(int)ob->query_temp("xuncheng_kill_num");
		ob->add_money("silver",sil);
		command("give "+ob->query("id")+" "+sil+" silver");
		ob->add("potential",pot);
		ob->add("score",score);
		ob->add("combat_exp",exp);
  	ob->set_temp("prize_reason","巡城"); //活人奖励四个标识
  	ob->set_temp("can_give_prize",1);
  	ob->set_temp("prize_exp",exp);
  	ob->set_temp("prize_pot",pot);
    if (ob->query("family/family_name")==this_object()->query("family/family_name"))
      ob->add("family/fealty", s_bonus);    
		ob->add("dali_job",1);
		ob->delete_temp("xuncheng");
		ob->delete_temp("dali_xc");
		ob->delete_temp("xuncheng_kill_num");
		t = HIW" 你被奖励了：\n" + 
			chinese_number(exp) + "点实战经验\n" +
			chinese_number(pot) + "点潜能\n"+
			chinese_number(score)+"点江湖阅历\n";
		if (ob->query("family/family_name")==this_object()->query("family/family_name"))
		t += chinese_number(s_bonus)+"点忠诚度\n";
		t += chinese_number(sil)+"两白银\n"+
			"你为镇南王府做了"+ob->query("dali_job")+"次工作。\n"NOR;
		tell_object(ob,t);
		return 1;
	}
	return 1;
}

int new_give_job()
{       
	object *ob_list;
	int i;
	ob_list = children("/clone/quest/questxuncheng");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
			message_vision("$N说道：大爷还有事要忙，没空陪你啦！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
   	this_object()->delete("xuncheng_star", 1);
} 

#include "/kungfu/class/dali/weishi.h"; 
