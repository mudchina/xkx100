// baby.c
#include <ansi.h>
inherit NPC;
inherit F_SAVE;

void try_move();

string *reject_msg = ({
	"说道：您太客气了，这怎么敢当？\n",
	"像是受宠若惊一样，说道：请教？这怎么敢当？\n",
	"笑着说道：您见笑了，我这点雕虫小技怎够资格「指点」您什么？\n",
});
string query_save_file();
int do_save();
int do_do(string msg);
void improve_npcskill(string skill, int amount, int weak_mode);
int exercising(object me);
int halt_exercise(object me);
void update_me();
void create()
{
	seteuid(getuid());
	if (!restore())
	{
		set_name("宝宝", ({"xiao baobao","baby"}) );
		set("gender", "女性");
		set("age", 1);
		set("attitude", "friendly");
		set("long","一个乖宝宝。\n");
		set("combat_exp", 1);
		set("parents",({"dad","mom"}));
   
		set("chat_chance", 2);
		set("chat_msg", ({
			(: random_move :)
		}));

		set("is_baby",1);
		setup();
	}
}

void init()
{
	add_action("do_kill",({"kill","fight","hit","steal"}));
	add_action("do_get","get");
	add_action("do_drop","drop");
	if(member_array(this_player()->query("id"), this_object()->query("parents"))>-1)
	{
		add_action("do_save","bsave");
		add_action("do_teach","bjiao");
		add_action("do_teach","bteach");
		add_action("do_practice","blian");
		add_action("do_practice","bpractice");
		add_action("do_exercise","bdazuo");
		add_action("do_exercise","bexercise");
		add_action("do_learn","blearn");
		add_action("do_learn","bxue");
		add_action("do_study","bstudy");
		add_action("do_study","bdu");
		add_action("do_do","do");
		this_object()->set_leader(this_player());
	}

	remove_call_out("try_move");
	call_out("try_move",1);
}
void unconcious()
{

/*        message("system", HIR "\n你的眼前一黑，接着什么也不知道了....\n\n" NOR,
this_object());

	 this_object()->disable_player(" <昏迷不醒>");

        set("jing", 0);
        set("qi", 0);

        set_temp("block_msg/all", 1);
        COMBAT_D->announce(this_object(), "unconcious");
*/
	add("die",1);
	set("eff_jing", query("max_jing"));
	set("jing",     query("max_jing"));
	set("eff_qi",   query("max_qi"));
	set("qi",       query("max_qi"));
	save();
	::die();
}

void try_move()
{
	if(random(20)==0)
	{
		remove_call_out("random_move");
		call_out("random_move",5);
	}
}

int do_drop(string arg)
{
	object me=this_object(),who=this_player(),env;
	if(!arg) return 0;
	env = environment(who);
	if(present(arg,who)!=me) return 0;
	if(me->move(env))
	{
		message_vision("$N把$n从怀里放了下来。\n",who,me);
		return 1;
	}
	return 0;
}

int do_get(string arg)
{
	object me=this_object(),who=this_player(),env;

	if(!arg) return 0;
	env = environment(who);
	if(present(arg,env)!=me) return 0;
	if(member_array(who->query("id"), me->query("parents"))>-1)
	{
		if(me->move(who)) message_vision("$N弯下腰把$n抱了起来，搂在怀里。\n",who,me);
		else message_vision("$N弯下腰一抱却没把$n抱起来，小家伙好沉哪！\n",who,me);
	}
	else message_vision("$N蹲下身朝$n伸开双手，$n却一下子闪开了．．．\n",who,me);
	return 1;
}

int do_kill(string arg)
{	
	object me,who;
	string name,verb,what,obj;
	if (!arg) return 0;
	verb=query_verb();
	me=this_player();
   
	if(verb=="steal")
	{
		if(sscanf(arg, "%s from %s", what, obj)!=2 ) return 0;
	}
	else obj=arg;

	if(!objectp(who=present(obj,environment(me))) 
		|| !living(who)) return 0;
	if(who==this_object())
	{
		switch(verb)
		{
			case "kill":
			case "touxi":
			case "ansuan":
				tell_object(environment(this_object()),who->query("name")+"拼命地哭了起来：爹～～，娘～～，"+me->query("name")+"要杀我．．．快回来呀！\n");
				break;
			case "hit":
				tell_object(environment(this_object()),who->query("name")+"大哭了起来：爹～～，娘～～，"+me->query("name")+"欺负我．．．快回来呀！\n");
				break;
			case "fight":
				tell_object(environment(this_object()),who->query("name")+"哭了起来：爹～～，娘～～，"+me->query("name")+"要抢我的糖吃．．．快回来呀！\n");
				break;
			case "steal":
				tell_object(environment(this_object()),who->query("name")+"哭了起来：爹～～，娘～～，"+me->query("name")+"要偷吃我的糖！\n");
				break;
			case "beg":
				tell_object(environment(this_object()),who->query("name")+"小嘴一歪哭了起来：爹～～，娘～～，"+me->query("name")+"要骗我的糖吃！\n");
				break;
		}
	}
//	command(verb);
	return 0;
}

