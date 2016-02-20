// fu-mishi.c 密室
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "密室");
        set("long", @LONG
这里是一间密室，四周散布着几条带血的鞭子，还有一些各
种各样的刑具。看来传说果然不虚，这侯员外果真是个鱼肉乡里
的恶霸。
LONG
        );
        set("exits", ([
                "northwest" : __DIR__"fu-midao",
                "up" : __DIR__"fu-woshi",
        ]));
        set("objects", ([
                "/clone/medicine/vegetable/xuejie" : 1,
        ]));
	set("coor/x", -3130);
	set("coor/y", -60);
	set("coor/z", -10);
	setup();
        replace_program(ROOM);
}