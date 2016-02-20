// Feb. 6, 1999 by Winder
inherit ROOM;
void init();
void close_door();
int do_open(string arg);
int do_close(string arg);
void create()
{
	set("short", "暗道尽头");
	set("long",@LONG
这里是暗道的尽头，有扇铁门(door)看起来很陈旧，不知道通往
哪里。
LONG		
	);
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"andao2",
	]));
	set("item_desc",([
		"door"	: "这是一扇破旧的铁门。\n"
	]));
	set("coor/x", 1620);
	set("coor/y", -1750);
	set("coor/z", -10);
	setup();
}
void init()
{
	add_action("do_open", "open");
	add_action("do_close", "close");
}
void close_door()
{
	object room;
	if(!( room = find_object("/d/shiliang/tingzi")) )
		room = load_object("/d/shiliang/tingzi");
	if(objectp(room))
	{
		delete("exits/east");
			message("vision", "忽然间，水流翻涌，又把门合上了。\n", this_object());
		room->delete("exits/west");
		message("vision", "水流又悠然合上了。\n", room);
	}
}
int do_close(string arg)
{
	if (!query("exits/east"))
		return notify_fail("已经没有出路了！\n");
	if (!arg || (arg != "door" && arg != "east"))
		return notify_fail("你要关什么？\n");
	message_vision("$N点了点头。\n", this_player());
	remove_call_out("close_door");
	call_out("close_door", 2);
	return 1;
}
int do_open(string arg)
{
	object room;
	if (query("exits/east"))
		return notify_fail("已经有出路了！\n");
	if (!arg || (arg != "door" && arg != "east"))
		return notify_fail("你要开什么？\n");
	if(!( room = find_object(__DIR__"tingzi")) )
		room = load_object(__DIR__"tingzi");
	if(objectp(room))
	{
		set("exits/east",__DIR__"tingzi");
		message_vision("$N用力把破铁门打了开来。\n", this_player());
		room->set("exits/west", __FILE__);
		message("vision", "忽然间，水流分开，露出一条出路。\n", this_object());
		remove_call_out("close_door");
		call_out("close_door", 2);
	}
	return 1;
}