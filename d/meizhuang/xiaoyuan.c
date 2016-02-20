// /d/meizhuang/xiaoyuan.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "琴音小院");
	set("long", @LONG
这是一座看起来非常普通的小小的院落，院子的中间建着一间小屋，
小屋也很普通，就是用茅草为顶，砖土为墙，院子里没有什么摆设，只
有几堆干木柴(wood)放在角落里，其中有一捆特别引人注目。 
LONG
	);
	set("weapon_count",1);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"xiaodao",
		"enter" : __DIR__"xiaowu",
	]));
	set("item_desc",([
		"wood" : "一大堆干柴，其中有一捆的颜色比较特别。\n",
	]));
	set("objects", ([
		__DIR__"npc/ding" : 1,
	]));
	set("outdoors", "meizhuang");

	set("coor/x", 3510);
	set("coor/y", -1430);
	set("coor/z", 20);
	setup();
}
void init()
{
	add_action("do_pull", "pull");
	add_action("do_unlock", "unlock");
	if (present("ding jian", environment(this_player())))
		delete("exits/east");
}
int do_unlock(string arg)
{
	object ob;
	if (query("exits/east"))
		return notify_fail("这扇门已经是打开的。\n");
	if (!arg || (arg != "men" && arg != "east"))
		return notify_fail("你要打开什么？\n");
	if (!(ob = present("hongyu yaoshi", this_player())))
		return notify_fail("你不会撬锁。\n");
	set("exits/east", __DIR__"mishi2");
	message_vision("$N把红玉钥匙放进门的凹陷处，东边的一扇门无声的打开了。\n", this_player());
	destruct(ob);
	return 1;
}
int do_pull(string arg)
{
	object ob, me = this_player();
	if (arg == "wood" && !present("sea-wood", me) &&
		query("weapon_count") >= 1)
	{
		add("weapon_count", -1);
		ob=new(WEAPON_DIR"treasure/sea-wood");
		if ( ob->violate_unique() )
		{
			destruct( ob );
			message_vision("$N找了半天，也没有发现什么特别的东西。\n", me);
			return 1;
		}
		ob->move(__DIR__"xiaoyuan");
		message_vision("$N在木柴堆里拨弄着，一根剑形的木棒掉了出来。\n", me);
		return 1;
	}
	else {
		message_vision("$N找了半天，也没有发现什么特别的东西。\n", me);
		return 1;
	}
}
