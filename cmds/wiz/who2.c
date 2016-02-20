// who2.c

inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string str)
{
    object where, ob, *ob_list;
     int i,t,size,num,max;
    string stri;
    seteuid(getuid());

    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());
	size = (int)sizeof(ob_list)/20;
    str = HIG" 玩家    年龄 存款           地址               所在       程序       \n"NOR;
    str +=    "---------------------------------------------------------------------\n";
	message("vision", str, me);
    for(t=0; t<=size; t++)
    {
        num = t*20;
    	max = num + 20;
    	if( max > sizeof(ob_list)) max = (int)sizeof(ob_list);
    	ob = ob_list[num];
        where = environment(ob);
        str = sprintf(WHT"%-8s:  ",ob->name());
        str += sprintf(HIR"%-2d ", ob->query("age"));
        str += sprintf(HIG"%-10d ", ob->query("balance"));
        str += sprintf(HIY"%-20s ", query_ip_name(ob));
        if (where) str += sprintf(HIM"%-10s ", where->query("short"));
        if (!where) str += sprintf(""NOR);
        else str += sprintf(HIC"%s"NOR, file_name(where));
	   for(i=num+1; i<max; i++)
    	{
        ob = ob_list[i];
        where = environment(ob);
		str += sprintf(WHT"\n%-8s:  ",ob->name());
        str += sprintf(HIR"%-2d ", ob->query("age"));
        str += sprintf(HIG"%-10d ", ob->query("balance"));
        str += sprintf(HIY"%-20s ", query_ip_name(ob));
        if (where) str += sprintf(HIM"%-10s ", where->query("short"));
        if (!where) str += sprintf(""NOR);
       else str += sprintf(HIC"%s"NOR, file_name(where));
		}
	 me->start_more(str);
    }
    str =     "---------------------------------------------------------------------\n";
    str += sprintf("共有 %d 位使用者连线中。\n", sizeof(ob_list));
    message("vision", str, me);
    return 1;
}
int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	if( wizardp(ob2) && !wizardp(ob1) ) return 1;
	if( wizardp(ob1) && wizardp(ob2) )
		return (int)SECURITY_D->get_wiz_level(ob2) 
			- (int)SECURITY_D->get_wiz_level(ob1);
	
	return (int)ob2->query("mud_age") - (int)ob1->query("mud_age");
}
int help(object me)
{
        write(@HELP
指令格式：who2

玩家信息查询。
HELP
        );
        return 1;
}
