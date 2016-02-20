// Room: /d/wuxi/dayifenduo.c
// Last Modifyed by Winder on Dec. 4 2001
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "大义分舵");
	set("long", @LONG
这里是杏子林中的丐帮大义分舵。分舵群丐分坐草地上，次序和职
司前后井然。林子边有一个大草堆(dui) ，看似十分平常，可是你总觉
得有点奇怪。
LONG );
	set("item_desc", ([
		"dui"  : "你仔细一看，发现秘密了：呵呵，草堆下面有个黑乎乎的大洞口！\n",
	]));
	set("exits", ([
		"south" : __DIR__"xinlin1",
	]));
	set("objects", ([
		CLASS_D("gaibang") + "/jiang" : 1,
		CLASS_D("gaibang") + "/bangzhong" : random(5),
	]));
	set("coor/x", 400);
	set("coor/y", -740);
	set("coor/z", 0);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
	object me;
	mapping fam;

	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="dui" )
	{
		if((fam = me->query("family")) && fam["family_name"] == "丐帮" )
		{
			message("vision",
				me->name() + "运起丐帮缩骨功，一弯腰往草堆下的洞里钻了进去。\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/underwx");
                	message("vision", me->name() + "从洞里走了进来。\n", environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("这么小的洞，你钻得进去吗？\n");
	}
}	

