// /d/npc/renzhi.c 人质
//modified by sega 1/10/99
//修改了奖励的上限
#include <ansi.h>
#define lay_exp 20
#define lay_pot 5
#define lay_score 10
#define price_exp 300
#define price_pot 80
#define price_score 100
#define total_appear 10
#define killer_appear 2
#define total_cmd 10
#define rz_cmd 3
#define A_TIME 60
#define B_TIME 5

inherit NPC;
string * des_str=({
	"这是一位黑纱蒙面的人，看不出有多大岁数。\n",
	"他整个人都被裹在一件长大的黑衣里，默默站在那里一言不发。\n",
	"一位微微发胖的人，满脸堆着笑。\n",
	"他的眉头都锁在一起，似乎对什么事很担心的样子。\n",
	"这个人猥猥琐琐地站在那里，好象有什么话又不敢说似的。\n",
	"一位看起来神神秘秘的人，可是总让人觉得有点怪异的样子。\n",
	"这个人站在那里好象不停地在发抖，也许是害怕什么。\n",
	"他满脸的皱纹，看起来好象岁数很大，不过仔细一看，又好象并没有实际那么大。\n",
	"他穿着一件本来质地很好的衣服，可是现在衣服上沾满了尘土和血迹。\n",
});

string * random_act = ({
	"fear",
	"dazuo 40",
	"dazuo 60",
	"dazuo 100",
	"dazuo 120",
	"sigh",
	"sigh1",
	"say 你要把我带到哪里去啊？",
	"remove all",
	"remove all",
	"remove all",
	"drop all",
});

string * escape_msg = ({
	"$N突然惊恐地道：“哎呀，杀手来了，我从这条路先跑了。”\n",
	"$N突然惊恐地指着你，歇斯底里地大喊起来：“杀手！你就是杀手！你就是派来杀我的杀手！”没等谁反应过来，$N转身大跑起来。\n",
	"$N怯怯地四处看了看，突然叫了起来：“这地方如此偏僻，怎么能多呆呢，我先走吧。”\n",
	"$N一回头，似乎看见远处有什么东西掠过，惊得转身就跑。\n",
	"忽然听到$N一声惨叫，好象被踩住了尾巴的兔子一样转身逃了开去。\n",
	"$N突然恍然般道：“哦，这地方我以前来过，该从这条路走。说罢，转身就走。”\n"
,
	"$N蓦地撒腿就跑，怎么喊他也不回头，一溜烟地消失了。\n",
});

string status_color(int current, int max);

void create()
{
	mapping name;
	if (random(2) == 0)
	{
		name = NAME_D->woman_name();
		set("gender", "女性");
	}
	else
	{
		name = NAME_D->man_name();
		set("gender", "男性");
	}
	set_name(name["name"],({"ren zhi", "rz"}));

	set("age", 17 + random(60) );
	set("long", des_str[random(sizeof(des_str))]);

	set("combat_exp", 500 + random(5000));
	set("attitude", "friendly");
	set("inquiry", ([
		"name" : "我的姓名是不能对人乱讲的。\n",
	]));

	set("env/wimpy",50);
	set("no_get",1);
	set("no_beg",1);
	set("no_steal",1);
	set("no_kill",1);
	set("max_neili",150 + random(150) );
	set("neili",query("max_neili") );

	set_skill("unarmed",20);
	set_skill("sword",20);
	set_skill("blade",20);
	set_skill("dodge",20);
	set_skill("force",20);
	set_skill("huntian-qigong",20);
	map_skill("force","huntian-qigong");
	
	set( "max_qi", 350 + random(200) );
	set( "max_jing", 200 + random(300) );

	set("leader_name","");
	set("dest_add","");
	set("combat_num",0);
	set("total_steps",0);
	set("total_tired",0);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_baohu","baohu");
	add_action("do_order","order");
	add_action("do_steal","steal");
	add_action("do_hit","hit");
	add_action("do_kill","kill");
	add_action("do_give","give");
	add_action("do_hp","hp");
	add_action("do_touxi","touxi");
	remove_call_out("do_check");
	call_out("do_check",A_TIME);
	remove_call_out("do_check1");
	call_out("do_check1",B_TIME);
}


