// /cmds/std/give.c

// Modified by Constant Jan 5 2001
// Modified by Zeratul Jan 12 2001
inherit F_CLEAN_UP;

#include <ansi.h>

int do_give(object me, object obj, object who);
object i_have(object env,string name); // env中取包含 name的物品
string filter_color(string arg);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("你要给谁什么东西？\n");
	if( me->is_busy() ) return notify_fail("你上一个动作还没有完成！\n");
	if( sscanf(arg, "%s to %s", item, target)==2 ||
		sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("你要给谁什么东西？\n");
//	if(!objectp(who = present(target, environment(me))) ||
	if(!objectp(who = i_have( environment(me),target )) ||
		!living(who) || who->query_temp("noliving") )
		return notify_fail("这里没有这个活人。\n");
	if( who->query("env/no_accept") )
		return notify_fail("人家现在不想要什么东西。\n");
	if(sscanf(item, "%d %s", amount, item)==2)
	{
	//	if( !objectp(obj = present(item, me)) )	
		if( !objectp(obj = i_have( me,item )) ) // me have item	
			return notify_fail("你身上没有这样东西。\n");
		if( obj->query("no_drop") )
			return notify_fail("这样东西不能随便给人。\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "不能被分开给人。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("你没有那么多的"+obj->name()+"。\n");
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else
		{
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if (do_give(me, obj2, who)) return 1;
			else
			{
				obj->set_amount((int)obj->query_amount() + amount);
				return 0;
			}
		}
	}
	if(arg=="all")
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			do_give(me, inv[i], who);
		}
		write("给好了。\n");
		return 1;
	}
//	if(!objectp(obj = present(item, me)))
	if(!objectp(obj = i_have( me,item)))
		return notify_fail("你身上没有这样东西。\n");
	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{

	if( obj->query("no_drop") )
		return notify_fail("这样东西不能随便给人。\n");
	if( obj->query_temp("is_rided_by") )
		return notify_fail("把坐骑给别人，你不就掉地上了？\n");
	if( userp(obj) )
		return notify_fail("你只能卖玩家。\n");
	// 增加对任务物品奖励的判断。
	// Added by Constant Jan 5 2001
	if (obj->query("owner") != me->query("id") && (obj->query("taskobj")))
		return notify_fail("任务必须自己完成。\n");
	if (obj->query("dynamic_quest") && TASK_D->quest_reward(me, who, obj))
		return 1;
	if ((strsrch(obj->query("name"), me->query("quest/betrayer/name")) >= 0)
		&& who->accept_quest_betrayer(me, obj))
		return 1;
	if ((strsrch(obj->query("name"), me->query("quest/book/book")) >= 0)
		&& who->accept_quest_book(me, obj))
		return 1;
	if ((strsrch(obj->query("name"), me->query("quest/thief/name")) >= 0)
		&& who->accept_quest_thief(me, obj))
		return 1;
	if ((strsrch(obj->query("name"), me->query("quest/kill/name")) >= 0)
		&& who->accept_quest_kill(me, obj))
		return 1;
	if( !interactive(who) && !who->accept_object(me, obj) )
		return notify_fail("对方不想接受这样东西。\n");
	if (!objectp(obj)) return 1;
	if (obj->query("id") == "bao wu")
	{
		destruct(obj);
		return 1;
	}
// 入帮会的投名状
	if( obj->query("id") == "head")
		who->set_temp("party/toumingzhuang", me->query("id"));
	if( !userp(who) && obj->value() )
	{
		message_vision("$N拿出" + obj->short() + "给$n。\n", me, who);
		destruct(obj);
        	me->save();
	        if (userp(who)) who->save();
		return 1;
	}
	else if( obj->move(who) )
		{
			printf("你给%s一%s%s。\n", who->name(), obj->query("unit"), obj->name());
			message("vision", sprintf("%s给你一%s%s。\n", me->name(), obj->query("unit"), obj->name()), who );
			message("vision", sprintf("%s给%s一%s%s。\n", me->name(), who->name(),
			obj->query("unit"), obj->name()), environment(me), ({me, who}) );
			me->save();
			if (userp(who)) who->save();
			return 1;
		}
		else return 0;
}
object i_have(object env,string name)
{
	int i;
	object *inv;
	object obj;
	if (objectp(obj = present(name,env))) return obj;
	inv=all_inventory(env);
	for(i=0;i<sizeof(inv);i++)
	{
		if (filter_color(inv[i]->query("name"))==name)
		return inv[i];
	}
	return 0;
}
string filter_color(string arg)
{
  if(!arg) return "";
  arg = replace_string(arg, BLK, "");
  arg = replace_string(arg, RED, "");
  arg = replace_string(arg, GRN, "");
  arg = replace_string(arg, YEL, "");
  arg = replace_string(arg, BLU, "");
  arg = replace_string(arg, MAG, "");
  arg = replace_string(arg, CYN, "");
  arg = replace_string(arg, WHT, "");
  arg = replace_string(arg, HIR, "");
  arg = replace_string(arg, HIG, "");
  arg = replace_string(arg, HIY, "");
  arg = replace_string(arg, HIB, "");
  arg = replace_string(arg, HIM, "");
  arg = replace_string(arg, HIC, "");
  arg = replace_string(arg, HIW, "");
  arg = replace_string(arg, NOR, "");
/*  arg = replace_string(arg, BBLK, "");
  arg = replace_string(arg, BRED, "");
  arg = replace_string(arg, BGRN, "");
  arg = replace_string(arg, BYEL, "");
  arg = replace_string(arg, BBLU, "");
  arg = replace_string(arg, BMAG, "");
  arg = replace_string(arg, BCYN, "");
  arg = replace_string(arg, HBRED, "");
  arg = replace_string(arg, HBGRN, "");
  arg = replace_string(arg, HBYEL, "");
  arg = replace_string(arg, HBBLU, "");
  arg = replace_string(arg, HBMAG, "");
  arg = replace_string(arg, HBCYN, "");
  arg = replace_string(arg, HBWHT, "");
  arg = replace_string(arg, NOR, "");
*/
  return arg;
}
int help(object me)
{
write(@HELP

指令格式 : give <物品名称> to <某人>
      或 : give <某人> <物品名称>
 
    这个指令可以让你将某样物品给别人，当然，首先你要拥有这样物品。
 
HELP
    );
    return 1;
}
