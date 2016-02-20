// Room: /d/5lt/eroad1.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
这是一个繁华的村子，一派欣欣向荣的景象。你走在一条东西向的
碎石路上，南面是一间甜品店，微风习习，空气中夹杂着的饼的香味让
你不禁食指大动。北面是牌局室，隐约可以听到传出来吆五喝六的声音。
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"zoulang1",
            "south" : __DIR__"tianpindian",
	    "west"  : __DIR__"center",
            "east"  : __DIR__"eroad2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -140);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}