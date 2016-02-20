// title.c (Mon 09-04-95)
// 增加巫师察看在线或不在线玩家阶级和头衔的功能。
// Modified by Spacenet@FXLT 1.16.2000
inherit F_CLEAN_UP;
 
#include <ansi.h>

 
int main(object me, string name)
{
	object ob;
	
	seteuid(getuid());
	
	if (!wizardp(me) || !name)
	{
		printf(BOLD"%s"NOR"%s\n\n",RANK_D->query_rank(me),me->short(1));
    		return 1;
  }
    	
    	if (ob = LOGIN_D->find_body(name)) {
    		printf(BOLD"%s"NOR"%s\n\n",RANK_D->query_rank(ob),ob->short(1));
    		return 1;
    	}
	    ob = new(USER_OB);
    	seteuid(name);
    	export_uid(ob);
    	
    	if (!ob->restore())
    	{
    		destruct(ob);
    		return notify_fail("没有这个玩家。\n");
    	}
    	printf(BOLD "%s" NOR "%s\n", RANK_D->query_rank(ob), ob->short(1));
	printf("%s \n\n", "该玩家目前不在线。");	
	destruct(ob);
	return 1;
    	
}
 
int help(object me)
{
    write(@HELP
指令格式: title [玩家名]
 
    玩家用 title 可以显示目前自己的阶级和头衔。
    巫师用 title + 玩家名 可以显示该玩家的阶级和头衔。
 
HELP
    );
}
 

