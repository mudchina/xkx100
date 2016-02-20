// Room: /d/tiezhang/xxs.c
// Last Modified by winder on Nov. 17 2000

#include <room.h>
inherit ROOM;
void init();
int do_open();
int do_close();
void create()
{
	set("short", "休息室");
	set("long", @LONG
这是一个黑暗的大房间。窗户用厚厚的帘子遮住，不露丝毫光亮。
屋内整齐的排列着十几张木板搭成的床铺，可以让练功后的帮众及时得
到休息。这里静悄悄的，黑暗中偶尔传来清微的鼾声。
LONG );
	set("sleep_room", 1);
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("coor/x", -2020);
	set("coor/y", -1950);
	set("coor/z", 30);
	setup();
}

void init()
{
	add_action("do_tui", "tui");
	add_action("do_tui", "push");
}
void close_men()
{
	object room;

	if(!( room = find_object(__DIR__"zoulang4")) )
		room = load_object(__DIR__"zoulang4");
	if(objectp(room))
	{
		delete("exits/south");
			message("vision", "门吱吱呀呀地自己合上了。\n", this_object());
		room->delete("exits/north");
		message("vision", "门吱吱呀呀地自己合上了。\n", room);
	}
}
int do_tui(string arg)
{
	object room;
	object me = this_player();

	if (query("exits/south"))
		return notify_fail("大门已经是开着了。\n");

	if (arg != "men" && arg != "door" && arg != "south")
		return notify_fail("你要开什么？\n");

	if(!( room = find_object(__DIR__"zoulang4")) )
		room = load_object(__DIR__"zoulang4");
	if(objectp(room))
	{
		set("exits/south", __DIR__"zoulang4");
		message_vision("$N轻手轻脚地把门打开。\n", this_player());
		room->set("exits/north", __FILE__);
		
		if (me->query_temp("sleeped"))
		{
			message("vision", "吱地一声，"+me->query("name")+"从里面把门打开了。\n", room);
		} else 
		{
			message("vision", "吱地一声，"+me->query("name")+"从里面把门打开。\n", room);
		}	
		remove_call_out("close_men");
		call_out("close_men", 10);
	}

	return 1;
}
