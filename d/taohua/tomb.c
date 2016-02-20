// Room: /d/taohua/tomb.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
int do_bai(string arg);

void create()
{
	set("short", "石坟");
	set("long", @LONG
从幽暗的迷阵中走出来，只见绿草如荫，中间是一片白色花丛，重
重叠叠，宛如一座白花堆成的小湖。白花之中有一块东西高高隆起，走
近了才发现是一座石坟，坟前有一块墓碑(mubei)。
LONG
	);
	set("exits", ([ 
		"east"  : __DIR__"taohua1",
		"west"  : __DIR__"taohua1",
		"south" : __DIR__"taohua1",
		"north" : __DIR__"taohua1",
	]) );
	set("item_desc",([
		"mubei" : "
桃
花
岛
女
主
冯
氏
埋
香
之
冢\n
"
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("coor/x", 9010);
	set("coor/y", -3100);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_bai", "bai");
	add_action("do_bai", "guibai");
	add_action("do_bai", "gui");
	add_action("do_bai", "knee");
	add_action("do_push", "push");
}

int do_bai(string arg)
{
	object me = this_player();

	if (arg != "mubei")
		return notify_fail("你要拜什么？\n");
	message_vision("$N在坟前跪倒，恭恭敬敬地拜了四拜。\n", me);
	me->set_temp("tomb_knee", 1);
	return 1;
}

void check_trigger()
{
	object room;

	if( (int)query("left_trigger")==3 && (int)query("right_trigger")==3 &&
		!query("exits/down") )
	{
		message("vision","墓门忽然发出轧轧的声音，缓缓向两边移动著，露出一个向下的阶梯。\n", this_object() );
		set("exits/down", __DIR__"mudao");
		if( room = find_object(__DIR__"mudao") )
		{
			room->set("exits/up", __FILE__);
			message("vision","墓门忽然发出轧轧的声音，缓缓向两边移动著，露出一个向上的阶梯。\n", room );
		}
		delete("left_trigger");
		delete("right_trigger");
		call_out("close_passage", 30);
	}
}

void close_passage()
{
	object room;

	if( !query("exits/down") ) return;
	message("vision","墓门忽然发出轧轧的声音，缓缓合拢，将向下的通道盖住了。\n", this_object() );
	if( room = find_object(__DIR__"mudao") )
	{
		room->delete("exits/up");
		message("vision","墓门忽然发出轧轧的声音，缓缓合拢，将向上的通道盖住了。\n"HIR"你脑海中闪过一个念头：坏了！出不去了！\n" NOR , room );
	}
	delete("exits/down");
}

int do_push(string arg)
{
	string dir;

	if( !arg || arg=="" ) return 0;

	if( arg=="mubei" ) {
		write("你试著推动墓碑，发现它可以左右推动....\n");
		return 1;
	}
	if( this_player()->query("neili") <100) {
		write("你试著推动墓碑，可是内力太低....\n");
		return 1;
	}
	if( sscanf(arg, "mubei %s", dir)==1 ) {
		if( dir=="right" ) {
			message_vision("$N将墓碑往右推...，忽然轧轧几声墓碑又移回原位。\n", this_player());
			add("right_trigger", 1);
			check_trigger();
			return 1;
		} else if( dir=="left" ) {
			message_vision("$N将墓碑往左推...，忽然轧轧几声墓碑又移回原位。\n", this_player());
			add("left_trigger", 1);
			check_trigger();
			return 1;
		} else {
			write("你要将墓碑推向那个方向？\n");
			return 1;
		}
	}
}
void reset()
{
	::reset();
	delete("left_trigger");
	delete("right_trigger");
}
