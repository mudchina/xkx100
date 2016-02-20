// Room: /d/xingxiu/xiaolu.c
// Last Modified by winder on Apr. 25 2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在一条在星宿海海边乱石堆里崎岖的小路上，路边有一群星宿
弟子正在长啸练功。这里，阴风凛冽，西面是望浩浩百里方圆的星宿海。
东面是座陡峭之极的山壁，壁上有一凸出的巨石(jushi) 。
LONG);
	set("exits", ([
		"west"    : __DIR__"xxh1",
		"northup" : __DIR__"shanbi",
	]));
	set("item_desc", ([
		"jushi" : "一数米高的黑褐色巨石。\n"
	]));
	set("objects", ([
		CLASS_D("xingxiu")+"/tianlang"  : 1,
		__DIR__"npc/xxdizi" : 1,
	]));
	set("coor/x", -49900);
	set("coor/y", 20200);
	set("coor/z", 0);
	set("outdoors", "xingxiu");
	setup();
}

void init()
{
	add_action("do_pa", "pa");
	add_action("do_pa", "climb");
}

int do_pa(string arg)
{
	object me = this_player();
	mapping myfam;
	myfam = (mapping)me->query("family");

	if( !arg || arg=="" ) return 0;
	if( arg=="jushi" )
	{
		if ((!myfam || myfam["family_name"] != "星宿派") &&
			(present("tianlang zi", environment(me)))) 
			return notify_fail("天狼子闪身拦在你面前, 喝道：不想死的就快滚开！\n");
		if(me->query_skill("dodge") < 100)
			return notify_fail("你想爬上巨石，怎奈身法不够上不去。\n");       
		message_vision("$N很费劲地爬上巨石。\n", me);
		message("vision", me->name() + "一转眼便消失在山壁上。\n", environment(me), ({me}) );
		if ( time()-me->query_temp("LAST_PKER_TIME")<7200)
		{
			write( WHT"你爬上巨石，却发现上面已无容身之处，只好悻悻的退了下来。\n"NOR );
			me->move( __DIR__"xiaolu" );
			return 1;
		}
		me->move(__DIR__"jushi");
		message("vision", me->name() + "从山壁下爬了上来。\n", environment(me), ({me}) );
		return 1;
	}
}
