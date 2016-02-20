// minju2.c 民居
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "民居");
        set("long", @LONG
这是一家用茅草搭的房屋，家徒四壁，屋角的米缸是空的，厨房内
的水缸也是空的。几个缺胳膊少腿的桌椅靠墙立着。看来主人已经把所
有能值钱的东西全都变卖了。
LONG
        );
        set("exits", ([
                "south" : __DIR__"xijie",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3160);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}