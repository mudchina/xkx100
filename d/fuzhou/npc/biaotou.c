// biaotou.c
inherit NPC;
#include <ansi.h>

#define lay_exp 20
#define lay_pot 5
#define price_exp 300
#define price_pot 80
#define total_appear 10
#define killer_appear 3
#define delay_appear 2
#define total_cmd 10
#define bt_cmd 3
#define A_TIME 60
#define B_TIME 1

string * random_act = ({
	"fear",
	"dazuo 40",
	"dazuo 60",
	"dazuo 100",
	"dazuo 120",
	"sigh",
	"sigh1",
	"say 你要把镖车运到哪里去？",
	"remove all",
	"remove all",
	"remove all",
	"drop all",
});

string * inroad_msg = ({
	"$N突然恍然般道：“哦，这地方我以前来过，该从这走。”说罢，转身就走。\n",
	"$N突然惊恐地道：“哎呀，劫匪来了，我从这条路先走了。”\n",
	"$N奇怪地瞪着$n：“哎，你不认识路吧？去北京走这边！”说着自顾走了。\n",
	"$N向$n摆摆手：“那边现在路不平静，江湖人物多。走僻静的吧！”一边说一边扭头就走。\n",
	"$N悄悄对$n说道：“江湖有言道：『小心天下去得，莽撞寸步难行』。”抛下$n就走了。\n",
	"$N对$n说道：“『忍得一时之气，可免百日之灾。』上次在这吃过亏，这次往那边闪吧。”\n",
	"$N说道：“江湖上有言道：『宁可不识字，不可不识人。』”理也不理$n，拔步就走。\n",
	"$N说道：“江湖上有言道：『晴天不肯走，等到雨淋头。』”脚下丝毫不停，一路小跑而去。\n",
	"$N说道：“江湖上有言道：『念念当如临敌日，心心便似过桥时。』$n，我先行一步。”\n",
	"$N说道：“江湖上有言道：『路逢险处须当避，不是才子莫吟诗。』”双腿一拔，回身狂奔。\n",
	"$N说道：“江湖上有言道：『若要精，听一听；站得远，望得清。』你往那边去，我往这边走。”\n",
	"$N说道：“江湖上有言道：『真人不露相，露相不真人。』你先探探那边路，我到这边躲躲再走。”\n",
	"$N对$n说道：“『你去你的阳关道，我走我的独木桥。』回见回见。”\n",
	"$N满脸堆笑，对$n说道：“『光棍不吃眼前亏，伸手不打笑脸人。』在下到那边方便方便。”\n",
});

string *xing=({"赵","钱","孙","李","周","吴","郑","王","冯","陈","褚","卫","蒋","沈","韩","杨","朱","秦","尤","许","何","吕","施","张","孔","曹","严","华","金","魏","陶","姜","戚","谢","邹","喻","柏","水","窦","章","云","苏","潘","葛","奚","范","彭","郎","鲁","韦","昌","马","苗","凤","花","方","俞","任","袁","柳","酆","鲍","史","唐","费","廉","岑","薛","雷","贺","倪","汤","滕","殷","罗","毕","郝","邬","安","常","乐","于","时","傅","皮","卞","齐","康","伍","余","元","卜","顾","孟","平","黄","和","穆","萧","尹","姚","邵"}); 

string status_color(int current, int max);

void create()
{
	object ob;
	string name = xing[random(sizeof(xing))]+"镖头";
	set_name(name, ({"biao tou", "bt" }));
	set("title", HIR"福"HIC"威"YEL"镖局"HIY"镖头"NOR);
	set("gender", "男性" );
	set("age", 20+random(10));
        set("max_qi",300+random(200));
        set("combat_exp", 100000);
	set("attitude", "friendly");
	set("vendetta_mark", "authority");
	set("env/wimpy",50);
	set("per",2);
	set("chat_chance", 15);
	set("chat_msg",({
		name+"喝道：“闲杂人等闪开了。”\n",
		name+"喝道：“快走快走，别偷懒！”\n",
		name+"说道：“江湖上有言道：『容情不动手，动手不容情。』”\n",
		name+"说道：“江湖上有言道：『只要人手多，牌楼抬过河。』诸位和我同保此镖，还怕谁来！”\n",
		name+"说道：“江湖上有言道：『行家一伸手，便知有没有。』”\n",
		name+"说道：“江湖上有言道：『做贼的心虚，放屁的脸红。』你们可得定下神，别让人瞧出了破绽。”\n",
		name+"说道：“江湖上有言道：『手稳口也稳，到处好藏身。』待回到镖局，咱们再痛痛快快的大醉一场。”\n",
		name+"说道：“江湖上有言道：『有缘千里来相会，无缘对面不相逢。』此次同往保镖，真是幸会哪！幸会！”\n",
	}) );
	set("chat_chance_combat",80);
	set("chat_msg_combat", ({
		name+"大喊道：“不好了，有人劫镖了。”\n",
	}) );
	
	set_skill("sword",50);
	set_skill("force",40);
	set_skill("parry",50);
	set_skill("dodge",50);
	set_skill("bixie-sword",50);
	map_skill("sword","bixie-sword");
	map_skill("parry","bixie-sword");
	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/cloth/cloth");
}

