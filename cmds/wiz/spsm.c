// smash.c 2-22-95
inherit F_CLEAN_UP;
 
#include "/doc/help.h"


 
int main(object me, string arg)
{
	object ob;
	string name1, name2;

	if (!arg) return notify_fail("指令格式: smash <living>\n");
	ob = present(arg, environment(me));
	if (!ob) return notify_fail("找不到这个生物.\n");
	name1 = (string)me->query("name");
	name2 = (string)ob->query("name");
	ob -> die();
	return 1;
}
 
int help(object me)
{
   write(@HELP
指令格式: smash <生物>
 
hehehehehe...........

HELP
   );
   return 1;
}
