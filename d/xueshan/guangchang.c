//      guangchang.c 广场

inherit ROOM;

void create()
{
        set("short","广场");
        set("long",@LONG
这里是雪山寺内的广场。广场石埕铺就，黄土垫砌，平整而坚实。
广场的北面就是依山而建的雪山寺大殿。往西是块练武场，南面是山门。
寺内有一些手持僧棍的僧兵在巡逻。
LONG );
        set("outdoors","xueshansi");
        set("exits",([
                "east" : __DIR__"xiaoyuan",
                "west" : __DIR__"chang",
                "north" : __DIR__"dadian",
                "south" : __DIR__"shanmen",
        ]));
        set("objects" , ([
                __DIR__"npc/seng-bing1"  : 4 ,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -70000);
	set("coor/y", -19900);
	set("coor/z", 120);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "south" ) return 0;

	return ::valid_leave(me, dir);
}
