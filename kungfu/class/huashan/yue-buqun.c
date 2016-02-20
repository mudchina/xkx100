// yue-buqun.c lasted updated by cocacola on 2.19 for adding chushi
// 岳不群
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
#include <ansi.h>
int do_xunshan();
/*
mixed out_master(mixed arg);
mixed out_master(mixed arg)
{
	object me;
	me = this_player();
	if( (string)me->query("family/family_name")!="华山派")
	{
		tell_object(me,"岳不群疑惑地对你说:哇拷!有没有搞错啊!\n");
		return 1;
	}
	if(me->query("gender")=="女性"){
		tell_object(me,"这位小姑娘,你是我内人的徒弟,你该出找她出师才是!\n");
		return 1;
	}
	if(me->query("combat_exp") <= 100000) {
		tell_object(me,"岳不群对"+me->query("name")+
		"怒道:功夫还没学到家就想出去丢脸.\n");
		return 1;
	}

	tell_object(me,"岳不群沉吟了一会,对"+me->query("name")+"说道:要想出师,
		你必须接我三招不死(accept test).\n");
	add_action("do_accept","accept");
	return 1;
}
int do_accept(string arg)
{
        mapping guild;

        if( arg== "test" ) {

		say("\n岳不群点了点头，说道：很好，小心了　，这是第一招....\n\n");
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		if( (int)this_player()->query("kee") < 0
			|| !present(this_player(), environment()))
		{
		say("岳不群叹了口气，说道：嘻嘻，连第一招都撑不过，真是自不量力....\n");
                       return 1;
                }
                say("\n岳不群喝道：第二招....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0
                || !present(this_player(), environment())) {
			say("岳不群叹道：这样子还想出师,唉.....\n");
			return 1;
                }
                say("\n岳不群怒道：第三招，你去死吧!....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0
                || !present(this_player(), environment())) {
			say("岳不群笑道：嘿嘿，看样子姜还是老的辣,哼.....\n");
                        return 1;
	}
	say("\n岳不群冷笑道：恭喜,你出师了.你我师徒一场，师傅没什么好送的 .
	\n为师送你八字真言:天外有天,人外有人!徒儿,喔,不...大侠你好自为知.\n\n");
	this_player()->set("betrayer",this_player()->query("betrayer")-1);
	this_player()->set("title","隐士");
	this_player()->set("family/family_name","华山派");
	this_player()->set("family/generation",13);
	this_player()->set("family/master_name",0);
	command("chat " + this_player()->query("name")+"已脱离华山，日后一切江湖恩怨均与本派无关。\n");
                return 1;
        }
        return 0;
}
*/
void create()
{
        set_name("岳不群", ({ "yue buqun", "yue" }) );
        set("title", "华山派掌门");
        set("nickname", "君子剑");
        set("gender", "男性");
        set("class", "swordsman");
        set("age", 55);
        set("long", "岳不群自幼执掌华山派，乃当今武林中一等一的高手。\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 2400);
        set("max_neili", 2400);
        set("jiali", 30);
        set("max_qi",2000);
        set("max_jing",1200);

        set("combat_exp", 3000000);
        set("shen", -200000);
        set("xunshan", 3);
        set("apprentice_available", 3);
        set("no_get",1);

        
        
        set("inquiry", ([
//		"出师": (: out_master :),
		"巡山": (: do_xunshan :),
        ]) );

        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 100);
        set_skill("huashan-sword", 300);
        set_skill("zixia-shengong", 200);
        set_skill("huashan-ken", 300);
        set_skill("feiyan-huixiang", 300);
        set_skill("bixie-sword",300);
        set_skill("zhengqijue",100);
        set_skill("ziyunyin",100);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");       
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jianzhang" :),
		(: perform_action, "sword.feilong" :),		
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

        create_family("华山派", 13, "掌门");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/book/zixia_book");
}
void init()
{
    	object ob;
	mapping myfam;

	::init();
    	
    	if (interactive(ob=this_player()) && ob->query("family"))
	{ 
		myfam = (mapping)ob->query("family");
		if((myfam["family_name"] == "华山派")
		  &&(!ob->query_skill("zixia-shengong",1))
		    &&(ob->query("combat_exp")>500000))
       		{
                command("say 你竟敢放弃本门心法！从我这里滚出去吧！");
                command("expell " + ob->query("id"));
        	}
	    add_action("do_qiecuo","qiecuo");
	}
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 老夫今天已经收了三个弟子，不想再收徒了。");
        }
}

void do_recruit(object ob)
{
        if( (int)ob->query("int") < 20 )
                command("say 我华山派以剑法为主，依我看"+RANK_D->query_respect(ob)+"不适合于学剑法。");
        else {
                command("say 好，好，好，很好。");
                command("recruit " + ob->query("id") );
        }
}
/*
void die()
{
message("channel:rumor", MAG"【谣言】某人："+this_player()->query("name")+"抢了紫霞秘芨啦。\n"NOR, users());
	::die();
}
*/
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        add("apprentice_availavble", -1);
}
void reset()
{
//        delete_temp("learned");
        set("apprentice_available", 3);
}
int do_xunshan()
{       
        int exp, pot, score, num, times;

        object me = this_player();       	        
        if ( me->query_temp("xunshan"))
        {
               if (!me->query_temp("xunshan/chaoyang"))
               {
                      message_vision("$N对着$n说：你朝阳峰没去看看？这算巡的什么山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/lianhua"))
               {
                      message_vision("$N对着$n说：你莲花峰没去看看？这算巡的什么山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/yuntai"))
               {
                      message_vision("$N对着$n说：你云台峰没去看看？这算巡的什么山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/sheshen"))
               {
                      message_vision("$N对着$n说：你怎么没去舍身崖？这算巡的什么山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/siguo"))
               {
                      message_vision("$N对着$n说：你到了思过崖去了？这算巡的什么山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/yunu"))
               {
                      message_vision("$N对着$n说：你到玉女峰后面华山小筑去看过了？这算巡的什么山？\n", this_object(), me);
                      return 1;
               }              
               message_vision("$N对着$n说：不错，辛苦了。你这就去休息去吧。\n", this_object(), me);
               me->delete_temp("xunshan");                      
               
               num=(int)me->query("perform/number")+1;
	       if (num<4) times=num;
	        else times=4;
               
               exp=random(100);
               pot=random(30);
               score=random(10)+ 10 * times;

               me->add("combat_exp",exp );
               me->add("potential",pot);
               me->add("family/fealty",score);
               tell_object(me,HIW"好！任务完成,你被奖励了：\n" + 
	       chinese_number(exp) + "点实战经验\n" +
	       chinese_number(pot) + "点潜能\n"+
	       chinese_number(score) + "点忠诚度\n");


               
               return 1;
        }
        else
        {
               if ( query("xunshan") < 1)
               {
                      message_vision("$N对着$n说：今天已经有人巡山去了。你明天再来吧。\n", this_object(), me);
                      return 1;
               }
               if( me->query("family/family_name") != "华山派")
               {
                      message_vision("$N对着$n大喝一声：本派弟子才能巡山。你是哪来的奸细？休怪我剑下不留情！\n", this_object(), me);
                     // this_object()->kill_ob(me);
                      return 1;
               }
               else
               {
                      add("xunshan", -1);
                      message_vision("$N对着$n说：本派弟子例当巡山。你，很好，很好！这就去吧。\n", this_object(), me);
                      me->set_temp("xunshan/start", 1);
                      me->set_temp("xunshan/time", time());
                      return 1;
               }
        }
}