void relay_emote(object ob, string verb)
{
	if( !userp(ob) ) return;

	switch(verb)
	{
		case "kick":
			command("say 爹～～，娘～～，"  + ob->query("name") + "踢我耶！");
			command("kick " + ob->query("id"));
			break;
		case "slap":
			command("say 爹～～，娘～～，"  + ob->query("name") + "打我耶，好痛啊～～～～");
			command("slap " + ob->query("id"));
			break;
		case "hit":
			command("pain " + ob->query("id"));
			break;
		case "bite":
			command("face " + ob->query("id"));
			break;  
		case "papaya":
			command("angry");
			break;  
	}
}

void relay_whisper(object me, string msg)
{
	if (member_array(me->query("id"),query("parents"))==-1)
	{
		message_vision((string)this_object()->query("name")
			+ "疑惑地看着$N。\n", me);
		return;
	}

	//note, do not allow the order contain "chat", "tell"...
	//may need disable more later...
	if( strsrch(msg, "chat") != -1 || strsrch(msg, "tell") != -1 ||
		strsrch(msg,"follow")!= -1 || strsrch(msg,"apprentice")!= -1 ||
		strsrch(msg, "recruit") != -1 )
		return;

	if (msg)
	{
		remove_call_out ("relaying");
		call_out ("relaying", 1+random(3), msg);
	}
}

void relaying(string msg)
{
	command (msg);
}

int do_do(string msg)
{
	string act, sth;
	if (!msg || sscanf(msg, "%s %s",act,sth) != 2)
		return notify_fail("你要叫你孩子干什么？\n");

	if(
	// 〖用户系统命令〗
	act!="nick" &&
// 〖交流探险命令〗
	act!="follow" && //new
  act!="ask" && 	//new
	act!="drop" &&	//new
	act!="halt" && //new
	act!="put" && //new
	act!="ride" && //new
	act!="unride" && //new
	act!="hit" &&
	act!="fight" && 
	act!="kill"	&& 
	act!="say" && 
	act!="chat" && 
	act!="chat*" && 
	act!="go" && 
	act!="give" && 
	act!="wear" && 
	act!="remove" && 
	act!="get" && 
	act!="eat" && 
	act!="drink" && 
	act!="wield" && 
	act!="unwield" && 
// 〖武功技能命令〗
	act!="abandon" && 
	act!="apprentice" && 
	act!="bei" && 
	act!="du" &&  //bdu功能实现
	act!="enable" && 
	act!="enforce" && 
	act!="exert" && 
	act!="fangqi" && 
	act!="jiali" && 
	act!="jifa" && 
	act!="learn" && 
	act!="perform" && //new
	act!="yong" && //new
	act!="prepare" && 
	act!="study" && // bdu功能实现
	act!="xue" && 
	act!="yun" && 
	act!="bai" &&
	act!="order"  //new 其它命令
	)
		return notify_fail("目前暂时不能叫你孩子干这事！\n");

	command (msg);
	return 1;
}

string query_save_file()
{ 
	string id;

	if( !stringp(id = query("saveid")) ) return 0;
	return DATA_DIR + "baby/" + id[0..0] + "/" + id;
}

int do_save()
{
	save();
	write(this_object()->query("name")+"存盘完毕。\n");
	return 1;
}

