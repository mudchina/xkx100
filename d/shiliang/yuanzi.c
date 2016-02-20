// Feb. 6, 1999 by Winder
inherit ROOM;
void init();
void close_gate();
int do_open(string arg);
int do_close(string arg);
string look_gate();
void create()
{
	set("short", "大院");
	set("long", @LONG
这里就是温宅进门的一个大庭院，地上铺着一块块平整的
大理石，光可鉴人。院子的面积很大，看得出来这家主人家资
丰厚。南面的大门(gate)紧锁着。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","shiliang");
	set("exits", ([ 
            "west" : __DIR__"xixiangfang",
            "east" : __DIR__"dongxiangfang",
            "north" : __DIR__"dating",
	]));
	set("item_desc",([
		"gate"		:	(: look_gate :),
	]));
	set("coor/x", 1610);
	set("coor/y", -1960);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_open", "open");
	add_action("do_close", "close");
}
void close_gate()
{
	object room;
	if(!( room = find_object(__DIR__"gate")) )
		room = load_object(__DIR__"gate");
	if(objectp(room))
	{
		delete("exits/south");
			message("vision", "有人走上前来把门关上了。\n", this_object());
		room->delete("exits/north");
		message("vision", "乒地一声，里面有人把大门关上了。\n", room);
	}
}
int do_close(string arg)
{
	if (!query("exits/south"))
		return notify_fail("大门已经是关着的了。\n");
	if (!arg || (arg != "gate" && arg != "south"))
		return notify_fail("你要关什么？\n");
	message_vision("$N点了点头。\n", this_player());
	remove_call_out("close_gate");
	call_out("close_gate", 2);
	return 1;
}
int do_open(string arg)
{
	object room;
	if (query("exits/south"))
		return notify_fail("大门已经是开着了。\n");
	if (!arg || (arg != "gate" && arg != "south"))
		return notify_fail("你要开什么？\n");
	if(!( room = find_object(__DIR__"gate")) )
		room = load_object(__DIR__"gate");
	if(objectp(room))
	{
		set("exits/south", __DIR__"gate");
		message_vision("$N用力把大门打了开来。\n", this_player());
		room->set("exits/north", __FILE__);
		message("vision", "吱地一声，里面有人把大门打开了。\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}
	return 1;
}
string look_gate()
{
	return "一道三丈来高的朱红杉木包铜大门。\n";
}
int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "south" ) return 0;
	return ::valid_leave(me, dir);
}