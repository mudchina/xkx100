// who1.c

inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string str)
{
    object ob, *ob_list;
    int i,t,size,num,max;
    string stri;
    seteuid(getuid());

    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());
    size = (int)sizeof(ob_list)/20;
    str = HIG"   线上玩家           精        气       神      内力      体力    经验值 潜能\n"NOR;
    str +=   "------------------------------------------------------------------------------\n";
    message("vision", str, me);
    for(t=0; t<=size; t++)
    {
    	num = t*20;
    	max = num + 20;
    	if( max > sizeof(ob_list)) max = (int)sizeof(ob_list);
    	ob = ob_list[num];

        str = sprintf(WHT"%-16s:  ",ob->name()+"("+ob->query("id")+")");
        str += sprintf(RED"%-4d/%-4d ", ob->query("jing"), ob->query("max_jing"));
        str += sprintf(YEL"%-4d/%-4d ", ob->query("qi"), ob->query("max_qi"));
        str += sprintf(GRN"%-7d ", ob->query("shen"));
        str += sprintf(BLU"%-4d/%-4d ", ob->query("neili"), ob->query("max_neili"));
        str += sprintf(BLK"%-4d/%-4d ", ob->query("tili"), ob->query("max_tili"));
        str += sprintf(MAG"%-7d ", ob->query("combat_exp"));
        str += sprintf(CYN"%-3d "NOR, ob->query("potential")-ob->query("learned_points"));
    	for(i=num+1; i<max; i++)
    	{
        ob = ob_list[i];

        str += sprintf(WHT"\n%-16s:  ",ob->name()+"("+ob->query("id")+")");
        str += sprintf(RED"%-4d/%-4d ", ob->query("jing"), ob->query("max_jing"));
        str += sprintf(YEL"%-4d/%-4d ", ob->query("qi"), ob->query("max_qi"));
        str += sprintf(GRN"%-7d ", ob->query("shen"));
        str += sprintf(BLU"%-4d/%-4d ", ob->query("neili"), ob->query("max_neili"));
        str += sprintf(BLK"%-4d/%-4d ", ob->query("tili"), ob->query("max_tili"));
        str += sprintf(MAG"%-7d ", ob->query("combat_exp"));
        str += sprintf(CYN"%-3d "NOR, ob->query("potential")-ob->query("learned_points"));
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
	
	return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}
int help(object me)
{
        write(@HELP
指令格式：who1

玩家信息查询。
HELP
        );
        return 1;
}
