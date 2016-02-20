// hong.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
int try_to_learn_ds();

void create()
{
	set_name("洪七公", ({"hong qigong", "hong", "qigong"}));
	set("nickname", "九指神丐");
	set("gender", "男性");
	set("age", 75);
	set("long", 
		"他就是丐帮第十七任帮主，号称“北丐”的洪七公老爷子。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 10);
	
	set("str", 30);
	set("int", 24);
	set("con", 30);
	set("dex", 24);

	set("chat_chance", 1);
	set("chat_msg", ({
	"洪七公叹了口气道：“唉……何时能再吃到蓉儿做的「叫化鸡」啊……”\n",
	"洪七公说道：“俗话说「吃在江南」，所以老叫化特地跑来扬州看看。”\n",
	"洪七公喃喃道：“我们丐帮的「降龙十八掌」是天下最霸道的掌法。”\n",
	}));
	set("inquiry", ([
		"青竹林" : "东北西北东西北。\n",
		"丐帮" : "东北西北东西北。\n",
	]));
	set("no_teach", ([
				"xianglong-zhang" : (: try_to_learn_ds :),
	]));
	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 300);
	
	set("combat_exp", 3000000);
	set("score", 200000);
	set("shen", 100000);
	 
	set_skill("force", 200);             // 基本内功
	set_skill("huntian-qigong", 200);    // 混天气功
	set_skill("unarmed", 200);           // 基本拳脚
	set_skill("dodge", 200);      	     // 基本躲闪
	set_skill("xiaoyaoyou", 300);        // 逍遥游
	set_skill("parry", 200);             // 基本招架
	set_skill("strike", 200);            // 基本掌法
	set_skill("xianglong-zhang", 300);   // 降龙十八掌
	set_skill("hand", 200);              // 基本手法
	set_skill("suohou-hand", 300);       // 锁喉擒拿手
	set_skill("blade", 200);             // 基本刀法
	set_skill("liuhe-blade", 300);       // 四象六合刀
	set_skill("staff", 200);             // 基本杖法
	set_skill("fengmo-staff", 300);      // 疯魔杖法
	set_skill("stick", 200);             // 基本棒法
	set_skill("dagou-bang", 300);        // 打狗棒法
	set_skill("begging", 100);           // 叫化绝活
	set_skill("checking", 100);          // 道听途说
	set_skill("training", 100);         // 驭兽术
	set_skill("lianhua-zhang",100);      // 莲花掌
	
	map_skill("force", "huntian-qigong");
	map_skill("strike", "lianhua-zhang");
	map_skill("hand",  "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "dagou-bang");
	map_skill("stick", "dagou-bang");
	map_skill("staff", "fengmo-staff");
	prepare_skill("hand",  "suohou-hand");
	prepare_skill("strike", "lianhua-zhang");
  

	set("party/party_name", HIC"丐帮"NOR);
	set("party/rank", HIR"帮主"NOR);
	set("party/level", 10);
	create_family("丐帮", 17, "帮主");

	setup();
	
	carry_object(__DIR__"obj/lvyv_bang")->wield();
	carry_object(__DIR__"obj/jiaohuaji");
	carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
 	object ob; 
	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_qiecuo","qiecuo");
}


void greeting(object me)
{
       
       	mapping myfam;
	myfam = (mapping)me->query("family");
	if((myfam["family_name"] == "丐帮")&&(!me->query_skill("huntian-qigong",1))&&(me->query("combat_exp")>500000))
        {
                command("say 你竟敢放弃本门心法！从我这里滚出去吧！");
                command("expell " + me->query("id"));
        }
        
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_str() < 20 || (int)ob->query_con() < 20) {
		command("say 当叫化子需要能吃苦耐劳，依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合当叫化子？");
		return;
	}
	if ((string)ob->query("family/family_name") != "" &&
	    (string)ob->query("family/family_name") != "丐帮")
	{
		command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜老叫化呢？");
		return;
	}
	if (ob->query_temp("jiahuoji")) command("recruit "+ob->query("id"));
	else
	command("say " + RANK_D->query_respect(ob) + "各项条件都不错，只可惜老叫化现在没力气收徒……");
	
}

