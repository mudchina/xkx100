// go.c
inherit F_CLEAN_UP;

#include <ansi.h>


mapping default_dirs = ([
	"north":	"北方",
	"south":	"南方",
	"east":		"东方",
	"west":		"西方",
	"northup":	"北边",
	"southup":	"南边",
	"eastup":	"东边",
	"westup":	"西边",
	"northdown":	"北边",
	"southdown":	"南边",
	"eastdown":	"东边",
	"westdown":	"西边",
	"northeast":	"东北",
	"northwest":	"西北",
	"southeast":	"东南",
	"southwest":	"西南",
	"up":		"上面",
	"down":		"下面",
	"enter":	"里面",
	"out":		"外面",
	"in":		"里",
	"left":		"左",
	"right":	"右",
	"leitai":	"擂台上面",
]);

string day_event() { return NATURE_D->outdoor_room_event();}
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string dest, mout, min, dir, blk, gud, skill, face, thing_msg;
	object env, obj, blocker, thing, *f_obs, *ob;
	mixed horse;
	mapping exit;
	mixed oldobj;
	string riding;
	int result, i, my_dex, count = 0;

	if( !arg ) return notify_fail("你要往哪个方向走？\n");
	if( me->over_encumbranced() )
		return notify_fail("你的负荷过重，动弹不得。\n");
	if( me->query_temp("bixie/cizu") )
		return notify_fail("你的双腿受伤，动弹不得。\n");
	if( me->is_busy() )
		return notify_fail("你的动作还没有完成，不能移动。\n");
	if(strsrch(file_name(environment(me)), "/death/") < 0 &&
		me->is_ghost() && !wizardp(me))
		return notify_fail("你是鬼魂，不能在阳间行走。\n");

	env = environment(me);
	if(!env) return notify_fail("你哪里也去不了。\n");

	if (me->is_fighting() )
	{
		f_obs = me->query_enemy();
		for(i=0; i<sizeof(f_obs); i++)
		{
//			if(f_obs[i]->query_temp("nian") == me)
			if(objectp(f_obs[i]) && environment(me) == environment(f_obs[i]))
			{
//			  if(f_obs[i]->query_temp("nian") == me->query("id"))	
			  if(f_obs[i]->query_temp("nian") == me)
		  	{	
			  	message_vision("$N转身要走，被$n太极云手粘劲粘住，不禁心里叫苦不迭！\n", me, f_obs[i]);
			  	return notify_fail("你无法逃跑。\n");
		  	}
			}
		}
		if (objectp(f_obs[0]) && !f_obs[0]->is_busy() )
			if (random((int)me->query("dex")) <= 
				random((int)f_obs[0]->query("dex")))
			{
				me->start_busy(1);
				message_vision("$N见势不好，转身要走，被$n一把拦在面前。想走？可没那么容易！\n", me, f_obs[0]);
				return notify_fail("你逃跑失败。\n");
			}
	}

// 守卫的问题
//if( !env->valid_leave(me, arg) ) return 0;

	result = env->valid_leave(me, arg);
	if (!wizardp(me) || !me->query("env/invisibility"))
	{
		if ( result < 0 ) return 1;
		else if ( result == 0 )
		{
			if (query_fail_msg())
			{
				tell_object(me,query_fail_msg());
				return 1;
			}
			return 0;
		}
	}

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) )
	{
		if( query_verb()=="go")
			return notify_fail("这个方向没有出路。\n");
		else return 0;
	}
/*
	if(userp(me) && me->query("tili") <= 20)
	{
		message_vision(HIY"$N觉得全身酸痛，疲劳感阵阵袭来。\n"NOR,me);
	}
	if(userp(me) && me->query("tili") <= 10)
	{
		message_vision(HIR"$N太累了，歇会儿再走吧。\n"NOR,me);
		return 1;
	}
	if(userp(me) && me->query("tili") <= 0)
	{
		message_vision(HIR"$N突然一阵眩晕，顿觉体力严重透支。\n"NOR,me);
		me->unconcious();
		return 1;
	}
*/
	if ( oldobj = me->query_temp("guardfor") )
	{
		if(objectp(oldobj))
		{
			if( !living(oldobj) || oldobj->query_temp("noliving") )
			{
				tell_object(me,"你放弃保护"+oldobj->name()+"。\n");
				me->delete_temp("guardfor");
			}
		}
	}

	dest = exit[ arg ];
	if ( !(obj = find_object(dest)) )
		call_other( dest, "???" );
	if ( !(obj = find_object(dest)) )
		return notify_fail( sprintf( "无法向 %s 移动。\n", dest ) );
	if( obj->query("day_shop") && ( day_event() == "event_night" ||
		day_event() == "event_midnight"))
		return notify_fail(obj->query("short")+"晚上不开，请天亮了再来！\n");
       
       if (  me->query_temp("LAST_PKER_TIME") && 
	     ( obj->query("no_fight")|| 
	     base_name(obj)=="/d/taohuacun/taohua1") &&
	     time() - me->query_temp("LAST_PKER_TIME")<7200 && !wizardp(me))
	     return notify_fail("杀了人，可不能做缩头乌龟！\n");
	if ( horse = me->query_temp("is_riding"))
	{
		if (objectp(horse))	riding = horse->name();
		else if (stringp(horse))riding = horse;	
	}
	if ( stringp(riding) &&
		(arg=="up" || arg=="down" || arg=="leitai" ||
		arg=="enter" || arg=="out"))
		return notify_fail("这个方向没法骑在座骑上过去。\n");

	ob = all_inventory(obj);
	for(i=0; i<sizeof(ob); i++)
		if( living(ob[i]) && !ob[i]->query_temp("noliving") &&
			ob[i] != me )
			count++;
