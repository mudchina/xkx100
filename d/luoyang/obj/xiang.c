// xiang.c
#include <ansi.h>
inherit ITEM;
int do_chuangli(string arg);

int do_weapon();
object creat_weapon();

void create()
{
	set_name("关帝像", ({ "guandi xiang", "xiang" }) );
	set("gender", "男性" );
	set("unit", "尊");
	set("value", 1);
	set("kar", random(21));
	set("no_get", 1);
	set("no_put", 1);
	set("no_get_from", 1);
        set("long", 	
"这是一尊三人像。前坐者"HIG"绿衫"HIR"赤面"NOR"，右手捋髯，左手正执竹简，正是
关帝夜读春秋像。后立者，左手一位"HIW"银甲白面"NOR"，手捧令旗，正是关平。
右手一将，"BLK"黑面皂袍"NOR"，手握"HIC"青龙偃月刀"NOR"的，便是周仓了。\n");
}

void init()
{
	add_action("do_chuangli","chuangli");
	add_action("do_chuangli","kaibang");
}

int do_chuangli(string arg)
{
	string *line, file;
	int i, j;
	object ob, me = this_player();

	if (!arg) return notify_fail("你要创立什么帮、教、会？\n");

	file = read_file("/log/PARTY");
	line = explode(file, "\n");
	for(j = 0; j < sizeof(line); j ++)
	{
		if (line[j] == arg)
			return notify_fail(arg+"已经存在，不用你费心创立。\n");
	}
	if (me->query("age") < 50 && !wizardp(me))
		return notify_fail("你还嫩着呢！还想创立帮会？\n");
	if (me->query("combat_exp") < 5000000)
		return notify_fail("凭你这么点能耐，还想创立帮会？\n");
	if (me->query("party") )
		return notify_fail("你现在还是"+me->query("party/party_name")+"中人。不退出来，不能创立帮会。\n");
	i = strlen(arg);

	if( (strlen(arg) < 4) || (strlen(arg) > 8 ) )
	{
		write("对不起，帮派的中文名字必须是 2 到 4 个中文字。\n");
		return 0;
	}
	while(i--)
	{
		if( arg[i]<=' ' )
		{
			write("帮派名字不能用控制字元。\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(arg[i..<0]) )
		{
			write("帮派名字必须是「中文」。\n");
			return 0;
		}
	}
	i = strlen(arg);
	if ((arg[i-2..i]=="教") || (arg[i-2..i]=="帮") || (arg[i-2..i]=="门"))
	{
		if(me->query("kar")-this_object()->query("kar")<11)
		{
			me->set("party/party_name", arg);
			me->set("party/rank", arg[i-2..i]+"主");
			me->set("party/level", 1);
			me->set("party/player", 1);
			me->set("party/enter_time", time());
			seteuid(getuid());
			ob=new("/d/luoyang/obj/yaopai");
			ob->move(me);
message_vision("$N点起三柱香，冲着关帝像拜了下去：弟子创立"+arg+"，志在
匡扶正义，除恶扬善。蒙关帝护佑，今日终于开坛。此后当得
约束帮众，同践此誓。若有不肖匪类，坏我帮规，天厌之！天
厌之！！\n", me);
			message_vision("$N获得一块腰牌！\n",me);
			message("channel:chat", HIY"【通告】"HIR+me->query("name")+"于"+NATURE_D->game_time()+"创立"+arg+"！\n"NOR,users());
			log_file("PARTY", arg+"\n");
		}
		else return notify_fail("关林里一阵阵阴风吹过，看来今天不是开帮会的黄道吉日。改天再来吧。\n");
	}
	else return notify_fail("帮会名称只能以教、帮、门结尾。\n");
	return 1;
}