void init()
{
	add_action("do_baobiao","baobiao");
	add_action("do_baobiao","jiebiao");
	add_action("do_order","order");
	add_action("do_give","give");
	add_action("do_hp","hp");
	remove_call_out("do_check");
	call_out("do_check",A_TIME);
	remove_call_out("do_check1");
	call_out("do_check1",B_TIME);
}

int do_baobiao(string arg)
{
	object me = this_player();

	if (!me->query_temp("fuwei_ready"))
		return notify_fail(this_object()->query("name") +"说：“去去去，去帐房交钱去！”\n"); 
	if ( query("leader_name") != me->query("id") )
		return notify_fail(this_object()->query("name") +"说：“你没有负责保护此镖的义务！”\n"); 
	set("gurader_name",me->query("id") );
	me->set_leader(this_object());
	tell_object(me, "你现在开始接管镖队了，命令(order)他们启程，人镖齐全送到"+me->query_temp("fuwei_dest")+"分局就成！\n");
	return 1;
}

int do_hp(string arg)
{
	object ob = this_object();
	object me = this_player();
	string msg;
	mapping my;

	if (!arg || (arg != ob->query("id") && arg != "bt") )
		return 0;
	my = ob->query_entire_dbase();

	if (me->query("id") == query("leader_name") )
	{
		tell_object(me,sprintf("%s的健康情况如下：\n",my["name"]));
		msg = sprintf(" 精  ： %s%4d/ %4d %s(%3d%%)\n" NOR ,
status_color(my["jing"], my["eff_jing"]), my["jing"], my["eff_jing"],
status_color(my["eff_jing"],my["max_jing"]),my["eff_jing"]*100/my["max_jing"]);
		tell_object(me,msg);
		msg = sprintf(" 气  ： %s%4d/ %4d %s(%3d%%)\n" NOR ,
status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
status_color(my["eff_qi"], my["max_qi"]), my["eff_qi"] * 100 / my["max_qi"]);
		tell_object(me,msg);
		return 1;
	}
	else return 0;
}

int do_order(string arg)
{
	object me = this_player();
	string ss_name,act,sth,dest,dest_add, *dirs;
	int give_exp,give_pot,i,flag;
	object room,gaoshou,jiefei,fbiaotou,cart,ob = this_object();
	mapping exits;

	if ( query("leader_name") != me->query("id") )
		return notify_fail("这不是你要接的镖，镖队不会听你指挥！\n");
	if ( query("gurader_name") != me->query("id") )
		return notify_fail("由于你没有接镖(jiebiao)，镖队不会听你指挥！\n");
	if (!arg || sscanf(arg, "%s %s",act,sth) != 2)
		return notify_fail("指令格式：order <动作词> <具体动作描述>\n");

	if ( act!="go" && act!="give" && act!="wear" && act!="remove" && act!="zou" && act!="wield" && act!="unwield" && act!="enter" && act!="eat" )
		return notify_fail("目前暂时不支持该项动作指令！\n");

	if (act == "go")
	{
		if (! objectp(cart = present("cart", environment(me))))
		{
			command(arg);
			if (! objectp(cart = present("cart", environment(me))))
			return notify_fail(HIR"镖车没跟着，找找吧。\n"NOR);
		}
		if (ob->is_busy() )
			return notify_fail(HIG"镖车轮陷泥里了，等会吧。\n"NOR);
		dest = sprintf( "exits/%s",sth);
		if (! dest_add = environment()->query(dest))
			return notify_fail("这个方向没有出路。\n");
		add("total_steps",1);

		if (random(5) == 0)
		{
			message_vision("镖车隆隆驶了开去。\n",ob);
			if (mapp(exits=environment(me)->query("exits")))
				dirs = keys(exits);
			message_vision(HIY+inroad_msg[random(sizeof(inroad_msg))]+NOR,ob,me);
			command("go " + dirs[random(sizeof(dirs))]);
			cart->move(environment());
			message_vision("镖车隆隆驶了过来。\n",ob);
		}
		else
		if (random(total_appear) < killer_appear)
		{
			message_vision("镖车隆隆驶了开去。\n",ob);
			if ( !room=find_object(dest_add) )
				room=load_object(dest_add);
			if (random(2)>0)
			{
				ss_name=__DIR__"gaoshou";
				gaoshou = new(ss_name);
				gaoshou->move(room);
			}
			else
			{
				ss_name=__DIR__"fake-biaotou";
				fbiaotou = new(ss_name);
				fbiaotou->move(room);
				fbiaotou->set("name", ob->query("name"));
//				fbiaotou->set("id", ob->query("id"));
				fbiaotou->set_leader(ob);
				message_vision("\n$N走了过来。\n",fbiaotou);
				message_vision("\n\n$N忽然发现有点不对劲。不过来不及啦！\n",me);
			}
			command(arg);
			ob->start_busy(1);
			cart->move(environment());
			message_vision("镖车隆隆驶了过来。\n",ob);
		}
		else
		if (random(total_appear) < delay_appear)
		{
			command(arg);
			ob->start_busy(1);
			message_vision(HIR"镖车没跟着，找找吧。\n"NOR, ob);
		}
		else
		{
			message_vision("镖车隆隆驶了开去。\n",ob);
			command(arg);
			ob->start_busy(random(2));
			cart->move(environment());
			message_vision("镖车隆隆驶了过来。\n",ob);
		}
	}
	else command(arg);
	return 1;
}
void die()
{
	object me, cart;
	object ob;

	ob = this_object();
	if ( objectp( cart = present("cart", environment(ob))) )
		destruct(cart);
	if ( ob->query("leader_name") && objectp(me = find_player(ob->query("leader_name")) ))
		tell_object(me,HIB"镖师死了，镖车丢了，你交不了差了！\n"NOR);
	return ::die();
}
int do_give(string arg)
{
	object me = this_player();
	object ob ;
	string o_name,p_name;

	if ( me->query("id") != query("leader_name") ) return 0;
	if ( sscanf(arg,"%s %s",p_name,o_name) == 2 ||
		sscanf(arg,"%s to %s",o_name,p_name) ==2 ) ;
	else return 0;
	if ( p_name != "bt") return 0;
	if (! ob = present(o_name,me))
		return notify_fail("你身上没有这样东西。\n");
	if (ob->query("no_drop"))
		return notify_fail("这样东西不能随便给人。\n");

	ob -> move(this_object());
	message("vision",sprintf("%s给%s一%s%s。\n",me->name(),
		this_object()->name(),ob->query("unit"),ob->name()),me);
	return 1; 
}