int do_baohu(string arg)
{
	object me = this_player();

	if ( query("leader_name") != me->query("id") )
		return notify_fail("你没有负责保护该人质的义务！\n"); 
	set("gurader_name",me->query("id") );
	tell_object(me,HIR"注意：你现在开始对人质进行保卫，任何针对人质的攻击都将自动转移到你身上！\n"NOR);
	return 1;
}

int do_hp(string arg)
{
	object ob = this_object();
	object me = this_player();
	string msg;
	mapping my;

	if (!arg || (arg != ob->query("id") && arg != "rz") )
		return 0;
	my = ob->query_entire_dbase();

	if (me->query("id") == query("leader_name") ) {
		tell_object(me,sprintf("%s的健康情况如下：\n",my["name"]));
		msg = sprintf(" 精  ： %s%4d/ %4d %s(%3d%%)\n" NOR ,
			status_color(my["jing"], my["eff_jing"]), my["jing"], my["eff_jing"],
			status_color(my["eff_jing"], my["max_jing"]), my["eff_jing"] * 100 / my["max_jing"]);
		tell_object(me,msg);
		msg = sprintf(" 气  ： %s%4d/ %4d %s(%3d%%)\n" NOR ,
status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
status_color(my["eff_qi"], my["max_qi"]), my["eff_qi"] * 100 / my["max_qi"]);
		tell_object(me,msg);
		return 1;
	}
	else
		return 0;
}

int do_hit(string arg)
{
	object ob = this_object();
	object me = this_player();
	object gurad_ob;

	if (!arg || (arg != ob->query("id") && arg != "rz") )
		return 0;
	if (!query("gurader_name") || !gurad_ob = present(query("gurader_name"),environment(ob)) )
	{
		if (userp(me) )
		{
			tell_object(me,HIW"玩家不能攻击无保护的人质！\n"NOR);
			return 1;
		}
		else
			return 0;
	}
	if (me == gurad_ob)
	{
		tell_object(me,HIR"咦？你不是他的保护者吗?\n"NOR);
		return 1;
	}
	else
	{
		tell_object(me,HIR"人质正受到"+gurad_ob->query("name")+"的保护，人家加入战斗对你发起攻击！\n"NOR);
		tell_object(gurad_ob,HIR"人质受到"+me->query("name")+"攻击，你挺身加入战斗！\n"NOR);
		me -> fight_ob(gurad_ob);		
		gurad_ob -> fight_ob(me);
		return 1;
	}
}

int do_kill(string arg)
{
	object ob = this_object();
	object me = this_player();
	object gurad_ob;

	if (!arg || (arg != ob->query("id") && arg != "rz") ) return 0;
	if (!query("gurader_name") || !gurad_ob = present(query("gurader_name"),
environment()) )
	{
		if (userp(me) )
		{
			tell_object(me,HIW"玩家不能攻击无保护的人质！\n"NOR);
			return 1;
		}
		else return 0;
	}

	if (!gurad_ob = present(query("gurader_name"),environment(ob) ) )
		return 0;
	if (me == gurad_ob)
	{
		tell_object(me,HIR"你不想完成你的任务了吗？\n"NOR);
		return 1;
	}
	else
	{
		tell_object(me,HIR"人质正受到"+gurad_ob->query("name")+"的保护，人家加入战斗抵御你的攻击！\n"NOR);
		tell_object(gurad_ob,HIR+me->query("name")+"准备杀死人质，你挺身加入战斗！\n"NOR);
		me -> kill_ob(gurad_ob);		
		gurad_ob -> fight_ob(me);
		return 1;
	}
}

