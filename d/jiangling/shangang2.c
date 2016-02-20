#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山冈");
	set("long", @LONG
这是一片乱石堆成的山冈。几棵小树稀稀落落地长在岩石的罅隙里。
杂草丛里，露出一块石碑(bei)的一角。
LONG );
	set("exits", ([
		"west"  : __DIR__"gumiao",
		"south" : __DIR__"xilingxia",
		"north" : __DIR__"xiaowu",
	]));
	set("outdoors", "jiangling");
	set("item_desc", ([
		"bei": "象是块墓碑，只露出一角。\n"
	]) );
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2058);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_dig", "dig");
}
void check_trigger()
{
	object room;

	if( (int)query("left_trigger")==3 && (int)query("right_trigger")==2 && !query("exits/down") )
	{
        message("vision", "墓碑被挖得松动了，突然往地上一陷，露出一个向下的阶梯。\n", this_object() );
        set("exits/down", __DIR__"gumu");
        if( room = find_object(__DIR__"gumu") )
		{
			room->set("exits/up", __FILE__);
            message("vision", "墓碑突然往地上一陷，露出一个向上的阶梯。\n",
				room );
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
	message("vision", "墓碑轧轧移动，又将向下的通道盖住了。\n", this_object());
	if( room = find_object(__DIR__"mudao") )
	{
		room->delete("exits/up");
		message("vision", "墓碑轧轧移动，缓缓合拢，你的眼前一片漆黑。\n"
		HIR "你脑海中闪过一个念头：坏了！出不去了！\n" NOR ,
			room );
	}
	delete("exits/down");
}

int do_dig(string arg)
{
        object weapon,me = this_player();
	string dir;

        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("name") != "锄头")
        return notify_fail(HIR"你双手刨出血来，却什么也没发现。\n"NOR);        
	if( !arg || arg=="" ) return 0;

	if( arg=="bei" )
	{
		write("你试著挖出墓碑，发现它边上有些松动……\n");
		return 1;
	}
	if( this_player()->query_str() <40)
	{
		write("你试著挖出墓碑，可是力气太小……\n");
		return 1;
	}
	if( sscanf(arg, "bei %s", dir)==1 )
	{
		if( dir=="right" ) {
			message_vision("$N在墓碑右边挖了挖……\n", this_player());
			add("right_trigger", 1);
			check_trigger();
			return 1;
		} else if( dir=="left" ) {
			message_vision("$N在墓碑左边挖了挖……\n", this_player());
			add("left_trigger", 1);
			check_trigger();
			return 1;
		} else {
			write("你乱挖一气，累得半死，墓碑还是没半点动静。\n");
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