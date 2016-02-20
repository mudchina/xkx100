// Room: /d/5lt/qsroad.c

inherit ROOM;

void create()
{
        set("short", "青石大道");
        set("long", @LONG
你走在一条青石大道上,人来人往非常繁忙,不时有人骑着马匆匆而
过。北面是一片平缓的草地，一些叫不出名目的大鸟小兽在草丛中出没
十分自在地游嘻。南边是块菜地，刚刚下了场小雨，满眼的青翠让你心
情格外舒畅。东边通向村口。
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"caodi",
            "south" : __DIR__"caidi",
            "west"  : __DIR__"eroad2",
            "east"  : __DIR__"exit",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -120);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}