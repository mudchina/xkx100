// mudao01.c 墓道
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
LONG	);
	set("exits", ([
		"north" : __DIR__"mumen",
		"south" : __DIR__"qianting",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3220);
	set("coor/y", 20);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_move", "move");
	add_action("do_move", "luo");
	add_action("do_move", "tui");
}

int do_move(string arg)
{
	object room, me = this_player();

	if( !arg || arg != "shi" )
	{
		return notify_fail("你要移动什么？\n");
	}
	if( !query("exits/north"))
	{
		return notify_fail("降龙石已经落下，你还能移动什么？\n");
	}
	if((int)me->query_str()>33)
	{
		message_vision("$N站在降龙石前，双掌发力推动降龙石，只听得降龙石吱吱连声，缓缓向下落去，封住了墓门。\n", me);
		delete("exits/north");
		if( !(room = find_object(__DIR__"mumen")) )
			room = load_object(__DIR__"mumen");
		room->delete("exits/south");
		tell_room(room,"只听得降龙石吱吱连声，缓缓向下落去，封住了墓门。\n");
	}
	else
		message_vision("$N试着推了推巨石，巨石纹丝不动，只得罢了。\n", this_player());
	return 1;
}

