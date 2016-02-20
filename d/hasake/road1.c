// road1.c 小路

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
说是路，其实是人才草原上走过留下的痕迹，天长日久就渐渐行成了。
这只哈萨克部族在这里定居已久，可以看见到处是这种原始的道路。
LONG
        );

        
        set("exits", ([
            "northeast" : __DIR__"road2",
            "west" : __DIR__"shop",
            "north" : __DIR__"caoyuan4",
            "southdown" : __DIR__"caoyuan3",
            
        ]));

        set("outdoors", "hasake");
        
        setup();
        replace_program(ROOM);
}
