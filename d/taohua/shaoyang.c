// Room: /d/taohua/shaoyang.c
// Last Modified by winder on Nov. 17 2000

#include <localtime.h>

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "少阳");
	set("long", @LONG
这里是四象层的少阳。少阳是阴中之阳。西方对应四灵兽中的白虎，
白虎之形，尚白。以方位入五行，有一道铁梯直通下方的西方庚辛金。
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"sixiang",
		"down" : __DIR__"jin",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8510);
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
		if (local[LT_HOUR] >= 17 && local[LT_HOUR] < 23)
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