int do_touxi(string arg)
{
	object ob = this_object();
	object me = this_player();
	object gurad_ob;

	if (!arg || (arg != ob->query("id") && arg != "rz") )
		return 0;
	if (!query("gurader_name") || !gurad_ob = present(query("gurader_name"),environment(ob)) )
	{
		if (userp(me) )
		{
			tell_object(me,HIW"玩家不能攻击无保护的人质！\n"NOR);
			return 1;
		}
		else return 0;
	}

	if (!gurad_ob = present(query("gurader_name"),environment() ) )
		return 0;
	if (me == gurad_ob)
	{
		command("papa "+me->query("id"));
		tell_object(me,HIR"你不能偷袭人质。\n"NOR);
		return 1;
	}
	else
	{
		tell_object(me,HIR"人质正受到"+gurad_ob->query("name")+"的保护，人家加入战斗抵御你的攻击！\n"NOR);
		tell_object(gurad_ob,HIR+me->query("name")+"准备对人质进行偷袭，你挺身加入战斗！\n"NOR);
		me -> kill_ob(gurad_ob);
		gurad_ob -> fight_ob(me);
		return 1;
	}
}

int do_steal(string arg)
{
	object ob = this_object();
	object me = this_player();
	string who;

	sscanf(arg,"%*s %*s %s",who);

	if (who == ob->query("id") || who == "rz" )
	{
		message("vision",HIW"玩家不能偷人质身上的东西！\n"NOR,me);
		return 1;
	}
	return 0;
}

int do_order(string arg)
{
	object me = this_player();
	object ml;
	string act,sth,dest,dest_add;
	int give_exp,give_pot,give_score;
	int i;
	object room,shashou,anshazhe;
	string ss_name;

	if ( query("leader_name") != me->query("id") )
		return notify_fail("由于你不是该任务的接收者，人质不会听你的指挥！\n");
	if (!arg || sscanf(arg, "%s %s",act,sth) != 2)
		return notify_fail("指令格式：order <动作词> <具体动作描述>\n");

	if (query("qi") < 50)
		return notify_fail("目前人质没有力气执行该项动作！\n");

	if ( act!="go" && act!="ask chuanfu about 出海" && act!="get" && act!="give" && act!="drink" && act!="wear" && act!="remove" && act!="zou" && act!="wield" && act!="unwield" && act!="enter" && act!="eat" )
		return notify_fail("目前暂时不支持该项动作指令！\n");

        if ( me->is_busy() || me->is_fighting())
		    return notify_fail("你正忙着呢。\n");

	if (act == "go")
	{
		if (this_object()->is_busy() )
			return notify_fail(HIY"人质要休息一会儿再上路。\n"NOR);
		dest = sprintf( "exits/%s",sth);
		if (! dest_add = environment()->query(dest))
			return notify_fail("这个方向没有出路。\n");
		if (! environment(this_object())->query("no_fight"))
			add("total_steps",1);
		if (dest_add == query("dest_add") )
		{
		//目的地到达
			message_vision(YEL"$N长出了一口气道：哎，终于到了。不知道从哪里冒出来一辆马车将$N接上了车，然后扬尘而去。\n"NOR,this_object(),me);
			tell_object(me,HIW"恭喜你成功将人质送到目的地，完成了这项任务！\n"NOR);
			i = 0;
			give_exp = lay_exp * query("total_steps");
			give_pot = lay_pot * query("total_steps");
			give_score = lay_score * query("total_steps");
			while ( i < query("combat_num") )
			{
				give_exp += (price_exp/2 + random(price_exp/2));
				give_pot += (price_pot/2 + random(price_pot/2));
				give_score += (price_score/2 + random(price_score/2));
				i++;
			}
			if(give_exp > 8000) give_exp = 6000 + random(2000);
			if(give_pot > 2000 ) give_pot = 1200 + random(400);
			if(give_score > 4000 ) give_score = 3000 + random(500);
			tell_object(me,HIW + sprintf("你被奖励了！得到%s点经验和%s点潜能，%s点江湖阅历。\n", chinese_number(give_exp), chinese_number(give_pot), chinese_number(give_score) ) + NOR);
			me->add("combat_exp",give_exp);
			me->add("potential",give_pot);
			if ( ml = present("mi ling",me) ) destruct(ml);
			destruct(this_object());
			return 1;
		}
		else
		{
			if (random(total_appear) < killer_appear)
			{
				if (random(2)>0) ss_name=__DIR__"shashou";
				else ss_name=__DIR__"anshazhe";
				if ( !room=find_object(dest_add) )
					room=load_object(dest_add);
				shashou = new(ss_name);
				shashou->move(room);
				shashou->set_leader(this_object());
				command(arg);
				this_object()->start_busy(1);
			}
			else
			{
				command(arg);
				this_object()->start_busy(random(2));
			}
		}
	}
	else command(arg);
	return 1;

}

