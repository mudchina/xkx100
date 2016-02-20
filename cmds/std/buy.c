inherit F_CLEAN_UP;

#include <ansi.h>


object i_have(object env,string name); // env中取包含 name的物品
string filter_color(string arg);

int main(object me, string arg)
{
        mapping goods;
        int amount;
        int value, val_factor;
        string ob_file;
	object *obs;
        object ob, env, obj;
	string my_id;
	int i;
	
        
        if(me->is_busy())
                return notify_fail("什么事都得等你忙完再说吧！\n");
        if (! arg)
                return notify_fail("指令格式：buy <物品> [from <玩家>]\n");
				env = environment(me);
				if (! (sscanf(arg, "%s from %s", arg, my_id) == 2) )
				{	        
  	      obs = all_inventory(env);
    	    for (i=0;i<sizeof(obs);i++)
     	   	{
     	   		if (!userp(obs[i]) && obs[i]->is_dealer())
     	   			return 0;
      	 	}
            return notify_fail("指令格式：buy <物品> [from <玩家>]\n");
         }

        if (! (obj = find_player(my_id)) || ! (present(obj->query("id"), env)))
                return notify_fail("这里没有这个商人。\n");

        if (obj == me)
                return notify_fail("问自己买东西？吃饱了撑的？\n");

        if (! obj->query("is_vendor"))
                return notify_fail(obj->name(1) + "并不是商人。\n");

        if (! obj->query_temp("on_baitan"))
                return notify_fail(obj->name(1) + "并没有摆摊。\n");

				SHOP_D->reset_goods(obj);
				
        if (! (goods = obj->query("vendor_goods")))
                return notify_fail(obj->name(1) + "并没有兜售任何货物。\n");

        ob = i_have(obj, arg);

				if (! ob || ! objectp(ob))
                return notify_fail(obj->name(1) + "并没有兜售这样货物。\n");

        if (! goods[file_name(ob)])
                return notify_fail(obj->name(1) + "并没有兜售这样货物。\n");

        value = goods[file_name(ob)];

        if (ob->query_amount()) 
        	return notify_fail("这样东西不值钱，买了也没用。\n");

        switch (MONEY_D->player_pay(me,value))
        {
        case 0:
                write(CYN + obj->name(1) + CYN "冷笑一声，骂道：穷"
                      "光蛋，一边呆着去。\n" NOR);
                return 1;
        case 2:
                write(CYN + obj->name(1) + CYN "皱眉道：您还有没有"
                      "零钱啊？银票我可找不开。\n" NOR);
                return 1;
        default:
                if (ob->query_amount())
                {
                        message_vision("$N从$n那里买下了" + ob->short() + "。\n",
                                        me, obj);
                } else
                {
                        message_vision("$N从$n那里买下了一" + ob->query("unit") + 
                	               ob->query("name") + "。\n",
			               me, obj);
                }
                ob->move(me, 1);
                obj->add("balance", value * 19 / 20); // 直接加入存款
                if (query_ip_number(obj) != query_ip_number(me))
               	 	obj->add("vendor_score", value / 2500);
        }
        me->start_busy(2);
        return 1;
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

int help (object me)
{
        write(@HELP
指令格式: buy <物品> [from <玩家>]

向一个商人购买商品。

相关指令：list

HELP);
	return 1;
}