int accept_object(object who, object ob)
{
        int lv;
        string by,hid;
        object hob;
        object me=this_object();
        if (ob->query("food_supply") <= 0)
        	return 0;
        if ((string)ob->query("id") != "jiaohua ji" && !ob->query("values"))
        {
        	"/cmds/std/say"->main(this_object(),"老叫化对" + (string)ob->query("name") + CYN+"没什么兴趣……");
        	return 0;
        }
        if (query("food") >= max_food_capacity() - ob->query("food_supply")) {
        	command("say 老叫化现在饱得很。");
        	return 0;
        }
        if((string)ob->query("id") == "jiaohua ji")
        {
        	command("say 啊……这正是我想吃的叫化鸡呀！");
          command("eat ji");
          who->set_temp("jiahuoji",1);
          return 1;
        }
        lv = ob->query("values");
        by  = ob->query("make_by");
        if (lv < 100)
        {
                message_vision(CYN "$N" CYN "嗅了嗅" + ob->name() +
                               CYN "，皱眉道：这东西你还是自个留着"
                               "吧。\n" NOR, me);
                return 0;
        }

        if (lv < 120)
        {
                message_vision(CYN "$N" CYN "嗅了嗅" + ob->name() +
                               CYN "道：味道不错，可还是稍微欠那么"
                               "点儿火候。\n" NOR, me);
                return 0;
        }

        message_vision(HIW "$N" HIW "嗅了嗅$n" HIW "递来的" + ob->name() +
                       HIW "，尝了几口，直咂舌头，连声称赞。\n" NOR, me, who);

        if (! who->id(by))
        {

                command("say 可惜不知道是谁做的，有空可得给我引见引见。");
                return 1;
        }

        if (who->query("gender") != "女性")
        {
                command("say 想不到你一个大老爷们手艺也不错。难得，难得。");
                return 1;
        }

        if (who->query("family/family_name") == query("family/family_name"))
        {
                command("say 帮里有你这样的人真不错，以后就靠你多照顾了。");
                return 1;
        }

        if (ob->query("id")!="yudiluomei")
        {
                "/cmds/std/say"->main(this_object(),"老叫花我吃遍大江南北，你这"+ob->query("name")+CYN+"也算是人间美味啊！不错，不错。");
                return 1;
        }

        if (who->query("can_learn/hong/xiaoyaoyou") >= 1)
        {
                command("pat " + who->query("id"));
                command("say 又给老叫花解搀来了？多谢，多谢。");
                return 1;
        }
        command("stuff");
        command("say 老叫花没啥值钱的，就传你一套身法作为报答吧。");

        tell_object(who, HIC "\n洪七公同意传授你「逍遥游身法」。\n" NOR);
        who->set("can_learn/hong/xiaoyaoyou", 1);

        if (lv >= 200)
        {
                message_vision(CYN "\n$N" CYN "沉思良久，又道：想不"
                               "到除了黄丫头，居然还有人能做出如此美"
                               "味。\n" NOR, me, who);

                if (! stringp(hid = who->query("couple/couple_id")))
                {
                        command("say 却不知你如今有婆家了没有，可要"
                                "老叫花给你介绍？");
                        return 1;
                }

                if (! objectp(hob = find_player(hid)))
                {
                        command("sigh");
                        command("say 可惜你那位不在，否则我倒是可以"
                                "传他两手功夫。罢了，罢了。");
                        return 1;
                }

                if (hob->query("family/family_name") == query("family/family_name"))
                {
                        command("say " + hob->name(1) + "能娶到你这"
                                "样的老婆，也不枉了。");
                        return 1;
                }
                command("say 什么时候空了也叫你那位来，我也教他点东西。");

                tell_object(hob, HIC "\n洪七公同意传授你「降龙十八掌」。\n" NOR);
                hob->set("can_learn/hong/sub-xianglong-zhang", 1);
//                hob->improve_skill("martial-cognize", 1500000);
        }
        destruct(ob);
        return 1;
}

