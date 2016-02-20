// Room: /d/tiezhang/zoulang4.c
// Last Modified by winder on Nov. 17 2000

#include <room.h>
inherit ROOM;
int have_man();
void create()
{
	set("short", "走廊");
	set("long", @LONG
你走在一条走廊上。北面似乎有个黑暗的小屋，还隐隐传来一些酣
声。东面是铁掌帮众的练功场。
LONG );
	set("exits", ([ 
		"west" : __DIR__"zoulang1",
		"east" : __DIR__"wuchang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -2020);
	set("coor/y", -1960);
	set("coor/z", 30);
	setup();
}
void init()
{
	   add_action("do_tui", "push");
	   add_action("do_tui", "tui");
}

int close_men()
{
	object room;

	if(!( room = find_object(__DIR__"xxs")) )
		room = load_object(__DIR__"xxs");
	if(objectp(room))
	{
		delete("exits/north");
		message("vision", "门吱吱呀呀地自己合上了。\n", this_object());
		room->delete("exits/south");
		message("vision", "门吱吱呀呀地自己合上了。\n", room);
	}
	else message("vision", "ERROR: men not found(close).\n", room);
}

int do_tui(string arg)
{
	object room;

	if (!living(this_player())) return 0;
	if (query("exits/north"))
		return notify_fail("门已经是开着了。\n");

	if (arg != "door" && arg != "men")
		return notify_fail("你要做什么？\n");

	if(!(room = find_object(__DIR__"xxs")))
		room = load_object(__DIR__"xxs");

	if(objectp(room))
	{
//	if (!have_man())
//	{
		set("exits/north", __DIR__"xxs");
		message_vision("$N轻轻地把门推开。\n", this_player());
		room->set("exits/south", __FILE__);
		remove_call_out("close_men");
		call_out("close_men", 10);
//	}
	}
	return 1;
}
/*
int have_man()
{
	object *ob = all_inventory(load_object(__DIR__"xxs"));
	int i, ret = 0;

	if (!ob) return 0;
	for (i = 0;i < sizeof(ob);i++)
	{
		if (!interactive(ob[i])) continue;
		if (living(ob[i])) return 1;
		ret = -1;
	}
	return ret;
}
*/
