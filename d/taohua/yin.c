// Room: /d/taohua/yin.c
// Last Modified by winder on Nov. 17 2000

#include <localtime.h>

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "阴");
	set("long", @LONG
这里是两仪层的阴。阴是太极的一端，古人以黑暗为阴，以死亡为
阴，又以地理而认为北方属阴，山之北水之南为阴。
LONG
	);
	set("exits", ([ 
		"southwest" : __DIR__"liangyi",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8530);
	set("coor/y", -4670);
	set("coor/z", 10);
	setup();
}

void init()
{
	mixed *local;
	object me = this_player();

	add_action("do_save", "save");
	add_action("do_quit", "quit");
	if (!me->query_temp("liangyi")) {
		local = localtime(time());
		if (local[LT_MDAY] < 16)
			me->set_temp("liangyi", 1);
		else
			me->set_temp("liangyi", -1);
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
