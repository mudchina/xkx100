// Room: /d/yueyang/gaibangyuan.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "大院");
	set("long", @LONG
院子里很是破败，铺地的青砖处处开裂，围墙的瓦片也是残缺不全
的。丐帮威镇天下，总舵却如此不起眼，也正是丐儿本色。南面是一扇
大门，北边的大屋黑咕隆咚的。东西两厢的房间窗户尽是蜘蛛网，地上
铺着一把把的茅草，看来是丐帮人众休息场所。院子中央是一眼井台长
满青苔的古井(jing)，井壁倒是很光滑，似乎常有人在井中出入。
LONG );
	set("outdoors", "yueyang");
	set("exits", ([
		"north" : __DIR__"gaibangtang",
		"south" : __DIR__"gaibanggate",
	]));
	set("item_desc", ([
		"jing"  : "一口满是水光的深井。\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1420);
	set("coor/y", -2250);
	set("coor/z", 0);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
	object me = this_player();
	mapping fam;

	if( !arg || arg=="" ) return 0;

	if( arg=="jing" )
	{
		if((fam = me->query("family")) && fam["family_name"] == "丐帮" )
		{
			message("vision", me->name() + "运起丐帮缩骨功，一弯腰往井里跳了下去。\n", environment(me), ({me}) );
			me->move("/d/gaibang/underyy");
                	message("vision", me->name() + "从井里走了进来。\n", environment(me), ({me}) );
			return 1;
		}
		else return notify_fail("这么小的井，你钻得进去吗？\n");
	}
}	