void do_check()
{
	object me,gaoshou,jiefei;
	string ss_name;
	int i;
	mapping exits;
	string * dirs;
	object ob = this_object();
	object where = environment(ob);

	add ("total_tired",1);

	if (ob->is_fighting())
	{
		remove_call_out("do_check");
		call_out("do_check",A_TIME);
	}
	else
		if (! living(ob))
		{
			ob->receive_damage("qi",1000);
		}
		else
		{   // 修改lijia
			//if (! me = find_player(query("leader_name") ))
			if (!me || ! me = find_player(query("leader_name") ))
			{
				remove_call_out("do_check");
				call_out("do_check",A_TIME);
			}
			else
			{
				if (random(total_appear) < killer_appear)
				{
					if (random(2)>0) ss_name=__DIR__"gaoshou";
					else ss_name=__DIR__"fake-biaotou";
					gaoshou = new(ss_name);
					gaoshou->move(where);
					ob -> start_busy(1);
				}
				else
				{
					if (random(total_cmd) < bt_cmd )
					{
						if (! ob->is_busy() )
						{
							if (random(2) >0 )
								command(random_act[random(sizeof(random_act))]);
							else
							{
								if ( mapp(exits = where->query("exits") ) )
								{
									message_vision(HIC+inroad_msg[random(sizeof(inroad_msg))]+NOR,ob);
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
        object cart;
        object ob = this_object();

	if (living(ob) && ob->query("qi") > 0 )
	{
		remove_call_out("do_check1");
		call_out("do_check1",B_TIME);
	}
	else
	{
		message_vision(HIR"$N在昏迷中突然急促地呻吟了一声，然后就再没有声音了。\n"NOR,ob);
	     if (objectp(cart = present("cart", environment(ob)))) destruct(cart);
  	      
             ob -> receive_damage("qi",1000);
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

int accept_hit(object me)
{
	object ob = this_object();
	object gurad_ob;

	if (!query("gurader_name")) return 1;
	if (!gurad_ob = present(query("gurader_name"),environment(ob) ) )
  {
  	if (userp(me))
  		return notify_fail(HIW"玩家不能劫镖！\n"NOR);
		return 1;
	}
	if (me == gurad_ob)
		return notify_fail(HIR"你不想干啦？早说嘛！\n"NOR);
	else
	{
		tell_object(me,HIR"当值镖师正受到"+gurad_ob->query("name")+"的保护，你受到反扑！\n"NOR);
		tell_object(gurad_ob,HIR"当值镖师受到"+me->query("name")+"攻击，危险！护镖要紧！你挺身就上！\n"NOR);
		me -> kill_ob(gurad_ob);
		gurad_ob -> fight_ob(me);
		return notify_fail("");
	}
}
int accept_fight(object who)	{return accept_hit(who);}
int accept_kill(object who)		{return accept_hit(who);}
int accept_touxi(object who)	{return accept_hit(who);}
