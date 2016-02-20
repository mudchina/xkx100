// Room: /yanziwu/matou.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>
#define MAX_EXP 20000
#define MIN_EXP 5000
inherit ROOM;
string look_sign();
int do_go(string);
mapping *sign=({
	([	"name" : "北京",
		"id"   : "bj",
		"file" : "/d/beijing/matou",
		"value": 100,
		"time" : 10
	]),
	([	"name" : "苏州",
		"id"   : "sz",
		"file" : "/d/suzhou/szyunhe",
		"value": 100,
		"time" : 10
	]),
	([	"name" : "杭州",
		"id"   : "hz",
		"file" : "/d/hangzhou/matou",
		"value": 200,
		"time" : 20
	])
});
void create()
{
	set("short","宁海桥码头");
	set("long",@LONG
这里是扬州城里最大的码头，南方的粮食，两淮的盐铁在此卸下由
漕运署的官员抽查，或转运或暂时储存。这里人员繁杂，有小贩在叫卖，
有工人在搬运粮袋，有官员手持长鞭在监工，有几个泼皮在转来转去，
不知打些什么主意。南边就是漕运署。东边是达士街，新开了几家店铺。
    岸边停靠着一条客船。客船醒目处，挂着一个牌子(sign)。
LONG );
	set("outdoors", "yangzhoue");
	set("worktimes", 20);
	set("exits", ([
		"north" : __DIR__"beiliuxiang",
		"south" : __DIR__"zhuqidian",
		"east"  : __DIR__"dashixijie",
		"west"  : __DIR__"ninghaiqiao",
	]));
	set("item_desc", ([
		"sign" : (: look_sign :)
	]));
	set("objects", ([
		__DIR__+"npc/jiangong" :1,
	]));
	set("coor/x", 40);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_work", ({"work", "ganhuo"}) );
	add_action("do_go", "qu");
}

int do_work()
{
	object me = this_player();
//	if ( query("worktimes") < 0)
//		return notify_fail("码头上现在不需要人干活，下次吧！\n");
	if ( me->query_temp("working") )
		return notify_fail("你已经在干活了！！\n");
	if ( !objectp( present ("jian gong", environment(me) ) ) )
		return notify_fail("码头上现在不需要人干活，下次吧！\n");
	if (me->query("combat_exp")<MIN_EXP)
	{
		tell_object(me,"这里都是重活，你现在还干不了。\n");
		return 1;
	}
	
	if (me->query("combat_exp")>=MAX_EXP)
	{
		tell_object(me,"这种小事不敢劳您大驾。\n");
		return 1;
	}
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");
	if ( (int)me->query("jing") < 10 || (int)me->query("qi") < 10 )
	{
		message_vision(
"监工冲着$N就是一鞭子，$N身上顿时起了一道血痕，$N踉踉跄跄躲到一\n"
"边去了。“妈的，你小子这副萎靡不振的样子还想干活？！！”监工骂\n"
"到：“滚！！”\n", me);
		me->receive_damage("qi", 11);
		me->receive_wound("qi", 11);
		return 1;
	}
	write("监工拿鞭子指了指，说道：“去那里搬麻袋吧。”\n");
	write("你搬起一个麻袋，开始干活。\n");
	add("worktimes", -1);
	me->start_busy(3);
	me->set_temp("working",1);
//	remove_call_out("work_end");
	call_out("work_end", 5, me);
	return 1;
}

int work_end(object me)
{
	object ob1;
	int add_exp,add_pot,add_score;
	write("终于做完苦工了，搬了一天的麻袋，累个半死。\n"
"监工过来拍了拍你的肩膀，说道：“小子，好样的，这是你的工钱。”\n");
	me->receive_damage("jing",10);
	me->receive_damage("qi",10);
		add_exp=60+random(20);
		add_pot=30+random(10);
		add_score=10+random(5);
		me->add("combat_exp",add_exp);
		me->add("potential",add_pot);
		me->add("score",add_score);
		ob1 = new("/clone/money/silver");
		ob1->set_amount(add_score);
		ob1->move(me);	
		tell_object(me,HIW"你得到了:"
			+ chinese_number(add_exp) + "点实战经验，"
			+ chinese_number(add_pot) + "点潜能，"
			+ chinese_number(add_score) + "点江湖阅历。\n"NOR);				
	if ( me->query_temp("working") ) me->delete_temp("working");
	return 1;
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

