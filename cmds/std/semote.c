// semote.c
// 增加参数功能，使semote命令可以查找开头部分字母匹配的emote
// Modified by Spacenet@FXLT
inherit F_CLEAN_UP;

#include "/doc/help.h"



int head_index(string str, string index);

int main(object me, string arg)
{
	string *e, str;
	int i;

	e = sort_array(EMOTE_D->query_all_emote(), 1);
	e = filter_array(e, (: head_index :), arg);

	if (sizeof(e)) {
		str = "                        侠客行一百表情动作总汇 \n\n";
		str += "—————————————————————————————————————\n";
		for(i=0; i<sizeof(e); i++)
//			printf("%-15s%s", e[i], (i%5==4)?"\n": "");
			str += sprintf("%-15s%s", e[i], (i%5==4)?"\n": "");
		me->start_more(str);
		write("\n");
		return 1;
	} else return notify_fail("没有符合指定要求的表情动作。\n");
}

int head_index(string str, string substr)
{
	int i;
	
	for (i = 0; i < sizeof(substr); i ++)
		if (str[i] != substr[i])
			return 0;
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : semote [词首]

    这个指令可以列出目前所能使用的ｅｍｏｔｅ。如果带上参数，将列出以
该参数为词首的所有ｅｍｏｔｅ，例如：ｓｅｍｏｔｅ ｓｕ，可以列出ｓｕ
开头的ｅｍｏｔｅ。不跟参数的话将列出全部的ｅｍｏｔｅ。

HELP
	);
	return 1;
}
