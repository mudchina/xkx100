// Room: /d/taohua/taiyin.c
// Last Modified by winder on Nov. 17 2000

#include <localtime.h>

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "太阴");
	set("long", @LONG
这里是四象层的太阴。太阴是阴中之阴，也即至阴。北方对应四灵
兽中的玄武，乌龟之形，尚黑。以方位入五行，有一道铁梯直通下方的
北方壬癸水。
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"sixiang",
		"down" : __DIR__"shui",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8520);
	set("coor/y", -4670);
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
		if (local[LT_HOUR] >= 23 || local[LT_HOUR] < 5)
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
