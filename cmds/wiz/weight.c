// weight.c
// created by doing
inherit F_CLEAN_UP;

#include <ansi.h>



int help(object me);

int main(object me, string arg)
{
        object env;
        int origin;
	      string msg;
        string to;

        if (!arg)
        {
         	 write("你现在体重是"+me->query_weight()+"负重"+me->query_encumbrance()+"。\n");
           return 1;
        }
        else if (arg=="-1")
        {
         	me->set_weight(40000+(me->query("str") - 10)*2000);
          write("你的体重恢复到原来的"+me->query_weight()+"。\n");
          return 1;
        }
        else if (sscanf(arg,"%d",origin)==1)
        {
        	if ( origin < 200)
        	 origin=200;
         	me->set_weight(origin);
          write("你把体重调整为"+me->query_weight()+"。\n");
          return 1;
        }
        else
          help(me);
       	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : wieght [数值| -1]
 
这个指令会使你的重量变化。如果参数是-1就恢复原来的体重。
 
HELP );
    return 1;
}
