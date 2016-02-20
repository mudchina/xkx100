// Room: /city/duchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "淮扬赌场");
	set("long", @LONG
这里是淮扬赌场的大院，烟花三月的扬州，怎么能少了这个？院子
四周是通往各个房间的通道。隐隐可以听到传出来吆五喝六的声音。你
摇头一笑，想要的正是这个调调儿。南面搏饼厅，也是本潭的网友联谊
会，联谊会四周是搏饼屋。
LONG );
	set("objects", ([
		CLASS_D("shenlong")+"/pang" : 1,
//		"/clone/misc/fifa2002" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"shaiziting",
		"west"  : __DIR__"shilijie2",
		"east"  : __DIR__"zoulang1",
		"south" : __DIR__"bobingting",
	]));
	set("no_clean_up", 0);
	set("outdoors", "duchang");
	set("coor/x", 20);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" && this_player()->query("age")<18)
                return notify_fail("小毛孩子往这儿瞎凑合什么？\n");
        return ::valid_leave(me, dir);
}
