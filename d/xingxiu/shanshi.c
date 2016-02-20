// Room: /d/xingxiu/shanshi.c
// Last Modified by Winder on Apr. 25 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "山石");
	set("long", @LONG
这里是星宿海海边一处山石。东面是方圆几百里都是一望无际的湖
泊和沼泽。因为阴冷潮湿，此处毒虫繁殖甚富。星宿派弟子常来此捕捉
毒虫，以备练毒之用。南边有个黑黢黢的山洞(cave)。
LONG
	);
	set("objects", ([
		CLASS_D("xingxiu")+"/shihou" : 1,
		__DIR__"npc/haoshou"  : 1,
	]) );
	set("exits", ([
		"eastdown" : __DIR__"xxhb4",
	]));
	set("item_desc", ([
	      "cave" : "山洞里飘出一股股腥臭味，你还是快点离开吧。\n"
	]) );
	set("coor/x", -50300);
	set("coor/y", 20400);
	set("coor/z", 200);
	set("outdoors", "xingxiuhai");
	setup();
}

void init()
{
	object me, ob;
	mapping fam;
	me = this_player();
	fam = (mapping)me->query("family");
  
	if((objectp(present("lanyu bo", me)) ||
		objectp(present("shenmu wangding", me))) &&
		objectp(ob = present("shihou zi", environment(me))))
	{
		message_vision("$N对着$n大吼一声：大胆"+RANK_D->query_rude(me)+"，竟敢偷拿本派宝物！\n", ob, me);   
		ob->kill_ob(me);
	}
	add_action("do_enter", "enter");
	add_action("do_enter", "zuan");   
}

int do_enter(string arg)
{
	object me;
	mapping myfam;
	me = this_player();
	myfam = (mapping)me->query("family");

	if( !arg || arg=="" ) return 0;
	if (arg == "cave" )
	{
		if ((!myfam || myfam["family_name"] != "星宿派") &&
			objectp(present("shihou zi", environment(me))))
			return notify_fail("狮吼子闪身拦在你面前，喝道：不想挨揍的就快滚开！\n");
		message_vision("$N小心翼翼地往山洞里探了探。\n", me); 
		message("vision",me->name() + "一弯腰往山洞里钻了进去。\n", environment(me), ({me}) );
		me->move(__DIR__"cave");
		message("vision",me->name() + "从外面钻了进来。\n", environment(me), ({me}) );
			return 1;
	}     
}

int valid_leave(object me, string dir)
{   
	if((objectp(present("lanyu bo", me)) ||
		objectp(present("shenmu wangding", me))) &&
		objectp(present("shihou zi", environment(me))) &&
		dir == "east")
		return notify_fail("狮吼子闪身拦在你面前，喝道：想溜？没那么容易！\n");
	
	return ::valid_leave(me, dir);
}