int do_teach(string skill)
{
	object ob=this_object(), me=this_player();
	string skill_name, obname=ob->query("name");
	int student_skill, my_skill, jing_cost, grade, student_combat_exp;

	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");
	if(!skill) return notify_fail("你要教"+obname+"什么技能？\n");
	if( me->is_fighting() )
		return notify_fail("你自己保命都悬。还有空教孩子？\n");
	if( !living(ob) )
		return notify_fail("嗯....你得先把"+obname+"弄醒再说。\n");
	if (ob->is_busy())
		return notify_fail(obname + "现在正忙着呢。\n");
	if( ob->is_fighting() )
		return notify_fail("没看到"+obname+"快玩完了？还不自己出手！\n");

	if( !my_skill = me->query_skill(skill, 1) )
		return notify_fail("这项技能你还不会呢！\n");

	if( ob->prevent_learn(me, skill) )
		return 0;

	student_skill = ob->query_skill(skill, 1);

	if( my_skill <= student_skill )
		return notify_fail("这项技能"+obname+"的程度已经不输于你了。\n");

	if( !SKILL_D(skill)->valid_learn(ob) ) 
		return notify_fail("依"+obname+"目前的能力，没办法学习这种技能。\n");

	jing_cost = 100 / ((int)me->query("int") + (int)ob->query("int"));

	if( !student_skill )
	{
		jing_cost *= 2;
		ob->set_skill(skill,0);
	}

	if( (int)me->query("learned_points") >= (int)me->query("potential") )
		return notify_fail("你的潜能已经发挥到极限了，没有办法再教了。\n");

	if( (int)ob->query("learned_points") >= (int)ob->query("potential") )
		return notify_fail(obname+"的潜能已经发挥到极限了，没有办法再成长了。\n");

	printf("你向%s解释有关「%s」的疑问。\n", obname, to_chinese(skill));

	if( (int)me->query("jing") > jing_cost )
	{
		if( userp(me) ) me->receive_damage("jing", jing_cost );
	} else {
		write("但是你太累了，没有办法再教"+obname+"。\n");
		return 1;
	}
		
	student_combat_exp = (int)ob->query("combat_exp");

/*	if(student_combat_exp < 10000)
		grade = 1;
	else if(student_combat_exp < 100000)
		grade = 3;
	else if(student_combat_exp < 1000000)
		grade = 8;
	else
		grade = 14;
*/
	if((int)ob->query("jing") > jing_cost)
	{
		if( (string)SKILL_D(skill)->type()=="martial" && student_skill * student_skill * student_skill / 10 > student_combat_exp)
		{
			tell_object(me, "也许是缺乏实战经验，"+obname+"对你的解释总是无法领会。\n");
		}
		else
		{
			if(skill_name = SKILL_D(skill)->query_skill_name(student_skill))

				tell_object(me, obname+"听了你的指导，对"+skill_name+"这一招似乎有些心得。\n");
			else
				tell_object(me, obname+"听了你的指导，似乎有些心得。\n");
             
   			me->add("learned_points", 1);
			ob->add("learned_points", 1);

//			if ( grade < 1 ) grade = 1;
			ob->improve_npcskill(skill, 100);
		}
	}
	else
	{
		jing_cost = ob->query("jing");
		tell_object(me,obname+"今天太累了，结果什么也没有学到。\n");
	}
	ob->receive_damage("jing", jing_cost );
	return 1;
}

void improve_npcskill(string skill, int amount, int weak_mode)
{
	int spi;
	object ob=this_object();
	string obname=ob->query("name");

	if( !find_object(SKILL_D(skill))
	&& file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !weak_mode || !userp(ob) )
	{
		if( !mapp(skills) ) skills = ([]);
		if( undefinedp(skills[skill]) ) skills[skill] = 0;
	}

	spi = 30;
	if( sizeof(learned) > spi )
		amount /= sizeof(learned) - spi;

	if( !amount ) amount = 1;

	if( !mapp(learned) ) learned = ([ skill : amount ]);
	else (int)learned[skill] += amount;

	if( (!weak_mode || !userp(ob))
		&& learned[skill] > (skills[skill] + 1) * (skills[skill] + 1) )
	{
		skills[skill]++;
		learned[skill] = 0;
		tell_object(this_player(), HIC+obname+"的「" + to_chinese(skill) + "」进步了！\n" NOR);
		SKILL_D(skill)->skill_improved(ob);
	}
}

