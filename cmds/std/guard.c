// guard.c
// Modified by Spacenet@FLXT 11.30.1999
inherit F_CLEAN_UP;

#include <ansi.h>


mapping default_dirs = ([
	"north":        "北",
	"south":        "南",
	"east":	        "东",
	"west":	        "西",
	"northup":      "北边",
	"southup":      "南边",
	"eastup":       "东边",
	"westup":       "西边",
	"northdown":    "北边",
	"southdown":    "南边",
	"eastdown":	"东边",
	"westdown":	"西边",
	"northeast":    "东北",
	"northwest":    "西北",
	"southeast":    "东南",
	"southwest":    "西南",
	"up":           "上",
	"down":	        "下",
	"out":	        "外",
	"in" :          "里",
	"enter" :       "里面",
]);

int main(object me, string arg)
{
	string dir;
	object ob, *guards, env;
	mixed old_obj, old_dir; 

	if( me->is_busy() )
		return notify_fail("你现在没有办法分心去做这类事！\n");
	if( me->query("jing") < 200 || me->query("qi") < 200 )
		return notify_fail("你现在没有足够的精、气去做这类事！\n");
	old_dir = me->query_temp("guardto");  
	old_obj = me->query_temp("guardfor");  
	env = environment(me);
	if(env->query("no_guard") || env->query("no_fight"))
		return notify_fail("你无法在这里守护什么！\n");

	if( !arg || arg=="" )
	{
		if( !old_obj && !old_dir)
			return notify_fail("指令格式：guard <生物> | <物品> | <方向>\n");
		if( objectp(old_obj) )
			if(living(old_obj) && !old_obj->query_temp("noliving"))
				write("你正在守护着"+old_obj->name()+"。\n");
			else
				write("你正守在"+old_obj->name()+"一旁，防止别人拿走。\n");
		else write( "你正把守住往 "+default_dirs[old_dir]+" 的方向，不准任何人离开。\n");
		return 1;
	}

	ob = present(arg, env);
	if( ob )
	{
		if( ob==me )
			return notify_fail("守卫自己？不用说你也会，对吧。\n");
		me->delete_temp("guardto", ob);
		me->set_temp("guardfor", ob);
	}
	else
		if( env->query("exits/" + arg) )
		{
			if( env->query("no_fight") )
				return notify_fail("这里不准战斗，也不准堵住别人去路！\n");
		}
		else
			if( arg == "cancel" )
			{
				if (!old_obj)
					return notify_fail("你本来就没有守护什么东西啊。\n");
				write("什么也不用守护了，真是好轻松。\n");
				me->delete_temp("guardfor");
				guards = old_obj->query_temp("guarded");
				guards -= ({ me });
				old_obj->set_temp("guarded", guards);
				return 1;
			}
			else
				return notify_fail("你要守护谁，什么，或是把守哪个方向？\n");

	if( objectp(old_obj) )
	{
		guards = old_obj->query_temp("guarded");
		guards -= ({ me });
		old_obj->set_temp("guarded", guards);
		if( living(old_obj) && !old_obj->query_temp("noliving") )
		{
			if (old_obj != ob)  
				message_vision("$N不再保护$n了。\n",me,old_obj);
		}
	}
	else
	{
		env->delete("guarded/"+old_dir);
		me->delete_temp("guardto");
		if (old_dir && arg != old_dir)
			message_vision( "$N不再把守"+default_dirs[old_dir]+"这个方向了。\n",me);
		me->enable_path();
	}

	if( objectp(ob) )
	{
		ob->add_temp("guarded", ({ me }) );
		if( living(ob) && !ob->query_temp("noliving") )
		{
			if (ob == old_obj)  
				message_vision("$N正在保护$n。\n", me, ob);
			else message_vision("$N开始保护$n。\n", me, ob);
		}
		else
		{
			if (ob == old_obj)  
				message_vision("$N站到地上的$n一旁守着，以免别人取走。\n", me, ob);
			else message_vision("$N正在守着地上的$n。\n", me, ob);
		}
	}
	else
	{
		if( env->query("guarded/"+arg))
		{
			dir = env->query("guarded/"+arg);
			if( ob = present(dir, env) )
				return notify_fail(HIR+ob->query("name")+"已经挡住了往"+default_dirs[arg]+"去的出路！\n"NOR);
		}
		me->start_busy(1);
		me->set_temp("guardto", arg);
		me->delete_temp("guardfor");
		env->set("guarded/" + arg, me->query("id") );
		if (arg == old_dir)  
			message_vision( "$N正在把守着往" + default_dirs[arg] + "的方向不让任何人通行。\n", me);
		else
		{
			message_vision( "$N开始把守住往" + default_dirs[arg] + "的方向不让任何人通行。\n", me);
		}
	}

	return 1;
}

// guarding需耗精气，因太累将自动结束guard。
// 程序设置在/kungfu/condition/autosaved.c。
int help(object me)
{
	write(@TEXT
指令格式：guard [<某人>|<地上某物>|<某个出口>|cancel]

这个指令有三种作用方式，分别如后：

guard <某人>      保护<某人>，当他／她受到攻击时，保护者会自动加入战斗，并且
                  受攻击的顺位会排在被保护者前面，由于只有攻击顺位前四个目标
                  才会受到攻击，因此理论上如果有四个人  guard 你，你就不会受
                  到任何攻击。

guard <地上某物>  守住放在地上的某件东西，防止别人来拿，只要你还在这个房间，
                  而且没有忙着其他事，别人就无法拿走这件东西。若你离开后再回
                  来，只要东西还在，那仍将在你守护之下。

guard cancel      取消上述的 guard 对象。

guard <某个出口>  守住某个出口防止所有人从这个出口离开，可以用来阻拦善于逃跑
                  的敌人或拦路打劫做坏事。只要你一移动，guard 的状态就会解除。

guard             不接任何参数会显示你目前 guard 的对象。
TEXT
	);
	return 1;
}

