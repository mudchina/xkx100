// houyuan.c 财主后院

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "财主后院");
	set("long", @LONG
这里是财主后院，各种古玩琳琅满目，商周的青铜、汉瓦当、唐三
彩……，应有尽有，只要拥有一件，就够你吃一辈子了。崔员外正坐在
琉璃榻上，慢悠悠地喝着参汤。东侧有一扇门(men)。
LONG );
	set("item_desc", ([
		"men" : "这扇门似乎通向一间密室。\n",
	]));
	set("exits", ([
//		"east" : __DIR__"dongxiang",
		"south" : __DIR__"dayuan",
		"west" : __DIR__"xixiang",
	]));
	set("objects", ([
		__DIR__"npc/cui" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", -13);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_unlock", "unlock");
	if (present("cui yuanwai", environment(this_player())))
		delete("exits/east");
}
int do_unlock(string arg)
{
	object ob;
	if (query("exits/east"))
		return notify_fail("这扇门已经是打开的。\n");
	if (!arg || (arg != "men" && arg != "east"))
		return notify_fail("你要打开什么？\n");
	if (!(ob = present("laofang key", this_player())))
		return notify_fail("你不会撬锁。\n");
	set("exits/east", __DIR__"dongxiang");
	message_vision("$N用一把钥匙打开了秘门，可是钥匙却断了。\n", this_player());
	destruct(ob);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("cui yuanwai", environment(me))) && 
                     dir == "west" && living(present("cui yuanwai", environment(me))))
		return notify_fail("崔员外挡住了你。\n");
	return ::valid_leave(me, dir);
}