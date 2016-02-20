// Room: /d/hangzhou/matou.c
// Last Modified by winder on Mar. 8 2001

#include <ansi.h>
string look_sign();
int do_go(string);
inherit ROOM;

mapping *sign=({
	([	"name" : "苏州",
		"id"   : "sz",
		"file" : "/d/suzhou/szyunhe",
		"value": 100,
		"time" : 10
	]),
	([	"name" : "扬州",
		"id"   : "yz",
		"file" : "/d/city/matou",
		"value": 200,
		"time" : 20
	]),
	([	"name" : "北京",
		"id"   : "bj",
		"file" : "/d/beijing/matou",
		"value": 300,
		"time" : 30
	])
});

void create()
{
	set("short", "临安码头");
	set("long", @long
这里是古老的运河的终点，运河自燕山脚下的帝都南下，横穿中国
的华北大平原，连绵海河、黄河、淮河、长江和钱塘江五大水系，止于
号称天堂和鱼米之乡的杭州城。运河中满是来来往往的樯影，江南的丰
厚的产出经此国家命脉，源源北上。
    你走进码头，就看见一位老船夫站在船边，手上高举着一个写满字
的木牌(sign)。
long);
	set("exits",([
		"southwest" : __DIR__"road9",
	]));
	set("item_desc", ([
		"sign" : (: look_sign :)
	]));
	set("coor/x", 4200);
	set("coor/y", -1430);
	set("coor/z", 0);
	set("outdoors", "xihu");
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_go", "qu");
}

string look_sign()
{
	string str="由此去(qu)到下列码头：\n";
	int i=sizeof(sign);

	while (i--)
	{
		str += sign[i]["name"];
		str += "(" + sign[i]["id"] + ") ";
		str += MONEY_D->price_str(sign[i]["value"]) + "\n";
	}

	return str;
}

void do_move(object ob, int i)
{
//	ob->enable_player();
	ob->delete_temp("noliving");
	ob->delete_temp("block_msg/all");
	tell_object(ob, "终点站到了。\n");
	ob->move(sign[i]["file"]);
	tell_room(environment(ob), ob->name() + "从船上走了下来。\n", ({ob}));
}

int do_go(string arg)
{
	object ob=this_player();
	int i=sizeof(sign);

	if (!arg) return 0;
	if (ob->is_busy() || ob->is_fighting())
		return notify_fail("你正忙着呢！\n");
	while(i--)
	{
		if (arg == sign[i]["id"])
		{
			switch (MONEY_D->player_pay(ob, sign[i]["value"]))
			{
				case 0:
					return notify_fail("穷光蛋，一边呆着去！\n");
				case 2:
					return notify_fail("有零钱吗？\n");
			}
			message_vision("$N登上了去" + sign[i]["name"] + "的船。\n", ob);
//			ob->disable_player("<旅途中>");
			ob->set_temp("noliving/journey", 1);
			ob->set_temp("block_msg/all", 1);
			ob->move("/d/suzhou/onroad");
			call_out("do_move", sign[i]["time"], ob, i);
			return 1;
		}
	}
	return notify_fail("你要去哪里？\n");
}

