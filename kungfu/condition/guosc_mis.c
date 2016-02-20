// guosc_mis.c
// 郭靖守城任务

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	object room;
	object* ob_list;
	int i,stat;
		
	room = environment(me);

	me->apply_condition("guosc_mis", duration - 1 );
	if (me->query_temp("guosc_mis_flag"))
	{
		if (me->query_temp("guosc_mis_where")!=environment(me)->query("short"))
		{
			message_vision( HIY"一个宋兵跑过来对$N说道：叫你守城，你却到处闲逛，我去报告郭大侠！\n"NOR,me);
		}
		else me->set_temp("guosc_mis_flag",2);
		if (me->query_temp("guosc_mis_flag")==2 && me->query_temp("guosc_mis_where")==environment(me)->query("short"))
		{
			switch( random(8) )
			{
				case 0:
					message_vision( HIY"$N正站在城墙上密切注视着城下"HIR"蒙古兵"HIY"的一举一动。\n"NOR,me);
					break;
				case 1:
					message_vision(HIY"$N指挥一队宋兵吆喝着将无数巨石从城墙上推下来，城下的"HIR"蒙古兵"HIY"一时不备，死伤不少。\n"NOR,me);
					break;
				case 2:
					message_vision(HIC"但听一声梆子响，从箭垛后面钻出无数士兵，箭如飞蝗，城外的"HIR"蒙古兵"HIC"纷纷中箭倒下。\n"NOR,me);
					break;
				case 3:
					message_vision(HIR"$N大叫：放火、放火。城上扔下无数燃着的火把，惨叫声中，蒙古的士兵死伤甚众。\n"NOR,me);
					break;
				case 4:
					message_vision(HIC"城外一声号角传来，蒙古靼子发动了新一轮的攻势，城中箭如雨下，守城的宋兵死伤不少。\n"NOR,me);
					me->receive_wound("jing", 50+random(50));
					me->receive_damage("qi", 300+random(100));
					break;
				case 5:
					message_vision(HIR"$N大叫一声：大家小心。城外蒙古兵的投石车飞来无数巨石，惨叫声中，城中的守兵死伤甚众。\n"NOR,me);
					me->receive_wound("jing", 50+random(50));
					me->receive_damage("qi", 300+random(100));
					break;
				case 6:
					message_vision(HIR"城中宋兵大叫：着火啦、着火啦。城中的蒙古奸细趁守军不备四处放火，一片救火声中，城中的军备损失惨重！\n"NOR,me);
					me->receive_wound("jing", 50+random(50));
					me->receive_damage("qi", 300+random(100));
					break;
				case 7:
					message_vision(HIR"$N大叫：小心暗器！蒙古奸细趁守军不备射出不少暗器，城中的军士一时大意，不少人中了偷袭！\n"NOR,me);
					me->apply_condition("anqi_poison", 3+random(3));
					break;
				case 8:
					message_vision(HIY"城外蒙古兵发动一轮急攻，但守城的宋兵在$N的带领下却早有防备，没有受到损失。\n"NOR, me);
					break;
			}
		}
	}
	if(duration <1)
	{
		message_vision( CYN"\n一个守城宋兵跑过来说道：蒙古靼子暂时被击退了，$N可以回去复命了！\n"NOR,me);
		if (me->query_temp("guosc_mis_flag"))
		{
			me->set_temp("guosc_mis_flag",3);
		}
		ob_list = children("/d/xiangyang/task/robber1");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
			message_vision("$N叹道：襄阳守军竟有高人协助，撤呼！\n",ob_list[i]);	
			destruct(ob_list[i]);
                }
		ob_list = children("/d/xiangyang/task/robber2");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                        message_vision("$N叹道：襄阳守军竟有高人协助，撤呼！\n",ob_list[i]);    
                        destruct(ob_list[i]);
                }
		ob_list = children("/d/xiangyang/task/robber3");
                for(i=0; i<sizeof(ob_list); i++)
                if(environment(ob_list[i]))
                {
                        message_vision("$N叹道：襄阳守军竟有高人协助，撤呼！\n",ob_list[i]);
                        destruct(ob_list[i]);
                }

		return 0;
	}
	return 1;
}

string query_type(object me)
{
	return "job";
}

