// mishi.c 密室
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "密室");
        set("long", @LONG
这里是全真教弟子为了直达中原修建的密室，这里的光线非常
昏暗，也许已经身处地下了。
LONG
        );
        set("exits", ([
                "up" : __DIR__"diziju",
                "eastup" : "/d/city/shilijie4",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2730);
	set("coor/y", 100);
	set("coor/z", 140);
	setup();
        replace_program(ROOM);
}