int recognize_apprentice(object me, string skill)
{
        if (! me->query("can_learn/hong/sub-xianglong-zhang")
           && ! me->query("can_learn/hong/xiaoyaoyou"))
        {
                command("say 你是谁？哪里来的？要干啥？");
                return notify_fail("");
        }

        if ((me->query("can_learn/hong/sub-xianglong-zhang")
           && skill != "xianglong-zhang"
           && skill != "strike")
           || (me->query("can_learn/hong/xiaoyaoyou")
           && skill != "xiaoyaoyou"
           && skill != "dodge"))
        {
                command("say 老叫化教你什么就学什么，你不学就算了。");
                return notify_fail("");
        }

        if ((skill == "strike"
           && me->query_skill("strike", 1) > 179)
           || (skill == "dodge"
           && me->query_skill("dodge", 1) > 179))
        {
                command("say 到此为止，你的功力也不差了，剩下的自己去练。");
                return notify_fail("");
        }
        return 1;
}

int try_to_learn_ds()
{
        object me;
        object sob;
        int i;
        int flag;
        string *sub_skills;

        me = this_player();

        if (me->query("family/family_name") == query("family/family_name")
           && me->query("party/level") < 9)
        {
                command("say 你要学降龙十八掌？等你升到本帮长老再说吧！");
                return 1;
        }

        if (me->query("family/family_name") != query("family/family_name")
           && ! me->query("can_learn/hong/sub-xianglong-zhang"))
        {
                command("say 你是哪里来的？一边呆着去。");
                return 1;
        }

        if (me->query("shen") < 80000)
        {
                command("say 你的侠义正事还做得不够，我可不放心传你绝技。");
                return 1;
        }

        sob = find_object(SKILL_D("xianglong-zhang"));

        if (! sob)
                sob = load_object(SKILL_D("xianglong-zhang"));

 //       if (! sob->valid_learn(me))
 //               return 0;

        if (me->query_skill("xianglong-zhang", 1))
        {
                command("say 你不是已经会了么？自己好好练吧。");
                return 1;
        }
        
        if ((int)me->query("max_neili") < 3000)
        {
            command("say 你的内力太弱，还无法练降龙十八掌。");
            return 1;
        }
        if ((int)me->query("str") < 25)
        {
            command("say 你的先天膂力孱弱，难以修炼降龙十八掌。");
            return 1;
        }
        if ((int)me->query("con") < 20)
        {
            command("say 你的先天根骨孱弱，难以修炼降龙十八掌。");
            return 1;
        }
        if ((int)me->query_skill("strike", 1) < 180)
        {
            command("say 你的基本掌法火候不够，难以修炼降龙十八掌。");
            return 1;
        }

        sub_skills = keys(sob->query_sub_skills());

        flag = 0;
        for (i = 0; i < sizeof(sub_skills); i++)
        {
                if (me->query_skill(sub_skills[i], 1) >= 10)
                        continue;

                me->set_skill(sub_skills[i], 10);

                if (! flag)
                {
                        flag = 1;
                        command("nod");
                        command("say 我将十八路掌法传授与你，假以时"
                                "日，必能融会贯通。");
                }
                write(HIC "你对" + to_chinese(sub_skills[i]) + "有了"
                      "一些领悟。\n" NOR);
        }

        if (! flag)
        {
                command("say 不是说了待到你融会贯通再来向我讨教吗？");
                return 1;
        }

        me->set("can_learn/hong/sub-xianglong-zhang",1);
        command("say 你先将这十八路掌法融会贯通，合而为一再说吧。");
        notify_fail("你自己下去好好练习吧。\n");
        return 1;
}