// Room: /qingcheng/zoulang2.c
// Date: Aug. 10 1998 by Winder

inherit ROOM;
void create()
{
	set("short", "松风东廊");
	set("long", @LONG
这里是松风观中连贯操练场和东厢的走廊，松风观高矗山顶，从走
廊望去，青山鸟寂，幽谷风生，漫天薄雾时时弥散在长林翠竹之间。自
古号称：“青城天下幽”，不妨在此体味。这里的南边是书房，北边是
兵器室，东边一直关着门的是本派的库房。
LONG );
	set("outdoors", "qingcheng");
	set("exits", ([
		"west"  : __DIR__"caochang",
		"south" : __DIR__"shufang",
		"north" : __DIR__"bingqishi",
	]));
	set("objects", ([
		__DIR__"npc/hong" : 1,
	]));
	set("coor/x", -8070);
	set("coor/y", -840);
	set("coor/z", 90);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if((!myfam || myfam["family_name"] != "青城派") && dir != "west" &&
		objectp(present("hong renxiong", environment(me))))
	return notify_fail("洪人雄拦住你说：此处乃本派禁地，请止步。\n");

	if( me->query_skill("qingming-xuangong", 1) < 10 && dir != "west" &&
		objectp(present("hong renxiong", environment(me))))
	return notify_fail("洪人雄拦住你：师父交代，内功未臻小成不得入内。\n");

	return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_open", "open");
	add_action("do_open", "unlock");
}

void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"kufang")) )
		room = load_object(__DIR__"kufang");
	if(objectp(room))
	{
		delete("exits/east");
		message("vision","只听乒地一声，库门自动关了起来。\n",this_object());
		message("vision","你脑海中闪过一个念头：哎哟！又进不去了！\n", this_object());
		room->delete("exits/west");
		message("vision","只听乒地一声，库门自动关了起来。\n",room);
		message("vision","你脑海中闪过一个念头：坏了！出不去了！\n" , room);
	}
}

int do_open(string arg)
{
	object room;
	object ob;

	if (query("exits/east"))
		return notify_fail("库门已经是开着了。\n");

	if (!arg || (arg != "men" && arg != "east" && arg != "door"))
		return notify_fail("你要开什么？\n");
	if (!(ob = present("qingcheng key", this_player())))
		return notify_fail("你不会撬锁。\n");
	message_vision("$N用一把钥匙打开了库门。结果用力过猛，把钥匙拗断了。\n", this_player());

	if(!( room = find_object(__DIR__"kufang")) )
		room = load_object(__DIR__"kufang");
	if(objectp(room))
	{
		set("exits/east", __DIR__"kufang");
		message_vision("$N使劲把库门推了开来。\n",this_player());
		room->set("exits/west", __FILE__);
		message("vision","外面有人把库门推开了。\n",room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}

	return 1;
}