// Room: /d/wudujiao/jingshi.c

inherit ROOM;

void create()
{
        set("short", "静室");
        set("long", @LONG
这是一个昏暗的房间，除了几张床之外什么都没有。室内光线昏暗，你
不由的打了一个哈欠。
LONG
        );
        set("sleep_room", 1);
        set("no_fight", 1);
	set("no_clean_up", 0);
        set("exits", ([
                "north" : __DIR__"dating",
        ]));

	set("coor/x", -44910);
	set("coor/y", -81060);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}