int do_practice(string skb)
{
	object ob=this_object(), me=this_player();
	string sknm, obname = ob->query("name");
	int sk, skbasic;

	seteuid(getuid());

        if(ob->is_busy())
                return notify_fail(obname+"现在正忙着呢。\n");
	if(ob->is_fighting())
		return notify_fail(obname+"已在战斗中了，学点实战经验也好。\n");
	if( !skb) return notify_fail("你要让"+obname+"练习什么？\n");
	if( !stringp(sknm = ob->query_skill_mapped(skb)) )
		return notify_fail("你只能让"+obname+"练习用 enable 指定的特殊技能。\n");

	skbasic = ob->query_skill(skb, 1);
	sk = ob->query_skill(sknm, 1);
	if( sk < 1 )
		return notify_fail(obname+"好像还没有学过这项技能吧？\n");
	if( skbasic < 1 )
		return notify_fail(obname+"对这方面的技能还是一窍不通，最好从先从基本学起。\n");
	if( skbasic/2 <= sk/3 )
		return notify_fail(obname+"的基本功火候未到，必须先打好基础才能继续提高。\n");
	if( !SKILL_D(sknm)->valid_learn(ob) ) 
		return notify_fail("依"+obname+"目前的能力，没办法学习这种技能。\n");
	if( SKILL_D(sknm)->practice_skill(ob) )
		return notify_fail("依"+obname+"目前的能力，没办法练习这种技能。\n");
	notify_fail(obname+"现在不能练习这项技能。\n");
	if( !SKILL_D(sknm)->valid_learn(ob) ) return 0;

	notify_fail( obname+"试着练习"+to_chinese(sknm)+"，但是并没有任何进步。\n");
	if (sk*sk*sk/10 > (int)ob->query("combat_exp")) 
	{
		return notify_fail("也许是缺乏实战经验，练习总没法进步。\n");
		return 1;
	}

	ob->receive_damage("qi", 10);
	write(HIC + obname+"试着把" + to_chinese(sknm) + "练了一趟。\n"NOR);
	ob->improve_npcskill(sknm, skbasic * 2);
	write(HIY + obname + to_chinese(sknm) + "进步了！\n" NOR);
	return 1;
}

int do_exercise(string arg)
{
	int exercise_cost;
	object ob=this_object();
	string obname=ob->query("name");

	seteuid(getuid());

	if (ob->is_busy() || ob->query_temp("pending/exercising"))
		return notify_fail(obname+"现在正忙着呢。\n");
	if( ob->is_fighting() )
		return notify_fail("战斗中不能练内功，会走火入魔。\n");
	if( !stringp(ob->query_skill_mapped("force")) )
		return notify_fail("你必须先让"+obname+"选择要用的内功心法。\n");
	if( !arg || !sscanf(arg, "%d", exercise_cost))
		return notify_fail(obname+"要花多少气练功？\n");
	if (exercise_cost < 10)
		return notify_fail(obname+"的内功还没有达到那个境界！\n");
	if( (int)ob->query("qi") < exercise_cost )
		return notify_fail(obname+"现在的气太少了，无法产生内息运行全身经脉。\n");

	if( (int)ob->query("jing") * 100 / (int)ob->query("max_jing") < 70 )
		return notify_fail(obname+"现在精不够，无法控制内息的流动！\n");
	write(obname+"坐下来运气用功，一股内息开始在体内流动。\n");

	ob->set_temp("pending/exercise", 1);
	ob->set_temp("exercise_cost", exercise_cost);
	message_vision("$N盘膝坐下，开始修炼内力。\n", ob);
	ob->start_busy((: exercising :), (:halt_exercise:));
	return 1;
}

