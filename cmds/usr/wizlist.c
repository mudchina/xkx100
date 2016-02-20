// wizlist.c
// Modified by winder May.26 2000
inherit F_CLEAN_UP;

#include <ansi.h>
#include <mudlib.h>


int level(mixed, mixed);
string wiz_rank(string hood);

int main(object me, string arg)
{
	string *list, hood = "", str;
	int j = 0;

	list = sort_array(SECURITY_D->query_wizlist(), (: level :) );
	str = HIC+CHINESE_MUD_NAME+NOR +"巫师董事会成员：\n";
	str += "───────────────────\n";
	for(int i=0; i<sizeof(list); i++, j++)
	{
		if (hood!= wiz_rank(wizhood(list[i])))
		{
			hood = wiz_rank(wizhood(list[i]));
			if (j%7) str += "\n";
			str += hood;
			str = replace_string(str,"(",HIG);
			str = replace_string(str,")",": "NOR);
			j = 0;
		}
		str += sprintf(" %s%s", list[i],
			( j%7==6 ) ? "\n" : ( i<sizeof(list)-1 && hood ==wizhood(list[i+1]) ) ? ", " : "" );
	}
	str += "\n───────────────────\n";
	str += sprintf("目前一共有: %s个巫师\n",chinese_number(sizeof(list)) );
	me->start_more(str);
	return 1;
}

string wiz_rank(string hood)
{
	switch(hood)
	{
		case "(admin)":
			return HIM "【 天  帝 / 天  后 】" NOR;
		case "(arch)":
			return HIY "【 仙  官 / 仙  妃 】" NOR;
		case "(wizard)":
			return HIG "【 神  仙 / 神  女 】" NOR;
		case "(apprentice)":
			return HIC "【 半  仙 / 仙  女 】" NOR;
		case "(immortal)":
			return HIC "【 仙  童 / 女仙童 】" NOR;
	}
}

int level(mixed ob1, mixed ob2)
{
	if (wiz_level(ob1) != wiz_level(ob2))
		return wiz_level(ob2) - wiz_level(ob1);
	return ob1 > ob2?-1:1;
}

int help(object me)
{
	write(@HELP
指令格式 : wizlist
 
    这个指令会显示这个游戏目前的巫师名单。
 
HELP
	);
	return 1;
}

