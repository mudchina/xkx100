// room: midao.c

#include <room.h>

inherit ROOM;
int do_press(string arg);

void create()
{ 
       set("short", "密道");
       set("long", @TEXT
这是水井里的一个密道。周围都是些机关，只有出口很明显在哪里。
湿漉漉的墙壁上有四块石板，分别刻着１、２、３、４。旁边还有一个
铁板(tieban)扔在地上。
TEXT );
        set("exits", ([
            "out" : __DIR__"well",
        ]));

        set("item_desc", ([
            "tieban" :      
            "铁板歪歪斜斜地写着：方人智到此一游，空手悻悻而归。\n",
        ]) );
        set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6311);
	set("coor/z", -10);
	setup();
}

void init()
{
        add_action("do_press", "press");
}

int do_press(string arg)
{
	string p;

	p = sprintf("%d", this_player()->query("passwd"));
	if( !arg || arg == "" )
	{
		write("别瞎按！\n");
		return 1;
	}
	if( arg == p )
	{
		message_vision("只听得一阵隆隆的响声由远及近。\n", this_player());
		message_vision("石板缓缓移了开来，露出一个洞。\n", this_player());
		set("exits/enter", __DIR__"mishi");
		write("\n\n一个声音提醒你：记住你的密码，以后你就靠它来进出这里了！\n\n");

		remove_call_out("close");
		call_out("close", 5, this_object());

		return 1;
	}
	else
	{
		write("你心想：老天保佑这次能蒙着！\n");
		if (random(10) != 8)
		{
			message_vision("$N一阵乱按，什么反应也没有。\n", this_player());
			return 1;
		}
		else
		{
			message_vision("$N一阵乱按，突然石板的缝隙间射出一支毒箭！。\n", this_player());
			this_player()->die();
			return 1;
		}
	}
}

void close(object room)
{
        message("vision","轰隆隆的响声响过之后，石板又合上了。\n", room);
        room->delete("exits/enter");
}