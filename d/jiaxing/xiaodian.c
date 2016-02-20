// Room: /d/jiaxing/xiaodian.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

int do_move(string);
int do_turn(string);

void create()
{
	set("short", "小酒店");
	set("long", @LONG
这是一家已经废弃了的小酒店，柜台上积满了灰，一个角落里堆着
一大堆干草，旁边斜躺着一个大铁叉；柜台后的橱架上凌乱地放着几摞
破旧的青花瓷碗(wan)。在门前坐着一个梳着朝天辫的小姑娘。
LONG
	);

	set("item_desc", ([
		"wan"      : "一堆很凌乱地散放着的碗。\n",
		"bowl"     : "一堆很凌乱地散放着的碗。\n",
		"tiewan"   : "一只奇怪的碗，好象是固定在了架子上。\n",
		"ironbowl" : "一只奇怪的碗，好象是固定在了架子上。\n",
	]) );

	set("exits", ([
		"north" : __DIR__"njroad1",
	]));

	set("objects", ([
		__DIR__"npc/shagu": 1,
	]));

	set("coor/x", 1560);
	set("coor/y", -1060);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_move","move");
	add_action("do_move","yi");
	add_action("do_turn","turn");
	add_action("do_turn","zhuan");
}

int do_move(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");
	if (arg == "wan" || arg == "bowl")
	{
		write( "你将架子上的碗使劲地摔到地上去，却发现有一只碗竟然拿不起来。仔细一看，才发现这是一只铁碗(tiewan)！\n");
		me->set_temp("mishi_temp",1);
		return 1;
	}
	return notify_fail("你要搬动什么？\n");
}

int do_turn(string arg)
{
	int temp;
	object me = this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");
	if (arg == "tiewan left" || arg == "tiewan zuo")
	{
		temp = me->query_temp("mishi_temp");
		if (!temp) return 0;
		if (temp < 4) temp++;
		else temp = 1;
		write("你将铁碗用劲地向左扳动，发出了“咯吱”的声音。\n");
		me->set_temp("mishi_temp",temp);
		return 1;
	}
	if (arg == "tiewan right" || arg == "tiewan you")
	{
		temp = me->query_temp("mishi_temp");
		if (!temp) return 0;
		if (temp > 3) temp++;
		else temp = 1;
		write("你将铁碗用劲地向右扳动，发出了“咯吱”的声音。\n");
		if (temp == 7)
		{
			write( "只听“喀啦”一声巨响，你的眼前出现了一道门。你毫不犹豫的走了进去。\n");
			message("vision","橱架后面忽然现出一道暗门，" + me->name() + "举步走了进去，橱架吱呀呀地又关上了。\n", this_object(), me);
			me->delete_temp("mishi_temp");
			me->move(__DIR__"mishi");
			message("vision", me->name() + "打开暗门，走了进来。\n", environment(me), me);
		}
		else me->set_temp("mishi_temp",temp);
		return 1;
	}
	return notify_fail("你要做什么？\n");
}