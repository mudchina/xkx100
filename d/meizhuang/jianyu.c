// /d/meizhuang/jianyu.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", BLU"梅庄地牢"NOR);
	set("long", @LONG
这里黑黑暗暗，几乎伸手不见五指。唯一的光亮来自墙上忽明忽暗
的松油灯。地上和墙上布满了暗红色的血痕，散发出阵阵腥气。不断传
来的喘息声在死沉的地牢里回荡，令人毛骨耸然。从地牢的墙缝里透出
几缕阳光。西边是一扇紧闭的囚门。
LONG
	);
	set("item_desc", ([
		"door" : "囚门似乎以前有人动过什么手脚。\n",
		"门"   : "囚门似乎以前有人动过什么手脚。\n",
	]) );
	set("objects", ([
		CLASS_D("heimuya")+"/ren" : 1,
	]) );
	set("valid_startroom","1");

	set("coor/x", 3510);
	set("coor/y", -1420);
	set("coor/z", -10);
	setup();
}

void init()
{
	add_action("do_push", "push");
}

void check_trigger()
{
	object room;
	if( (int)query("trigger")==8 && !query("exits/out") )
	{
		message("vision","囚室门被你推得裂开了一道缝隙，刚好可以容你钻出去。\n", this_object() );
		set("exits/west", __DIR__"midao4");
		if(!( room = find_object(__DIR__"midao4")) )
			room = load_object(__DIR__"midao4");
		message("vision", "囚室门突然裂开一条窄缝。\n", room );
		room->set("exits/east", __FILE__);
		delete("trigger");
		call_out("close_passage", 5);
	}
}

void close_passage()
{
	object room;

	if( !query("exits/west") ) return;
	message("vision","铁门伊咿呀呀一阵响，砰地一声又关上了。\n", this_object());
	if( room = find_object(__DIR__"midao4") )
	{
		message("vision", "铁门伊咿呀呀一阵响，砰地一声又关上了。\n", room);
		room->delete("exits/east");
	}
	delete("exits/west");
}

int do_push(string arg)
{
	string dir;

	if( !arg || arg=="" )
	{
		write("你要推什么？\n");
		return 1;
	}

	if( arg=="door" || arg == "门")
	{
		add("trigger", 1);
		write("你试着用力推着紧闭着的囚门，似乎有一点松动....\n");
		check_trigger();
		return 1;
	}
}

void reset()
{
	::reset();
	delete("trigger");
}