int exercising(object ob)
{
	int exercise_cost = (int)ob->query_temp("exercise_cost");
	int neili_gain = 1 + (int)ob->query_skill("force") / 10;
	int max_neili_gain = (int) random(ob->query("max_neili") /500);
	int taixuan;
	object where=environment(ob);
	string obname=ob->query("name");

	if (exercise_cost < 1)
		return 0;
	ob->add("neili", neili_gain);
	ob->set_temp("exercise_cost", exercise_cost -= neili_gain);
// 灵鹫玄冰室
	if(where->query("xuanbing"))
		ob->add("qi", (int)neili_gain/3);
// 太玄功
	if ((int)ob->query_skill("taixuan-gong",1))
	{
		taixuan = (int)ob->query_skill("taixuan-gong",1);
		if(taixuan > 10)
			ob->add("qi", (int)neili_gain * taixuan / 400);
	}
// 神照经
	if ((int)ob->query_skill("shenzhao-jing",1))
	{
		taixuan = (int)ob->query_skill("shenzhao-jing",1);
		if(taixuan > 10)
			ob->add("qi", (int)neili_gain * taixuan / 400);
	}

	if(living(ob))
	ob->add("qi", -neili_gain);
	
	if (exercise_cost > 0)
		return 1;

	ob->set_temp("pending/exercise", 0);
	message_vision("$N运功完毕，深深吸了口气，站了起来。\n", ob);
	if ((int)ob->query("neili") < (int)ob->query("max_neili") * 2)
		return 0;
	else
	{
		if((int)ob->query("max_neili")>(int)ob->query_skill("force")*10)
		{
			write(obname+"内力修为似乎已达到了瓶颈。\n");
			ob->set("neili", (int)ob->query("max_neili"));
			return 0;
		}
		else {
			if (max_neili_gain>2) max_neili_gain=2;
			ob->add("max_neili", 1+max_neili_gain);
			ob->set("neili", (int)ob->query("max_neili"));
			message_vision(HIC"$N的内力增加了！！\n"NOR, ob);
			return 0;
		}
	}
}

int halt_exercise(object ob)
{
	if ((int)ob->query("neili") > (int)ob->query("max_neili") * 2)
		ob->set("neili", (int)ob->query("max_neili") * 2);
	ob->set_temp("pending/exercise", 0);
	return 1;
}
int do_study(string arg)
{
	object book, ob = this_object();
	string zhao_name, obname = ob->query("name");
	mapping skill;
	int my_skill, cost, i, success=0;

	if(!arg) return notify_fail("你要"+obname+"读什么？\n");
        if(ob->is_busy())
                return notify_fail(obname+"现在正忙着呢。\n");
	if(ob->is_fighting() )
		return notify_fail(obname+"无法在战斗中专心下来研读新知！\n");
	if(!objectp(book = present(arg, ob)) )
		return notify_fail(obname+"没这本书可读啊？\n");
	if( !mapp(skill = book->query("skill")) )
		return notify_fail(obname+"无法从这样东西学到任何东西。\n");
	if( !ob->query_skill("literate", 1) )
		return notify_fail(obname+"是个文盲，先学点文化吧。\n");

	message("vision", obname+"正专心地研读"+book->name()+"。\n", environment(ob), ob);
	if( (int)ob->query("combat_exp") < skill["exp_required"] )
	{
		message_vision(HIC"$N的实战经验不足，再怎么读也没用。\n"NOR,ob);
		return 1;
	}

	notify_fail("以"+obname+"目前的能力，还没有办法学这个技能。\n");
	if( !SKILL_D(skill["name"])->valid_learn(ob) ) return 0;

	cost = skill["jing_cost"] + skill["jing_cost"] 
		* (skill["difficulty"] - (int)ob->query("int"))/20;
	if (cost < 10) cost = 10; // minimum cost

	if( ob->query_skill(skill["name"], 1) > skill["max_skill"] )
	{
		message_vision(HIR"$N研读了一会儿，但是发现上面所说的都太浅了，没有学到任何东西。\n"NOR, ob);
		return 1;
	}
	if( ob->query_skill(skill["name"], 1) < skill["min_skill"] )
	{
		message_vision(HIR"$N研读了一会儿，但是发现上面所说的都太深奥了，毫无收获。\n"NOR, ob);
		return 1;
	}

	if( !ob->query_skill(skill["name"],1)) ob->set_skill(skill["name"], 0);

	my_skill = ob->query_skill(skill["name"], 1);

	if( (int)ob->query("jing") > cost )
	{
		if( (string)SKILL_D(skill["name"])->type()=="martial"
		&& my_skill*my_skill*my_skill/10 > (int)ob->query("combat_exp"))
		{
			message_vision("也许是缺乏实战经验，$N对$n上面所说的东西总是无法领会。\n", ob, book);
		}
		else
		{
			if(zhao_name = SKILL_D(skill["name"])->query_skill_name(my_skill))
			printf(obname+"研读了有关%s的技巧，对「%s」这一招似乎有些心得。\n", 
				to_chinese(skill["name"]), zhao_name);
			else
			printf(obname+"研读了有关%s的技巧，似乎有点心得。\n", to_chinese(skill["name"]));
			ob->improve_npcskill(skill["name"], (int)ob->query_skill("literate", 1)/5+1);
		}
	} else {
		cost = ob->query("jing");
		return notify_fail(obname+"现在过于疲倦，无法专心下来研读新知。\n");
	}
	ob->receive_damage("jing", cost);

	return 1;
}

