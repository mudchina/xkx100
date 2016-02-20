// /d/xingxiu/silk4.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "丝绸之路");
	set("long", @LONG
这是一条中原和西域之间的商道。西面是一望无际的大沙漠，传说
那里常有盗匪出没。西北则通向一片连绵的山脉，东面就是通向中原的
路。路边有一块石碑(shibei)。
LONG );
	set("outdoors", "xiyu");
	set("exits", ([
		"southeast" : __DIR__"tugu",
		"west"      : __DIR__"shamo1",
		"northwest" : __DIR__"shanjiao",
		"southwest" : "/d/xueshan/caoyuan" ,
	]));
	set("objects", ([
		__DIR__"npc/trader" : 1,
	]));
	set("item_desc", ([
		"shibei" : "北至西域，东达中原。谁若西行，格杀勿论。白驼山主人启。\n",
	]));
	set("coor/x", -24000);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_push", "push");
	add_action("do_push", "tui");
}

int valid_leave(object me, string dir)
{
	object ob;

	if ((dir == "west")&& !userp(me)) return 0;
	return ::valid_leave(me, dir);
	if(me->query_temp("wait_target") &&
		objectp(present("anran zi", environment(me))))
		return notify_fail("黯然子闪身拦在你面前，喝道：临阵想溜？给我滚回来！\n");
	if(me->query_temp("xx_rob") &&
		objectp(ob = present("hubiao biaoshi", environment(me))) &&
		ob->query("target") == me)
		return notify_fail("护镖镖师闪身拦住你的去路，看来是想把你给废了！\n");  
	if(me->query_temp("xx_rob") && objectp(present("shangdui",environment(me))))
		return notify_fail("商队在这里呢，快抢(qiang)啊！\n");  
	return ::valid_leave(me, dir);
}

int do_push(string arg)
{
	object me = this_player();
	mapping fam;

	if( !arg || arg=="" ) return 0;
	if( arg=="shibei" )
	{
		if((fam = me->query("family")) && fam["family_name"] == "丐帮")
		{
			message_vision("$N推开石碑，只见泥沙纷纷跌落，地面上露出一个小洞。\n", me);
			message("vision", me->name() + "运起丐帮缩骨功，一弯腰往洞里钻了进去。\n", environment(me), ({me}) );
			me->move("/d/gaibang/underxx");
			message("vision", me->name() + "从洞里走了进来。\n", environment(me), ({me}) );
			return 1;
		}
		else return notify_fail("这么小的洞，你钻得进去吗？\n");
	}
}	

