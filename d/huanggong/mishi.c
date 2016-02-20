// Room: /d/huanggong/mishi.c
#include <room.h>
inherit ROOM;

void close_gate();
int do_open(string arg);
int do_close(string arg);

void create()
{
	set("short", "暗室");
	set("long", @LONG
这是康熙与心腹大臣密谋大事的地方, 寻常人是进不来的.
LONG
	);

	set("objects", ([
		"/d/beijing/obj/book14_8" : 1,
		__DIR__"obj/feicui" : 1,
	]));

	set("coor/x", -190);
	set("coor/y", 5281);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_open", "open");
	add_action("do_open", "unlock");
}

void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"yushufang")) )
		room = load_object(__DIR__"yushufang");
	if(objectp(room))
	{
		delete("exits/south");
		message("vision","只听乒地一声，暗门自动关了起来。\n", this_object());
		message("vision","你脑海中闪过一个念头：坏了！出不去了！\n", this_object());
		room->delete("exits/north");
		message("vision","只听乒地一声，暗门自动关了起来。\n",room);
		message("vision","你脑海中闪过一个念头：哎哟！又进不去了！\n", room );
	}
}

int do_open(string arg)
{
	object room;

	if (query("exits/south"))
		return notify_fail("暗门已经是开着了。\n");

	if (!arg || (arg != "door" && arg != "south"))
		return notify_fail("你要开什么？\n");

	if(!( room = find_object(__DIR__"yushufang")) )
		room = load_object(__DIR__"yushufang");

	if(objectp(room))
	{
		set("exits/south", __DIR__"yushufang");
		message_vision("$N使劲把暗门打了开来。\n",this_player());
		room->set("exits/north", __FILE__);
		message("vision","里面有人把暗门打开了。\n",room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}
	return 1;
}
