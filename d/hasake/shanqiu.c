// shanqiu.c 小山丘

inherit ROOM;

void create()
{
        set("short", "小山丘");
        set("long", @LONG
这里是草原和森林的分界线，往西可以看到高耸如云的天山山脉和从
这里一直延伸出去的针叶林，往东可以看见部族的跑马场，还隐隐可以听
见哈萨克族人的话语。
LONG);        
        set("exits", ([
            "eastdown" : __DIR__"road",
            "south" : __DIR__"caoyuan9",
            "north" : __DIR__"caoyuan9",
            "westdown" : __DIR__"senlin1",
        ]));

        set("objects", ([
                         __DIR__"npc/bird" : 1,
                         __DIR__"npc/supu" : 1,
        ]));

        set("outdoors", "hasake");
        
        setup();
        replace_program(ROOM);
}