// 移动前方是否太挤? 擂台上不超出2人
	if ( arg == "leitai")
	{
		if (!wizardp(me) && count>2)
		return notify_fail("擂台上人太多了，你上去找扁去啊？\n");
	}
	else
	{
		my_dex = (int)me->query_dex();
		if (!wizardp(me) && userp(me) &&
			(((my_dex < 15) && (count > 15)) ||
			((my_dex < 20) && (count > 20)) ||
			((my_dex < 30) && (count > 30)) ||
			((my_dex < 40) && (count > 40)) ||
			(count > 50)))
			return notify_fail("前面人太多了，你怎么挤也挤不过去。\n");
	}
//	if( !env->valid_leave(me, arg) ) return 0;
//	if( userp(me)) me->add("tili", -1);

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else dir = arg;

	if( me->is_fighting() )
	{
		if( me->query("race") == "人类" )
		{
			if (stringp(riding) )
			{
				mout = me->name()+"伏在" + riding + "身上往" + dir + "落荒而逃了。\n";	       
				min = me->name()+"骑着" + riding + "跌跌撞撞地跑了过来，模样有些狼狈。\n";
			}
			else
			{
				mout = me->name()+"往" + dir + "落荒而逃了。\n";
				min = me->name()+"跌跌撞撞地跑了过来，模样有些狼狈。\n";
			}
		}
		else {
			mout = me->name()+replace_string( me->query("fleeout_message"), "$d", dir );
			min  = me->name()+me->query("fleein_message");
		}
	} 
	else
	{
		if( wizardp(me) && me->query("env/invisibility") &&
			(wiz_level(me) >= wiz_level(env)))
		{
			mout = "";
			min = "";
		}
		else
		{
			if( me->query("race") == "人类" && me->query("age")>15)
			{
				face="的";
				if (me->query("gender")=="女性")
				{
					if (me->query("per") >= 30)
						face ="娇艳绝伦" + face;
					if ((me->query("per") >= 28) &&
						(me->query("per") < 30))
						face= "清丽绝俗" + face;
					if ((me->query("per") >= 26) &&
						(me->query("per") < 28))
						face= "风情万种" + face;
					if ((me->query("per") >= 24) &&
						(me->query("per") < 26))
						face= "容色秀丽" + face;
					if ((me->query("per") >= 21) &&
						(me->query("per") < 24))
						face= "面目姣好" + face;
					if (me->query("str") <= 16)
						face = "亭亭玉立" + face;
					if ((me->query("str") <= 20) &&
						(me->query("str") > 16))
						face= "体态轻盈"+ face;
					if ((me->query("per") < 21) &&
						(me->query("str") > 20) ||
						!userp(me))
						face = "";
				}
				else
				{
					if (me->query("per") >= 30)
						face= "玉树临风般" + face;
					if ((me->query("per") >= 26) &&
						(me->query("per") < 30))
						face="英俊潇洒" + face;
					if ((me->query("per") >= 22) &&
						(me->query("per") < 26))
						face="仪表堂堂" + face;
					if (me->query("str") >=23)
						face = "身材壮硕" + face;
					if ((me->query("str") >= 20) &&
						(me->query("str") < 23))
						face= "膀大腰圆"+ face;
					if ((me->query("per")<22) &&
						(me->query("str")<20) ||
						!userp(me))
						face = "";
				}
			} else face="";
			if (objectp(thing = me->query_temp("armor/cloth")))
				thing_msg = "身着" + thing->query("name");
			else thing_msg = "全身清洁溜溜";
			if (objectp(thing = me->query_temp("weapon")))
				thing_msg += "手执" + thing->query("name");
			if( me->query("race") == "人类" )
			{
				if ( arg == "leitai")
				{
					mout = me->name()+"双腿力蹬，纵起身形，轻轻跃上擂台。\n";
					min = me->name()+"从擂台下一跃而起，稳稳地落在台上。\n";
				}
				else
					if( env->query("outdoors") && stringp(riding) )
					{
						mout = me->name()+"骑着"+riding+"向" + dir + "疾驰而去。\n";
						min = face + me->name() + thing_msg + "骑着"+riding+"一路疾驰而来。\n";
					}
					else
					{
						mout = me->name() + "往" + dir + "离开。\n";
						min = face + me->name() + thing_msg + "走了过来。\n";
					}
			}
			else
			{
				mout = me->name()+replace_string( me->query("comeout_message"), "$d", dir );
				min = me->name()+me->query("comein_message");
			}
		}
	}
