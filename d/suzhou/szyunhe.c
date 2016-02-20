// Room: /d/suzhou/szyunhe.c
// Last Modified by winder on Mar. 8 2001

#include <ansi.h>
string look_sign();
int do_go(string);
inherit RIVER;

mapping *sign=({
	([	"name" : "北京",
		"id"   : "bj",
		"file" : "/d/beijing/matou",
		"value": 200,
		"time" : 20
	]),
	([	"name" : "扬州",
		"id"   : "yz",
		"file" : "/d/city/matou",
		"value": 100,
		"time" : 10
	]),
	([	"name" : "杭州",
		"id"   : "hz",
		"file" : "/d/hangzhou/matou",
		"value": 100,
		"time" : 10
	])
});

void create()
{
	::create();
	set("short", "运河");
	set("long", @long
这里是古老的运河的桥头边，只见这条运河(river) 蜿蜒流淌，从
苏州城里穿过。运河的两岸都是苏州的寻常百姓家，在苏州的城里出门
最好的交通工具就是船了。只见进处有一位老船夫，见你走过来，起身
向你迎来，手上挂着一个竹牌(sign)。
long);
	set("exits",([
		"southeast" : __DIR__"xidajie1",
	]));
	set("item_desc", ([
		"river" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",
		"sign" : (: look_sign :)
	]));
	set("coor/x", 830);
	set("coor/y", -1000);
	set("coor/z", 0);
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
  set("yell_about", "船家");             // yell 船家
  set("river_type", "湖");               // 江面上传来回响
  set("need_dodge",300);                 // 需要多少轻功
  set("come_msg_out",   "一叶扁舟缓缓地驶了过来，采莲女将一块踏脚板搭上堤岸，以便乘客上下。\n");
  set("busy_msg",       "只听得河面不远处隐隐传来：“别急嘛，这儿正忙着呐……”\n");
  set("wait_msg",       "岸边一只渡船上的采莲女说道：正等着你呢，上来吧。\n");
  set("leave_msg_out",  "采莲女把踏脚板收了起来，竹篙一点，扁舟向运河驶去。\n");
  set("leave_msg_in",   "采莲女把踏脚板收起来，说了一声“坐稳喽”，竹篙一点，扁舟向运河驶去。\n");
  set("come_msg_in",    "采莲女说“到啦，上岸吧”，随即把一块踏脚板搭上堤岸。\n");
  set("item_desc/river", HIC "\n只见近岸处有一叶小舟，也许大声喊("
                         HIY "yell" HIC ")一声船家(" HIY "boat" HIC
                        ")就\n能听见。倘若你自负轻功绝佳,也可直接"
                        "渡水(" HIY "cross" HIC ")踏水而过。\n" NOR);
  set("boat_short", "渡船");    
  set("boat_desc",  @LONG
一叶小舟，最多也就能载七、八个人。一名十多岁的采莲小姑娘手
持长竹篙，正在船尾轻轻地荡舟。
LONG );
                                   // 渡船上的描述
  set("to",         __DIR__"huzhongdao");  // 船的终点 /*   必选   */
	setup();
}

void init()
{
	::init();
	add_action("do_go", "qu");
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
			ob->move(__DIR__"onroad");
			call_out("do_move", sign[i]["time"], ob, i);
			return 1;
		}
	}
	return notify_fail("你要去哪里？\n");
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

