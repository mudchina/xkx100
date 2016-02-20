// Room: /d/wudujiao/neijin.c

inherit ROOM;

void create()
{
        set("short", "客房");
        set("long", @LONG
这里是一间客房，靠墙布着一溜通铺，行人累可以在这里随
意休息。窗边摆着一个破破烂烂的木桌，一个游方道人正坐在桌
边喝茶。
LONG
        );

        set("exits", ([
                "east" : __DIR__"xiaodian",
        ]));
        set("objects", ([
                CLASS_D("wudujiao")+"/daoshi": 1,
        ]));

	set("coor/x", -45020);
	set("coor/y", -79000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}