/* 无效守护 */
	if( strlen(env->query("guarded/"+arg)) < 3 )
		env->delete("guarded/"+arg);
	if( env->query("guarded/"+arg) )
		blocker = present(env->query("guarded/"+arg), env);
/* 人不在自动失去守护 */
	if(!blocker) env->delete("guarded/"+arg);
	if( env->query("guarded/"+arg) &&
		me->query("race") == "人类" && blocker != me)
	{
		if(interactive(blocker) && living(blocker))
		{ /* 活人在守护 */
			if( !stringp(riding)) /*不在坐骑上*/
			{
				if(me->query_dex()<blocker->query_dex()+5+random(5))
				{
					message_vision("$N试图朝"+dir+"走去，但是被$n挡住了出路。\n", me, blocker);
					return 1;
				}
				mout = me->name()+"施展轻功，从" + blocker->name() +"身旁一晃而过，连衣角也没挨着。\n";
			}
			else /* 在坐骑上 */
			{
				if( me->query("combat_exp") >=
					blocker->query("combat_exp"))
				{
/*
					if(blocker->query_temp("is_riding"))
					{
						message_vision(HIR"$N骑着"+rided_name+"冲过来，一头把$n从坐骑上撞下来，摔个四脚朝天。\n"NOR, me, blocker);
						blocker->query("rided")->delete("rider");
						blocker->delete("rided");
					}
					else message_vision(HIR"$N骑着"+rided_name+"冲过来，把$n撞个四脚朝天。\n"NOR, me, blocker);
*/
					message_vision(HIR"$N骑着"+riding+HIR"冲过来，把$n撞个四脚朝天。\n"NOR, me, blocker);
					blocker->receive_wound("qi",50);
					blocker->start_busy(2);
					blocker->delete_temp("guardto");
					env->delete("guarded/"+arg);
				} 
				if( me->query("combat_exp") <
					blocker->query("combat_exp")/2)
				{
					message_vision(HIG"$N一把抓住"+riding+HIG"的缰绳，把$n连人带坐骑一齐停了下来。\n"NOR,blocker,me);
					me->start_busy(2);
					blocker->start_busy(1);
					return 1;
				}
				else
					if( me->query("combat_exp") <
						blocker->query("combat_exp"))
						message_vision(RED"$N见$n骑着"+riding+RED"冲过来，赶紧闪到一旁让$n通过。\n"NOR, blocker, me);
			}
		}
		else mout = me->name()+"踩着"+blocker->name()+"向"+dir+"走了出去。\n";
	}

	if(me->query_temp("guardto"))
	{
		env->delete("guarded/"+me->query_temp("guardto"));
		me->delete_temp("guardto");
		mout = me->name()+"放弃守护，朝"+dir+"离去。\n";
	}
	if (me->query_condition("baitan"))
	{
		"/cmds/std/baitan"->halt_baitan(me);
		me->clear_condition("baitan");
	}
	message( "vision", mout, environment(me), ({me}) );
	if( me->move(obj) )
	{
		me->remove_all_enemy();
		if (me->query_temp("pretend") && stringp(me->query_temp("apply/come_msg")))
		min = me->query_temp("apply/come_msg");
		message( "vision", min, environment(me), ({me}) );
		me->set_temp("pending", 0);
		if (me->query_temp("no_follow"))
		  me->delete_temp("no_follow");
		else 
		  all_inventory(env)->follow_me(me, arg);
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if( !environment(me) || !living(me) || me->query_temp("noliving"))
		return;
	exits = environment(me)->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	tell_object(me, "看来该找机会逃跑了...\n");
	main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
	write(@HELP
指令格式 : go <方向>
 
    这个指令让你往指定的方向移动。可以直接键入方向，可能存在的方向有
东：ｅａｓｔ（ｅ）、西：ｗｅｓｔ（ｗ）、南：ｓｏｕｔｈ（ｓ）、北：
ｎｏｒｔｈ（ｎ）、进入：ｅｎｔｅｒ、出去：ｏｕｔ等。用进入指令还可以
钻洞，钻草堆等等。

 
HELP
	);
	return 1;
}


