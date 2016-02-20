// id.c
// Modified by Spacenet@FXLT

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i, j;
	object obj, *inv, *inv1;
	string *id;
	string str;

	if( !arg ) {
		inv = all_inventory(me);
		if( !sizeof(inv) )
			return notify_fail("你身上没有任何东西。\n");
		for (i = 0;i < sizeof(inv);i ++)
			if (!arrayp(inv1)) 
				inv1 = ({inv[i]});
			else {
				for (j = 0;j < sizeof(inv1);j ++)
					if (inv[i]->short(1) == inv1[j]->short(1))
						break;
				if (j == sizeof(inv1))
					inv1 += ({inv[i]});
			}
			
		write( "你(你)身上携带物品的别称如下(右方) :\n");
		for(i = 0; i < sizeof(inv1); i ++) {
			if( !me->visible(inv1[i]) ) continue;
			printf("%-20s = %s\n", inv1[i]->name(),
				implode(inv1[i]->parse_command_id_list(), ", ") );
		}
		return 1;
	}

	if( arg=="here" ) {
		inv = all_inventory(environment(me));
		if( !sizeof(inv) )
			return notify_fail("这里没有任何东西。\n");
		write( "在这个房间中, 生物及物品的(英文)名称如下 :\n");
		for(i=0; i<sizeof(inv); i++) {
			if( !me->visible(inv[i]) ) continue;
			str = implode(inv[i]->parse_command_id_list(), ", ");
			if (inv[i]->query_temp("pretend") && 
				arrayp(inv[i]->query_temp("apply/pid")))
			str = implode(inv[i]->query_temp("apply/pid"), ", ");
			printf("%-20s = %s\n", inv[i]->name(),str );
		}
		return 1;
	}
}
int help(object me)
{
write(@HELP
指令格式 : id [here]
 
    这个指令可以让你知道物品的英文名称及名字。只打 id 会显示
你身上所携带物品的名称。'id here' 则显示所有跟你在同一个环境
里的物件名称。
 
HELP
	);
	return 1;
}
 

