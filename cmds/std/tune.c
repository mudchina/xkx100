// tune.c
// Modified by zeratul,2000.1.14

inherit F_CLEAN_UP;

mapping channel_name = ([
	"sys"  :        1,
	"snp"  :        1,
	"debug":        1,
	"wiz"  :        1,
	"gwiz" : 	1,
	"qst"  :  1,
	"rumor":        0,
	"chat" :        0,
	"xkx"  :        0,
	"sing" :        0,
	"party":        0,
	"snow" :        0,
	"es"   :	0,	
]);

int main(object me, string arg)
{
	string *tuned_ch, chinese_name;
	int i;

	tuned_ch = me->query("channels");
	if( !arg )
	{
		if( !pointerp(tuned_ch) || !sizeof(tuned_ch) )
			write("你现在并没有收听任何频道。\n");
		else
			write("你现在收听的频道：" + implode(tuned_ch, ", ") + "。\n");
		return 1;
	}

	switch (arg)
	{
		  case "sys" 	: chinese_name = "系统"; break;
		  case "snp" 	: chinese_name = "监听"; break;
		  case "debug"	: chinese_name = "调试"; break;
		  case "wiz"	: chinese_name = "巫师"; break;
		  case "gwiz"	: chinese_name = "网际巫师"; break;
		  case "qst"  : chinese_name = "任务"; break;
		  case "rumor"	: chinese_name = "谣言"; break;
		  case "chat"	: chinese_name = "闲聊"; break;
		  case "xkx"	: chinese_name = "侠客行"; break;
		  case "sing"	: chinese_name = "歌唱"; break;
		  case "party"	: chinese_name = "门派"; break;
		  case "es"	: chinese_name = "网际闲聊"; break;
		  case "snow": chinese_name = "风闻"; break;
	}	
	if( pointerp(tuned_ch) && member_array(arg, tuned_ch)!=-1 )
	{
		tuned_ch -= ({ arg });
		me->set("channels", tuned_ch);
		write("关闭" + chinese_name + "频道。\n");
		return 1;
	}
	else
		if ( !undefinedp(channel_name[arg]))
		{
			if (!wizardp(me) && channel_name[arg])
				return notify_fail("你没有使用这个频道的权力。\n");
			tuned_ch += ({ arg });
			me->set("channels",tuned_ch);
			write("打开" + chinese_name + "频道。\n");
			return 1;
		}

	if ( arg == "on" )
	{
		tuned_ch = ({ });
		for ( i = 0; i < sizeof(channel_name); i++ )
			if ( (!wizardp(me) && !values(channel_name)[i]) ||
				wizardp(me) )
				tuned_ch += ({ keys(channel_name)[i] });
		me->set("channels", tuned_ch);
		write("已打开所有频道。\n");
		return 1;
	}
	if ( arg == "off" )
	{
		tuned_ch = ({ });
		me->set("channels", tuned_ch);
		write("已关闭所有频道。\n");
		return 1;
	}

	return notify_fail("有这个频道吗？\n");
}

int help(object me)
{
	write(@HELP
指令格式：tune [<频道名称> | on | off]

    这个指令让你选择是否要收听某一频道的讯息，如果没有指定频
道名称，就会列出你目前收听中的频道，如果指定了频道，原来收听
中的就会关掉，反之打开。
    用 tune on|off 可以打开或关闭所有频道。

如果你对一个没有收听中的频道讲话，会自动将它打开。
要对一个频道讲话，只要用：

<频道名称> <讯息> ....

例子：
     chat hello everyone!

你可以用 help channels 查询目前有哪些频道可以收听。

see also : shout
HELP
	);
	return 1;
}

