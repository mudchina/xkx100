//inventory.c
// Modified by Spacenet@FXLT
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)
{
	int i, j, *count=({});
	object *inv, *inv1=({}), ob;
	string str;
	string *invname=({});

  if (wizardp(me) && arg)
  {
  	ob = present(arg, environment(me));
  	if (!ob) ob = find_player(arg);
  	if (!ob) ob = find_living(arg);
  }
  else if ( !wizardp(me) && arg )
  {
  	ob = present(arg, environment(me));
	  if ( ob && !ob->is_baby() )
  	   ob = me;
    else 
    if ( ob && ob->is_baby() && member_array(me->query("id"),ob->query("parents")) < 0 ) 
        return notify_fail("只有爹娘能察看宝宝身上的东西。");
  }
  if (!ob) ob = me;
	inv = all_inventory(ob);
	if( !sizeof(inv) )
	{
		write((ob==me)? "目前你身上没有任何东西。\n"
			: ob->name() + "身上没有携带任何东西。\n");
		return 1;
	}
	for (i = 0;i < sizeof(inv);i ++)
    {
      if (me->visible(inv[i]))
      {
       	j=member_array( inv[i]->short()+"/"+inv[i]->query("id")+"/"+inv[i]->query("equipped"),invname );
		  	if (j == -1  )
		  	{
		  		inv1 += ({inv[i]});
		  		invname += ({ inv[i]->short() + "/" + inv[i]->query("id")+"/"+inv[i]->query("equipped") });
		  		count += ({1});
		  	} else 	
		  		count[j] += 1;
		  }
		}
 
	printf("%s身上带着下列这些东西(负重 %d%%)：\n", (ob==me)? "你": ob->name(), (int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance());
	for (i = 0;i < sizeof(inv1);i ++)
	{
		printf("%s%s%s%s \n",inv1[i]->query("equipped") ? ((inv1[i] == me->query_temp("secondary_weapon")) ? HIC "○" NOR: HIC "□" NOR): "  ",
			(inv1[i]->query("base_unit") || inv1[i]->query("equipped"))?"":chinese_number(count[i]), 
			(inv1[i]->query("base_unit") || inv1[i]->query("equipped"))?"":inv1[i]->query("unit"),
			inv1[i]->short());
	}		
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: inventory
 
    可列出你目前身上所携带的所有物品。
    □表示右手兵器，○表示左手兵器。

注 : 此指令可以 " i " 代替。
 
HELP
);
	return 1;
}

