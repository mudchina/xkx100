// road2.c 小路

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
说是路，其实是人才草原上走过留下的痕迹，天长日久就渐渐行成了。
这只哈萨克部族在这里定居已久，可以看见到处是这种原始的道路。北边
好象有一间小草棚。
LONG);
        
        set("exits", ([
            "southwest" : __DIR__"road1",
            "north" : __DIR__"room-ji",
            "northeast" : __DIR__"caoyuan6",
            
        ]));

         set("objects", ([
                    __DIR__"npc/bird" : 1

        ]));

        set("outdoors", "hasake");
        
        setup();
        replace_program(ROOM);
}
