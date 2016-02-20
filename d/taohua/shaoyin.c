// Room: /d/taohua/shaoyin.c
// Last Modified by winder on Nov. 17 2000

#include <localtime.h>

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "少阴");
	set("long", @LONG
这里是四象层的少阴。少阴是阳中之阴。东方对应四灵兽中的青龙，
青龙之形，尚青。以方位入五行，有一道铁梯直通下方的东方甲乙木。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"sixiang",
		"down" : __DIR__"mu",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8530);
	set("coor/y", -4680);
	set("coor/z", 0);
	setup();
}

void init()
{
	mixed *local;
	object me = this_player();

	add_action("do_save", "save");
	add_action("do_quit", "quit");
	if (!me->query_temp("sixiang")) {
		local = localtime(time());
		if (local[LT_HOUR] >= 5 && local[LT_HOUR] < 11)
			me->set_temp("sixiang", 1);
		else
			me->set_temp("sixiang", -1);
	}
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
