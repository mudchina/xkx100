// Room: /d/kunlun/pubu.c
// Last Modified by winder on Jun. 29 2001

inherit ROOM;
void create()
{
	set("short", "瀑布");
	set("long", @LONG
向西走了二里多，只见峭壁上有一道大瀑布冲击而下，料想是雪融
而成，阳光照射下尤如一条大玉龙，极是壮丽。瀑布泄在一座清澈碧绿
的深潭(tan )之中，潭水却也不见满，当是另有泄水的去路。你观赏了
半晌，一低头，见手足上染满了清苔污泥，另有无数给荆棘硬草割破的
血痕，於是走近潭边，除下鞋袜，伸足到潭水中去洗涤(xidi)。
LONG );
	set("outdoors", "hongmei");
	set("exits", ([
		"east" : __DIR__"cuigu",
	]));
	set("no_clean_up", 0);
	set("fish_count",2);
	set("item_desc", ([
		"tan": "你附身潭边，凝神瞧去，只见碧绿的水中十馀条大白鱼来回游动。\n",
	]));
	set("coor/x", -100020);
	set("coor/y", 20050);
	set("coor/z", 40);
	setup();
}
void init()
{
	add_action("do_xidi", "xidi");
}
int do_xidi()
{
	object fish, me = this_player();
	if ((this_player()->query_dex()<25) || query("fish_count")<=0)
		message_vision("$N洗了一会，突然泼喇一声，潭中跳起一尾大白鱼，足有一尺多\n长，$N忙伸手去抓，虽然碰到了鱼身，却一滑滑脱了。\n", me);
	else
	{
		message_vision("$N洗了一会，突然泼喇一声，潭中跳起一尾大白鱼，足有一尺多\n长，$N忙伸手去抓，一把把它攥在手心。\n", me);
		add("fish_count",-1);
	}
	fish = new(__DIR__"obj/fish");
	fish -> move(me);
	return 1;
}

