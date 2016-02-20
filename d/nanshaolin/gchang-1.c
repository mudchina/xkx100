// Room: /d/nanshaolin/gchang-1.c
// Last Modified by Winder on May. 29 2001

#include <ansi.h>
inherit ROOM;
void init();
void close_gate();
int do_close(string arg);
string look_gate();
int do_open(string arg);

void create()
{
	set("short", "广场");
	set("long", @LONG
穿过山门，面前三道平行的青石台阶通向前方的一个广场。台阶上
精工镂刻着麒麟，玄龟，松鹤等瑞兽，形态逼真动人。广场正中放着个
二人高的青铜大香炉，前面摆着个香台，几位香客正在虔诚谟拜。再往
前就是天王殿。南边就是南少林的山门(gate)了。
LONG);
	set("item_desc",([
		"gate" : (: look_gate :),
	]));
	set("exits", ([
		"east"  : __DIR__"gchang-3",
		"west"  : __DIR__"gchang-2",
		"north" : __DIR__"qdian",
	]));

	set("outdoors", "nanshaolin");
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));
	set("coor/x", 1820);
	set("coor/y", -6290);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_open", "open");
	add_action("do_close", "close");
}

void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"shanmen")) )
		room = load_object(__DIR__"shanmen");
	if(objectp(room))
	{
		delete("exits/south");
			message("vision", "僧兵上前把大门关了起来。\n", this_object());
		room->delete("exits/north");
		message("vision", "乒地一声，里面有人把大门关上了。\n", room);
	}
}

int do_close(string arg)
{
	if (!query("exits/south"))
		return notify_fail("大门已经是关着的了。\n");

	if (!arg || (arg != "gate" && arg != "south"))
		return notify_fail("你要关什么？\n");

	message_vision("$N朝僧兵点了点头。\n", this_player());

	remove_call_out("close_gate");
	call_out("close_gate", 2);
	return 1;
}

int do_open(string arg)
{
	object room;

	if (query("exits/south"))
		return notify_fail("大门已经是开着了。\n");
	if (!arg || (arg != "gate" && arg != "south"))
		return notify_fail("你要开什么？\n");
	if(!( room = find_object(__DIR__"shanmen")) )
		room = load_object(__DIR__"shanmen");
	if(objectp(room))
	{
		set("exits/south", __DIR__"shanmen");
		message_vision("$N使劲把大门打了开来。\n", this_player());
		room->set("exits/north", __FILE__);
		message("vision", "吱地一声，里面有人把大门打开了。\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}

	return 1;
}

string look_gate()
{
	return "一道三丈来高的朱红杉木包铜大门。\n";
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "south" ) return 0;
	return ::valid_leave(me, dir);
}
