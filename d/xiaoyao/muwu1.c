// muwu1.c
// Modified by Winder June.25 2000

inherit ROOM;
int do_move(string arg);

void create()
{
	set("short", "木屋");
	set("long", @LONG
这里是一间不大的木头屋子，但是麻雀虽小，五脏俱全，屋子中只
是疏疏落落地摆着一张桌子和几张小凳，靠墙放着一个大柜子(gui)，
所以也不显得怎么小。
LONG );
	set("exits", ([
		"north" : __DIR__"xiaodao5",
	]));
 	set("objects", ([
		CLASS_D("xiaoyao")+"/kangguangling": 1,
	]));
	set("item_desc", ([
		"gui"   : "一座挺破旧的高柜。\n",
	]));
	set("coor/x", 80);
	set("coor/y", -520);
	set("coor/z", 0);
	setup();
}

void init()
{
        add_action("do_move","move");
}

int do_move(string arg)
{
	object me = this_player();

	if(!arg || arg!="gui") return 0;
	if (me->is_busy() || me->is_fighting()) return notify_fail("你正忙着呢。\n");
	if(me->query_skill("construction", 1) < 10)
		return notify_fail("你的土木机关还不够精熟，没法打开高柜机关。\n");
	message_vision("$N用力把高柜移开，发现里面竟然有一条秘密通道！\n",me);
	me->move(__DIR__"midao3");
	tell_object(me,"接着是一阵轰隆隆的响声，你定神一看，自己已经处身在秘密通道中了。\n");
	return 1; 
}
