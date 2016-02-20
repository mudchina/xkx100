// Room: /city/pomiao.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "土地庙");
	set("long", @LONG
这是一间破破烂烂的土地庙，庙里破败不堪，土地神像推在一旁，
梁上地下也布满了灰尘。一看就知道已经很久没有人来清理过了。正中
放着个大香案，上面零乱地扔着几根吃剩下来的鸡骨头。也许正是因为
隐蔽的原因吧，据说丐帮江南分舵就被设在此处。香案黑洞洞的，好象
下边有个大洞(dong)。
LONG );
	set("valid_startroom", 1);
//	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"shoushe",
		"east"  : __DIR__"sheyuan",
		"south" : "/d/city/ml4",
		"enter" : __DIR__"gbandao",
	]));
	set("objects", ([
		CLASS_D("gaibang") + "/lu" : 1,
		CLASS_D("gaibang") + "/peng" : 1,
         	CLASS_D("gaibang") + "/first" : 1,
	]));
	create_door("enter", "小门", "out", DOOR_CLOSED);
	set("coor/x", 70);
	set("coor/y", 60);
	set("coor/z", 0);
	setup();
	"/clone/board/gaibang_r"->foo();
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

	if( arg=="dong" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "丐帮" ) 
		{
			message("vision",
				me->name() + "运起丐帮缩骨功，一弯腰往香案下的洞里钻了进去。\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/undergb");
                	message("vision",
				me->name() + "从洞里走了进来。\n",
                		environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("这么小的洞，你钻得进去吗？\n");
	}
}	

int valid_leave(object me, string dir)
{
        mapping myfam;
        object lu;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "丐帮") &&
            (dir == "west" || dir == "east") &&
                objectp(lu = present("lu youjiao", environment(me))) && living(lu))
           return notify_fail("鲁有脚拦住你说：此处乃本帮禁地，请止步。\n");

        return ::valid_leave(me, dir);
}
