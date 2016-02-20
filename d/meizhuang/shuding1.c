// /d/meizhuang/shuding1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "松树顶");
	set("long", @LONG
你终于爬上了松树的顶端，在这里你可以看见一片密密厚厚的树林，
你踩在这里，如同踩在一块草地上一样，远处可以看见隐隐约约的一座
巍峨的高山。
LONG
	);
	set("book_count",1);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"senlin1",
	]));
	set("item_desc", ([ /* sizeof() == 1 */
		"song zhen" : "这块地方的松针看起来和其他地方的不太一样。",
		"松树"      : "这块地方的松针看起来和其他地方的不太一样。",
	]));
	set("outdoors", "meizhuang");
	set("no_clean_up", 0);

	set("coor/x", 3500);
	set("coor/y", -1400);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_pull", "pull");
}
int do_pull(string arg)
{
	object me , ob;
	me = this_player();
	if (arg == "song zhen" &&
		!present("qinpu", me) &&
		query("book_count") >= 1)
	{
		add("book_count", -1);
		ob=new(BOOK_DIR"qinpu");
		ob->move(__DIR__"shuding1");
		message_vision("$N轻轻的掀开厚厚的松针，哇，下面居然有一本书。\n", me);
		return 1;
	}
	else {
		me->receive_damage("qi", 20);
		message_vision("$N的手已经被松针扎得鲜血淋淋，不要再掀了。\n", me);
		return 1;
	}
}
