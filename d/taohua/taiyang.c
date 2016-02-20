// Room: /d/taohua/taiyang.c
// Last Modified by winder on Nov. 17 2000

#include <localtime.h>

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "太阳");
	set("long", @LONG
这里是四象层的太阳。太阳是阳中之阳，也即至阳。南方对应四灵
兽中的朱雀，赤日之形，尚红。以方位入五行，有一道铁梯直通下方的
南方丙丁火。
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"sixiang",
		"down" : __DIR__"huo",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8520);
	set("coor/y", -4690);
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
		if (local[LT_HOUR] >= 11 && local[LT_HOUR] < 17)
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
