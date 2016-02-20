// Room: /d/xingxiu/kezhan.c
// Last Modified by winder on Apr. 25 2001

inherit ROOM;

void create()
{
	set("short", "客栈");
	set("long", @LONG
这里是伊犁城的客栈，门口放有一个大茶桶(tong)，有免费的茶水
供应，客站里的小姑娘正在买烤熟的羊肉。你如果累了可以到楼上睡一
觉。
LONG);
	set("resource/water", 1);
	set("exits", ([ 
		"up"    : __DIR__"kezhan2",
		"south" : __DIR__"yili",
		"east"  : __DIR__"majiu",
	]));
	set("item_desc", ([
	      "tong" : "一只装满茶水的大茶桶，你可以舀(drink)起来喝。\n"
	]) );
	set("objects", ([
//		__DIR__"npc/caiyaoren1" : 1    
	]));
	set("coor/x", -39000);
	set("coor/y", 13100);
	set("coor/z", 0);
	setup();
	"/clone/board/kedian14_b"->foo();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_drink", "drink");
}
int do_drink(string arg)
{
	int current_water;
	int max_water;
	object me;

	me = this_player();
	current_water = me->query("water");
	max_water = me->query("str")*10 + 100;
	if (current_water<max_water)
	{
		me->set("water", current_water+30);
		message("vision", me->name()+"用茶勺从茶桶中舀了一口茶水来喝。\n", environment(me), ({me}) );
		write("你舀了一口桶中的茶水来喝。\n");
	}
	else write("你再也喝不下了。\n");
	return 1;
}
