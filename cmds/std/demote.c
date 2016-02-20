// demote.c  display emote
inherit F_CLEAN_UP;
inherit EMOTE_D;

#include "/doc/help.h"



int main(object me, string arg)
{
	string *e, msg, str;
	int i;

	e = sort_array(query_all_emote(), 1);
	msg = "\n";

	for(i=0; i<sizeof(e); i++)
	{
		if(emote[e[i]]["others_target"])
			str = emote[e[i]]["others_target"];
		else
		{
			if(emote[e[i]]["others"])
				str = emote[e[i]]["others"];
			else str = emote[e[i]]["others_self"];
		}
		if(!str) continue;
		str = replace_string(str, "$n", "某人");
		str = replace_string(str, "$N", "你");
		str = replace_string(str, "$p", "他");
		str = replace_string(str, "$s", "壮士");
		str = replace_string(str, "$r", "小王八蛋");
		if( strlen(e[i]) > 6 )
			msg += e[i]+"\t : ";
		else
			msg += e[i]+"\t\t : ";
		msg += str;
	}

	msg += "\n";
	me->start_more(msg);

	return 1;
}

int help(object me)
{
	write(@HELP

指令格式 : demote

    这个指令可以列出目前所能使用的emote的具体内容。

HELP
	);

	return 1;
}

