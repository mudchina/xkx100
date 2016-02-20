// Modified by Zeratul 4.12 2001 匕首和宝甲修改为唯一物品
#include <room.h>
inherit ROOM;

void close_gate();
int do_open(string arg);
int do_close(string arg);

void create()
{
	object ob;
	set("short", "暗室");
	set("long", @LONG
这里是鳌拜藏宝的地方，各种珠宝玉器，应有尽有，有几样尤其显眼。
LONG );

	set("objects", ([
//		WEAPON_DIR"treasure/bishou" : 1,
//		ARMOR_DIR"treasure/baojia" : 1,
		__DIR__"obj/shouzhuo" : 1,
		__DIR__"obj/jinduan" : 1,
		__DIR__"obj/book14_1" : 1,
		__DIR__"obj/book14_7" : 1,
	]));
	set("coor/x", -202);
	set("coor/y", 4052);
	set("coor/z", 0);
	setup();
  ob=new(WEAPON_DIR"treasure/bishou");
  if ( ob->violate_unique() || 	uptime() < 300)
    destruct(ob);
  else
    ob->move(this_object()); 
  ob=new(ARMOR_DIR"treasure/baojia");
  if ( ob->violate_unique() || 	uptime() < 300)
    destruct(ob);
  else
    ob->move(this_object()); 
}

void init()
{
	add_action("do_open", "open");
	add_action("do_open", "unlock");
}

void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"aobai7")) )
		room = load_object(__DIR__"aobai7");
	if(objectp(room))
	{
		delete("exits/south");
		message("vision","只听乒地一声，暗门自动关了起来。\n",this_object());
                message("vision","你脑海中闪过一个念头：坏了！出不去了！\n" ,
			this_object());
		room->delete("exits/north");
		message("vision","只听乒地一声，暗门自动关了起来。\n",room);
                message("vision","你脑海中闪过一个念头：哎哟！又进不去了！\n" ,
			room );
	}
}

int do_open(string arg)
{
	object room;

	if (query("exits/south"))
		return notify_fail("暗门已经是开着了。\n");

	if (!arg || (arg != "door" && arg != "south"))
		return notify_fail("你要开什么？\n");

	if(!( room = find_object(__DIR__"aobai7")) )
		room = load_object(__DIR__"aobai7");
	if(objectp(room))
	{
		set("exits/south", __DIR__"aobai7");
		message_vision("$N使劲把暗门打了开来。\n",this_player());
		room->set("exits/north", __FILE__);
		message("vision","里面有人把暗门打开了。\n",room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}
	return 1;
}
