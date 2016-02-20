// spy.c
// by ReyGod  in  12/16/1996  in BUPT
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{	
	object ob;
	mapping mine;
	string line;
	int basic_data;

//	me = this_player();

	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看谁的状态？\n");
	} else
		return notify_fail("只有巫师能察看别人的状态。\n");
	
	mine = ob->query_entire_dbase();
	line = sprintf("\n-------先天资质-------\n");
	line += sprintf(
			" 膂力：[%s]  悟性：[%s]  根骨：[%s]  身法：[%s]\n\n", 
			sprintf("%3d",mine["str"]),
			sprintf("%3d",mine["int"]),
			sprintf("%3d",mine["con"]),
			sprintf("%3d",mine["dex"]));
	line += sprintf("-------后天资质-------\n");
	line += sprintf(
			" 膂力：[%s]  悟性：[%s]  根骨：[%s]  身法：[%s]\n\n", 
			sprintf("%3d",ob->query_str()),
			sprintf("%3d",ob->query_int()),
			sprintf("%3d",ob->query_con()),
			sprintf("%3d",ob->query_dex()));
	line += sprintf(HIC"-------魔法提升先天根骨：%s\n\n"NOR, sprintf("%3d",ob->query("con_improve_time")));

	basic_data = mine["str"] + mine["int"] + mine["con"] + mine["dex"];
	if(basic_data > (80 + (int)ob->query("con_improve_time")))
 	  line += sprintf(HIY "先天资质异常, %3d - 80 = %3d\n\n" NOR,basic_data,(basic_data-80));
			
	write(line); 

	return 1;
}


