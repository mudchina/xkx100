//room: huanyuan.c
inherit ROOM;
void init();
int do_move(string arg);
int do_enter(object me);

void create()
{
	set("short","花园");
	set("long",@LONG
你的眼前出现了一个美丽的花园，花园里种着一些花，花从中隐约
可见飘渺的倩影，那是宫中的姐妹们在玩耍。花园中央有一座假山(jiashan)。
花园的东西两头是长廊，北边有一条小道通向天山童姥修练之处。
LONG );
	set("exits",([
		"west"  : __DIR__"changl1",
		"east"  : __DIR__"changl2",
		"north" : __DIR__"xiaodao1",
		"south" : __DIR__"changl15",
	]));
	set("outdoors", "lingjiu");
	set("item_desc", ([
		"jiashan" : "这座假山看起来不算太大，你应该可以搬动(move)它.\n",
	]));
	set("objects",([
		__DIR__"npc/lu" : 1,
		__DIR__"npc/zhang" : 1,
	]));
	set("coor/x", -51000);
	set("coor/y", 30150);
	set("coor/z", 70);
	setup();
}

void init()
{
	add_action("do_move", "move");
	add_action("do_enter", "enter");
}

int do_move(string arg)
{
	object me=this_player();
	if(!arg || arg!="jiashan")
		return notify_fail("你要移动什么？\n");
	if((int)me->query_str()>28)
	{
		message_vision("$N使出吃奶的力气把假山挪开,只见下面露出一个大洞，似乎可以进去(enter)。\n", this_player());
		set("move_jiashan",1);
	}
	else
		message_vision("$N使出吃奶的力气也挪不动假山，只好悻悻地放弃了。\n", this_player());	
	return 1;	
}

int do_enter(object me)
{
	object room;
	object where;
	me=this_player();
	where=environment(me);
	if(!where->query("move_jiashan"))
		return notify_fail("你要进哪去？\n");
	if (me->is_busy()) return notify_fail("你正忙着呢。\n");
	if(!( room = find_object(__DIR__"midao1")) )
		room = load_object(__DIR__"midao1");
	message_vision("$N“咕咚”一声，跳进洞中。\n",me);
	me->move(room);
	set("move_jiashan",0);
	return 1;
}