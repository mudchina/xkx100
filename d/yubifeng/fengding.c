// /yubifeng/fengding.c
// Last modified by winder 2003.9.2

int do_enter(string arg);

inherit ROOM;

void create()
{
	set("short", "玉笔峰");
	set("long", @long
只见山峰旁好大三个绞盘，互以竹索牵连，三盘互绞，升降竹篮，
需要上下的人等，只能在竹篮(basket)中上下。
long );
	set("exits", ([
		"east" : __DIR__"damen",
	]));
	set("item_desc", ([
		"basket" : "那是一个竹篮，好象是装人下山的。\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yubifeng");
	set("coor/x", 6110);
	set("coor/y", 5170);
	set("coor/z", 100);
	setup();
}

void init()
{
	add_action("do_enter", "enter");
	add_action("do_enter", "zuan");
	add_action("do_enter", "jin");
}

int do_enter(string arg)
{
	object me = this_player();

	if( arg != "basket")
		return notify_fail("你要往那里钻？\n");
	message_vision("$N哈腰钻进竹篮，只听“嗖”地一声，绞盘转动，竹篮被急速放了下去。\n\n....\n\n只见眼前白雪耀眼，白云飞动\n\n....\n\n", me);
	me->move(__DIR__"fengdi");
	return 1;
}
