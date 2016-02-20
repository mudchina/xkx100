// Room: /d/5lt/eroad2.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
这是一个繁华的村子，一派欣欣向荣的景象。你走在一条东西向的
碎石路上，东北面是一片竹林，好大一片绿竹丛，迎风摇曳，雅致天然。
南面有一片小树林。
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "northeast" : __DIR__"zhulin",
            "south" : __DIR__"xiaoshulin",
            "west"  : __DIR__"eroad1",
            "east"  : __DIR__"qsroad",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");
	set("coor/x", -130);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}