int do_learn(string arg)
{
	object obt, ob = this_object();
	string skill, teacher, master, skill_name, obname=ob->query("name");
	int master_skill, my_skill, jing_cost, pertimes;

	if( ob->is_busy()) return notify_fail(obname+"现在正忙着呢。\n");
	if(!arg || (sscanf(arg, "%s %s", teacher, skill) !=2 ))
		return notify_fail("指令格式：blearn | bxue <某人> <技能>\n");
	if( ob->is_fighting() )
		return notify_fail("让"+obname+"临阵磨枪？来不及啦。\n");
	if( !(obt = present(teacher, environment(ob))) || !obt->is_character())
		return notify_fail("让"+obname+"向谁求教？\n");
	if( !living(obt) )
		return notify_fail("嗯....得先把"+obt->name()+"弄醒再说。\n");

	if( !ob->is_apprentice_of(obt) && !(obt->recognize_apprentice(ob)) )
	{
		return notify_fail(obt->name()+reject_msg[random(sizeof(reject_msg))] );
	}

	if( !master_skill = obt->query_skill(skill, 1) )
		return notify_fail("这项技能"+obname+"恐怕必须找别人学了。\n");

	notify_fail(obt->name()+"不愿意教"+obname+"这项技能。\n");
	if( obt->prevent_learn(ob, skill) ) return 0;

	my_skill = ob->query_skill(skill, 1);
	if( my_skill >= master_skill )
		return notify_fail("这项技能"+obname+"的程度已经不输"+obname+"的师父了。\n");
	if( my_skill >= (int)(master_skill - ob->query("betrayer")*2))
		return notify_fail(obt->name()+"皱了皱眉头，不禁想起"+obname+"过去的叛师经历。\n");
	notify_fail("依"+obname+"目前的能力，没有办法学习这种技能。\n");
	if( !SKILL_D(skill)->valid_learn(ob) ) return 0;
	jing_cost = 100 / (int)ob->query("int");
	if( !my_skill )
	{
		jing_cost *= 2;
		ob->set_skill(skill,0);
	}
	if( (ob->query("potential") - ob->query("learned_points")) < 1)
		return notify_fail(obname+"的潜能不够学习了。\n");
	printf(HIC+obname+"向%s请教了有关「%s」的疑问。\n"NOR, obt->name(), to_chinese(skill));

	if( obt->query("env/no_teach") )
		return notify_fail("但是"+obt->name()+"现在并不准备回答"+obname+"的问题。\n");

	tell_object(obt, sprintf("%s向你请教有关「%s」的问题。\n",
		obname, to_chinese(skill)));

	if( (int)obt->query("jing") > jing_cost/5 + 1 )
	{
		if( userp(obt) ) obt->receive_damage("jing", jing_cost/5 + 1);
	} else
	{
		write("但是"+obt->name()+"显然太累了，没有办法教"+obname+"什麽。\n");
		tell_object(obt, "但是你太累了，没有办法教"+obname+"。\n");
		return 1;
	}
		
	if( (int)ob->query("jing") > jing_cost )
	{
		if( (string)SKILL_D(skill)->type()=="martial"
		&& my_skill*my_skill*my_skill/10 > (int)ob->query("combat_exp"))
		{
			return notify_fail("也许是缺乏实战经验，"+obname+"对"+obt->name()+"的回答总是无法领会。\n");
		} else
		{
			if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
	 			printf(obname+"听了%s的指导，对「%s」这一招似乎有些心得。\n", obt->name(), skill_name);
			else
				printf(obname+"听了%s的指导，似乎有些心得。\n", obt->name());
			ob->add("learned_points", 1);
			ob->improve_npcskill(skill, random(ob->query_int()));
		}
	} else
	{
		if (jing_cost > ob->query("jing"))
			jing_cost = ob->query("jing");
		return notify_fail(obname+"今天太累了，结果什么也没有学到。\n");
	}
	ob->receive_damage("jing", jing_cost);
	return 1;
}
void update_me()
{
	object obj=this_object();
	obj->set("max_qi",100+obj->query("max_neili")/4);
	obj->set("max_jing",100+obj->query("max_jingli")/4);
}
