// /d/meizhuang/didao3.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void cloth_path();
void create()
{
	set("short", "梅庄密道");
	set("long", @LONG
这是一条昏暗潮湿的地道，地道很长，两边点着两根不太明亮的火
把，地道两旁的墙壁上画着很多不知道出自何人之手的壁画，而且画得
相当难看，你加快脚步，想知道地道的尽头是什么地方。突然之间你发
现这里的地面已经是木板拼成的了。
LONG
	);
	set("exits", ([
	    "south" : __DIR__"didao2",
	]));
	set("item_desc", ([
		"floor": "这层木板似乎可以拉开(pull)。\n",
	]) );

	set("coor/x", 3490);
	set("coor/y", -1480);
	set("coor/z", 20);
	setup();
}
void init()
{
	add_action("do_open", "pull");
}
int do_open(string arg)
{
	object obj, me = this_player();

	if(!arg || arg=="")
	{
		write("你要打开什么？\n");
		return 1;
	}
	if( arg == "floor")
	{
		message_vision("$N拉起地上的木板，发现下面是空的。\n", me);
		if( !query("exits/down") )
		{
			set("exits/down", __DIR__"didao4");
			call_out("close_path", 1);
		}
		return 1;
	}
	else
	{
		write("你不可以打开"+arg+"\n");
		return 1;
	}
}
void close_path()
{
	if( !query("exits/down") ) return;
	message("vision", "木板又弹了回来，遮住了下面的密道。\n", this_object() );
	delete("exits/down");
}
