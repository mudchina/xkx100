// mudao06.c 墓道
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"墓道"NOR);
	set("long", @LONG
这里是古墓中的墓道，四周密不透风，借着墙上昏暗的灯光，你能
勉强分辨出方向。墙是用整块的青石砌合起来的，接合得甚是完美，难
以从中找出一丝缝隙。灯光照在青石壁上，闪烁着碧幽幽的光点。
    东边石壁上似乎有一扇暗门(door)。
LONG	);
	set("exits", ([
		"west" : __DIR__"zhongting",
//		"east" : __DIR__"houting",
	]));
	set("item_desc", ([
		"door" : "一扇厚重的石门，光溜溜的全没有把手。你认真看了看，发现门边的石壁上似乎有什么按钮(niu)可以开门。\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3190);
	set("coor/y", 10);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_an", "press");
	add_action("do_an", "an");
}

int do_an(string arg)
{
	object room, me = this_player();

	if( !arg || arg != "niu" )
	{
		message_vision("你在石壁上乱按一气，除了一手灰，啥也没摸着。\n", me);
		return 1;
	}
	if( query("exits/east"))
	{
		return notify_fail("石门已经是开着的，你还按个啥？\n");
	}
	if( me->query_skill("yunv-xinfa", 1) > 10)
	{
		message_vision("$N站在石门前，也不知在哪里按了一下，石门吱吱响着，缓缓打开了。\n", me);
		if( !(room = find_object(__DIR__"houting")) )
			room = load_object(__DIR__"houting");
		set("exits/east", __DIR__"houting");
		room->set("exits/west", __DIR__"mudao06");
		tell_room(room,"只听得石门在吱吱声中被缓缓打开。\n");
		remove_call_out("close");
		call_out("close", 5, me);
	}
	else
		message_vision("$N试着在石壁上按来按去，可是石门纹丝不动，只得罢了。\n", me);
	return 1;
}

void close(object me)
{
	object room;

	tell_room(this_object(), "石门缓缓地关上，恢复了原状。\n");
	delete("exits/east");
	if( !(room = find_object(__DIR__"houting")) )
		room = load_object(__DIR__"houting");
	room->delete("exits/west");
	tell_room(room,"西墙的暗门缓缓地关上了。\n");
}
