#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_break(string arg);
int do_climb(string arg);

void create()
{
	set("short", "庄府大门");
	set("long", @LONG
这里就是文士庄允城的旧居。自从他被朝廷抓走后，这里好象就没
有人住了。一扇大门 (men)紧锁着，周围是高高的围墙(wall)。一切都
很干净，并没有积多少灰尘。
LONG );
	set("outdoors", "huabei");
	set("exits", ([
		"south" : __DIR__"zhuang2",
	]));
	set("item_desc", ([
		"men" : "这扇门是锁着的，除非你打破(break)它。\n",
		"wall" : "墙很高，可能翻不过去(climb)。\n",
	]) );
	set("no_clean_up", 0);
	set("coor/x", 100);
	set("coor/y", 4700);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_break", "break");
	add_action("do_climb", "climb");
}

int do_break(string arg)
{
	int n;
	object me = this_player();

	n = me->query("neili");
	if( !arg || arg!="men" )
	{
		write("不要随便打碎别人的东西！\n");
		return 1;
	}
	message_vision("$N走到门前，深吸一口气，双掌同时拍出。\n", me);
	if (n>=200)
	{
		message_vision("$N只听一声轰响，$N把门震开了！\n", me);
		set("exits/north", __DIR__"zhuang4");
		me->set("neili",n-200);
		remove_call_out("close");
		call_out("close", 5, this_object());
	}
	else
	{
		message_vision("$N大吼一声“开！”，结果什么也没发生。看来$N的内力不够强。\n", me);
		me->set("neili",0);
	}
	return 1;
}

int do_climb(string arg)
{
	int n;
	object me = this_player();

	n = me->query_skill("dodge");
	if( !arg || arg!="wall" )
	{
		write("不要到处乱爬！\n");
		return 1;
	}
	message_vision("$N在墙前站定，深吸一口气，猛然跃起。\n", me);
	if (n>=80)
	{
		message_vision("只见$N足尖在墙上一点，已悠然飘落院中。\n", me);
		me->move(__DIR__"zhuang4");
	}
	else
		if (n>=50)
		{
			message_vision("只见$N双手在墙上一攀，勉强翻过围墙，跌落院中。\n", me);
			me->move(__DIR__"zhuang4");
		}
		else
		{
			message_vision("$N高高跃起，可还差一大截呢，看来是轻功不够好。\n", me);
		}
		return 1;
}

void close(object room)
{
	message("vision","门吱呀一声又合上了,好象有鬼。\n", room);
	room->delete("exits/north");
}
