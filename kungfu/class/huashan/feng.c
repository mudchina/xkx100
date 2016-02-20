// feng.c 风清扬

#define FENG "/log/feng"

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
//inherit F_CLEAN_UP;
string ask_skill1();
string ask_skill2();
string ask_skill3();
string ask_skill4();
int check_betrayal(object ob);
int check_student(object ob);
int improve_sword(object ob);
int save_data();
int load_data();
int auto_perform();

void create() 
{
	seteuid(getuid());
	set_name("风清扬", ({ "feng qingyang", "feng", "qingyang" }));
	set("title", "华山第十二代剑宗长老");
	set("long", 
"这便是当年名震江湖的华山名宿风清扬。他身著青袍，神气抑郁脸如金纸。
身材瘦长，眉宇间一直笼罩着一股淡淡的忧伤神色，显然对当年的剑宗气宗
之争一直难以忘怀。\n");
	set("gender", "男性");
	set("age", 68);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 4800);
	set("max_qi", 4800);
	set("jing", 3600);
	set("max_jing", 3600);
	set("neili", 4400);
	set("max_neili", 4400);
	set("jiali", 200);

	set("combat_exp", 3000000);
	set("score", 200000);

	set_skill("cuff", 200);
	set_skill("force", 180);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 220);
	set_skill("strike", 200);
	set_skill("zixia-shengong", 200);
	set_skill("poyu-quan", 300);
	set_skill("fanliangyi-dao", 300);
	set_skill("huashan-sword", 300);
	set_skill("hunyuan-zhang", 300);
	set_skill("lonely-sword", 300);
	set_skill("feiyan-huixiang",250);
	set_skill("literate", 120);
	set_skill("ziyunyin",100);
	set_skill("zhengqijue",100);

	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("cuff", "poyu-quan");
	map_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "poyu-quan");
	prepare_skill("strike", "hunyuan-zhang");
	create_family("华山派", 12, "风清扬");

	set("chat_chance_combat", 90);
	set("inquiry", ([
		"破剑式" 	:	(: ask_skill1 :),
		"破气式"  :	(: ask_skill2 :),
		"总决式"  :	(: ask_skill3 :),
		"破众"    : (: ask_skill4 :),
	]));
	set("chat_msg_combat", ({
		(: perform_action, "sword.po" :),
		(: perform_action, "sword.po" :),
		(: perform_action, "sword.poqi" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

	setup();
	carry_object(WEAPON_DIR"sword/changjian")->wield();
	carry_object(CLOTH_DIR"cloth")->wear();
	load_data();
}

void init()
{
	object ob, me = this_object();

	::init();

	if( interactive(ob = this_player()) &&
		ob->query("family/master_id") == "feng qingyang" )
	{
		remove_call_out("check_student");
		call_out("check_student",0,ob);
	}
	else if( ob->query("family/master_id") != "feng qingyang" &&
			(int)ob->query_skill("lonely-sword", 1) > 1 )
	{
		remove_call_out("check_betrayal");
		call_out("check_betrayal",0,ob);
	}
	else if( !ob->is_fighting() &&	!ob->query("fengtaugh") &&
		file_name(environment(me)) ==	"/d/huashan/xiaofang" )
	{
		remove_call_out("improve_sword");
		call_out("improve_sword", 0, ob );
	}
	if (wizardp(this_player()))
	{
		add_action("do_stnow", "stnow");
		add_action("save_data","sdt");
		add_action("load_data","ldt");
	}
}

int do_stnow(string arg) // 检查在线玩家中所有的风弟子
{
	object *user;
	string *list=({});
	string str;
	mapping st;
	int i;
	
	load_data();
	user=users();
	for (i=0;i<sizeof(user);i++)
	{
		if (user[i]->query("family/master_id")=="feng qingyang")
			list += ({user[i]->query("id")});
	}
	if (arrayp(list))
	{
		write("江湖中的风弟子共有"+sizeof(list)+"人："+implode(list,"、")+"\n");
	}
	else 
	{
		write("江湖中没有风弟子。\n");
	}
	if (mapp(st = query("students")))
	{
		write("系统风弟子有"+sizeof(query("students"))+"人："+implode(keys(st),"、")+"。\n");
	}
	else
	{
		write("系统风没有收弟子。\n");
	}
	if (stringp(str=query("pending")))
	{
		write("风清扬目前不收"+str+"为徒。\n");
	}
	if (mapp(st = query("no_accept")))
	{
		write("风清扬永远不收"+implode(keys(st),"、")+"为徒。\n");
	}
	return 1;
}

int check_betrayal(object ob)
{
	object me=this_object();
	mapping std_status;
	string *stdname;
	int i;

//	load_data();
	if ( mapp(std_status = me->query("students")) )
	{
		stdname = keys(std_status);
		for(i=0; i<sizeof(std_status); i++)
		{
			if ( ob->query("id")==stdname[i] &&
				ob->query("normal_die") == me->query("students/"+ob->query("id")) ) // 没死过换师父
			{
				command( "chat 叛师灭祖的家伙，亏你还有脸回来见我？" );
				me->delete( "students/"+ob->query("id") );
				me->set( "no_accept/"+ob->query("id"), 1);
				save_data();
			}
		}
	}
	return 1;
}

int check_student(object ob)
{
	int death_time;
	string std_id;
	object me = this_object();
	int ap_death_time;

	death_time = ob->query("normal_die");
	std_id = ob->query("id");

	if ( ob->query("family/master_id")=="feng qingyang")
	{
		if (member_array(ob->query("id"),keys(this_object()->query("students")))==-1)
		{
			// 非法风弟子
			command( "say 好个畜生，竟敢在外为非做歹！" );
			command( "expell " + ob->query("id"));
			ob->delete_skill("lonely-sword");
			ob->delete("can_perform/lonely-sword");
			this_object()->set( "no_accept/"+ob->query("id"), 1);
			save_data();
			return 1;
		}
	}
	sscanf(me->query("students/"+std_id),"%d",ap_death_time);
	if ( death_time +1 > ap_death_time )
	{
		// 已死风弟子
		ob->delete("family");
		ob->set("title","普通百姓");
		message_vision( "风清扬看了看$N，脸上现出悲戚的神色。\n", ob );
		command( "say 你我师徒之情已尽，以候你好自为之吧。" );
		me->delete( "students/"+std_id );
		me->set( "pending", std_id );
	}
	else if ( ob->query("shen") < 0 )
	{
		command( "say 好个畜生，竟敢在外为非做歹！" );
		command( "expell " + ob->query("id"));
		ob->delete_skill("lonely-sword");
		ob->delete("can_perform/lonely-sword");
		me->delete( "students/"+std_id );
		me->set( "pending", std_id );

	}
	else if ( (int)ob->query_skill("zixia-shengong", 1) < 50 )
	{
		command( "say 虽说剑宗重剑轻气，但你竟然弃气，孺子不可教也！" );
		command( "expell " + ob->query("id"));
		ob->delete_skill("lonely-sword");
		ob->delete("can_perform/lonely-sword");
		me->delete( "students/"+std_id );
		me->set( "pending", std_id );
	}
	save_data();
	return 1;
}

int improve_sword(object ob)
{
	int my_sword, add_level;
	
	if (!userp(ob)) return 0;
	
	my_sword = ob->query_skill("sword", 1);
	command( "say "+RANK_D->query_respect(ob)+"既然一场来到，你我可谓有缘，待我指点你一些剑法吧。");
	message_vision( "风清扬开始为$N解说基本剑法的精义。\n", ob );

	if ( my_sword < 100 )
	{
		add_level = my_sword + 20;
		tell_object( ob, "你的基本剑法增加了二十级！\n");
	}
	else if ( my_sword < 120 )
		{
			add_level = my_sword + 10;
			tell_object( ob, "你的基本剑法增加了十级！\n");
		}
		else if ( my_sword < 150 )
			{
				add_level = my_sword + 5;
				tell_object( ob, "你的基本剑法增加了五级！\n");
			}
			else
			{
				message_vision( "风清扬对着$N惊讶地「啊！」了一声。\n", ob );
				command( "say "+RANK_D->query_respect(ob)+"的剑法已然登堂入室，老朽不胜佩服！\n");
				tell_object( ob, "你的基本剑法已踌炉火纯青之境，风清扬已没什么可指点于你的了！\n");
				ob->set("fengtaugh", 1);
				return 1;
			}

	ob->set_skill("sword", add_level);
	ob->set("fengtaugh", 1);
	if(ob->query("combat_exp") > 100000 && userp(ob) )
		ob->add("combat_exp", 15000);

	return 1;
}

void attempt_apprentice(object ob)
{
	object ob1, room, me = this_object();
	mapping no_status, student_stat, skl = ob->query_skills();
	string mengzhu, *noname, *sk;
	int i;


	if ( mapp(no_status = me->query("no_accept")) )
	{
		noname = keys(no_status);
		for (i=0; i<sizeof(no_status); i++)
		{
			if ( ob->query("id") == noname[i] )
			{
				command("say 我是永远不会重收你这个欺师灭祖的家伙的！");
				return;
			}
		}
	}
	
	if ( (string)ob->query("id") == me->query("pending") )
	{
		command("say 老夫现在不想收你为徒，你还是走吧。");
		return;
	}
	if ( mapp(student_stat = me->query("students")) &&
		sizeof(student_stat) >= 5 )
	{
		command("say 老夫已有五徒，不再收弟子了。");
		return;
	}
	if ( (string)ob->query("gender") == "无性" )
	{
		command("say " + RANK_D->query_respect(ob) + "是东厂中人，恕我不能收你。");
		return;
	}
	if ((string)ob->query("class")=="bonze")
	{
		command ("say 老夫不收出家人为徒，你请回吧。");
		return;
	}
	if ((string)ob->query("party/party_name") == HIC"丐帮"NOR )
	{
		command("say " + RANK_D->query_respect(ob) + "曾得丐帮不少好处，何必叛帮以拜我为师呢？");
		return;
	}       
	if ( (int)ob->query_int() < 33 )
	{
		command("say " + RANK_D->query_respect(ob) + "资质不够，学不了独孤九剑。");
		return;
	}
	if ( (int)ob->query("shen") < 100000 )
	{
		command("say 我华山派乃是堂堂名门正派，对弟子要求极严。");
		command("say "+RANK_D->query_respect(ob)+"德行不够，恕我不能收你。");
		return;
	}
	if ( (int)ob->query_skill("sword", 1) < 80 )
	{
		command("say "+RANK_D->query_respect(ob)+"的基本剑法修为不够，恕我不能收你。");
		return;
	}
	if ( (int)ob->query_skill("strike", 1) < 80 )
	{
		command("say "+RANK_D->query_respect(ob)+"的基本掌法修为不够，恕我不能收你。");
		return;
	}
	if ( (int)ob->query_skill("dodge", 1) < 80 )
	{
		command("say "+RANK_D->query_respect(ob)+"的基本轻功修为不够，恕我不能收你。");
		return;
	}
	if ( (int)ob->query_skill("parry", 1) < 80 )
	{
		command("say "+RANK_D->query_respect(ob)+"的基本招架修为不够，恕我不能收你。");
		return;
	}
	if ( (int)ob->query_skill("force", 1) < 80 )
	{
		command("say "+RANK_D->query_respect(ob)+"的基本内功修为不够，恕我不能收你。");
		return;
	}
	if ( (int)ob->query_skill("zixia-shengong", 1) < 80 )
	{
		command("say "+RANK_D->query_respect(ob)+"的紫霞神功修为不符合我的要求，恕我不能收你。");
		return;
	}

	sk = keys(skl);
	i = sizeof(sk);
	while (i--)
	{
		if (sk[i] != "lonely-sword" && sk[i] != "huashan-sword" &&
			SKILL_D(sk[i])->valid_enable("sword"))
		{
			command("say 独孤九剑的要旨在于悟，是以须得把原来所学的剑法完全忘却，方能突破剑法常规。");
			command("say "+RANK_D->query_respect(ob)+"可有此决心尽弃所学之"+to_chinese(sk[i])+"？");
			return;
		}
	}

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	if (ob->is_apprentice_of(me))
	{
		ob->set("title",HIY+BLINK+"★"+NOR+HIC+"孤独传人"+HIY+BLINK+"★"+NOR);
		command("chat 哈哈，独孤九剑终于又有传人了！"+ob->name()+"现已为我弟子，请各位同道多多关照。");
		me->set("students/"+(string)ob->query("id"), (int)ob->query("normal_die")+1);
		if ( stringp(me->query("pending")) )
		{
	  		me->delete("pending");
		}
		save_data();
	}
}

int accept_fight(object ob)
{
	object me = this_object();

	int my_max_qi = me->query("max_qi");
	if ( me->query("qi")*100 / my_max_qi <= 80 )
	{
		return 0;
	}

	remove_call_out("auto_perform");
	call_out("auto_perform", 1);

	return 1;
}

int accept_kill(object ob)
{
	object me = this_object();

	command("say 老夫与你无怨无仇，何以痛下毒手？让老夫为民除害！");
	remove_call_out("auto_perform");
	call_out("auto_perform", 1);	

	return 1;
}

int auto_perform()
{
	object me = this_object();
        object ob = me->select_opponent();
	object weapon, my_weapon;
	string action;

	if ( !me->is_fighting() )
	{
                if ( me->query("eff_qi") < me->query("max_qi") )
                        exert_function("heal");
                me->set("jiali", 100);

                return 1;
        }
	else
	{
		if ( objectp(my_weapon=me->query_temp("weapon")) )
		{
			action = "sword.po";
			remove_call_out("auto_perform");
			call_out("auto_perform", 1+random(5));
			return perform_action(action);
		}
		else if ( !me->query_temp("leidong") )
			{
				remove_call_out("auto_perform");
				call_out("auto_perform", 1+random(5));
				return perform_action("cuff.leidong");
			}
			else 
			{
				remove_call_out("auto_perform");
				call_out("auto_perform", 1+random(5));
				return perform_action("strike.wuji");
			}
	}
}

string ask_skill1()
{
	object me = this_player();
	
	if (me->query("can_perform/lonely-sword/po"))
		return "你不是已经学会了吗？";

	if (me->query("family/master_id")!= "feng qingyang")
		return "你非我弟子，何故有此一问。";

	if (me->query("potential") - me->query("learned_points") < 10)
	{
		me->set("learned_points", me->query("potential"));
		return "独孤九剑要旨在于「悟」，不可拘泥不化，讲究料敌机先，出奇制胜。\n"+
		HIG "你听了风清扬的教导，颇觉迷茫，看"
                        "来是潜能不够了。" NOR;
	}
	me->add("leaned_points",10);
	if (random(5))
	{
		return "独孤九剑要旨在于「悟」，不可拘泥不化，讲究料敌机先，出奇制胜。\n"HIY "你听了风清扬的教导，颇有心得。" NOR;
	}
	return teach_perform(this_player(),this_object(),([
					"perform" : "po",		//pfm的代码
					"name"	  : "破剑式",		//pfm的名称
					"sk1"	  : "lonely-sword",	//主要的武功的id
					"lv1"	  : 50,					//主要的武功的等级
					"sk2"	  : "sword",		//需要武功sk2的id
					"lv2"	  : 50,					//需要武功sk2 的等级
					"neili"	  : 500,					//需要基本内功等级
					]));
}
string ask_skill2()
{
	object me = this_player();
	
	if (me->query("can_perform/lonely-sword/poqi"))
		return "你不是已经学会了吗？";

	if (me->query("family/master_id")!= "feng qingyang")
		return "你非我弟子，何故有此一问。";

	if (me->query("potential") - me->query("learned_points") < 10)
	{
		me->set("learned_points", me->query("potential"));
		return "独孤九剑要旨在于「悟」，不可拘泥不化，讲究料敌机先，出奇制胜。\n"+
		HIG "你听了风清扬的教导，颇觉迷茫，看"
                        "来是潜能不够了。" NOR;
	}
	me->add("leaned_points",10);
	if (random(5))
	{
		return "独孤九剑要旨在于「悟」，不可拘泥不化，讲究料敌机先，出奇制胜。\n"HIY "你听了风清扬的教导，颇有心得。" NOR;
	}
	return teach_perform(this_player(),this_object(),([
					"perform"	: "poqi",		//pfm的代码
					"name"		: "破气式",		//pfm的名称
					"sk1"		: "lonely-sword",	//主要的武功的id
					"lv1"		: 100,			//主要的武功的等级
					"sk2"		: "sword",		//需要武功sk2的id
					"lv2"		: 100,			//需要武功sk2 的等级
					"neili"		: 500,			//需要基本内功等级
					]));
}
string ask_skill3()
{
	object me = this_player();
	
	if (me->query("can_perform/lonely-sword/zongjue"))
		return "你不是已经学会了吗？";

	if (me->query("family/master_id")!= "feng qingyang")
		return "你非我弟子，何故有此一问。";

	if (me->query("potential") - me->query("learned_points") < 10)
	{
		me->set("learned_points", me->query("potential"));
		return "独孤九剑要旨在于「悟」，不可拘泥不化，讲究料敌机先，出奇制胜。\n"+
		HIG "你听了风清扬的教导，颇觉迷茫，看"
                        "来是潜能不够了。" NOR;
	}
	me->add("leaned_points",10);
	if (random(5))
	{
		return "独孤九剑要旨在于「悟」，不可拘泥不化，讲究料敌机先，出奇制胜。\n"HIY "你听了风清扬的教导，颇有心得。" NOR;
	}
	return teach_perform(this_player(),this_object(),([
					"perform"	: "zongjue",		//pfm的代码
					"name"		: "总决式",		//pfm的名称
					"sk1"		: "lonely-sword",	//主要的武功的id
					"lv1"		: 20,			//主要的武功的等级
					"sk2"		: "sword",		//需要武功sk2的id
					"lv2"		: 100,			//需要武功sk2 的等级
					"neili"		: 500,			//需要基本内功等级
		]));
}
string ask_skill4()
{
	object me = this_player();
	
	if (me->query("can_perform/lonely-sword/pozhong"))
		return "你不是已经学会了吗？";

	if (me->query("family/master_id")!= "feng qingyang")
		return "你非我弟子，何故有此一问。";

	if (me->query("potential") - me->query("learned_points") < 10)
	{
		me->set("learned_points", me->query("potential"));
		return "独孤九剑要旨在于「悟」，不可拘泥不化，讲究料敌机先，出奇制胜。\n"+
		HIG "你听了风清扬的教导，颇觉迷茫，看"
                        "来是潜能不够了。" NOR;
	}
	me->add("leaned_points",10);
	if (random(5))
	{
		return "独孤九剑要旨在于「悟」，不可拘泥不化，讲究料敌机先，出奇制胜。\n"HIY "你听了风清扬的教导，颇有心得。" NOR;
	}
	return teach_perform(this_player(),this_object(),([
					"perform"	: "pozhong",		//pfm的代码
					"name"		: "破众",		//pfm的名称
					"sk1"		: "lonely-sword",	//主要的武功的id
					"lv1"		: 80,			//主要的武功的等级
					"sk2"		: "sword",		//需要武功sk2的id
					"lv2"		: 50,			//需要武功sk2 的等级
					"neili"		: 50,			//需要基本内功
					]));
}
int save_data()
{
	string str;
	mapping mydata;
	string *kdata;
	string *temp;
	int i;
	
	str = "students：";
	mydata = this_object()->query("students");
	if (mapp(mydata))
	{
		str += keys(mydata)[0];
		for (i=1;i<sizeof(mydata);i++)
		{
			str += "、";
			str += keys(mydata)[i];
		}
		str += "->";
		str += mydata[keys(mydata)[0]];
		for (i=1;i<sizeof(mydata);i++)
		{
			str += "、";
			str += mydata[keys(mydata)[i]];
		}
	}
	str += "\n";
	str += "pending：";
	if (stringp(this_object()->query("pending")))
		str += this_object()->query("pending");
	str += "\n";
	str += "no_accept：";
	mydata = this_object()->query("no_accept");
	if (mapp(mydata))
	{
		str += implode(keys(mydata),"、");
	}
	str += "\n";
	write_file(FENG,str,1);
	return 1;
}
int load_data()
{
	string str,*lines;
	mapping mydata;
	string *kdata,*kvalue;
	int i,j;
	string k,v,v1;
	int temp;
	
	str = read_file(FENG);
	if (!stringp(str)) return 0;
	lines = explode(str,"\n");
	for(i=0;i<sizeof(lines);i++)
	{
		sscanf(lines[i],"%s：%s",k,v);
		switch(k)
		{
			case "students":
				if (!stringp(v)) continue;
				sscanf(v,"%s->%s",v,v1);
				if (!stringp(v)) continue;
				if (!stringp(v1)) continue;
				kdata = explode(v,"、");
				kvalue= explode(v1,"、");
				for (j=0;j<sizeof(kdata);j++)
				{
					if (!stringp(kvalue[j])) kvalue[j] = "1";
					this_object()->set("students/"+kdata[j],kvalue[j]);
				}
				break;
			case "pending":
				if (!stringp(v)) continue;
				this_object()->set("pending",v);
				break;
			case "no_accept":
				if (!stringp(v)) continue;
				kdata = explode(v,"、");
				for(j=0;j<sizeof(kdata);j++)
				{
					this_object()->set("no_accept/"+kdata[j],1);
				}
				break;
			default:
				continue;
		}
	}
	return 1;
}