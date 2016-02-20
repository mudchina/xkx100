// Room: /d/nanshaolin/fanting3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

string* names = ({
	FOOD_DIR+"mizhi-tianou",
	FOOD_DIR+"jiaxin-biji",
	FOOD_DIR+"basi-shanyao",
	FOOD_DIR+"furong-huagu",
});

void create()
{
	set("short", "饭厅");
	set("long", @LONG
这里便是少林全寺寺僧用斋的地方。饭厅极大，足可容纳上千人同
时进膳。从东到西一排排摆满了长长的餐桌和长凳，几位小和尚正来回
忙碌着布置素斋。桌上摆了几盆豆腐，花生，青菜以及素鸭等美味素食。
在桌子的一端有一面很小的铜锣(luo)。东面是个厨房。
LONG
	);
	set("exits", ([
		"north" : __DIR__"fanting1",
		"east"  : __DIR__"chufang2",
	]));
	set("item_desc", ([
		"luo" : "这是一面铜制的小锣，是僧人们召唤侍斋的小沙弥用的。\n",
	]));
	set("objects",([
		__DIR__"npc/xiao-nan3" : 1
	]));
	set("coor/x", 1850);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_tap", "qiao");
	add_action("do_tap", "knock");
	add_action("do_zuo", "zuo");
	add_action("do_zuo", "sit");
}

int do_tap(string arg)
{
	object me = this_player();
	object cui;
	if (!arg || (arg != "luo"))
	{
		return notify_fail("你要敲什么？\n");	
	}
	if( !objectp(cui = present("xiao shami", environment(me))) )
	 	return notify_fail("你敲了一下小锣，却发现没人理你。\n");
	if( !me->query_temp("marks/sit") )
		return notify_fail("你敲了一下小锣，锣声在饭厅内回荡，你突然感觉自己很愚蠢。\n");
	if( me->query_temp("marks/served") )
	{
		message_vision("小沙弥对$N说道：我少林寺虽物产甚丰，可也不能象你这样吃呀！！！\n", me);
		return notify_fail("");
	}
	message_vision("$N端坐在桌前，轻轻敲了一下桌上的小锣，小沙弥弓身作了个揖，过来招呼。\n", me);
	cui->serve_food(me) ;
	me->set_temp("marks/served", 1);
	remove_call_out("delete_served");
	call_out("delete_served", 10, me);

	return 1;
}

void delete_served(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/served");
}

int do_zuo(string arg)
{
	if ( !arg || (arg != "changdeng" && arg != "chair") )
		return notify_fail("你要坐什么上面？\n");	
	if (this_player()->query_temp("marks/sit"))
		return notify_fail("你已经有了个座位了。\n");	
	this_player()->set_temp("marks/sit", 1);
	return notify_fail("你找了个空位座下。\n");	
}

int valid_leave(object me, string dir)
{
	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");
	return ::valid_leave(me, dir);
}

