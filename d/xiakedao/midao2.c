// midao2.c 密道


inherit ROOM;

void create()
{
        set("short", "秘密通道");
        set("long", @LONG
这是一条很长的秘密通道，也许好久没人来过了，密道中充满
了一种潮湿的气味，隐约可以感觉到四周是冰冷的石壁，你什么也
看不见，只可以靠摸索着前进。
LONG );
        set("exits", ([
               "west" : __DIR__"midao1",
               "south" : __DIR__"midao3",
               "east" : __FILE__,
               "north" : __FILE__,
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3090);
	set("coor/y", -25000);
	set("coor/z", -20);
	setup();
        replace_program(ROOM);
}