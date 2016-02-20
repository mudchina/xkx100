// Room: /d/5lt/wroad4.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
这是一个繁华的村子，一派欣欣向荣的景象。你走在一条东西向的
碎石路上。西北面是条小路，椰林掩映下，不知通向哪里。
LONG );
        set("exits", ([ /* sizeof() == 3 */
            "northwest" : __DIR__"xiaolu",
            "south"     : __DIR__"kongdi",
            "east"      : __DIR__"wroad3",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -190);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}