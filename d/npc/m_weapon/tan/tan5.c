//tan5.c

inherit ROOM;
void init();
int do_push(string);
void create()
{
	set("short", "嘉兴南湖 ");
	set("long",
		"这里是嘉兴南湖底，四周黑忽忽的，头顶上看不见一点亮光，身边的水流\n"
		"忽上忽下的涌动着。看起来是一处海眼。东边似乎有一点亮光，被一块巨大\n"
		"的石块(stone)挡着。周围一片死寂，似乎暗藏着层层杀机。\n"

	);
	set("exits", ([
		"up" : __DIR__"tan6",	
		"west" : __DIR__"tan7",
		"south" : __DIR__"tan7",
		"north" : __DIR__"tan7",
	]));
	set("item_desc", ([
		"stone": 
"\n这是一块巨大的石头，看起来质地是玄武岩的，显得十分的坚硬。你用手试着推了一把\n"
"(push)，石头动了一下，马上又回到原地了。从移开一瞬间，你恍惚看见几缕光线从里\n"
"面投射出来。看来里面一定别有一番洞天。\n"
	]) );
	set("no_clean_up", 0);
	set("coor/x", -1520);
	set("coor/y", -1020);
	set("coor/z", -40);
	setup();
}

void init()
{	
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player();
	object room;

	if ((arg !="stone" || !arg))
		return notify_fail("你要推什么？\n");
	if ((int)me->query_skill("dodge") < 50 ) {
		me->add_temp("tmark/金",1);
		write("忽然一道暗流冲来，你脚下一个踉跄，大叫一声：不好！\n");
		message("vision","前面的人影身行猛然一晃，急剧向下坠去。看来是凶多吉少了!\n",
			environment(me), ({me}) );
		me->unconcious();
		me->move("/d/taohua/haitan");
		message_vision("海浪一阵翻涌，砰的一个人被抛了上来。\n", me);
		return 0;
	}
	
	if (!( room = find_object(__DIR__"cave")) )
		room = load_object(__DIR__"cave");
	if (!query("exits/east"))
		{
		set("exits/east", __DIR__"cave");
		message_vision("$N把巨石推到一边，露出一个洞口，里面幽幽的有些光亮。\n",me);
		room -> set("exits/west", __FILE__);
		message("vision", "外面传来一阵移动巨石的隆隆的响声。\n",room);
		}
	else
	{
		delete("exits/east");
		message_vision("水流一阵涌动，巨石轰隆一声滚回了原处，洞口又被封住了。\n",me);
		room -> delete("exits/west");
		message("vision","外面传来一声巨响，洞口被封住了。\n", room);
	}
	return 1;
}
