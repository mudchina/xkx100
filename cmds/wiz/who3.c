// who3.c

inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string str)
{
    object ob, *ob_list;
     int i,t,size,num,max;
    seteuid(getuid());

    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());
    size = (int)sizeof(ob_list)/20;
    str = HIG"\n 玩家     悟性   根骨   身法   膂力   耐力   灵性   容貌   福缘 定力 胆识\n"NOR;
    str +=     "---------------------------------------------------------------------";
    message("vision", str, me);
    for(t=0; t<=size; t++)
    {
	num = t*20;
    	max = num + 20;
    	if( max > sizeof(ob_list)) max = (int)sizeof(ob_list);
    	ob = ob_list[num];
    	if( num == 0) str = sprintf(NOR"\n%-10s",ob->name());
    	else str = sprintf(NOR"%-10s",ob->name());
        str += sprintf(HIR"%-2d/",ob->query("int"));
        str += sprintf(HIR"%-3d ",ob->query_int());
        str += sprintf(HIG"%-2d/",ob->query("con"));
        str += sprintf(HIG"%-3d ",ob->query_con());
        str += sprintf(HIY"%-2d/",ob->query("dex"));
        str += sprintf(HIY"%-3d ",ob->query_dex());
        str += sprintf(HIB"%-2d/",ob->query("str"));
        str += sprintf(HIB"%-3d ",ob->query_str());
        str += sprintf(HIW"%-2d/",ob->query("sta"));
        str += sprintf(HIW"%-3d ",ob->query_sta());
        str += sprintf(CYN"%-2d/",ob->query("spi"));
        str += sprintf(CYN"%-3d ",ob->query_spi());
        str += sprintf(HIM"%-2d/",ob->query("per"));
        str += sprintf(HIM"%-3d ",ob->query_per());
        str += sprintf(YEL"%-2d   ",ob->query_kar());
        str += sprintf(HIC"%-2d   ",ob->query_cps());
        str += sprintf(GRN"%-2d "NOR,ob->query_cor());

	for(i=num+1; i<max; i++)
    	{
        ob = ob_list[i];
        str += sprintf(NOR"\n%-10s",ob->name());
        str += sprintf(HIR"%-2d/",ob->query("int"));
        str += sprintf(HIR"%-3d ",ob->query_int());
        str += sprintf(HIG"%-2d/",ob->query("con"));
        str += sprintf(HIG"%-3d ",ob->query_con());
        str += sprintf(HIY"%-2d/",ob->query("dex"));
        str += sprintf(HIY"%-3d ",ob->query_dex());
        str += sprintf(HIB"%-2d/",ob->query("str"));
        str += sprintf(HIB"%-3d ",ob->query_str());
        str += sprintf(HIW"%-2d/",ob->query("sta"));
        str += sprintf(HIW"%-3d ",ob->query_sta());
        str += sprintf(CYN"%-2d/",ob->query("spi"));
        str += sprintf(CYN"%-3d ",ob->query_spi());
        str += sprintf(HIM"%-2d/",ob->query("per"));
        str += sprintf(HIM"%-3d ",ob->query_per());
        str += sprintf(YEL"%-2d   ",ob->query_kar());
        str += sprintf(HIC"%-2d   ",ob->query_cps());
        str += sprintf(GRN"%-2d "NOR,ob->query_cor());
	}
	me->start_more(str);
    }
    str = "------------------------------------------------------------------------------\n";
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
指令格式：who3

玩家信息查询。
HELP
        );
        return 1;
}            

