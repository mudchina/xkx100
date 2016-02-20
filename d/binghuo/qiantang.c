// Room: /binghuo/qiantang.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "钱塘江畔");
	set("long", @LONG
钱塘江到了六和塔下转一个大弯，然后直向东流。该处和府城相
距不近，塔东三株大柳树下系着一艘扁舟(zhou)。江船张有风帆，船
头挂着两盏碧纱灯笼。碧纱灯下，一个少女独坐船头，身穿淡绿衫子。
LONG );
	set("outdoors", "wangpan");
	set("no_clean_up", 0);
	set("item_desc", ([
		"zhou" : "一艘小舟，不妨进去(enter)看看。\n",
	]));
	set("exits", ([
		"westup" : "/d/hangzhou/qiantang",
	]));
	set("coor/x", 4080);
	set("coor/y", -1800);
	set("coor/z", -10);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
        object me;
        mapping fam;

        me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="zhou" )
        {
               message("vision",
                        me->name() + "运起轻功，一纵身上了小舟。",
                        environment(me), ({me}) );
               me->move(__DIR__"zhou");
               message("vision",
                        me->name() + "从岸上跃上舟来。\n",
                        environment(me), ({me}) );
                        return 1;
        }
        else  return notify_fail("你想到哪去？\n");
}