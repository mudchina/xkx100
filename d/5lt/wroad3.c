// Room: /d/5lt/wroad3.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
这是一个繁华的村子，一派欣欣向荣的景象。你走在一条东西向的
碎石路上。西北面是条乡间小道，椰林掩映下，不知通向哪里。
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "northwest" : __DIR__"xiaodao",
            "southup"   : __DIR__"shijie",
            "west"      : __DIR__"wroad4",
            "east"      : __DIR__"wroad2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -180);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}