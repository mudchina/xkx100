// Room: /d/beijing/matou.c
// Last Modified by winder on Mar. 8 2001

#include <ansi.h>
string look_sign();
int do_go(string);
inherit ROOM;

mapping *sign=({
	([	"name" : "扬州",
		"id"   : "yz",
		"file" : "/d/city/matou",
		"value": 100,
		"time" : 10
	]),
	([	"name" : "苏州",
		"id"   : "sz",
		"file" : "/d/suzhou/szyunhe",
		"value": 200,
		"time" : 20
	]),
	([	"name" : "杭州",
		"id"   : "hz",
		"file" : "/d/hangzhou/matou",
		"value": 300,
		"time" : 30
	])
});

void create()
{
	set("short", "通州码头");
	set("long", @long
这里是古老的运河的起始点，运河由此南下，横穿华北大平原，沟
通海河、黄河、淮河、长江和钱塘江五大水系，纵横中国南北，是帝都
命脉。河里来来往往的，都是江南运来的粮米货物。帆影蔽日，十分繁
华。你走进码头，就看见一位老船夫，起身向你迎来，手上挂着一个木
牌(sign)。
long);
	set("exits",([
		"north" : __DIR__"dongmen",
	]));
	set("item_desc", ([
		"sign" : (: look_sign :)
	]));
	set("outdoors", "beijing");
	set("no_clean_up", 0);
	set("coor/x", -170);
	set("coor/y", 4030);
	set("coor/z", 0);
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

