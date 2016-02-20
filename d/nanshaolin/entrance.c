// Room: /d/nanshaolin/entrance.c 木人巷入口
// Last Modified by winder on May. 29 2001

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "木人巷入口");
	set("long", @LONG
这里是木人巷的入口。一旦走到这里，就已经无法再回头了，虽然
明知前面将会是步步凶险无比，也只有硬着头皮向前闯了。
LONG );
	set("exits", ([ 
		"north" : __DIR__"murenxiang",
	]) );
	set("coor/x", 1790);
	set("coor/y", -6090);
	set("coor/z", 10);
	set("no_clean_up", 0);
	setup();
}

void init()
{
	this_player()->delete_temp("murenxiang");
	add_action("do_save", "save");
	add_action("do_quit", "quit");
	add_action("do_quit", "exit");
}

int do_save()
{
	write("这里不准存盘！\n");
	return 1;
}

int do_quit()
{
	write("这里不准退出！\n");
	return 1;
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && __DIR__"murenxiang"->query("busy"))
	{
		return notify_fail("有人正在闯木人巷，你先等会吧！\n");
	}
	return ::valid_leave(me, dir);
}

