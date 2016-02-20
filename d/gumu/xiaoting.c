// xiaoting.c 小厅
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "小厅");
	set("long", @LONG
这里是一个小小的厅堂。你走到这里，周围的光线亮了一些，你发
觉壁上燃点着一些油灯。厅里的布置整洁而不简陋，一桌一椅都收拾的
井井有条。南面有一扇石门(door)。
LONG	);
	set("exits", ([
		"west"  : __DIR__"mudao09",
		"east"  : __DIR__"mudao12",
//		"south" : __DIR__"mudao11",
	]));
	set("item_desc", ([
		"door" : "一扇厚重的石门，光溜溜的全没有把手。你认真看了看，发现门边的石壁上似乎有什么按钮(niu)可以开门。\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", -20);
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
	if( query("exits/south"))
	{
		return notify_fail("石门已经是开着的，你还按个啥？\n");
	}
	if( me->query_skill("yunv-xinfa", 1) > 10)
	{
		message_vision("$N站在石门前，也不知在哪里按了一下，石门吱吱响着，缓缓打开了。\n", me);
		if( !(room = find_object(__DIR__"mudao11")) )
			room = load_object(__DIR__"mudao11");
		set("exits/south", __DIR__"mudao11");
		room->set("exits/north", __DIR__"xiaoting");
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
	delete("exits/south");
	if( !(room = find_object(__DIR__"mudao11")) )
		room = load_object(__DIR__"mudao11");
	room->delete("exits/north");
	tell_room(room,"北墙的石门缓缓地关上了。\n");
}