int do_give(string arg)
{
	object me = this_player();
	object ob ;
	string o_name,p_name;

	if ( me->query("id") != query("leader_name") ) return 0;
	if (!arg) return 0;
	if ( sscanf(arg,"%s %s",p_name,o_name) != 2) return 0;
	if ( sscanf(arg,"%s to %s",o_name,p_name) !=2 ) return 0;
	if ( p_name != "rz") return 0;
	if (! ob = present(o_name,me))
		return notify_fail("你身上没有这样东西。\n");
	if (ob->query("no_drop"))
		return notify_fail("这样东西不能随便给人。\n");

	ob -> move(this_object());
	message("vision",sprintf("%s给%s一%s%s。\n",me->name(),
		this_object()->name(),ob->query("unit"),ob->name()),me);
	return 1;

}

int active_died()
{
	object me;
	object ml;

	if (! me = find_player(query("leader_name")) ) return 1;
	else {
		tell_object(me,HIB"人质死了，你的任务失败了！\n"NOR);
		if (ml = present("mi ling",me) )
			destruct(ml);
		return 1;
	}
}

void do_check()
{
	object me,shashou;
	string ss_name;
	int i;
	mapping exits;
	string * dirs;
	object ob = this_object();
	object where = environment(ob);

	add ("total_tired",1);

	if (! living(ob) || ob->is_fighting())
	{
		remove_call_out("do_check");
		call_out("do_check",A_TIME);
	}
	else
	{
		if (! me = find_player(query("leader_name") ))
		{
			remove_call_out("do_check");
			call_out("do_check",A_TIME);
		}
		else
		{
			if (random(total_appear) < killer_appear)
			{
				if (random(2)>0) ss_name=__DIR__"shashou";
				else ss_name=__DIR__"anshazhe";
				shashou = new(ss_name);
				shashou->move(where);
				ob -> start_busy(1);
				shashou->set_leader(ob);
			}
			else
			{
				if (random(total_cmd) < rz_cmd )
				{
					if (! ob->is_busy() )
					{
						if (random(2) >0 ) command(random_act[random(sizeof(random_act))]);
						else
						{
							if ( mapp(exits = where->query("exits") ) )
							{
								message_vision(HIY+escape_msg[random(sizeof(escape_msg))]+NOR,ob);
								dirs = keys(exits);
								command("go "+dirs[random(sizeof(dirs))]);
							}
						}
					}
				}
			}
			remove_call_out("do_check");
			call_out("do_check",A_TIME);
		}
	}
}

void do_check1()
{
	object ob = this_object();

	if (ob -> query("qi") < 10)
	{
		message_vision(HIR"$N一声惨叫，轰地一声倒在地上。\n"NOR,ob);
		ob -> receive_damage("qi",100);
		ob -> receive_wound("qi",100);
		ob -> die();
	}
	else
	{
		if (living(ob) )
		{
			remove_call_out("do_check1");
			call_out("do_check1",B_TIME);
		}
		else
		{
			message_vision(HIR"$N在昏迷中突然急促地呻吟了一声，然后就再没有声音了。\n"NOR,ob);
			ob -> die();
		}
	}
}

string status_color(int current, int max)
{
	int percent;

	if( max>0 ) percent = current * 100 / max;
	else percent = 100;
	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}

