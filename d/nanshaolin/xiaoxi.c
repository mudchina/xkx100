// Room: /d/nanshaolin/xiaoxi.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
int do_jump(string arg);

void create()
{
	set("short", "小溪");
	set("long", @LONG
这是一条由后山流下来的溪流，小溪并不宽，纵身一跃似乎就可蹦
到对岸。溪旁两岸的青草长得极是茂盛，且无杂乱之感，好象经人整理
过。溪流的水质清澈，可以清晰的看到水底的鹅卵石和来回游动的小鱼。
小溪对面的空地上有一座两层的小楼。
LONG );
	set("exits", ([
		"west" : __DIR__"xiaolu4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1870);
	set("coor/y", -6150);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "yue");
}

int do_jump(string arg)
{
	object me = this_player();

	if (arg == "river" || arg == "xiaoxi")
	{
		if (me->query_skill("dodge", 1) >= 60)
		{
			message("vision", me->name() + "吸了口气，纵身向对面跃去。\n", environment(me), ({me}) );
			write("你吸了口气，纵身向对面跃去。\n");
			me->move(__DIR__"xiaoxi1");
			message("vision", "只见人影一闪，" + me->name() +  "纵身跃了过来。\n", environment(me), ({me}) );
			return 1;
		}
		else
		{
			message("vision", me->name()+"纵身向对面跃去，只听“扑通”一声，"+me->name()+"摔入溪中，狼狈的爬了回来。\n",environment(me),({me}) );
			write( "你纵身向对面跃去，只听“扑通”一声，你摔入溪中，狼狈的爬了回来。\n");
                        me->receive_damage("qi",30);
                        return 1;
		}
	}
	return 0;
}

