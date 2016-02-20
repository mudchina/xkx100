// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "山洞");
	set("long", @LONG
你壮起胆子，走进了山洞中，这里暗无天日，突然间，有
只蝙蝠在你面前飞过，你被惊出了一身冷汗。越往里走就越来
越黑，你好象迷失方向了。
LONG
	);
        set("exits", ([
                "east"  : __FILE__,
                "west"  : __DIR__"shandong5",
                "south" : __DIR__"shandong7",
                "north" : __FILE__,
        ]));
	set("coor/x", 1600);
	set("coor/y", -1960);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}