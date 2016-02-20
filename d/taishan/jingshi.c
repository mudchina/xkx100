// Room: /d/taishan/jingshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
int do_study(string arg);

void create()
{
	set("short", "经石峪");
	set("long", @LONG
这里是一块大石坪，石面刻有篆文「金刚经」，字体其大如斗，但
却没有记载刻石者的名字和刻石的年代。经石峪四面环山，深谷幽奥。
龙泉峰耸峙于东，锐若茁笋；炮高岭横亘于西；涧水自东北三叉沟乱石
中泠泠而出，绕龙泉峰流入中溪。
LONG );
	set("exits", ([
		"westdown"  : __DIR__"doumo",
		"northwest" : __DIR__"shijian",
	]));
	set("objects",([
		__DIR__"npc/seng-ren" : 1,
	]));
	set("outdoors", "taishan");
	set("coor/x", 410);
	set("coor/y", 600);
	set("coor/z", 60);
	setup();
}

void init()
{
	add_action("do_study", "study");
	add_action("do_study", "du");
}


int do_study(string arg)
{
	object me;

	me = this_player();

	if ( !arg || ( arg != "stone" ) )
		return notify_fail("什么？\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

	if ( (int)me->query("jing")<40)
		return notify_fail("你现在太累了，什么也没学进去。\n");

	me->receive_damage("jing", 30);

	message_vision("$N正专心研读石坪上的「金刚经」。\n", me);

	if ( (int)me->query_skill("buddhism", 1) < 100)
	{
		me->improve_skill("buddhism", me->query("int"));
		write("你对着石坪上的「金刚经」琢磨了一回儿，似乎对禅宗心法略有心得。\n");
		return 1;
	}

	write("你对着石坪瞧了一回儿，发现上面所说的佛理太过浅显，对你来说已毫无意义了。\n");

	return 1;
}
