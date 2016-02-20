//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "东楼");
	set ("long", @LONG
上得楼来，只见中间靠窗放着一张大书桌，放着笔墨纸砚与十来本
书，还有一件缝了一半的小孩衣衫。这是万家公子万圭住的地方。
LONG);
	set("exits", ([
		"down"  : __DIR__"ketang",
	]));
	set("objects", ([
		__DIR__"npc/wangui"    : 1,
		__DIR__"obj/lianpen"    : 1,
	]));
  
	set("coor/x", -1487);
	set("coor/y", 2040);
	set("coor/z", 10);
	setup();
}
void init()
{
	add_action("do_put","put");
	add_action("do_put","jin");
	add_action("do_put","fang");
}
int do_put(string arg)
{
	object ob, me = this_player();
	if (arg != "tangshi book")
		return notify_fail("你要把什么浸到脸盆中去？\n");
	if (! objectp(ob = present("tangshi book", me)))
		return notify_fail("你没有这本书。\n");
	message("vision", me->name()+"把唐诗选辑浸到脸盆中去，书上慢慢显示出数字来。哇！唐诗剑法！\n", environment(me));
	destruct(ob);
	ob = new("/clone/book/tangshi_book");
	ob->move(me);
	return 1;
}