// Room: /d/wudujiao/sl7.c

inherit ROOM;

void create()
{
        set("short", "松树林");
        set("long", @LONG
这里是一片松树林，连绵的看不到尽头，四周都是参天的古松，但
许多都莫名其妙的枯死了，只剩下一些惨白的树干矗立在那里。阳光透
过枯死的树枝间隙照射到林中，暖洋洋的。四周死一般寂静，你不由一
阵紧张。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"sl8",
                "northwest" : __DIR__"sl4",
                "west" : __DIR__"sl6",
                "northeast" : __DIR__"sl5",
                "north" : __DIR__"caodi",
        ]));

	set("coor/x", -44930);
	set("coor/y", -81090);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}