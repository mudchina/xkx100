// /yubifeng/shimen.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "石门");
	set("long", @LONG
洞穴愈来愈窄，须得弓身而行方能通过，洞中到处是千年不化的尖
冰，有些处所的冰条如刀剑般锋锐突出。有时头顶撞上了坚冰尖角，隐
隐生疼。通道尽头，只见一块圆形巨岩叠在另一块圆岩上，两块巨岩封
住了去路，俨然一座石门。两岩(yan)之间都是坚冰(bing)凝结。
LONG );
	set("exits", ([
		"south" : __DIR__"tongdao2",
	]));
	set("objects", ([
		__DIR__"npc/huyidao" : 1,
		__DIR__"npc/hu-wife" : 1,
	]));
	set("item_desc", ([
		"yan"  : "这是两块封闭通道的巨岩。\n",
		"bing" : "冻结巨岩的冰层，晶莹剔透，看来不是一时一日而成。\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", 6110);
	set("coor/y", 5130);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_push", "tui");
	add_action("do_push", "push");
	add_action("do_burn", "use");
	add_action("do_burn", "burn");
	add_action("do_burn", "shao");
}

int do_burn(string arg)
{
	object ob, me = this_player();

	if( !arg || arg=="" ) return 0;
	if (!present("fire", me)) return 0;
	if (!objectp(ob = present("mu chai", me))) return 0;
	if( arg=="yan" )
	{
		message_vision("$N点起木柴，去烧二岩之间的坚冰。\n火焰越烧越大，冰化为水，只听得叮钉之声不绝，一块块碎冰落在地下。\n", me);
		destruct(ob);
		if (me->query("neili",1) > 1000)
		{
			message_vision("眼见二岩之间的坚冰已融去大半，$N发力推挤，那巨岩幌了几幌，竟慢慢转将过去，露出一道空隙，宛似个天造地设的石门一般。\n", me);
			set("exits", ([
				"enter" : __DIR__"baozang",
				"south" : __DIR__"tongdao2",
			]));
		}
		else
		{
			message_vision("$N双手在巨岩上运力一推，那岩石毫不动弹。\n", me);
		}
	}
	else
	{
		write("你要在这个冰窟窿里点火干什么？\n");
	}
	return 1;
}

int do_push(string arg)
{
	object me = this_player();

	if (!arg || arg !="yan")
	{
		message_vision("这里地方这么小，推什么呀！\n", me);
		return 1;
	}
	else
	{
		message_vision("$N伸手抵在巨岩上，运足内力就是这么一推，结果纹丝不动。\n", me);
		return 1;
	}
}
