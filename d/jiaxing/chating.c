// Room: /d/jiaxing/chating.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
        set("short", "茶亭");
        set("long", @LONG
这是一家路边的小茶亭，赶山路的人常在此处歇歇脚。亭子里有几
张桌子和几支条凳。周围是一片树林。
LONG );
        set("exits", ([
		"northeast" : "/d/shiliang/road2",
		"northwest" : "/d/shiliang/shandao1",
                "west"      : __DIR__"jnroad4",
        ]));
        set("objects", ([
                CLASS_D("heimuya")+"/xiang" : 1,
        ]));
        set("outdoors", "shiliang");
	set("coor/x", 1600);
	set("coor/y", -2000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}