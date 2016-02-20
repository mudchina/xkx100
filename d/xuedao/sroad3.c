// sroad3.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
	set("short","山路");
	set("long",@LONG
这里是靠近川西的崇山峻岭，怪石嶙峋。再往东去就是川西边缘了。
往西有一座雪山高耸入云。路边上有一个大雪坑(hollow)。
LONG );
	set("exits",([
		"northwest" : "/d/lingxiao/boot",
		"eastdown"  : __DIR__"sroad2",
		"northdown" : __DIR__"nroad1",
		"westup"    : __DIR__"sroad4",
	]));
	set("objects",([
		__DIR__"npc/liuchengfeng" : 1,
	]));
	set("item_desc",([
		"hollow"  : "一个雪坑，似乎可以跳(jump)下去。\n"
	]));
	set("outdoors", "xueshan");
	set("no_clean_up", 0);
	set("coor/x", -30000);
	set("coor/y", -10000);
	set("coor/z", 50);
	setup();
}

void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object me = this_player();
	if( arg=="hollow")
	{
		message_vision("$N刚想往下跳，脚在雪地上一滑，卞叽一下摔到坑底。\n",me);
		me->move(__DIR__"hollow");
	}
	else
	{
		message_vision("$N跳了起来，脚在雪地上一滑就趴在地上了。\n",me);
	}
	return 1;
}
