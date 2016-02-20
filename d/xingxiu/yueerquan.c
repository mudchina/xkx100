// Room: /d/xingxiu/yueerquan.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "月儿泉");
	set("long", @LONG
出乎你的意料之外，在浩瀚沙漠中竟然有的泉水，一泓清澈的泉水
形成一个月牙的形状，因而得名月儿泉。涟漪萦回，水草丛生，清澈见
底。这里出产铁背鱼、七星草，但不常见。此泉虽在流沙山群中，风起
沙飞，均绕泉而过，从不落入泉内。北面是一片峭壁(cliff) ，东边传
来嗡嗡的声响。
LONG );
	set("outdoors", "qilian");
	set("resource/water", 1);
	set("exits", ([
		"southup" : __DIR__"shashan",
		"east"    : "/d/qilian/loulan",
	]));
	set("item_desc", ([
		"cliff" : "峭壁上似乎有一个洞(hole)。\n"
	]) );
	set("no_clean_up", 0);
	set("coor/x", -20310);
	set("coor/y", 200);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_enter", "enter");
}
int do_enter(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="hole" )
	{
		if(me->query_encumbrance()*100/me->query_max_encumbrance()< 20)
		{
			message("vision", me->name() + "一纵身跃进了洞里。\n", environment(me), ({me}) );
			me->move("/d/xingxiu/mogaoku");
			message("vision", me->name() + "从洞外跳了进来。\n", environment(me), ({me}) );
			return 1;
		}
		else
		{
			write("你身上背的东西太重，洞口又太高，你够不着。\n");
			return 1;
		}
	}
}
