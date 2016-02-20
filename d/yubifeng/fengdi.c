// /yubifeng/fengdi.c
// Last modified by winder 2003.9.2

int do_climb(string arg);

inherit ROOM;

void create()
{
	set("short", "玉笔峰下");
	set("long", @long
这座松林好长，走了半个时辰方始过完，一出松林，即到一座山峰
脚下。山峰(feng)虽非奇高，但宛如一根笔管般竖立在群山之中，陡削
异常，壁立千仞，非同小可。莫说是人，即令猿猴也是不易上去。	
long );
	set("exits", ([
		"west" : __DIR__"songlin5",
	]));
	set("item_desc", ([
		"feng" : "山峰覆盖坚冰，光洁晶莹，滑不留手，难以攀爬。\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yubifeng");
	set("coor/x", 6110);
	set("coor/y", 5170);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_climb","climb");
	add_action("do_climb","pa");
}

int do_climb(string arg)
{
	object me = this_player();
	int n;

	n = me->query_skill("dodge", 1);

	if ( !arg || arg != "feng")
	{
		write("你要爬什么呀？\n");
		return 1;
	}
	message_vision("$N深吸了一口气，运起壁虎游墙功，沿着崖壁向上爬。\n",me);
	if(n > 140 && me->query("qi") > 1400)
	{
		message_vision("\n .... \n\n .... \n\n$N爬了半天，终于爬了上来，$N不禁站在峰顶，俯视群峰，长长出了一口气。\n\n", me);
		me->move(__DIR__"fengding");
	}
	else
	{
		message_vision("$N爬了一会，太累了，无奈滑了下来。\n", me);
		me->receive_damage("qi",15);
		me->receive_wound("qi",10);
	}
	return 1;
}
